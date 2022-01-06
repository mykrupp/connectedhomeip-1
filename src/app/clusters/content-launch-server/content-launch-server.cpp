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

/**
 *
 *    Copyright (c) 2021 Silicon Labs
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
 * @brief Routines for the Content Launch plugin, the
 *server implementation of the Content Launch cluster.
 *******************************************************************************
 ******************************************************************************/

#include <app/clusters/content-launch-server/content-launch-delegate.h>
#include <app/clusters/content-launch-server/content-launch-server.h>

#include <app/AttributeAccessInterface.h>
#include <app/CommandHandler.h>
#include <app/ConcreteCommandPath.h>
#include <app/app-platform/ContentAppPlatform.h>
#include <app/data-model/Encode.h>
#include <app/util/af.h>
#include <app/util/attribute-storage.h>
#include <list>

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters::ContentLauncher;

// -----------------------------------------------------------------------------
// Delegate Implementation

using chip::app::Clusters::ContentLauncher::Delegate;
using namespace chip::AppPlatform;

namespace {

Delegate * gDelegate = NULL;

Delegate * GetDelegate(EndpointId endpoint)
{
#if CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
    ContentApp * app = chip::AppPlatform::AppPlatform::GetInstance().GetContentAppByEndpointId(endpoint);
    if (app != NULL && app->GetContentLauncherDelegate() != NULL)
    {
        ChipLogError(Zcl, "Content Launcher returning ContentApp delegate for endpoint:%" PRIu16, endpoint);
        return app->GetContentLauncherDelegate();
    }
#endif // CHIP_DEVICE_CONFIG_APP_PLATFORM_ENABLED
    ChipLogError(Zcl, "Content Launcher NOT returning ContentApp delegate for endpoint:%" PRIu16, endpoint);

    return gDelegate;
}

bool isDelegateNull(Delegate * delegate, EndpointId endpoint)
{
    if (delegate == nullptr)
    {
        ChipLogError(Zcl, "Content Launcher has no delegate set for endpoint:%" PRIu16, endpoint);
        return true;
    }
    return false;
}
} // namespace

namespace chip {
namespace app {
namespace Clusters {
namespace ContentLauncher {

void SetDefaultDelegate(Delegate * delegate)
{
    gDelegate = delegate;
}

} // namespace ContentLauncher
} // namespace Clusters
} // namespace app
} // namespace chip

// -----------------------------------------------------------------------------
// Attribute Accessor Implementation

namespace {

class ContentLauncherAttrAccess : public app::AttributeAccessInterface
{
public:
    ContentLauncherAttrAccess() :
        app::AttributeAccessInterface(Optional<EndpointId>::Missing(), chip::app::Clusters::ContentLauncher::Id)
    {}

    CHIP_ERROR Read(const app::ConcreteReadAttributePath & aPath, app::AttributeValueEncoder & aEncoder) override;

private:
    CHIP_ERROR ReadAcceptHeaderAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate);
    CHIP_ERROR ReadSupportedStreamingProtocolsAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate);
};

ContentLauncherAttrAccess gContentLauncherAttrAccess;

