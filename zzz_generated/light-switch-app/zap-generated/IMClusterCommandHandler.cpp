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

#include <cinttypes>
#include <cstdint>

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app-common/zap-generated/ids/Commands.h>
#include <app/CommandHandler.h>
#include <app/InteractionModelEngine.h>
#include <app/util/util.h>
#include <lib/core/CHIPSafeCasts.h>
#include <lib/support/TypeTraits.h>

// Currently we need some work to keep compatible with ember lib.
#include <app/util/ember-compatibility-functions.h>

namespace chip {
namespace app {

// Cluster specific command parsing

namespace Clusters {

namespace AdministratorCommissioning {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::OpenBasicCommissioningWindow::Id: {
            Commands::OpenBasicCommissioningWindow::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfAdministratorCommissioningClusterOpenBasicCommissioningWindowCallback(
                    apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::OpenCommissioningWindow::Id: {
            Commands::OpenCommissioningWindow::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfAdministratorCommissioningClusterOpenCommissioningWindowCallback(apCommandObj, aCommandPath,
                                                                                                     commandData);
            }
            break;
        }
        case Commands::RevokeCommissioning::Id: {
            Commands::RevokeCommissioning::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfAdministratorCommissioningClusterRevokeCommissioningCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace AdministratorCommissioning

namespace DiagnosticLogs {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::RetrieveLogsRequest::Id: {
            Commands::RetrieveLogsRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfDiagnosticLogsClusterRetrieveLogsRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace DiagnosticLogs

namespace EthernetNetworkDiagnostics {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ResetCounts::Id: {
            Commands::ResetCounts::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfEthernetNetworkDiagnosticsClusterResetCountsCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace EthernetNetworkDiagnostics

namespace GeneralCommissioning {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ArmFailSafe::Id: {
            Commands::ArmFailSafe::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGeneralCommissioningClusterArmFailSafeCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::CommissioningComplete::Id: {
            Commands::CommissioningComplete::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfGeneralCommissioningClusterCommissioningCompleteCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::SetRegulatoryConfig::Id: {
            Commands::SetRegulatoryConfig::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGeneralCommissioningClusterSetRegulatoryConfigCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace GeneralCommissioning

namespace GroupKeyManagement {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::KeySetRead::Id: {
            Commands::KeySetRead::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupKeyManagementClusterKeySetReadCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::KeySetReadAllIndices::Id: {
            Commands::KeySetReadAllIndices::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupKeyManagementClusterKeySetReadAllIndicesCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::KeySetRemove::Id: {
            Commands::KeySetRemove::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupKeyManagementClusterKeySetRemoveCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::KeySetWrite::Id: {
            Commands::KeySetWrite::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupKeyManagementClusterKeySetWriteCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace GroupKeyManagement

namespace Groups {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddGroup::Id: {
            Commands::AddGroup::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterAddGroupCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AddGroupIfIdentifying::Id: {
            Commands::AddGroupIfIdentifying::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterAddGroupIfIdentifyingCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::GetGroupMembership::Id: {
            Commands::GetGroupMembership::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterGetGroupMembershipCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveAllGroups::Id: {
            Commands::RemoveAllGroups::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterRemoveAllGroupsCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveGroup::Id: {
            Commands::RemoveGroup::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterRemoveGroupCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ViewGroup::Id: {
            Commands::ViewGroup::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGroupsClusterViewGroupCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace Groups

namespace Identify {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::Identify::Id: {
            Commands::Identify::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfIdentifyClusterIdentifyCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::IdentifyQuery::Id: {
            Commands::IdentifyQuery::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfIdentifyClusterIdentifyQueryCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::TriggerEffect::Id: {
            Commands::TriggerEffect::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfIdentifyClusterTriggerEffectCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace Identify

namespace NetworkCommissioning {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddOrUpdateThreadNetwork::Id: {
            Commands::AddOrUpdateThreadNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfNetworkCommissioningClusterAddOrUpdateThreadNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AddOrUpdateWiFiNetwork::Id: {
            Commands::AddOrUpdateWiFiNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfNetworkCommissioningClusterAddOrUpdateWiFiNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ConnectNetwork::Id: {
            Commands::ConnectNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterConnectNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveNetwork::Id: {
            Commands::RemoveNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterRemoveNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ReorderNetwork::Id: {
            Commands::ReorderNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterReorderNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ScanNetworks::Id: {
            Commands::ScanNetworks::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterScanNetworksCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace NetworkCommissioning

namespace OtaSoftwareUpdateRequestor {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AnnounceOtaProvider::Id: {
            Commands::AnnounceOtaProvider::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOtaSoftwareUpdateRequestorClusterAnnounceOtaProviderCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OtaSoftwareUpdateRequestor

namespace OperationalCredentials {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddNOC::Id: {
            Commands::AddNOC::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddNOCCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AddTrustedRootCertificate::Id: {
            Commands::AddTrustedRootCertificate::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterAddTrustedRootCertificateCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AttestationRequest::Id: {
            Commands::AttestationRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterAttestationRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::CSRRequest::Id: {
            Commands::CSRRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterCSRRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::CertificateChainRequest::Id: {
            Commands::CertificateChainRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterCertificateChainRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveFabric::Id: {
            Commands::RemoveFabric::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveFabricCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveTrustedRootCertificate::Id: {
            Commands::RemoveTrustedRootCertificate::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveTrustedRootCertificateCallback(apCommandObj, aCommandPath,
                                                                                                      commandData);
            }
            break;
        }
        case Commands::UpdateFabricLabel::Id: {
            Commands::UpdateFabricLabel::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateFabricLabelCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::UpdateNOC::Id: {
            Commands::UpdateNOC::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateNOCCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OperationalCredentials

namespace SoftwareDiagnostics {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ResetWatermarks::Id: {
            Commands::ResetWatermarks::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfSoftwareDiagnosticsClusterResetWatermarksCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace SoftwareDiagnostics

namespace ThreadNetworkDiagnostics {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ResetCounts::Id: {
            Commands::ResetCounts::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfThreadNetworkDiagnosticsClusterResetCountsCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace ThreadNetworkDiagnostics

namespace WiFiNetworkDiagnostics {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ResetCounts::Id: {
            Commands::ResetCounts::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfWiFiNetworkDiagnosticsClusterResetCountsCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace WiFiNetworkDiagnostics

} // namespace Clusters

void DispatchSingleClusterCommand(const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aReader, CommandHandler * apCommandObj)
{
    Compatibility::SetupEmberAfCommandHandler(apCommandObj, aCommandPath);

    switch (aCommandPath.mClusterId)
    {
    case Clusters::AdministratorCommissioning::Id:
        Clusters::AdministratorCommissioning::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::DiagnosticLogs::Id:
        Clusters::DiagnosticLogs::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::EthernetNetworkDiagnostics::Id:
        Clusters::EthernetNetworkDiagnostics::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::GeneralCommissioning::Id:
        Clusters::GeneralCommissioning::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::GroupKeyManagement::Id:
        Clusters::GroupKeyManagement::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::Groups::Id:
        Clusters::Groups::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::Identify::Id:
        Clusters::Identify::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::NetworkCommissioning::Id:
        Clusters::NetworkCommissioning::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::OtaSoftwareUpdateRequestor::Id:
        Clusters::OtaSoftwareUpdateRequestor::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::OperationalCredentials::Id:
        Clusters::OperationalCredentials::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::SoftwareDiagnostics::Id:
        Clusters::SoftwareDiagnostics::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::ThreadNetworkDiagnostics::Id:
        Clusters::ThreadNetworkDiagnostics::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::WiFiNetworkDiagnostics::Id:
        Clusters::WiFiNetworkDiagnostics::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    default:
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandPath.mClusterId));
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCluster);
        break;
    }

    Compatibility::ResetEmberAfObjects();
}

} // namespace app
} // namespace chip
