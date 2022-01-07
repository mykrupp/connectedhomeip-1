/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
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
 * @brief classes relating to Content App of the Video Player.
 */

#pragma once

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/enums.h>
#include <app/clusters/account-login-server/account-login-delegate.h>
#include <app/clusters/application-basic-server/application-basic-delegate.h>
#include <app/clusters/application-launcher-server/application-launcher-delegate.h>
#include <app/clusters/channel-server/channel-delegate.h>
#include <app/clusters/content-launch-server/content-launch-delegate.h>
#include <app/clusters/keypad-input-server/keypad-input-delegate.h>
#include <app/clusters/media-playback-server/media-playback-delegate.h>
#include <app/clusters/target-navigator-server/target-navigator-delegate.h>
#include <app/util/attribute-storage.h>
#include <functional>
#include <list>
#include <stdbool.h>
#include <stdint.h>
#include <string>

namespace chip {
namespace AppPlatform {

class DLL_EXPORT ContentApp
{
public:
    virtual ~ContentApp() = default;

    inline void SetEndpointId(chip::EndpointId id) { mEndpointId = id; };
    inline chip::EndpointId GetEndpointId() { return mEndpointId; };

    virtual chip::app::Clusters::AccountLogin::Delegate * GetAccountLoginDelegate()               = 0;
    virtual chip::app::Clusters::ApplicationBasic::Delegate * GetApplicationBasicDelegate()       = 0;
    virtual chip::app::Clusters::ApplicationLauncher::Delegate * GetApplicationLauncherDelegate() = 0;
    virtual chip::app::Clusters::Channel::Delegate * GetChannelDelegate()                         = 0;
    virtual chip::app::Clusters::ContentLauncher::Delegate * GetContentLauncherDelegate()         = 0;
    virtual chip::app::Clusters::KeypadInput::Delegate * GetKeypadInputDelegate()                 = 0;
    virtual chip::app::Clusters::MediaPlayback::Delegate * GetMediaPlaybackDelegate()             = 0;
    virtual chip::app::Clusters::TargetNavigator::Delegate * GetTargetNavigatorDelegate()         = 0;

    EmberAfStatus HandleReadAttribute(ClusterId clusterId, chip::AttributeId attributeId, uint8_t * buffer, uint16_t maxReadLength);
    EmberAfStatus HandleWriteAttribute(ClusterId clusterId, chip::AttributeId attributeId, uint8_t * buffer);

protected:
    chip::EndpointId mEndpointId = 0;
};

} // namespace AppPlatform
} // namespace chip