CHIP_ERROR ContentLauncherAttrAccess::Read(const app::ConcreteReadAttributePath & aPath, app::AttributeValueEncoder & aEncoder)
{
    EndpointId endpoint = aPath.mEndpointId;
    Delegate * delegate = GetDelegate(endpoint);

    if (isDelegateNull(delegate, endpoint))
    {
        return CHIP_NO_ERROR;
    }

    switch (aPath.mAttributeId)
    {
    case app::Clusters::ContentLauncher::Attributes::AcceptHeaderList::Id: {
        return ReadAcceptHeaderAttribute(aEncoder, delegate);
    }
    case app::Clusters::ContentLauncher::Attributes::SupportedStreamingProtocols::Id: {
        return ReadSupportedStreamingProtocolsAttribute(aEncoder, delegate);
    }
    default: {
        break;
    }
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR ContentLauncherAttrAccess::ReadAcceptHeaderAttribute(app::AttributeValueEncoder & aEncoder, Delegate * delegate)
{
    std::list<std::string> acceptHeaderList = delegate->HandleGetAcceptHeaderList();
    return aEncoder.EncodeList([acceptHeaderList](const auto & encoder) -> CHIP_ERROR {
        for (const auto & acceptedHeader : acceptHeaderList)
        {
            CharSpan span(acceptedHeader.c_str(), acceptedHeader.length());
            ReturnErrorOnFailure(encoder.Encode(span));
        }
        return CHIP_NO_ERROR;
    });
}

CHIP_ERROR ContentLauncherAttrAccess::ReadSupportedStreamingProtocolsAttribute(app::AttributeValueEncoder & aEncoder,
                                                                               Delegate * delegate)
{
    uint32_t streamingProtocols = delegate->HandleGetSupportedStreamingProtocols();
    return aEncoder.Encode(streamingProtocols);
}

} // anonymous namespace

// -----------------------------------------------------------------------------
// Matter Framework Callbacks Implementation

bool emberAfContentLauncherClusterLaunchContentRequestCallback(
    chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
    const chip::app::Clusters::ContentLauncher::Commands::LaunchContentRequest::DecodableType & commandData)
{
    CHIP_ERROR err      = CHIP_NO_ERROR;
    EndpointId endpoint = commandPath.mEndpointId;

    auto & autoplay = commandData.autoPlay;
    auto & data     = commandData.data;
    // TODO: Decode the parameter and pass it to delegate
    // auto searchIterator = commandData.search.begin();
    std::list<Parameter> parameterList;

    Delegate * delegate = GetDelegate(endpoint);
    VerifyOrExit(isDelegateNull(delegate, endpoint) != true, err = CHIP_ERROR_INCORRECT_STATE);

    {
        Commands::LaunchResponse::Type response = delegate->HandleLaunchContent(parameterList, autoplay, data);
        err                                     = commandObj->AddResponseData(commandPath, response);
        SuccessOrExit(err);
    }

exit:
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(Zcl, "emberAfContentLauncherClusterLaunchContentRequestCallback error: %s", err.AsString());

        emberAfSendImmediateDefaultResponse(EMBER_ZCL_STATUS_FAILURE);
    }

    return true;
}

bool emberAfContentLauncherClusterLaunchURLRequestCallback(
    chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
    const chip::app::Clusters::ContentLauncher::Commands::LaunchURLRequest::DecodableType & commandData)
{
    CHIP_ERROR err      = CHIP_NO_ERROR;
    EndpointId endpoint = commandPath.mEndpointId;

    auto & contentUrl    = commandData.contentURL;
    auto & displayString = commandData.displayString;
    // TODO: Decode the parameter and pass it to delegate
    // auto brandingInformationIterator = commandData.brandingInformation.begin();
    std::list<BrandingInformation> brandingInformationList;

    Delegate * delegate = GetDelegate(endpoint);
    VerifyOrExit(isDelegateNull(delegate, endpoint) != true, err = CHIP_ERROR_INCORRECT_STATE);

    {
        Commands::LaunchResponse::Type response = delegate->HandleLaunchUrl(contentUrl, displayString, brandingInformationList);
        err                                     = commandObj->AddResponseData(commandPath, response);
        SuccessOrExit(err);
    }

exit:
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(Zcl, "emberAfContentLauncherClusterLaunchURLCallback error: %s", err.AsString());

        emberAfSendImmediateDefaultResponse(EMBER_ZCL_STATUS_FAILURE);
    }

    return true;
}

// -----------------------------------------------------------------------------
// Plugin initialization

void MatterContentLauncherPluginServerInitCallback(void)
{
    registerAttributeAccessOverride(&gContentLauncherAttrAccess);
}
