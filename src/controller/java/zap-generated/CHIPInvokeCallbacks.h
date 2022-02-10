/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP
#include "CHIPCallbackTypes.h"

#include <app-common/zap-generated/cluster-objects.h>
#include <jni.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

class CHIPAccountLoginClusterGetSetupPINResponseCallback
    : public Callback::Callback<CHIPAccountLoginClusterGetSetupPINResponseCallbackType>
{
public:
    CHIPAccountLoginClusterGetSetupPINResponseCallback(jobject javaCallback);

    ~CHIPAccountLoginClusterGetSetupPINResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::AccountLogin::Commands::GetSetupPINResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPApplicationLauncherClusterLauncherResponseCallback
    : public Callback::Callback<CHIPApplicationLauncherClusterLauncherResponseCallbackType>
{
public:
    CHIPApplicationLauncherClusterLauncherResponseCallback(jobject javaCallback);

    ~CHIPApplicationLauncherClusterLauncherResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::ApplicationLauncher::Commands::LauncherResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPChannelClusterChangeChannelResponseCallback
    : public Callback::Callback<CHIPChannelClusterChangeChannelResponseCallbackType>
{
public:
    CHIPChannelClusterChangeChannelResponseCallback(jobject javaCallback);

    ~CHIPChannelClusterChangeChannelResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Channel::Commands::ChangeChannelResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPContentLauncherClusterLaunchResponseCallback
    : public Callback::Callback<CHIPContentLauncherClusterLaunchResponseCallbackType>
{
public:
    CHIPContentLauncherClusterLaunchResponseCallback(jobject javaCallback);

    ~CHIPContentLauncherClusterLaunchResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::ContentLauncher::Commands::LaunchResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback
    : public Callback::Callback<CHIPDiagnosticLogsClusterRetrieveLogsResponseCallbackType>
{
public:
    CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback(jobject javaCallback);

    ~CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DiagnosticLogs::Commands::RetrieveLogsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetCredentialStatusResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetCredentialStatusResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetCredentialStatusResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetCredentialStatusResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetCredentialStatusResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetUserResponseCallback : public Callback::Callback<CHIPDoorLockClusterGetUserResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetUserResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetUserResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::GetUserResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetWeekDayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetWeekDayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetWeekDayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetWeekDayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetWeekDayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetYearDayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetYearDayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetYearDayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetYearDayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetYearDayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetCredentialResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterSetCredentialResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetCredentialResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetCredentialResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::SetCredentialResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterArmFailSafeResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterArmFailSafeResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterArmFailSafeResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterArmFailSafeResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::GeneralCommissioning::Commands::ArmFailSafeResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::GeneralCommissioning::Commands::CommissioningCompleteResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::GeneralCommissioning::Commands::SetRegulatoryConfigResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupKeyManagementClusterKeySetReadAllIndicesResponseCallback
    : public Callback::Callback<CHIPGroupKeyManagementClusterKeySetReadAllIndicesResponseCallbackType>
{
public:
    CHIPGroupKeyManagementClusterKeySetReadAllIndicesResponseCallback(jobject javaCallback);

    ~CHIPGroupKeyManagementClusterKeySetReadAllIndicesResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::GroupKeyManagement::Commands::KeySetReadAllIndicesResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupKeyManagementClusterKeySetReadResponseCallback
    : public Callback::Callback<CHIPGroupKeyManagementClusterKeySetReadResponseCallbackType>
{
public:
    CHIPGroupKeyManagementClusterKeySetReadResponseCallback(jobject javaCallback);

    ~CHIPGroupKeyManagementClusterKeySetReadResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::GroupKeyManagement::Commands::KeySetReadResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterAddGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterAddGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterAddGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterAddGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::AddGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterGetGroupMembershipResponseCallback
    : public Callback::Callback<CHIPGroupsClusterGetGroupMembershipResponseCallbackType>
{
public:
    CHIPGroupsClusterGetGroupMembershipResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterGetGroupMembershipResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Groups::Commands::GetGroupMembershipResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterRemoveGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterRemoveGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterRemoveGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterRemoveGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::RemoveGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterViewGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterViewGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterViewGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterViewGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::ViewGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPIdentifyClusterIdentifyQueryResponseCallback
    : public Callback::Callback<CHIPIdentifyClusterIdentifyQueryResponseCallbackType>
{
public:
    CHIPIdentifyClusterIdentifyQueryResponseCallback(jobject javaCallback);

    ~CHIPIdentifyClusterIdentifyQueryResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Identify::Commands::IdentifyQueryResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPKeypadInputClusterSendKeyResponseCallback : public Callback::Callback<CHIPKeypadInputClusterSendKeyResponseCallbackType>
{
public:
    CHIPKeypadInputClusterSendKeyResponseCallback(jobject javaCallback);

    ~CHIPKeypadInputClusterSendKeyResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::KeypadInput::Commands::SendKeyResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterPlaybackResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterPlaybackResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterPlaybackResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterPlaybackResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::PlaybackResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterConnectNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterConnectNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterConnectNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterConnectNetworkResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::ConnectNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterNetworkConfigResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterNetworkConfigResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterNetworkConfigResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterNetworkConfigResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::NetworkConfigResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterScanNetworksResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterScanNetworksResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterScanNetworksResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterScanNetworksResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::ScanNetworksResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback
    : public Callback::Callback<CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallbackType>
{
public:
    CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback(jobject javaCallback);

    ~CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::ApplyUpdateResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback
    : public Callback::Callback<CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallbackType>
{
public:
    CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback(jobject javaCallback);

    ~CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::QueryImageResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterAttestationResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterAttestationResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterAttestationResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterAttestationResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::AttestationResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterCSRResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterCSRResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterCSRResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterCSRResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::CSRResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterCertificateChainResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterCertificateChainResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterCertificateChainResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterCertificateChainResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OperationalCredentials::Commands::CertificateChainResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterNOCResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterNOCResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterNOCResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterNOCResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::NOCResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterAddSceneResponseCallback : public Callback::Callback<CHIPScenesClusterAddSceneResponseCallbackType>
{
public:
    CHIPScenesClusterAddSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterAddSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::AddSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterGetSceneMembershipResponseCallback
    : public Callback::Callback<CHIPScenesClusterGetSceneMembershipResponseCallbackType>
{
public:
    CHIPScenesClusterGetSceneMembershipResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterGetSceneMembershipResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Scenes::Commands::GetSceneMembershipResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterRemoveAllScenesResponseCallback
    : public Callback::Callback<CHIPScenesClusterRemoveAllScenesResponseCallbackType>
{
public:
    CHIPScenesClusterRemoveAllScenesResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterRemoveAllScenesResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Scenes::Commands::RemoveAllScenesResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterRemoveSceneResponseCallback : public Callback::Callback<CHIPScenesClusterRemoveSceneResponseCallbackType>
{
public:
    CHIPScenesClusterRemoveSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterRemoveSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::RemoveSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterStoreSceneResponseCallback : public Callback::Callback<CHIPScenesClusterStoreSceneResponseCallbackType>
{
public:
    CHIPScenesClusterStoreSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterStoreSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::StoreSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterViewSceneResponseCallback : public Callback::Callback<CHIPScenesClusterViewSceneResponseCallbackType>
{
public:
    CHIPScenesClusterViewSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterViewSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::ViewSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTargetNavigatorClusterNavigateTargetResponseCallback
    : public Callback::Callback<CHIPTargetNavigatorClusterNavigateTargetResponseCallbackType>
{
public:
    CHIPTargetNavigatorClusterNavigateTargetResponseCallback(jobject javaCallback);

    ~CHIPTargetNavigatorClusterNavigateTargetResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TargetNavigator::Commands::NavigateTargetResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterBooleanResponseCallback : public Callback::Callback<CHIPTestClusterClusterBooleanResponseCallbackType>
{
public:
    CHIPTestClusterClusterBooleanResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterBooleanResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::TestCluster::Commands::BooleanResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterSimpleStructResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterSimpleStructResponseCallbackType>
{
public:
    CHIPTestClusterClusterSimpleStructResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterSimpleStructResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::SimpleStructResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestAddArgumentsResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestAddArgumentsResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestAddArgumentsResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestAddArgumentsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestAddArgumentsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestEmitTestEventResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestEmitTestEventResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestEmitTestEventResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestEmitTestEventResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestEmitTestEventResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestEnumsResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestEnumsResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestEnumsResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestEnumsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestEnumsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestListInt8UReverseResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestListInt8UReverseResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestListInt8UReverseResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestListInt8UReverseResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestListInt8UReverseResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestNullableOptionalResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestNullableOptionalResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestNullableOptionalResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestNullableOptionalResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestNullableOptionalResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestSpecificResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestSpecificResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestSpecificResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestSpecificResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestSpecificResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPThermostatClusterGetRelayStatusLogResponseCallback
    : public Callback::Callback<CHIPThermostatClusterGetRelayStatusLogResponseCallbackType>
{
public:
    CHIPThermostatClusterGetRelayStatusLogResponseCallback(jobject javaCallback);

    ~CHIPThermostatClusterGetRelayStatusLogResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Thermostat::Commands::GetRelayStatusLogResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPThermostatClusterGetWeeklyScheduleResponseCallback
    : public Callback::Callback<CHIPThermostatClusterGetWeeklyScheduleResponseCallbackType>
{
public:
    CHIPThermostatClusterGetWeeklyScheduleResponseCallback(jobject javaCallback);

    ~CHIPThermostatClusterGetWeeklyScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Thermostat::Commands::GetWeeklyScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

} // namespace chip
