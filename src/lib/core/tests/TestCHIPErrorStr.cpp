/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
 *    Copyright (c) 2016-2017 Nest Labs, Inc.
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
 *    @file
 *      This file implements a process to effect a functional test for
 *      the CHIP Core library error string support interfaces.
 *
 */

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#include <inttypes.h>
#include <stdint.h>
#include <string.h>

#include <lib/core/CHIPError.h>
#include <lib/support/ErrorStr.h>
#include <lib/support/UnitTestRegistration.h>

#include <nlunit-test.h>

using namespace chip;

// Test input data.

// clang-format off
static const CHIP_ERROR kTestElements[] =
{
    CHIP_ERROR_TOO_MANY_CONNECTIONS,
    CHIP_ERROR_SENDING_BLOCKED,
    CHIP_ERROR_CONNECTION_ABORTED,
    CHIP_ERROR_INCORRECT_STATE,
    CHIP_ERROR_MESSAGE_TOO_LONG,
    CHIP_ERROR_UNSUPPORTED_EXCHANGE_VERSION,
    CHIP_ERROR_TOO_MANY_UNSOLICITED_MESSAGE_HANDLERS,
    CHIP_ERROR_NO_UNSOLICITED_MESSAGE_HANDLER,
    CHIP_ERROR_NO_CONNECTION_HANDLER,
    CHIP_ERROR_TOO_MANY_PEER_NODES,
    CHIP_ERROR_NO_MEMORY,
    CHIP_ERROR_NO_MESSAGE_HANDLER,
    CHIP_ERROR_MESSAGE_INCOMPLETE,
    CHIP_ERROR_DATA_NOT_ALIGNED,
    CHIP_ERROR_UNKNOWN_KEY_TYPE,
    CHIP_ERROR_KEY_NOT_FOUND,
    CHIP_ERROR_WRONG_ENCRYPTION_TYPE,
    CHIP_ERROR_TOO_MANY_KEYS,
    CHIP_ERROR_INTEGRITY_CHECK_FAILED,
    CHIP_ERROR_INVALID_SIGNATURE,
    CHIP_ERROR_UNSUPPORTED_MESSAGE_VERSION,
    CHIP_ERROR_UNSUPPORTED_ENCRYPTION_TYPE,
    CHIP_ERROR_UNSUPPORTED_SIGNATURE_TYPE,
    CHIP_ERROR_INVALID_MESSAGE_LENGTH,
    CHIP_ERROR_BUFFER_TOO_SMALL,
    CHIP_ERROR_DUPLICATE_KEY_ID,
    CHIP_ERROR_WRONG_KEY_TYPE,
    CHIP_ERROR_WELL_UNINITIALIZED,
    CHIP_ERROR_WELL_EMPTY,
    CHIP_ERROR_INVALID_STRING_LENGTH,
    CHIP_ERROR_INVALID_LIST_LENGTH,
    CHIP_ERROR_INVALID_INTEGRITY_TYPE,
    CHIP_END_OF_TLV,
    CHIP_ERROR_TLV_UNDERRUN,
    CHIP_ERROR_INVALID_TLV_ELEMENT,
    CHIP_ERROR_INVALID_TLV_TAG,
    CHIP_ERROR_UNKNOWN_IMPLICIT_TLV_TAG,
    CHIP_ERROR_WRONG_TLV_TYPE,
    CHIP_ERROR_TLV_CONTAINER_OPEN,
    CHIP_ERROR_INVALID_TRANSFER_MODE,
    CHIP_ERROR_INVALID_PROFILE_ID,
    CHIP_ERROR_INVALID_MESSAGE_TYPE,
    CHIP_ERROR_UNEXPECTED_TLV_ELEMENT,
    CHIP_ERROR_STATUS_REPORT_RECEIVED,
    CHIP_ERROR_NOT_IMPLEMENTED,
    CHIP_ERROR_INVALID_ADDRESS,
    CHIP_ERROR_INVALID_ARGUMENT,
    CHIP_ERROR_INVALID_PATH_LIST,
    CHIP_ERROR_INVALID_DATA_LIST,
    CHIP_ERROR_TIMEOUT,
    CHIP_ERROR_INVALID_DEVICE_DESCRIPTOR,
    CHIP_ERROR_UNSUPPORTED_DEVICE_DESCRIPTOR_VERSION,
    CHIP_END_OF_INPUT,
    CHIP_ERROR_RATE_LIMIT_EXCEEDED,
    CHIP_ERROR_SECURITY_MANAGER_BUSY,
    CHIP_ERROR_INVALID_PASE_PARAMETER,
    CHIP_ERROR_PASE_SUPPORTS_ONLY_CONFIG1,
    CHIP_ERROR_KEY_CONFIRMATION_FAILED,
    CHIP_ERROR_INVALID_USE_OF_SESSION_KEY,
    CHIP_ERROR_CONNECTION_CLOSED_UNEXPECTEDLY,
    CHIP_ERROR_MISSING_TLV_ELEMENT,
    CHIP_ERROR_RANDOM_DATA_UNAVAILABLE,
    CHIP_ERROR_UNSUPPORTED_HOST_PORT_ELEMENT,
    CHIP_ERROR_INVALID_HOST_SUFFIX_INDEX,
    CHIP_ERROR_HOST_PORT_LIST_EMPTY,
    CHIP_ERROR_UNSUPPORTED_AUTH_MODE,
    CHIP_ERROR_INVALID_SERVICE_EP,
    CHIP_ERROR_INVALID_DIRECTORY_ENTRY_TYPE,
    CHIP_ERROR_FORCED_RESET,
    CHIP_ERROR_NO_ENDPOINT,
    CHIP_ERROR_INVALID_DESTINATION_NODE_ID,
    CHIP_ERROR_NOT_CONNECTED,
    CHIP_ERROR_NO_SW_UPDATE_AVAILABLE,
    CHIP_ERROR_CA_CERT_NOT_FOUND,
    CHIP_ERROR_CERT_PATH_LEN_CONSTRAINT_EXCEEDED,
    CHIP_ERROR_CERT_PATH_TOO_LONG,
    CHIP_ERROR_CERT_USAGE_NOT_ALLOWED,
    CHIP_ERROR_CERT_EXPIRED,
    CHIP_ERROR_CERT_NOT_VALID_YET,
    CHIP_ERROR_UNSUPPORTED_CERT_FORMAT,
    CHIP_ERROR_UNSUPPORTED_ELLIPTIC_CURVE,
    CHIP_CERT_NOT_USED,
    CHIP_ERROR_CERT_NOT_FOUND,
    CHIP_ERROR_INVALID_CASE_PARAMETER,
    CHIP_ERROR_UNSUPPORTED_CASE_CONFIGURATION,
    CHIP_ERROR_CERT_LOAD_FAILED,
    CHIP_ERROR_CERT_NOT_TRUSTED,
    CHIP_ERROR_INVALID_ACCESS_TOKEN,
    CHIP_ERROR_WRONG_CERT_DN,
    CHIP_ERROR_INVALID_PROVISIONING_BUNDLE,
    CHIP_ERROR_PROVISIONING_BUNDLE_DECRYPTION_ERROR,
    CHIP_ERROR_WRONG_NODE_ID,
    CHIP_ERROR_CONN_ACCEPTED_ON_WRONG_PORT,
    CHIP_ERROR_CALLBACK_REPLACED,
    CHIP_ERROR_NO_CASE_AUTH_DELEGATE,
    CHIP_ERROR_DEVICE_LOCATE_TIMEOUT,
    CHIP_ERROR_DEVICE_CONNECT_TIMEOUT,
    CHIP_ERROR_DEVICE_AUTH_TIMEOUT,
    CHIP_ERROR_MESSAGE_NOT_ACKNOWLEDGED,
    CHIP_ERROR_RETRANS_TABLE_FULL,
    CHIP_ERROR_INVALID_ACK_MESSAGE_COUNTER,
    CHIP_ERROR_SEND_THROTTLED,
    CHIP_ERROR_WRONG_MSG_VERSION_FOR_EXCHANGE,
    CHIP_ERROR_TRANSACTION_CANCELED,
    CHIP_ERROR_LISTENER_ALREADY_STARTED,
    CHIP_ERROR_LISTENER_ALREADY_STOPPED,
    CHIP_ERROR_UNKNOWN_TOPIC,
    CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE,
    CHIP_ERROR_PASE_RECONFIGURE_REQUIRED,
    CHIP_ERROR_INVALID_PASE_CONFIGURATION,
    CHIP_ERROR_NO_COMMON_PASE_CONFIGURATIONS,
    CHIP_ERROR_UNSOLICITED_MSG_NO_ORIGINATOR,
    CHIP_ERROR_INVALID_FABRIC_ID,
    CHIP_ERROR_DRBG_ENTROPY_SOURCE_FAILED,
    CHIP_ERROR_TLV_TAG_NOT_FOUND,
    CHIP_ERROR_INVALID_TOKENPAIRINGBUNDLE,
    CHIP_ERROR_UNSUPPORTED_TOKENPAIRINGBUNDLE_VERSION,
    CHIP_ERROR_NO_TAKE_AUTH_DELEGATE,
    CHIP_ERROR_TAKE_RECONFIGURE_REQUIRED,
    CHIP_ERROR_TAKE_REAUTH_POSSIBLE,
    CHIP_ERROR_INVALID_TAKE_PARAMETER,
    CHIP_ERROR_UNSUPPORTED_TAKE_CONFIGURATION,
    CHIP_ERROR_TAKE_TOKEN_IDENTIFICATION_FAILED,
    CHIP_ERROR_KEY_NOT_FOUND_FROM_PEER,
    CHIP_ERROR_WRONG_ENCRYPTION_TYPE_FROM_PEER,
    CHIP_ERROR_UNKNOWN_KEY_TYPE_FROM_PEER,
    CHIP_ERROR_INVALID_USE_OF_SESSION_KEY_FROM_PEER,
    CHIP_ERROR_UNSUPPORTED_ENCRYPTION_TYPE_FROM_PEER,
    CHIP_ERROR_INTERNAL_KEY_ERROR_FROM_PEER,
    CHIP_ERROR_INVALID_KEY_ID,
    CHIP_ERROR_INVALID_TIME,
    CHIP_ERROR_LOCKING_FAILURE,
    CHIP_ERROR_UNSUPPORTED_PASSCODE_CONFIG,
    CHIP_ERROR_PASSCODE_AUTHENTICATION_FAILED,
    CHIP_ERROR_PASSCODE_FINGERPRINT_FAILED,
    CHIP_ERROR_SERIALIZATION_ELEMENT_NULL,
    CHIP_ERROR_WRONG_CERT_SIGNATURE_ALGORITHM,
    CHIP_ERROR_WRONG_CHIP_SIGNATURE_ALGORITHM,
    CHIP_ERROR_SCHEMA_MISMATCH,
    CHIP_ERROR_INVALID_INTEGER_VALUE,
    CHIP_ERROR_CASE_RECONFIG_REQUIRED,
    CHIP_ERROR_TOO_MANY_CASE_RECONFIGURATIONS,
    CHIP_ERROR_BAD_REQUEST,
    CHIP_ERROR_INVALID_MESSAGE_FLAG,
    CHIP_ERROR_KEY_EXPORT_RECONFIGURE_REQUIRED,
    CHIP_ERROR_INVALID_KEY_EXPORT_CONFIGURATION,
    CHIP_ERROR_NO_COMMON_KEY_EXPORT_CONFIGURATIONS,
    CHIP_ERROR_NO_KEY_EXPORT_DELEGATE,
    CHIP_ERROR_UNAUTHORIZED_KEY_EXPORT_REQUEST,
    CHIP_ERROR_UNAUTHORIZED_KEY_EXPORT_RESPONSE,
    CHIP_ERROR_EXPORTED_KEY_AUTHENTICATION_FAILED,
    CHIP_ERROR_TOO_MANY_SHARED_SESSION_END_NODES,
    CHIP_ERROR_IM_MALFORMED_ATTRIBUTE_DATA_ELEMENT,
    CHIP_ERROR_WRONG_CERT_TYPE,
    CHIP_ERROR_DEFAULT_EVENT_HANDLER_NOT_CALLED,
    CHIP_ERROR_PERSISTED_STORAGE_FAILED,
    CHIP_ERROR_PERSISTED_STORAGE_VALUE_NOT_FOUND,
    CHIP_ERROR_PROFILE_STRING_CONTEXT_ALREADY_REGISTERED,
    CHIP_ERROR_PROFILE_STRING_CONTEXT_NOT_REGISTERED,
    CHIP_ERROR_INCOMPATIBLE_SCHEMA_VERSION,
    CHIP_ERROR_ACCESS_DENIED,
    CHIP_ERROR_UNKNOWN_RESOURCE_ID,
    CHIP_ERROR_VERSION_MISMATCH,
    CHIP_ERROR_UNSUPPORTED_THREAD_NETWORK_CREATE,
    CHIP_ERROR_INCONSISTENT_CONDITIONALITY,
    CHIP_ERROR_LOCAL_DATA_INCONSISTENT,
    CHIP_EVENT_ID_FOUND,
    CHIP_ERROR_IM_MALFORMED_ATTRIBUTE_PATH,
    CHIP_ERROR_IM_MALFORMED_EVENT_PATH,
    CHIP_ERROR_IM_MALFORMED_COMMAND_PATH,
    CHIP_ERROR_IM_MALFORMED_ATTRIBUTE_STATUS_ELEMENT,
    CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT,
    CHIP_ERROR_IM_MALFORMED_EVENT_DATA_ELEMENT,
    CHIP_ERROR_IM_MALFORMED_STATUS_CODE,
    CHIP_ERROR_PEER_NODE_NOT_FOUND,
    CHIP_ERROR_IM_STATUS_CODE_RECEIVED,
};
// clang-format on

