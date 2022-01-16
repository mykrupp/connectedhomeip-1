/**
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/****************************************************************************
 * @file
 * @brief Routines for the Application Launcher plugin, the
 *server implementation of the Application Launcher cluster.
 *******************************************************************************
 ******************************************************************************/

#include <app/clusters/application-basic-server/application-basic-server.h>
#include <app/clusters/application-launcher-server/application-launcher-delegate.h>
#include <app/clusters/application-launcher-server/application-launcher-server.h>

#include <app/AttributeAccessInterface.h>
#include <app/CommandHandler.h>
#include <app/ConcreteCommandPath.h>
#include <app/app-platform/ContentAppPlatform.h>
#include <app/data-model/Encode.h>
#include <app/util/attribute-storage.h>

using namespace chip;
using namespace chip::app::Clusters;
using namespace chip::app::Clusters::ApplicationLauncher;
using namespace chip::AppPlatform;

// -----------------------------------------------------------------------------
// Delegate Implementation

using chip::app::Clusters::ApplicationLauncher::Delegate;

namespace {

Delegate * gDelegateTable[EMBER_AF_APPLICATION_LAUNCHER_CLUSTER_SERVER_ENDPOINT_COUNT] = { nullptr };

Delegate * GetDelegate(EndpointId endpoint)
{
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
    ContentApp * app = chip::AppPlatform::AppPlatform::GetInstance().GetContentAppByEndpointId(endpoint);
    if (app != NULL)
    {
        ChipLogError(Zcl, "ApplicationLauncher returning ContentApp delegate for endpoint:%" PRIu16, endpoint);
        return app->GetApplicationLauncherDelegate();
    }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
    ChipLogError(Zcl, "ApplicationLauncher NOT returning ContentApp delegate for endpoint:%" PRIu16, endpoint);

    uint16_t ep = emberAfFindClusterServerEndpointIndex(endpoint, chip::app::Clusters::ApplicationLauncher::Id);
    return ((ep == 0xFFFF || ep >= EMBER_AF_APPLICATION_LAUNCHER_CLUSTER_SERVER_ENDPOINT_COUNT) ? NULL : gDelegateTable[ep]);
}

bool isDelegateNull(Delegate * delegate, EndpointId endpoint)
{
    if (delegate == nullptr)
    {
        ChipLogError(Zcl, "Application Launcher has no delegate set for endpoint:%" PRIu16, endpoint);
        return true;
    }
    return false;
}
} // namespace

namespace chip {
namespace app {
namespace Clusters {
namespace ApplicationLauncher {

void SetDefaultDelegate(EndpointId endpoint, Delegate * delegate)
{
    uint16_t ep = emberAfFindClusterServerEndpointIndex(endpoint, chip::app::Clusters::ApplicationLauncher::Id);
    // if endpoint is found and is not a dynamic endpoint
    if (ep != 0xFFFF && ep < EMBER_AF_APPLICATION_LAUNCHER_CLUSTER_SERVER_ENDPOINT_COUNT)
    {
        gDelegateTable[ep] = delegate;
    }
    else
    {
    }
}

// this attribute should only be enabled for app platform instance (endpoint 1)
chip::app::Clusters::ApplicationLauncher::Structs::ApplicationEP::Type Delegate::HandleGetCurrentApp()
{
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
    if (HasFeature(chip::app::Clusters::ApplicationLauncher::ApplicationLauncherFeature::kApplicationPlatform))
    {
        chip::AppPlatform::AppPlatform platform = chip::AppPlatform::AppPlatform::GetInstance();
        if (platform.HasCurrentApp())
        {
            chip::app::Clusters::ApplicationLauncher::Structs::ApplicationEP::Type * app = platform.GetCurrentApp();
            if (app != NULL)
            {
                return *app;
            }
        }
    }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED

    // TODO: change to return null once 13606 is fixed
    Structs::ApplicationEP::Type currentApp;
    currentApp.application.catalogVendorId = 123;
    currentApp.application.applicationId   = chip::CharSpan("applicationId", strlen("applicationId"));
    currentApp.endpoint                    = chip::CharSpan("endpointId", strlen("endpointId"));
    return currentApp;
}

} // namespace ApplicationLauncher
} // namespace Clusters
} // namespace app
} // namespace chip

// -----------------------------------------------------------------------------
// Attribute Accessor Implementation

namespace {

class ApplicationLauncherAttrAccess : public app::AttributeAccessInterface
{
public:
    ApplicationLauncherAttrAccess() :
        app::AttributeAccessInterface(Optional<EndpointId>::Missing(), chip::app::Clusters::ApplicationLauncher::Id)
    {}

