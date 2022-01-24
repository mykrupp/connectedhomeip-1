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

#pragma once

#include <app/clusters/account-login-server/account-login-server.h>

#include <app/util/af-types.h>

using chip::CharSpan;
using chip::Platform::CopyString;
using AccountLogin        = chip::app::Clusters::AccountLogin::Delegate;
using GetSetupPINResponse = chip::app::Clusters::AccountLogin::Commands::GetSetupPINResponse::Type;

class AccountLoginManager : public AccountLogin
{
public:
    AccountLoginManager() : AccountLoginManager("tempPin123"){};
    AccountLoginManager(const char * setupPIN);

    inline void SetSetupPIN(char * setupPIN) override { CopyString(mSetupPIN, sizeof(mSetupPIN), setupPIN); };

    bool HandleLogin(const CharSpan & tempAccountIdentifierString, const CharSpan & setupPinString) override;
    bool HandleLogout() override;
    GetSetupPINResponse HandleGetSetupPin(const CharSpan & tempAccountIdentifierString) override;

protected:
    static const int kSetupPINSize = 12;
    char mSetupPIN[kSetupPINSize];
};
