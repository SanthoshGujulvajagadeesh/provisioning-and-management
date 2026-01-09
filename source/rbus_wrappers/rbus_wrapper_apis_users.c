/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
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

/*
 * 
 * code generated with: python rbus_code_generator_ccsp_style_Duplicate.py TR181-USGv2_with_distro.XML Users
 */

#include <rbus.h>
#include <rbus_context_helpers.h>
#include <rtMemory.h>
#include <rtLog.h>
#include <stdlib.h>
#include <string.h>
#include "dlfcn.h"
#include <rbus_wrapper_apis_include.h>
#include <rbus_wrapper_common_apis.h>


rbusError_t dm_init_users_rbus(rbusHandle_t rbusHandle)
{
    rbusError_t rc;
    rc = registerGeneratedDataElements(rbusHandle);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rbus_close(rbusHandle);
        return rc;
    }
    return RBUS_ERROR_SUCCESS;
}

rbusError_t dm_de_init_users_rbus(rbusHandle_t rbusHandle)
{
    rbusError_t rc;
    rc = de_registerGeneratedDataElements(rbusHandle);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rbus_close(rbusHandle);
        return rc;
    }
    return RBUS_ERROR_SUCCESS;
}

static rbusError_t User_AddEntry_rbus(rbusHandle_t handle, char const* tableName, char const* aliasName, uint32_t* instNum)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(tableName);
    UNREFERENCED_PARAMETER(aliasName);
    ULONG inst_Num = *instNum;
    void *hInsContext = NULL;

    void* rowContext = User_AddEntry(hInsContext, &inst_Num);
    if(!rowContext)
    {
        rtLog_Error("User_AddEntry returned null row context");
        return RBUS_ERROR_BUS_ERROR;
    }

    return RBUS_ERROR_SUCCESS;
}

static rbusError_t User_DelEntry_rbus(rbusHandle_t handle, char const* rowName)
{
    UNREFERENCED_PARAMETER(handle);
    ULONG instNum = 0;
    void *hInsContext = NULL;

    int table_count = User_GetEntryCount(hInsContext);
    if (!table_count)
       return RBUS_ERROR_INVALID_INPUT;

    int ret = sscanf(rowName, "Device.Users.User.%ld", &instNum);
    if (ret != 1)
    {
       rtLog_Error("unable to fetch row instance");
       return RBUS_ERROR_INVALID_INPUT;
    }

    /* inst number need not to be in serial*/
    void *row_handle = NULL;
    ULONG temp_instnum = 0;
    for (int i=1; i <= table_count;i++)
    {
        row_handle = User_GetEntry(hInsContext,i,&temp_instnum);
        if (row_handle && (temp_instnum == instNum))
                break;
    }

    if(!row_handle)
    {
        rtLog_Error("User_GetEntry returned null row context");
        return RBUS_ERROR_INVALID_INPUT;
    }

    int rc = User_DelEntry(hInsContext, row_handle);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rtLog_Error("User_DelEntry failed");
        return RBUS_ERROR_BUS_ERROR;
    }
    return RBUS_ERROR_SUCCESS;
}

funcMap_t func_map[] = {
    { "Device.Users.User.",User_GetEntryCount,User_GetEntry,User_AddEntry,User_DelEntry,User_GetParamBoolValue,User_GetParamIntValue,User_GetParamUlongValue,
     User_GetParamStringValue,User_SetParamBoolValue,User_SetParamIntValue,User_SetParamUlongValue,User_SetParamStringValue,NULL,NULL,User_Validate,User_Commit,User_Rollback }
};


