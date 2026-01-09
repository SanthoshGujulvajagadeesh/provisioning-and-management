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

BOOL rbus_helper_GetParamBoolValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(opts);

    BOOL retBool = FALSE;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            helperctxt.cb_TableIsSynchronize(NULL);
        }

        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    BOOL retStatus = helperctxt.getparam_cb.cb_GetParamBoolValue(row_handle, param, &retBool);
    if (!retStatus)
    {
        return RBUS_ERROR_INVALID_INPUT;
    }
    rbusProperty_SetBoolean(property, retBool);
    return RBUS_ERROR_SUCCESS;
}
  

BOOL rbus_helper_GetParamIntValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(opts);

    int retInt = 0;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            helperctxt.cb_TableIsSynchronize(NULL);
        }

        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    BOOL retStatus = helperctxt.getparam_cb.cb_GetParamIntValue(row_handle, param, &retInt);
    if (!retStatus)
    {
        return RBUS_ERROR_INVALID_INPUT;
    }
    rbusProperty_SetInt32(property, retInt);
    return RBUS_ERROR_SUCCESS;
}
  


BOOL rbus_helper_GetParamUlongValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(opts);

    ULONG retUlong = 0;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            helperctxt.cb_TableIsSynchronize(NULL);
        }

        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    BOOL retStatus = helperctxt.getparam_cb.cb_GetParamUlongValue(row_handle, param, &retUlong);
    if (!retStatus)
    {
        return RBUS_ERROR_INVALID_INPUT;
    }
    rbusProperty_SetUInt32(property, retUlong);
    return RBUS_ERROR_SUCCESS;
}


BOOL rbus_helper_GetParamUlongValue_mapped(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt, map_t mapper_context[], int size)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(opts);

    ULONG retUlong = 0;
    char param[128] ={0};
    char retString[256] = {0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            helperctxt.cb_TableIsSynchronize(NULL);
        }

        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    BOOL retStatus = helperctxt.getparam_cb.cb_GetParamUlongValue(row_handle, param, &retUlong);
    if (!retStatus)
    {
        return RBUS_ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < size; i++) {
        if (mapper_context[i].id == retUlong) {
            strncpy(retString, mapper_context[i].name, sizeof(retString) - 1);
            retString[sizeof(retString) - 1] = '\0';
        }
    }
    if(retString[0] == '\0')
    {
        CcspTraceError(("Invalid value for %s\n", param));
        return RBUS_ERROR_INVALID_INPUT;
    }
    rbusProperty_SetString(property, retString);  
    return RBUS_ERROR_SUCCESS;
}


BOOL rbus_helper_GetParamStringValue(rbusHandle_t handle, rbusGetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);
    UNREFERENCED_PARAMETER(opts);

    char retString[256] = {0};
    ULONG ulSize = 256;;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            helperctxt.cb_TableIsSynchronize(NULL);
        }

        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    ULONG retStatus = helperctxt.getparam_cb.cb_GetParamStringValue(row_handle, param, retString, &ulSize);
    if (retStatus)
    {
        return RBUS_ERROR_INVALID_INPUT;
    }
    rbusProperty_SetString(property, retString);
    return RBUS_ERROR_SUCCESS;
}



