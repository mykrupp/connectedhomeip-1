/*
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

// THIS FILE IS GENERATED BY ZAP

#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/cluster-id.h>
#include <lib/support/Span.h>
#include <protocols/interaction_model/Constants.h>

using namespace chip;

// Cluster Init Functions
void emberAfClusterInitCallback(EndpointId endpoint, ClusterId clusterId)
{
    switch (clusterId)
    {
    case ZCL_ACCOUNT_LOGIN_CLUSTER_ID:
        emberAfAccountLoginClusterInitCallback(endpoint);
        break;
    case ZCL_ADMINISTRATOR_COMMISSIONING_CLUSTER_ID:
        emberAfAdministratorCommissioningClusterInitCallback(endpoint);
        break;
    case ZCL_APPLICATION_BASIC_CLUSTER_ID:
        emberAfApplicationBasicClusterInitCallback(endpoint);
        break;
    case ZCL_APPLICATION_LAUNCHER_CLUSTER_ID:
        emberAfApplicationLauncherClusterInitCallback(endpoint);
        break;
    case ZCL_AUDIO_OUTPUT_CLUSTER_ID:
        emberAfAudioOutputClusterInitCallback(endpoint);
        break;
    case ZCL_BASIC_CLUSTER_ID:
        emberAfBasicClusterInitCallback(endpoint);
        break;
    case ZCL_BINDING_CLUSTER_ID:
        emberAfBindingClusterInitCallback(endpoint);
        break;
    case ZCL_CONTENT_LAUNCH_CLUSTER_ID:
        emberAfContentLauncherClusterInitCallback(endpoint);
        break;
    case ZCL_DESCRIPTOR_CLUSTER_ID:
        emberAfDescriptorClusterInitCallback(endpoint);
        break;
    case ZCL_DIAGNOSTIC_LOGS_CLUSTER_ID:
        emberAfDiagnosticLogsClusterInitCallback(endpoint);
        break;
    case ZCL_ETHERNET_NETWORK_DIAGNOSTICS_CLUSTER_ID:
        emberAfEthernetNetworkDiagnosticsClusterInitCallback(endpoint);
        break;
    case ZCL_FIXED_LABEL_CLUSTER_ID:
        emberAfFixedLabelClusterInitCallback(endpoint);
        break;
    case ZCL_GENERAL_COMMISSIONING_CLUSTER_ID:
        emberAfGeneralCommissioningClusterInitCallback(endpoint);
        break;
    case ZCL_GENERAL_DIAGNOSTICS_CLUSTER_ID:
        emberAfGeneralDiagnosticsClusterInitCallback(endpoint);
        break;
    case ZCL_GROUP_KEY_MANAGEMENT_CLUSTER_ID:
        emberAfGroupKeyManagementClusterInitCallback(endpoint);
        break;
    case ZCL_KEYPAD_INPUT_CLUSTER_ID:
        emberAfKeypadInputClusterInitCallback(endpoint);
        break;
    case ZCL_LEVEL_CONTROL_CLUSTER_ID:
        emberAfLevelControlClusterInitCallback(endpoint);
        break;
    case ZCL_LOW_POWER_CLUSTER_ID:
        emberAfLowPowerClusterInitCallback(endpoint);
        break;
    case ZCL_MEDIA_INPUT_CLUSTER_ID:
        emberAfMediaInputClusterInitCallback(endpoint);
        break;
    case ZCL_MEDIA_PLAYBACK_CLUSTER_ID:
        emberAfMediaPlaybackClusterInitCallback(endpoint);
        break;
    case ZCL_NETWORK_COMMISSIONING_CLUSTER_ID:
        emberAfNetworkCommissioningClusterInitCallback(endpoint);
        break;
    case ZCL_OTA_PROVIDER_CLUSTER_ID:
        emberAfOtaSoftwareUpdateProviderClusterInitCallback(endpoint);
        break;
    case ZCL_ON_OFF_CLUSTER_ID:
        emberAfOnOffClusterInitCallback(endpoint);
        break;
    case ZCL_OPERATIONAL_CREDENTIALS_CLUSTER_ID:
        emberAfOperationalCredentialsClusterInitCallback(endpoint);
        break;
    case ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID:
        emberAfRelativeHumidityMeasurementClusterInitCallback(endpoint);
        break;
    case ZCL_SOFTWARE_DIAGNOSTICS_CLUSTER_ID:
        emberAfSoftwareDiagnosticsClusterInitCallback(endpoint);
        break;
    case ZCL_TV_CHANNEL_CLUSTER_ID:
        emberAfTvChannelClusterInitCallback(endpoint);
        break;
    case ZCL_TARGET_NAVIGATOR_CLUSTER_ID:
        emberAfTargetNavigatorClusterInitCallback(endpoint);
        break;
    case ZCL_THREAD_NETWORK_DIAGNOSTICS_CLUSTER_ID:
        emberAfThreadNetworkDiagnosticsClusterInitCallback(endpoint);
        break;
    case ZCL_USER_LABEL_CLUSTER_ID:
        emberAfUserLabelClusterInitCallback(endpoint);
        break;
    case ZCL_WAKE_ON_LAN_CLUSTER_ID:
        emberAfWakeOnLanClusterInitCallback(endpoint);
        break;
    case ZCL_WIFI_NETWORK_DIAGNOSTICS_CLUSTER_ID:
        emberAfWiFiNetworkDiagnosticsClusterInitCallback(endpoint);
        break;
    default:
        // Unrecognized cluster ID
        break;
    }
}

void __attribute__((weak)) emberAfAccountLoginClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfAdministratorCommissioningClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfApplicationBasicClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfApplicationLauncherClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfAudioOutputClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfBasicClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfBindingClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfContentLauncherClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfDescriptorClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfDiagnosticLogsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfEthernetNetworkDiagnosticsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfFixedLabelClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfGeneralCommissioningClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfGeneralDiagnosticsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfGroupKeyManagementClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfKeypadInputClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfLevelControlClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfLowPowerClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfMediaInputClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfMediaPlaybackClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfNetworkCommissioningClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfOtaSoftwareUpdateProviderClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfOnOffClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfOperationalCredentialsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfRelativeHumidityMeasurementClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfSoftwareDiagnosticsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfTvChannelClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfTargetNavigatorClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfThreadNetworkDiagnosticsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfUserLabelClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfWakeOnLanClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}
void __attribute__((weak)) emberAfWiFiNetworkDiagnosticsClusterInitCallback(EndpointId endpoint)
{
    // To prevent warning
    (void) endpoint;
}

//
// Non-Cluster Related Callbacks
//

void __attribute__((weak)) emberAfAddToCurrentAppTasksCallback(EmberAfApplicationTask tasks) {}

void __attribute__((weak)) emberAfRemoveFromCurrentAppTasksCallback(EmberAfApplicationTask tasks) {}

EmberAfAttributeWritePermission __attribute__((weak))
emberAfAllowNetworkWriteAttributeCallback(EndpointId endpoint, ClusterId clusterId, AttributeId attributeId, uint8_t mask,
                                          uint16_t manufacturerCode, uint8_t * value, uint8_t type)
{
    return EMBER_ZCL_ATTRIBUTE_WRITE_PERMISSION_ALLOW_WRITE_NORMAL; // Default
}

bool __attribute__((weak))
emberAfAttributeReadAccessCallback(EndpointId endpoint, ClusterId clusterId, uint16_t manufacturerCode, AttributeId attributeId)
{
    return true;
}

bool __attribute__((weak))
emberAfAttributeWriteAccessCallback(EndpointId endpoint, ClusterId clusterId, uint16_t manufacturerCode, AttributeId attributeId)
{
    return true;
}

bool __attribute__((weak)) emberAfDefaultResponseCallback(ClusterId clusterId, CommandId commandId, EmberAfStatus status)
{
    return false;
}

bool __attribute__((weak)) emberAfPreMessageSendCallback(EmberAfMessageStruct * messageStruct, EmberStatus * status)
{
    return false;
}

bool __attribute__((weak)) emberAfMessageSentCallback(const MessageSendDestination & destination, EmberApsFrame * apsFrame,
                                                      uint16_t msgLen, uint8_t * message, EmberStatus status)
{
    return false;
}

EmberAfStatus __attribute__((weak))
emberAfExternalAttributeReadCallback(EndpointId endpoint, ClusterId clusterId, EmberAfAttributeMetadata * attributeMetadata,
                                     uint16_t manufacturerCode, uint8_t * buffer, uint16_t maxReadLength)
{
    return EMBER_ZCL_STATUS_FAILURE;
}

EmberAfStatus __attribute__((weak))
emberAfExternalAttributeWriteCallback(EndpointId endpoint, ClusterId clusterId, EmberAfAttributeMetadata * attributeMetadata,
                                      uint16_t manufacturerCode, uint8_t * buffer)
{
    return EMBER_ZCL_STATUS_FAILURE;
}

uint32_t __attribute__((weak)) emberAfGetCurrentTimeCallback()
{
    return 0;
}

bool __attribute__((weak))
emberAfGetEndpointInfoCallback(EndpointId endpoint, uint8_t * returnNetworkIndex, EmberAfEndpointInfoStruct * returnEndpointInfo)
{
    return false;
}

void __attribute__((weak)) emberAfRegistrationAbortCallback() {}

EmberStatus __attribute__((weak))
emberAfInterpanSendMessageCallback(EmberAfInterpanHeader * header, uint16_t messageLength, uint8_t * message)
{
    return EMBER_LIBRARY_NOT_PRESENT;
}

bool __attribute__((weak)) emberAfStartMoveCallback()
{
    return false;
}

chip::Protocols::InteractionModel::Status __attribute__((weak))
MatterPreAttributeChangeCallback(const chip::app::ConcreteAttributePath & attributePath, uint8_t mask, uint8_t type, uint16_t size,
                                 uint8_t * value)
{
    return chip::Protocols::InteractionModel::Status::Success;
}

void __attribute__((weak)) MatterPostAttributeChangeCallback(const chip::app::ConcreteAttributePath & attributePath, uint8_t mask,
                                                             uint8_t type, uint16_t size, uint8_t * value)
{}