static rbusError_t User_GetParamUlongValue_rbus_mapped(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    map_t X_CISCO_COM_AccessPermission_mapper[] = {
     { 1, "Admin" }, { 2, "HomeUser" }, { 3, "Restricted" }, { 4, "Denied" }
    };
    int size = sizeof(X_CISCO_COM_AccessPermission_mapper) / sizeof(X_CISCO_COM_AccessPermission_mapper[0]);

    CcspRbusHelper_t helperctxt = {"Device.Users.User.", User_GetEntryCount,NULL,NULL,
                                    .tableentry_cb.cb_TableGetEntry = User_GetEntry,
                                    .getparam_cb.cb_GetParamUlongValue = User_GetParamUlongValue,
                                    .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue_mapped(handle, opts, property, helperctxt, X_CISCO_COM_AccessPermission_mapper, size);
}

rbusError_t do_User_Validate_User_Commit_User_Rollback(void* context)
{
    char ParamName[128] ={0};
    ULONG ParamLength = 0;
    if(User_Validate(context,ParamName,&ParamLength) == TRUE)
    {
        if(User_Commit(context) == 0)
            return RBUS_ERROR_SUCCESS;
        else
            return RBUS_ERROR_BUS_ERROR;
    }
    else
    {
        if(User_Rollback(context) == 0)
            return RBUS_ERROR_INVALID_INPUT;
        else
            return RBUS_ERROR_BUS_ERROR;  
    }
}

static rbusError_t User_SetParamUlongValue_rbus_mapped(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    map_t X_CISCO_COM_AccessPermission_mapper[] = {
     { 1, "Admin" }, { 2, "HomeUser" }, { 3, "Restricted" }, { 4, "Denied" }
    };
    int size = sizeof(X_CISCO_COM_AccessPermission_mapper) / sizeof(X_CISCO_COM_AccessPermission_mapper[0]);

    CcspRbusHelper_t helperctxt = {"Device.Users.User.", User_GetEntryCount,NULL,NULL,
                                    .tableentry_cb.cb_TableGetEntry = User_GetEntry,
                                    .getparam_cb.cb_GetParamUlongValue = NULL,
                                    .setparam_cb.cb_SetParamUlongValue = User_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue_mapped(handle, opts, property, helperctxt, X_CISCO_COM_AccessPermission_mapper, size);
}

static rbusError_t TableGetParamValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts, ParamType paramType)
{
    char const* name = rbusProperty_GetName(property);
    if (name && strlen(name))
    {
        for (int i=0;i < (int)ARRAY_SIZE(func_map);i++)
        {
            if (!strncmp(name,func_map[i].table_name,strlen(func_map[i].table_name)))
            {
                CcspRbusHelper_t helperctxt = {
                    .table_name = NULL,
                    .cb_TableGetEntryCount = NULL,
                    .cb_TableIsUpdated = NULL,
                    .cb_TableIsSynchronize = NULL,
                    .tableentry_cb = { .cb_TableGetEntry = NULL },
                    .getparam_cb = { .cb_GetParamBoolValue = NULL },
                    .setparam_cb = { .cb_SetParamBoolValue = NULL },
                    .cb_Validate = NULL,
                    .cb_Commit = NULL,
                    .cb_Rollback = NULL
                };
            switch (paramType)
            {
                case PARAM_BOOL:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.getparam_cb.cb_GetParamBoolValue = func_map[i].cb_GetParamBoolValue;
                    return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_INT:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.getparam_cb.cb_GetParamIntValue = func_map[i].cb_GetParamIntValue;
                    return rbus_helper_GetParamIntValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_ULONG:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.getparam_cb.cb_GetParamUlongValue = func_map[i].cb_GetParamUlongValue;
                    return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_STRING:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.getparam_cb.cb_GetParamStringValue = func_map[i].cb_GetParamStringValue;
                    return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
                    break;
                default:
                    CcspTraceError(("Unsupported parameter type"));
                    return RBUS_ERROR_INVALID_INPUT;
            }
            }
            else{
            return RBUS_ERROR_INVALID_INPUT;
            }
        }
        return RBUS_ERROR_INVALID_INPUT;
    }
    else{
        return RBUS_ERROR_INVALID_INPUT;
    }
}

static rbusError_t TableSetParamValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts, ParamType paramType)
{
    char const* name = rbusProperty_GetName(property);
    if (name && strlen(name))
    {
        for (int i=0;i < (int)ARRAY_SIZE(func_map);i++)
        {
            if (!strncmp(name,func_map[i].table_name,strlen(func_map[i].table_name)))
            {
                CcspRbusHelper_t helperctxt = {
                    .table_name = NULL,
                    .cb_TableGetEntryCount = NULL,
                    .cb_TableIsUpdated = NULL,
                    .cb_TableIsSynchronize = NULL,
                    .tableentry_cb = { .cb_TableGetEntry = NULL },
                    .getparam_cb = { .cb_GetParamBoolValue = NULL },
                    .setparam_cb = { .cb_SetParamBoolValue = NULL },
                    .cb_Validate = NULL,
                    .cb_Commit = NULL,
                    .cb_Rollback = NULL
                };
            switch (paramType)
            {
                case PARAM_BOOL:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.setparam_cb.cb_SetParamBoolValue = func_map[i].cb_SetParamBoolValue;
                    return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_INT:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.setparam_cb.cb_SetParamIntValue = func_map[i].cb_SetParamIntValue;
                    return rbus_helper_SetParamIntValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_ULONG:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.setparam_cb.cb_SetParamUlongValue = func_map[i].cb_SetParamUlongValue;
                    return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
                    break;
                case PARAM_STRING:
                    helperctxt.table_name = func_map[i].table_name;
                    helperctxt.cb_TableGetEntryCount = func_map[i].cb_TableGetEntryCount;
                    helperctxt.tableentry_cb.cb_TableGetEntry = func_map[i].cb_TableGetEntry;
                    helperctxt.setparam_cb.cb_SetParamStringValue = func_map[i].cb_SetParamStringValue;
                    return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
                    break;
                default:
                    CcspTraceError(("Unsupported parameter type"));
                    return RBUS_ERROR_INVALID_INPUT;
            }
            }
            else{
            return RBUS_ERROR_INVALID_INPUT;
            }
        }
        return RBUS_ERROR_INVALID_INPUT;
    }
    else{
        return RBUS_ERROR_INVALID_INPUT;
    }
}