    CHIP_ERROR Read(const app::ConcreteReadAttributePath & aPath, app::AttributeValueEncoder & aEncoder) override;

private:
    CHIP_ERROR ReadCatalogListAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate);
    CHIP_ERROR ReadCurrentAppAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate);
};

ApplicationLauncherAttrAccess gApplicationLauncherAttrAccess;

CHIP_ERROR ApplicationLauncherAttrAccess::Read(const app::ConcreteReadAttributePath & aPath, app::AttributeValueEncoder & aEncoder)
{
    EndpointId endpoint = aPath.mEndpointId;
    Delegate * delegate = GetDelegate(endpoint);

    if (isDelegateNull(delegate, endpoint))
    {
        return CHIP_NO_ERROR;
    }

    switch (aPath.mAttributeId)
    {
    case app::Clusters::ApplicationLauncher::Attributes::ApplicationLauncherList::Id: {
        return ReadCatalogListAttribute(aEncoder, delegate);
    }
    case app::Clusters::ApplicationLauncher::Attributes::ApplicationLauncherApp::Id: {
        return ReadCurrentAppAttribute(aEncoder, delegate);
    }
    default: {
        break;
    }
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR ApplicationLauncherAttrAccess::ReadCatalogListAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate)
{
    std::list<uint16_t> catalogList = delegate->HandleGetCatalogList();
    return aEncoder.EncodeList([catalogList](const auto & encoder) -> CHIP_ERROR {
        for (const auto & catalog : catalogList)
        {
            ReturnErrorOnFailure(encoder.Encode(catalog));
        }
        return CHIP_NO_ERROR;
    });
}

CHIP_ERROR ApplicationLauncherAttrAccess::ReadCurrentAppAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate)
{
    Structs::ApplicationEP::Type currentApp = delegate->HandleGetCurrentApp();
    return aEncoder.Encode(currentApp);
}

} // anonymous namespace

// -----------------------------------------------------------------------------
// Matter Framework Callbacks Implementation

bool emberAfApplicationLauncherClusterLaunchAppRequestCallback(app::CommandHandler * command,
                                                               const app::ConcreteCommandPath & commandPath,
                                                               const Commands::LaunchAppRequest::DecodableType & commandData)
{
    CHIP_ERROR err      = CHIP_NO_ERROR;
    EndpointId endpoint = commandPath.mEndpointId;
    auto & data         = commandData.data;
    auto & application  = commandData.application;

    Application appInput;
    appInput.catalogVendorId = application.catalogVendorId;
    appInput.applicationId   = (application.applicationId.size() > 0) ? application.applicationId : data;

    Delegate * delegate = GetDelegate(endpoint);
    VerifyOrExit(isDelegateNull(delegate, endpoint) != true, err = CHIP_ERROR_INCORRECT_STATE);

    {
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        // if the feature flag is APP_Plaform, then this is a call to endpoint 1 to launching an app
        //  1. Find target Content App and load if not loaded
        //  2. Set current app to Content App
        //  3. Set Content App status (basic cluster) to ACTIVE_VISIBLE_FOCUS
        //  4. Call launch app command on Content App
        if (delegate->HasFeature(chip::app::Clusters::ApplicationLauncher::ApplicationLauncherFeature::kApplicationPlatform))
        {
            ChipLogError(Zcl, "ApplicationLauncher has content platform feature");
            ContentApp * app = chip::AppPlatform::AppPlatform::GetInstance().GetLoadContentAppByAppId(appInput);
            if (app == NULL)
            {
                ChipLogError(Zcl, "ApplicationLauncher target app not found");
                Commands::LauncherResponse::Type response;
                response.data   = chip::CharSpan("data", strlen("data"));
                response.status = StatusEnum::kAppNotAvailable;
                err             = command->AddResponseData(commandPath, response);
                SuccessOrExit(err);
            }
            chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType =
                app->GetApplicationBasicDelegate()->HandleGetApplication();

            ChipLogError(Zcl, "ApplicationLauncher setting current app");
            chip::AppPlatform::AppPlatform::GetInstance().SetCurrentApp(applicationType.catalogVendorId,
                                                                        applicationType.applicationId, app->GetEndpointId());

            ChipLogError(Zcl, "ApplicationLauncher setting app status");
            app->GetApplicationBasicDelegate()->SetApplicationStatus(
                chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kActiveVisibleFocus);

            ChipLogError(Zcl, "ApplicationLauncher handling launch on ContentApp");
            Commands::LauncherResponse::Type response = app->GetApplicationLauncherDelegate()->HandleLaunchApp(data, application);
            err                                       = command->AddResponseData(commandPath, response);
            SuccessOrExit(err);
            return true;
        }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
       // otherwise, assume this is for managing status of the Content App on this endpoint
       //  1. Set Content App status (basic cluster) to ACTIVE_VISIBLE_FOCUS
       //  2. Call launch app command on the given endpoint

        ChipLogError(Zcl, "ApplicationLauncher no content platform feature");
        chip::app::Clusters::ApplicationBasic::Delegate * appBasic =
            chip::app::Clusters::ApplicationBasic::GetDefaultDelegate(endpoint);
        if (appBasic != NULL)
        {
            ChipLogError(Zcl, "ApplicationLauncher setting basic cluster status to visible");
            appBasic->SetApplicationStatus(chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kActiveVisibleFocus);
        }

#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType = appBasic->HandleGetApplication();

        chip::AppPlatform::AppPlatform::GetInstance().SetCurrentApp(applicationType.catalogVendorId, applicationType.applicationId,
                                                                    endpoint);
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED

        ChipLogError(Zcl, "ApplicationLauncher handling launch");
        Commands::LauncherResponse::Type response = delegate->HandleLaunchApp(data, application);
        err                                       = command->AddResponseData(commandPath, response);
        SuccessOrExit(err);
    }

exit:
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(Zcl, "emberAfApplicationLauncherClusterLaunchAppRequestCallback error: %s", err.AsString());
        emberAfSendImmediateDefaultResponse(EMBER_ZCL_STATUS_FAILURE);
    }

    return true;
}