static void CheckCoreErrorStr(nlTestSuite * inSuite, void * inContext)
{
    // Register the layer error formatter

    RegisterCHIPLayerErrorFormatter();

    // For each defined error...
    for (const auto & err : kTestElements)
    {
        const char * errStr = ErrorStr(err);
        char expectedText[9];

        // Assert that the error string contains the error number in hex.
        snprintf(expectedText, sizeof(expectedText), "%08" PRIX32, static_cast<uint32_t>(err.AsInteger()));
        NL_TEST_ASSERT(inSuite, (strstr(errStr, expectedText) != nullptr));

#if !CHIP_CONFIG_SHORT_ERROR_STR
        // Assert that the error string contains a description, which is signaled
        // by a presence of a colon proceeding the description.
        NL_TEST_ASSERT(inSuite, (strchr(errStr, ':') != nullptr));
#endif // !CHIP_CONFIG_SHORT_ERROR_STR
    }
}

/**
 *   Test Suite. It lists all the test functions.
 */

// clang-format off
static const nlTest sTests[] =
{
    NL_TEST_DEF("CoreErrorStr", CheckCoreErrorStr),

    NL_TEST_SENTINEL()
};
// clang-format on

int TestCHIPErrorStr(void)
{
    // clang-format off
    nlTestSuite theSuite =
	{
        "Core-Error-Strings",
        &sTests[0],
        nullptr,
        nullptr
    };
    // clang-format on

    // Run test suit againt one context.
    nlTestRunner(&theSuite, nullptr);

    return nlTestRunnerStats(&theSuite);
}

CHIP_REGISTER_TEST_SUITE(TestCHIPErrorStr)
