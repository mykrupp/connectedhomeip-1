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

#pragma once

#include <app/clusters/target-navigator-server/target-navigator-server.h>

using chip::CharSpan;
using chip::app::CommandResponseHelper;
using TargetNavigatorDelegate    = chip::app::Clusters::TargetNavigator::Delegate;
using TargetInfoType             = chip::app::Clusters::TargetNavigator::Structs::TargetInfo::Type;
using NavigateTargetResponseType = chip::app::Clusters::TargetNavigator::Commands::NavigateTargetResponse::Type;

class TargetNavigatorManager : public TargetNavigatorDelegate
{
public:
    std::list<chip::app::Clusters::TargetNavigator::Structs::TargetInfo::Type> HandleGetTargetList() override;
    uint8_t HandleGetCurrentTarget() override;
    void HandleNavigateTarget(CommandResponseHelper<NavigateTargetResponseType> & responser, const uint64_t & target,
                              const CharSpan & data) override;
};