/**
 * @brief Application Launcher Cluster StopApp Command callback (from client)
 */
bool emberAfApplicationLauncherClusterStopAppRequestCallback(app::CommandHandler * command,
                                                             const app::ConcreteCommandPath & commandPath,
                                                             const Commands::StopAppRequest::DecodableType & commandData)
{
    CHIP_ERROR err      = CHIP_NO_ERROR;
    EndpointId endpoint = commandPath.mEndpointId;
    auto & application  = commandData.application;

    Application appInput;
    appInput.catalogVendorId = application.catalogVendorId;
    appInput.applicationId   = application.applicationId;

    Delegate * delegate = GetDelegate(endpoint);
    VerifyOrExit(isDelegateNull(delegate, endpoint) != true, err = CHIP_ERROR_INCORRECT_STATE);

    {
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        // if the feature flag is APP_Plaform, then this is a call to endpoint 1 to stop an app
        //  1. Find target Content App
        //  3. If this was the current app then stop it
        //  2. Set Content App status (basic cluster) to ACTIVE_STOPPED
        //  4. Call stop app command on Content App
        if (delegate->HasFeature(chip::app::Clusters::ApplicationLauncher::ApplicationLauncherFeature::kApplicationPlatform))
        {
            ChipLogError(Zcl, "ApplicationLauncher has content platform feature");
            ContentApp * app = chip::AppPlatform::AppPlatform::GetInstance().GetContentAppByAppId(appInput);
            if (app == NULL)
            {
                ChipLogError(Zcl, "ApplicationLauncher target app not loaded");
                Commands::LauncherResponse::Type response;
                response.data   = chip::CharSpan("data", strlen("data"));
                response.status = StatusEnum::kAppNotAvailable;
                err             = command->AddResponseData(commandPath, response);
                SuccessOrExit(err);
            }
            chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType =
                app->GetApplicationBasicDelegate()->HandleGetApplication();

            chip::AppPlatform::AppPlatform::GetInstance().UnsetIfCurrentApp(applicationType.catalogVendorId,
                                                                            applicationType.applicationId);

            ChipLogError(Zcl, "ApplicationLauncher setting app status");
            app->GetApplicationBasicDelegate()->SetApplicationStatus(
                chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kStopped);

            ChipLogError(Zcl, "ApplicationLauncher handling stop on ContentApp");
            Commands::LauncherResponse::Type response = app->GetApplicationLauncherDelegate()->HandleStopApp(application);
            err                                       = command->AddResponseData(commandPath, response);
            SuccessOrExit(err);
            return true;
        }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
       // otherwise, assume this is for managing status of the Content App on this endpoint
       //  1. Set Content App status (basic cluster) to ACTIVE_STOPPED
       //  2. Call launch app command on the given endpoint

        ChipLogError(Zcl, "ApplicationLauncher no content platform feature");

        chip::app::Clusters::ApplicationBasic::Delegate * appBasic =
            chip::app::Clusters::ApplicationBasic::GetDefaultDelegate(endpoint);
        if (appBasic != NULL)
        {
            ChipLogError(Zcl, "ApplicationLauncher setting basic cluster status to stopped");
            appBasic->SetApplicationStatus(chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kStopped);
        }

#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType = appBasic->HandleGetApplication();

        chip::AppPlatform::AppPlatform::GetInstance().UnsetIfCurrentApp(applicationType.catalogVendorId,
                                                                        applicationType.applicationId);
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED

        Commands::LauncherResponse::Type response = delegate->HandleStopApp(application);
        err                                       = command->AddResponseData(commandPath, response);
        SuccessOrExit(err);
    }

exit:
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(Zcl, "emberAfApplicationLauncherClusterStopAppRequestCallback error: %s", err.AsString());
        emberAfSendImmediateDefaultResponse(EMBER_ZCL_STATUS_FAILURE);
    }

    return true;
}