rbusError_t rbus_helper_SetParamBoolValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);

    bool val;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    rbusValueError_t verr = rbusProperty_GetBooleanEx(property, &val);
    if(verr != RBUS_VALUE_ERROR_SUCCESS)
    {
	CcspTraceError(("%s:Unable to get value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    BOOL retStatus = helperctxt.setparam_cb.cb_SetParamBoolValue(row_handle, param, val);
    if (!retStatus)
    {
	CcspTraceError(("%s:Unable to set value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    if(opts->commit)
    {
      return do_User_Validate_User_Commit_User_Rollback(row_handle);
    }

 return RBUS_ERROR_SUCCESS;
}

rbusError_t rbus_helper_SetParamIntValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);

    int32_t val;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    rbusValueError_t verr = rbusProperty_GetInt32Ex(property, &val);
    if(verr != RBUS_VALUE_ERROR_SUCCESS)
    {
	CcspTraceError(("%s:Unable to get value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    BOOL retStatus = helperctxt.setparam_cb.cb_SetParamIntValue(row_handle, param, val);
    if (!retStatus)
    {
	CcspTraceError(("%s:Unable to set value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    if(opts->commit)
    {
      return do_User_Validate_User_Commit_User_Rollback(row_handle);
    }

 return RBUS_ERROR_SUCCESS;
}

rbusError_t rbus_helper_SetParamUlongValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);

    uint32_t val;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    rbusValueError_t verr = rbusProperty_GetUInt32Ex(property, &val);
    if(verr != RBUS_VALUE_ERROR_SUCCESS)
    {
	CcspTraceError(("%s:Unable to get value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    BOOL retStatus = helperctxt.setparam_cb.cb_SetParamUlongValue(row_handle, param, val);
    if (!retStatus)
    {
	CcspTraceError(("%s:Unable to set value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    if(opts->commit)
    {
      return do_User_Validate_User_Commit_User_Rollback(row_handle);
    }

 return RBUS_ERROR_SUCCESS;
}



rbusError_t rbus_helper_SetParamUlongValue_mapped(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt, map_t mapper_context[], int size)
{
    UNREFERENCED_PARAMETER(handle);

    uint32_t val;
    char param[128] ={0};
    const char* retString;
    void *row_handle = NULL;
    bool found = false;
    if (helperctxt.table_name)
    {
        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    rbusValueError_t verr = rbusProperty_GetStringEx(property, &retString, NULL);
    if(verr != RBUS_VALUE_ERROR_SUCCESS)
    {
	CcspTraceError(("%s:Unable to get value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < size; i++) {
        if (strcmp(mapper_context[i].name, retString) == 0) {
            val = mapper_context[i].id;
            found = true;
        }
    }
    if(!found)
    {
        CcspTraceError(("Invalid value for %s\n", param));
        return RBUS_ERROR_INVALID_INPUT;
    }

    BOOL retStatus = helperctxt.setparam_cb.cb_SetParamUlongValue(row_handle, param, val);
    if (!retStatus)
    {
	CcspTraceError(("%s:Unable to set value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    if(opts->commit)
    {
      return do_User_Validate_User_Commit_User_Rollback(row_handle);
    }

 return RBUS_ERROR_SUCCESS;
}

rbusError_t rbus_helper_SetParamStringValue(rbusHandle_t handle, rbusSetHandlerOptions_t* opts, rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(handle);

    const char* val;
    char param[128] ={0};
    void *row_handle = NULL;
    if (helperctxt.table_name)
    {
        row_handle = GetTableInstance_and_param(property, helperctxt, param);
        if (!row_handle)
           return RBUS_ERROR_INVALID_INPUT;
    }

    if(!row_handle){
        char const* name = rbusProperty_GetName(property);
        char *lastDot = strrchr(name, '.');
        if (lastDot != NULL) {
            char *substring = lastDot + 1;
            strncpy(param, substring, sizeof(param) - 1);
        } else {
            CcspTraceInfo(("No dot found in the string."));
        }
    }

    rbusValueError_t verr = rbusProperty_GetStringEx(property, &val, NULL);
    if(verr != RBUS_VALUE_ERROR_SUCCESS)
    {
	CcspTraceError(("%s:Unable to get value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    BOOL retStatus = helperctxt.setparam_cb.cb_SetParamStringValue(row_handle, param, (char *)val);
    if (!retStatus)
    {
	CcspTraceError(("%s:Unable to set value",__func__));    
        return RBUS_ERROR_INVALID_INPUT;
    }

    if(opts->commit)
    {
      return do_User_Validate_User_Commit_User_Rollback(row_handle);
    }

 return RBUS_ERROR_SUCCESS;
}


static void *GetTableInstance_and_param(rbusProperty_t property, CcspRbusHelper_t helperctxt, char *out_param)
{
    CcspTraceInfo(("Inside GetTableInstance_and_param if condition\n"));
    void *hInsContext = NULL;
    char param[128] = {0};
    ULONG instNum = 0;

    char const* name = rbusProperty_GetName(property);

    CcspTraceInfo(("Getting Property:%s\n",name));

    const char *buf = strstr(name,helperctxt.table_name);

    if (!buf)
       return NULL;

    int ret = sscanf(buf + strlen(helperctxt.table_name), "%ld.%127s", &instNum,param);
    CcspTraceInfo(("Getting return value:%d instNum:%ld param:%s\n",ret,instNum,param));
    if (ret != 2)
    {
       rtLog_Error("unable to fetch row instance");
       return NULL;
    }

    int table_count = helperctxt.cb_TableGetEntryCount(hInsContext);
    CcspTraceInfo(("Getting table_count:%d\n",table_count));
    if (!table_count)
       return NULL;

    /* inst number need not to be in serial*/
    void *row_handle = NULL;
    ULONG temp_instnum = 0;
    for (int i=0; i < table_count;i++)
    {
        row_handle = helperctxt.tableentry_cb.cb_TableGetEntry(hInsContext,i,&temp_instnum);
        CcspTraceInfo(("Param %s Found instancei:%ld %ld\n",param,temp_instnum,instNum));
        if (row_handle && (temp_instnum == instNum))
	{
                break;
	}
    }

    if(!row_handle)
    {
        CcspTraceError(("User_GetEntry returned null row context"));
        return NULL;
    }
    strncpy(out_param,param,strlen(param));
    return row_handle;
}