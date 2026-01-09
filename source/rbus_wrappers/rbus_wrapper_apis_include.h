/*
 * If not stated otherwise in this file or this component's Licenses.txt file
 * the following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _COSA_LANMANAGEMENT_DML
#define _COSA_LANMANAGEMENT_DML
#include "cosa_lanmanagement_dml.h"
#endif

#ifndef _COSA_USERS_DML
#define _COSA_USERS_DML
#include "cosa_users_dml.h"
#endif

#ifndef _COSA_DEVICEINFO_DML
#define _COSA_DEVICEINFO_DML
#include "cosa_deviceinfo_dml.h"
#endif

#include "cosa_x_rdkcentral_com_videoservice_dml.h"
#include "cosa_onboardlogging_dml.h"

typedef enum {
    PARAM_BOOL,
    PARAM_INT,
    PARAM_ULONG,
    PARAM_STRING
} ParamType;


typedef ULONG
(*TableGetEntryCount)
    (
        ANSC_HANDLE
    );

typedef ANSC_HANDLE
(*TableGetEntry)
    (
        ANSC_HANDLE                 hInsContext,
        ULONG                       nIndex,
        ULONG*                      pInsNumber
    );

typedef ANSC_HANDLE
(*TableAddEntry)
    (
        ANSC_HANDLE                 hInsContext,
        ULONG*                      pInsNumber
    );

typedef ULONG
(*TableDelEntry)
    (
        ANSC_HANDLE                 hInsContext,
        ANSC_HANDLE                 hInstance
    );

typedef BOOL
(*GetParamBoolValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        BOOL*                       pBool
    );

typedef BOOL
(*GetParamIntValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        int*                        pInt
    );

typedef BOOL
(*GetParamUlongValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        ULONG*                      pUlong
    );

typedef ULONG
(*GetParamStringValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        char*                       pValue,
        ULONG*                      pUlSize
    );

typedef BOOL
(*SetParamBoolValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        BOOL                        bValue
    );

typedef BOOL
(*SetParamIntValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        int                         value
    );

typedef BOOL
(*SetParamUlongValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        ULONG                       uValuepUlong
    );

typedef BOOL
(*SetParamStringValue)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       ParamName,
        char*                       strValue
    );

typedef BOOL
(*Validate)
    (
        ANSC_HANDLE                 hInsContext,
        char*                       pReturnParamName,
        ULONG*                      puLength
    );

typedef ULONG
(*Commit)
    (
        ANSC_HANDLE                 hInsContext
    );

typedef ULONG
(*Rollback)
    (
        ANSC_HANDLE                 hInsContext
    );

typedef BOOL
(*TableIsUpdated)
    (
        ANSC_HANDLE                 hInsContext
    );

typedef ULONG
(*TableIsSynchronize)
    (
        ANSC_HANDLE                 hInsContext
    );

typedef struct
{
    char                      *table_name;
    TableGetEntryCount        cb_TableGetEntryCount;
    TableIsUpdated            cb_TableIsUpdated;
    TableIsSynchronize        cb_TableIsSynchronize;
    union {
        TableGetEntry         cb_TableGetEntry;
        TableAddEntry         cb_TableAddEntry;
        TableDelEntry         cb_TableDelEntry;
    } tableentry_cb;
    union {
        GetParamBoolValue     cb_GetParamBoolValue;
        GetParamIntValue      cb_GetParamIntValue;
        GetParamUlongValue    cb_GetParamUlongValue;
        GetParamStringValue   cb_GetParamStringValue;
    } getparam_cb;
    union {
        SetParamBoolValue     cb_SetParamBoolValue;
        SetParamIntValue      cb_SetParamIntValue;
        SetParamUlongValue    cb_SetParamUlongValue;
        SetParamStringValue   cb_SetParamStringValue;
    } setparam_cb;
    Validate              cb_Validate;
    Commit                cb_Commit;
    Rollback              cb_Rollback;
} CcspRbusHelper_t;

typedef struct
{
    ULONG id;
    char name[64];
}map_t;

rbusError_t dm_init_users_rbus(rbusHandle_t rbusHandle);
rbusError_t dm_de_init_users_rbus(rbusHandle_t rbusHandle);

rbusError_t dm_init_deviceinfo_rbus(rbusHandle_t rbusHandle);
rbusError_t dm_de_init_deviceinfo_rbus(rbusHandle_t rbusHandle);

rbusError_t registerGeneratedDataElements(rbusHandle_t handle);
rbusError_t de_registerGeneratedDataElements(rbusHandle_t handle);

rbusError_t rbus_helper_Table_registerRow(rbusHandle_t handle,CcspRbusHelper_t helperctxt);
rbusError_t rbus_helper_Table_unregisterRow(rbusHandle_t handle,CcspRbusHelper_t helperctxt);
BOOL rbus_helper_GetParamIntValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
BOOL rbus_helper_GetParamBoolValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
BOOL rbus_helper_GetParamUlongValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
BOOL rbus_helper_GetParamStringValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
BOOL rbus_helper_GetParamUlongValue_mapped(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt, map_t mapper_context[], int size);
rbusError_t rbus_helper_SetParamUlongValue_mapped(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt, map_t mapper_context[], int size);
rbusError_t rbus_helper_SetParamIntValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
rbusError_t rbus_helper_SetParamBoolValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
rbusError_t rbus_helper_SetParamUlongValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
rbusError_t rbus_helper_SetParamStringValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);
rbusError_t rbus_helper_GetTableCount(rbusHandle_t handle,rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt);


typedef struct
{
    char                  *table_name;
    TableGetEntryCount    cb_TableGetEntryCount;
    TableGetEntry         cb_TableGetEntry;
    TableAddEntry         cb_TableAddEntry;
    TableDelEntry         cb_TableDelEntry;
    GetParamBoolValue     cb_GetParamBoolValue;
    GetParamIntValue      cb_GetParamIntValue;
    GetParamUlongValue    cb_GetParamUlongValue;
    GetParamStringValue   cb_GetParamStringValue;
    SetParamBoolValue     cb_SetParamBoolValue;
    SetParamIntValue      cb_SetParamIntValue;
    SetParamUlongValue    cb_SetParamUlongValue;
    SetParamStringValue   cb_SetParamStringValue;
    TableIsUpdated        cb_TableIsUpdated;
    TableIsSynchronize    cb_TableIsSynchronize;
    Validate              cb_Validate;
    Commit                cb_Commit;
    Rollback              cb_Rollback;
} funcMap_t;

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