/**
 * @brief Application Launcher Cluster HideApp Command callback (from client)
 */
bool emberAfApplicationLauncherClusterHideAppRequestCallback(app::CommandHandler * command,
                                                             const app::ConcreteCommandPath & commandPath,
                                                             const Commands::HideAppRequest::DecodableType & commandData)
{
    CHIP_ERROR err      = CHIP_NO_ERROR;
    EndpointId endpoint = commandPath.mEndpointId;
    auto & application  = commandData.application;

    Application appInput;
    appInput.catalogVendorId = application.catalogVendorId;
    appInput.applicationId   = application.applicationId;

    Delegate * delegate = GetDelegate(endpoint);
    VerifyOrExit(isDelegateNull(delegate, endpoint) != true, err = CHIP_ERROR_INCORRECT_STATE);

    {
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        // if the feature flag is APP_Plaform, then this is a call to endpoint 1 to stop an app
        //  1. Find target Content App
        //  3. If this was the current app then hide it
        //  2. Set Content App status (basic cluster) to ACTIVE_VISIBLE_NOT_FOCUS
        //  4. Call stop app command on Content App
        if (delegate->HasFeature(chip::app::Clusters::ApplicationLauncher::ApplicationLauncherFeature::kApplicationPlatform))
        {
            ChipLogError(Zcl, "ApplicationLauncher has content platform feature");
            ContentApp * app = chip::AppPlatform::AppPlatform::GetInstance().GetContentAppByAppId(appInput);
            if (app == NULL)
            {
                ChipLogError(Zcl, "ApplicationLauncher target app not loaded");
                Commands::LauncherResponse::Type response;
                response.data   = chip::CharSpan("data", strlen("data"));
                response.status = StatusEnum::kAppNotAvailable;
                err             = command->AddResponseData(commandPath, response);
                SuccessOrExit(err);
            }
            chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType =
                app->GetApplicationBasicDelegate()->HandleGetApplication();

            chip::AppPlatform::AppPlatform::GetInstance().UnsetIfCurrentApp(applicationType.catalogVendorId,
                                                                            applicationType.applicationId);

            ChipLogError(Zcl, "ApplicationLauncher setting app status");
            app->GetApplicationBasicDelegate()->SetApplicationStatus(
                chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kActiveHidden);

            ChipLogError(Zcl, "ApplicationLauncher handling stop on ContentApp");
            Commands::LauncherResponse::Type response = app->GetApplicationLauncherDelegate()->HandleHideApp(application);
            err                                       = command->AddResponseData(commandPath, response);
            SuccessOrExit(err);
            return true;
        }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
       // otherwise, assume this is for managing status of the Content App on this endpoint
       //  1. Set Content App status (basic cluster) to ACTIVE_VISIBLE_NOT_FOCUS
       //  2. Call launch app command on the given endpoint

        ChipLogError(Zcl, "ApplicationLauncher no content platform feature");

        chip::app::Clusters::ApplicationBasic::Delegate * appBasic =
            chip::app::Clusters::ApplicationBasic::GetDefaultDelegate(endpoint);
        if (appBasic != NULL)
        {
            ChipLogError(Zcl, "ApplicationLauncher setting basic cluster status to stopped");
            appBasic->SetApplicationStatus(chip::app::Clusters::ApplicationBasic::ApplicationStatusEnum::kActiveHidden);
        }

#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
        chip::app::Clusters::ApplicationBasic::Structs::Application::Type applicationType = appBasic->HandleGetApplication();

        chip::AppPlatform::AppPlatform::GetInstance().UnsetIfCurrentApp(applicationType.catalogVendorId,
                                                                        applicationType.applicationId);
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED

        Commands::LauncherResponse::Type response = delegate->HandleHideApp(application);
        err                                       = command->AddResponseData(commandPath, response);
        SuccessOrExit(err);
    }

exit:
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(Zcl, "emberAfApplicationLauncherClusterStopAppRequestCallback error: %s", err.AsString());
        emberAfSendImmediateDefaultResponse(EMBER_ZCL_STATUS_FAILURE);
    }

    return true;
}

// -----------------------------------------------------------------------------
// Plugin initialization

void MatterApplicationLauncherPluginServerInitCallback(void)
{
    registerAttributeAccessOverride(&gApplicationLauncherAttrAccess);
}