static rbusError_t Generic_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_BOOL;
    return TableGetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_GetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_INT;
    return TableGetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_ULONG;
    return TableGetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_STRING;
    return TableGetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_BOOL;
    return TableSetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_SetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_INT;
    return TableSetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_ULONG;
    return TableSetParamValue_rbus(handle, property, opts, paramType);
}

static rbusError_t Generic_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    ParamType paramType = PARAM_STRING;
    return TableSetParamValue_rbus(handle, property, opts, paramType);
}

static rbusDataElement_t dataElements[15] = {
        {"Device.Users.User.{i}.", RBUS_ELEMENT_TYPE_TABLE, {NULL, NULL, User_AddEntry_rbus, User_DelEntry_rbus, NULL, NULL}},
        {"Device.Users.User.{i}.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamBoolValue_rbus, Generic_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.RemoteAccessCapable", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamBoolValue_rbus, Generic_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_RDKCENTRAL-COM_PasswordReset", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamBoolValue_rbus, Generic_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_RDKCENTRAL-COM_RemainingAttempts", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamIntValue_rbus, Generic_SetParamIntValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_RDKCENTRAL-COM_LoginCounts", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamIntValue_rbus, Generic_SetParamIntValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_RDKCENTRAL-COM_LockOutRemainingTime", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamIntValue_rbus, Generic_SetParamIntValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_CISCO_COM_AccessPermission", RBUS_ELEMENT_TYPE_PROPERTY, {User_GetParamUlongValue_rbus_mapped, User_SetParamUlongValue_rbus_mapped, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.NumOfFailedAttempts", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamUlongValue_rbus, Generic_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.NumOfRestoreFailedAttempt", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamUlongValue_rbus, Generic_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.Username", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamStringValue_rbus, Generic_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.Password", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamStringValue_rbus, Generic_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.Language", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamStringValue_rbus, Generic_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_CISCO_COM_Password", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamStringValue_rbus, Generic_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.Users.User.{i}.X_RDKCENTRAL-COM_ComparePassword", RBUS_ELEMENT_TYPE_PROPERTY, {Generic_GetParamStringValue_rbus, Generic_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}}
};

rbusError_t registerGeneratedDataElements(rbusHandle_t handle)
{
    rbusError_t rc;
    CcspTraceInfo(("Calling regsitering data elements\n"));
    rc = rbus_regDataElements(handle, 15, dataElements);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rtLog_Error("rbus_regDataElements failed");
    }
    CcspTraceInfo(("REgistered success\n"));
    return rc;
}

rbusError_t de_registerGeneratedDataElements(rbusHandle_t handle)
{
    rbusError_t rc;
    CcspTraceInfo(("Calling de_regsitering data elements\n"));
    rc = rbus_unregDataElements(handle, 15, dataElements);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rtLog_Error("rbus_unregDataElements failed");
    }
    CcspTraceInfo(("DEregistered success\n"));
    return rc;
}
