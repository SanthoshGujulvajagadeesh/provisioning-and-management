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
 * code generated with: python rbus_code_generator_ccsp_style.py DeviceInfo_object.xml DeviceInfo
 */

#include <rbus.h>
#include <rbus_context_helpers.h>
#include <rtMemory.h>
#include <rtLog.h>
#include <stdlib.h>
#include <string.h>
#include "dlfcn.h"
#include <rbus_wrapper_apis_include.h>
#include <rbus_message_bus.h>
#include <rbus_wrapper_common_apis.h>

ULONG    g_lastWriteEntity       = 0;
ULONG    g_currentWriteEntity    = 0;
char g_currentParamFullName[512];

rbusError_t dm_init_deviceinfo_rbus(rbusHandle_t rbusHandle)
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

rbusError_t dm_de_init_deviceinfo_rbus(rbusHandle_t rbusHandle)
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

static rbusError_t DeviceInfo_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = DeviceInfo_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t DeviceInfo_GetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamIntValue = DeviceInfo_GetParamIntValue,
                                      .setparam_cb.cb_SetParamIntValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamIntValue(handle, opts, property, helperctxt);
}         

static rbusError_t DeviceInfo_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = DeviceInfo_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t DeviceInfo_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = DeviceInfo_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t DeviceInfo_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = DeviceInfo_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t DeviceInfo_SetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamIntValue = NULL,
                                      .setparam_cb.cb_SetParamIntValue = DeviceInfo_SetParamIntValue,NULL,NULL,NULL};
      return rbus_helper_SetParamIntValue(handle, opts, property, helperctxt);
}

rbusError_t DeviceInfo_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = DeviceInfo_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

rbusError_t DeviceInfo_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = DeviceInfo_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Syndication_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Syndication_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Syndication_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Syndication_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t WANsideSSH_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WANsideSSH_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WANsideSSH_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WANsideSSH_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t RDKB_Control_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RDKB_Control_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t RDKB_Control_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = RDKB_Control_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t RDKB_UIBranding_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RDKB_UIBranding_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t RDKB_UIBranding_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = RDKB_UIBranding_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t RDKB_UIBranding_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = RDKB_UIBranding_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Footer_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Footer_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Footer_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Footer_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Connection_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Connection_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Connection_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Connection_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t NetworkDiagnosticTools_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NetworkDiagnosticTools_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t NetworkDiagnosticTools_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = NetworkDiagnosticTools_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t WiFiPersonalization_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WiFiPersonalization_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t WiFiPersonalization_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = WiFiPersonalization_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t WiFiPersonalization_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WiFiPersonalization_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t WiFiPersonalization_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = WiFiPersonalization_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t LocalUI_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = LocalUI_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t LocalUI_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = LocalUI_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t LocalUI_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = LocalUI_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t LocalUI_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = LocalUI_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t HelpTip_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = HelpTip_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t HelpTip_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = HelpTip_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t CloudUI_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = CloudUI_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t CloudUI_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = CloudUI_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Logging_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Logging_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t Logging_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = Logging_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t Logging_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Logging_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Logging_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Logging_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t Logging_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = Logging_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t ReverseSSH_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = ReverseSSH_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t ReverseSSH_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = ReverseSSH_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t ForwardSSH_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = ForwardSSH_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t ForwardSSH_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = ForwardSSH_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t RPC_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RPC_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t RPC_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = RPC_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t RPC_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = RPC_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t RPC_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = RPC_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t RPC_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = RPC_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

rbusError_t RPC_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = RPC_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Control_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Control_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t Control_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = Control_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t Control_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Control_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Control_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Control_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t Control_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = Control_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

rbusError_t Control_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Control_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Identity_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Identity_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Identity_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Identity_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t Feature_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Feature_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t Feature_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Feature_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t TR104_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = TR104_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t TR104_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = TR104_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}
/*
static rbusError_t IHC_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = IHC_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t IHC_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = IHC_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}
*/
static rbusError_t SWDLDirect_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SWDLDirect_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t SWDLDirect_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SWDLDirect_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WebUIRemoteMgtOption_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WebUIRemoteMgtOption_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WebUIRemoteMgtOption_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WebUIRemoteMgtOption_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WebUI_GetParamUlongValue_rbus_mapped(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    map_t Enable_mapper[] = {
     { 1, "Enable" }, { 0, " Disable" }, { 2, " MSOonly" }
    };
    int size = sizeof(Enable_mapper) / sizeof(Enable_mapper[0]);
    
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                    .tableentry_cb.cb_TableGetEntry = NULL,
                                    .getparam_cb.cb_GetParamUlongValue = WebUI_GetParamUlongValue,
                                    .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue_mapped(handle, opts, property, helperctxt, Enable_mapper, size);
}         
      

static rbusError_t WebUI_SetParamUlongValue_rbus_mapped(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    map_t Enable_mapper[] = {
     { 1, "Enable" }, { 0, " Disable" }, { 2, " MSOonly" }
    };
    int size = sizeof(Enable_mapper) / sizeof(Enable_mapper[0]);
    
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                    .tableentry_cb.cb_TableGetEntry = NULL,
                                    .getparam_cb.cb_GetParamUlongValue = NULL,
                                    .setparam_cb.cb_SetParamUlongValue = WebUI_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue_mapped(handle, opts, property, helperctxt, Enable_mapper, size);
}         
      
rbusError_t WebUI_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = WebUI_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t CognitiveMotionDetection_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = CognitiveMotionDetection_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t CognitiveMotionDetection_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = CognitiveMotionDetection_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t MAPT_DeviceInfo_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MAPT_DeviceInfo_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MAPT_DeviceInfo_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MAPT_DeviceInfo_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t MocaAccountIsolation_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MocaAccountIsolation_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MocaAccountIsolation_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MocaAccountIsolation_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t CaptivePortalForNoCableRF_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = CaptivePortalForNoCableRF_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t CaptivePortalForNoCableRF_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = CaptivePortalForNoCableRF_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WMMdownstreamMap_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WMMdownstreamMap_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WMMdownstreamMap_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WMMdownstreamMap_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t ActiveMeasurements_RFC_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = ActiveMeasurements_RFC_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t ActiveMeasurements_RFC_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = ActiveMeasurements_RFC_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WPA3_Personal_Transition_RFC_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WPA3_Personal_Transition_RFC_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WPA3_Personal_Transition_RFC_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WPA3_Personal_Transition_RFC_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t ErrorsReceived_RFC_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = ErrorsReceived_RFC_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t ErrorsReceived_RFC_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = ErrorsReceived_RFC_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t EnableOCSPStapling_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = EnableOCSPStapling_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t EnableOCSPStapling_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = EnableOCSPStapling_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t OnboardingLogging_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = OnboardingLogging_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t OnboardingLogging_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = OnboardingLogging_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t CredDwnld_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = CredDwnld_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t CredDwnld_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = CredDwnld_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t CredDwnld_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = CredDwnld_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t CredDwnld_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = CredDwnld_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t DLCaStore_RFC_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = DLCaStore_RFC_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t DLCaStore_RFC_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = DLCaStore_RFC_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SHORTS_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SHORTS_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t SHORTS_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SHORTS_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t Telemetry_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Telemetry_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t Telemetry_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Telemetry_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Telemetry_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Telemetry_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t Telemetry_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = Telemetry_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t MessageBusSource_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MessageBusSource_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MessageBusSource_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MessageBusSource_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t MTLS_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MTLS_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MTLS_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MTLS_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SelfHeal_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = SelfHeal_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t SelfHeal_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = SelfHeal_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t UPnPRefactor_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = UPnPRefactor_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t UPnPRefactor_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = UPnPRefactor_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t HwHealthTestEnable_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = HwHealthTestEnable_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t HwHealthTest_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = HwHealthTest_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t HwHealthTestEnable_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = HwHealthTestEnable_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t HwHealthTest_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = HwHealthTest_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t HwHealthTestPTREnable_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = HwHealthTestPTREnable_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t HwHealthTestPTRFrequency_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = HwHealthTestPTRFrequency_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t HwHealthTestPTREnable_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = HwHealthTestPTREnable_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t HwHealthTestPTRFrequency_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = HwHealthTestPTRFrequency_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t PresenceDetect_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = PresenceDetect_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t PresenceDetect_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = PresenceDetect_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t LostandFoundInternet_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = LostandFoundInternet_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t LostandFoundInternet_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = LostandFoundInternet_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t CodeBigFirst_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = CodeBigFirst_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t CodeBig_First_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = CodeBig_First_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SSIDPSWDCTRL_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SSIDPSWDCTRL_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t SSIDPSWDCTRL_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SSIDPSWDCTRL_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t OAUTH_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = OAUTH_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t OAUTH_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = OAUTH_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t EncryptCloudUpload_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = EncryptCloudUpload_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t EncryptCloudUpload_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = EncryptCloudUpload_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t UploadLogsOnUnscheduledReboot_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = UploadLogsOnUnscheduledReboot_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t UploadLogsOnUnscheduledReboot_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = UploadLogsOnUnscheduledReboot_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t MEMSWAP_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MEMSWAP_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MEMSWAP_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MEMSWAP_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SyndicationFlowControl_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SyndicationFlowControl_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t SyndicationFlowControl_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = SyndicationFlowControl_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t SyndicationFlowControl_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SyndicationFlowControl_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t SyndicationFlowControl_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = SyndicationFlowControl_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t EasyConnect_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = EasyConnect_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t EasyConnect_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = EasyConnect_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t DFS_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = DFS_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t DFS_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = DFS_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t DFSatBootUp_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = DFSatBootUp_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t DFSatBootUp_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = DFSatBootUp_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t RBUS_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RBUS_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t SyseventTracer_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SyseventTracer_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t SyseventTracer_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SyseventTracer_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t BLUEZ_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = BLUEZ_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t BLUEZ_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = BLUEZ_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WANLinkHeal_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WANLinkHeal_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WANLinkHeal_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WANLinkHeal_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SNMP_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SNMP_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t SNMP_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SNMP_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t TDK_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = TDK_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t TDK_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = TDK_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t Collectd_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Collectd_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t Collectd_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Collectd_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t DNSSTRICTORDER_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = DNSSTRICTORDER_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t DNSSTRICTORDER_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = DNSSTRICTORDER_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t ShortsDL_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = ShortsDL_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t ShortsDL_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = ShortsDL_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t AutoExcluded_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = AutoExcluded_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t AutoExcluded_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = AutoExcluded_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t AutoExcluded_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = AutoExcluded_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t AutoExcluded_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = AutoExcluded_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t RDKFirmwareUpgrader_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RDKFirmwareUpgrader_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t RDKFirmwareUpgrader_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = RDKFirmwareUpgrader_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t PeriodicFWCheck_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = PeriodicFWCheck_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t PeriodicFWCheck_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = PeriodicFWCheck_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t AllowOpenPorts_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = AllowOpenPorts_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t AllowOpenPorts_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = AllowOpenPorts_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t BLE_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = BLE_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t BLE_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = BLE_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t PeriodicBeacon_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = PeriodicBeacon_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t PeriodicBeacon_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = PeriodicBeacon_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t PeriodicBeacon_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = PeriodicBeacon_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t PeriodicBeacon_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = PeriodicBeacon_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t Broadcast_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Broadcast_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t Broadcast_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Broadcast_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t IPv6subPrefix_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = IPv6subPrefix_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t IPv6subPrefix_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = IPv6subPrefix_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t IPv6onLnF_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = IPv6onLnF_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t IPv6onLnF_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = IPv6onLnF_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t IPv6onXHS_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = IPv6onXHS_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t IPv6onXHS_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = IPv6onXHS_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t IPv6onPOD_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = IPv6onPOD_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t IPv6onPOD_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = IPv6onPOD_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t IPv6onMoCA_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = IPv6onMoCA_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t IPv6onMoCA_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = IPv6onMoCA_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t EvoStream_DirectConnect_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = EvoStream_DirectConnect_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t EvoStream_DirectConnect_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = EvoStream_DirectConnect_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t TelemetryEndpoint_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = TelemetryEndpoint_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t TelemetryEndpoint_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = TelemetryEndpoint_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t TelemetryEndpoint_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = TelemetryEndpoint_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t TelemetryEndpoint_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = TelemetryEndpoint_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t AccountInfo_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = AccountInfo_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t AccountInfo_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = AccountInfo_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t CDLDM_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = CDLDM_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t CDLDM_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = CDLDM_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t WiFiInterworking_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WiFiInterworking_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WiFiInterworking_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WiFiInterworking_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t off_channel_scan_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = off_channel_scan_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t off_channel_scan_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = off_channel_scan_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WiFiPasspoint_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WiFiPasspoint_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WiFiPasspoint_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WiFiPasspoint_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t WiFiPsmDb_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = WiFiPsmDb_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t WiFiPsmDb_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = WiFiPsmDb_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t RadiusGreyList_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = RadiusGreyList_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t RadiusGreyList_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = RadiusGreyList_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t UniqueTelemetryId_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = UniqueTelemetryId_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t UniqueTelemetryId_GetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamIntValue = UniqueTelemetryId_GetParamIntValue,
                                      .setparam_cb.cb_SetParamIntValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamIntValue(handle, opts, property, helperctxt);
}         

static rbusError_t UniqueTelemetryId_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = UniqueTelemetryId_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t UniqueTelemetryId_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = UniqueTelemetryId_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t UniqueTelemetryId_SetParamIntValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamIntValue = NULL,
                                      .setparam_cb.cb_SetParamIntValue = UniqueTelemetryId_SetParamIntValue,NULL,NULL,NULL};
      return rbus_helper_SetParamIntValue(handle, opts, property, helperctxt);
}

rbusError_t UniqueTelemetryId_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = UniqueTelemetryId_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t LatencyMeasureTcpSetupIPv4_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = LatencyMeasureTcpSetupIPv4_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t LatencyMeasureTcpSetupIPv4_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = LatencyMeasureTcpSetupIPv4_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t LatencyMeasureTcpSetupIPv6_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = LatencyMeasureTcpSetupIPv6_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t LatencyMeasureTcpSetupIPv6_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = LatencyMeasureTcpSetupIPv6_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t ManageableNotification_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = ManageableNotification_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t ManageableNotification_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = ManageableNotification_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t Snmpv3DHKickstart_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Snmpv3DHKickstart_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t Snmpv3DHKickstart_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = Snmpv3DHKickstart_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t Snmpv3DHKickstart_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Snmpv3DHKickstart_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t Snmpv3DHKickstart_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = Snmpv3DHKickstart_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}
/*
static rbusError_t KickstartTable_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Table.", KickstartTable_GetEntryCount,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = KickstartTable_GetEntry,
                                      .getparam_cb.cb_GetParamStringValue = KickstartTable_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t KickstartTable_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Table.", KickstartTable_GetEntryCount,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = KickstartTable_GetEntry,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = KickstartTable_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}
*/
static rbusError_t TR069support_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = TR069support_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t TR069support_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = TR069support_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t newNTP_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = newNTP_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t newNTP_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = newNTP_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t MACsecRequired_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = MACsecRequired_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t MACsecRequired_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = MACsecRequired_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t SecureWebUI_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = SecureWebUI_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t SecureWebUI_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = SecureWebUI_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t SecureWebUI_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = SecureWebUI_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

rbusError_t SecureWebUI_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = SecureWebUI_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t UseXPKI_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = UseXPKI_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t UseXPKI_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = UseXPKI_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t LnFUseXPKI_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = LnFUseXPKI_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t LnFUseXPKI_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = LnFUseXPKI_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t CrashUpload_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = CrashUpload_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t CrashUpload_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = CrashUpload_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t mTlsLogUpload_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = mTlsLogUpload_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t mTlsLogUpload_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = mTlsLogUpload_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t mTlsCrashdumpUpload_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = mTlsCrashdumpUpload_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t mTlsCrashdumpUpload_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = mTlsCrashdumpUpload_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t NonRootSupport_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NonRootSupport_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t NonRootSupport_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = NonRootSupport_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t AutoReboot_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = AutoReboot_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t AutoReboot_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = AutoReboot_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t XHFW_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = XHFW_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t XHFW_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = XHFW_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t EthernetWAN_MACsec_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = EthernetWAN_MACsec_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

static rbusError_t xBlueTooth_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = xBlueTooth_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t xBlueTooth_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = xBlueTooth_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}
/*
static rbusError_t MaintenanceWindow_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = MaintenanceWindow_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t MaintenanceWindow_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = MaintenanceWindow_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}
*/
static rbusError_t Iot_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Iot_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t Iot_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Iot_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t VendorConfigFile_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.VendorConfigFile.", VendorConfigFile_GetEntryCount,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = VendorConfigFile_GetEntry,
                                      .getparam_cb.cb_GetParamStringValue = VendorConfigFile_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t VendorConfigFile_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.VendorConfigFile.", VendorConfigFile_GetEntryCount,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = VendorConfigFile_GetEntry,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = VendorConfigFile_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusError_t MemoryStatus_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = MemoryStatus_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

rbusError_t MemoryStatus_SetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = MemoryStatus_SetParamUlongValue,NULL,NULL,NULL};
      return rbus_helper_SetParamUlongValue(handle, opts, property, helperctxt);
}

static rbusError_t X_RDKCENTRAL_COM_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = X_RDKCENTRAL_COM_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

rbusError_t X_RDKCENTRAL_COM_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = X_RDKCENTRAL_COM_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

static rbusError_t Ops_GetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = Ops_GetParamBoolValue,
                                      .setparam_cb.cb_SetParamBoolValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamBoolValue(handle, opts, property, helperctxt);
}         

static rbusError_t Ops_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = Ops_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t Ops_SetParamBoolValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamBoolValue = NULL,
                                      .setparam_cb.cb_SetParamBoolValue = Ops_SetParamBoolValue,NULL,NULL,NULL};
      return rbus_helper_SetParamBoolValue(handle, opts, property, helperctxt);
}

#if 0
static rbusError_t ProcessStatus_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = ProcessStatus_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}
#endif

int do_Process_IsUpdated_Process_Synchronize(HandlerContext context)
{
    if(IsTimeToSyncDynamicTable(context.name))
    {
        if(Process_IsUpdated(context.userData))
        {
            return Process_Synchronize(context.userData);
        }
    }
    return 0;
}

rbusError_t rbus_helper_GetTableCount(rbusHandle_t handle,rbusGetHandlerOptions_t* opts, 
					   rbusProperty_t property, CcspRbusHelper_t helperctxt)
{
    UNREFERENCED_PARAMETER(opts);

    ULONG retUlong = 0;
    if (helperctxt.table_name && strncmp(helperctxt.table_name,"NULL",strlen("NULL")))
    {
	/*To do check whether we have to Call update before taking count*/    
	    
        if (helperctxt.cb_TableIsUpdated && helperctxt.cb_TableIsUpdated(NULL))
        {
            retUlong = helperctxt.cb_TableGetEntryCount(NULL);
            if (retUlong)
            {
                rbus_helper_Table_unregisterRow(handle,helperctxt);
            }
            helperctxt.cb_TableIsSynchronize(NULL);
            rbus_helper_Table_registerRow(handle,helperctxt);
        }

        retUlong = helperctxt.cb_TableGetEntryCount(NULL);
    	CcspTraceInfo(("Getting table_count:%ld\n",retUlong));
       	rbusProperty_SetUInt32(property, retUlong);
        return RBUS_ERROR_SUCCESS;
    }
    return RBUS_ERROR_INVALID_INPUT;
}

static rbusError_t ProcessStatus_GetEntryCount_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.ProcessStatus.Process.", Process_GetEntryCount,Process_IsUpdated,Process_Synchronize,
                                      .tableentry_cb.cb_TableGetEntry = Process_GetEntry,
                                      .getparam_cb.cb_GetParamUlongValue = NULL,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetTableCount(handle, opts, property, helperctxt);
}

static rbusError_t Process_GetParamUlongValue_rbus_mapped(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    map_t State_mapper[] = {
     { 1, "Running" }, { 2, "Sleeping" }, { 3, "Stopped" }, { 4, "Idle" }, { 5, "Uninterruptible" }, { 6, "Zombie" }
    };
    int size = sizeof(State_mapper) / sizeof(State_mapper[0]);
    
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.ProcessStatus.Process.", Process_GetEntryCount,Process_IsUpdated,Process_Synchronize,
                                    .tableentry_cb.cb_TableGetEntry = Process_GetEntry,
                                    .getparam_cb.cb_GetParamUlongValue = Process_GetParamUlongValue,
                                    .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue_mapped(handle, opts, property, helperctxt, State_mapper, size);
}         
      
static rbusError_t Process_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.ProcessStatus.Process.", Process_GetEntryCount,Process_IsUpdated,Process_Synchronize,
                                      .tableentry_cb.cb_TableGetEntry = Process_GetEntry,
                                      .getparam_cb.cb_GetParamUlongValue = Process_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t Process_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"Device.DeviceInfo.ProcessStatus.Process.", Process_GetEntryCount,Process_IsUpdated,Process_Synchronize,
                                      .tableentry_cb.cb_TableGetEntry = Process_GetEntry,
                                      .getparam_cb.cb_GetParamStringValue = Process_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

static rbusError_t NetworkProperties_GetParamUlongValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamUlongValue = NetworkProperties_GetParamUlongValue,
                                      .setparam_cb.cb_SetParamUlongValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamUlongValue(handle, opts, property, helperctxt);
}         

static rbusError_t NetworkProperties_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NetworkProperties_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

static rbusError_t WiFi_Telemetry_GetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusGetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = WiFi_Telemetry_GetParamStringValue,
                                      .setparam_cb.cb_SetParamStringValue = NULL,NULL,NULL,NULL};
      return rbus_helper_GetParamStringValue(handle, opts, property, helperctxt);
}         

rbusError_t WiFi_Telemetry_SetParamStringValue_rbus(rbusHandle_t handle, rbusProperty_t property, rbusSetHandlerOptions_t* opts)
{
    CcspRbusHelper_t helperctxt = {"NULL", NULL,NULL,NULL,
                                      .tableentry_cb.cb_TableGetEntry = NULL,
                                      .getparam_cb.cb_GetParamStringValue = NULL,
                                      .setparam_cb.cb_SetParamStringValue = WiFi_Telemetry_SetParamStringValue,NULL,NULL,NULL};
      return rbus_helper_SetParamStringValue(handle, opts, property, helperctxt);
}

static rbusDataElement_t dataElements[277] = {
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_ConfigureWiFi", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CaptivePortalEnable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_WiFiNeedsPersonalization", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CloudUICapable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CloudUIEnable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_xfinitywifiCapableCPE", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST_COM_xfinitywifiEnable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_rdkbPlatformCapable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ClearResetCount", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_AkerEnable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_IsCloudReachable", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_OnBoarding_DeleteLogs", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.CustomDataModelEnabled", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_EnableMoCAforXi5", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamBoolValue_rbus, DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_FirmwareDownloadAndFactoryReset", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamIntValue_rbus, DeviceInfo_SetParamIntValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.UpTime", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_BootTime", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFileNumberOfEntries", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_ConfigureDocsicPollTime", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamUlongValue_rbus, DeviceInfo_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.FactoryResetCount", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_BootloaderVersion", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_FirmwareName", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDK_FirmwareName", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_FirmwareBuildTime", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CloudPersonalizationURL", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_UI_ACCESS", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CloudUIWebURL", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDK_RDKProfileName", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_CM_MAC", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_CM_IP", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_WAN_MAC", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_WAN_IP", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_WAN_IPv6", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_MTA_MAC", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_MTA_IP", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_MTA_IPV6", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_AP_MAC", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_EMS_MobileNumber", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_COMCAST-COM_EMS_ServerURL", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_CMTS_MAC", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_BaseMacAddress", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.DeviceCategory", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Manufacturer", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ManufacturerOUI", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_AdvancedServices", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_CISCO_COM_ProcessorSpeed", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Hardware", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Hardware_MemUsed", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Hardware_MemFree", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ModelName", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Description", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProductClass", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.SerialNumber", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.HardwareVersion", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.SoftwareVersion", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.AdditionalHardwareVersion", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.AdditionalSoftwareVersion", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProvisioningCode", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_SystemTime", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_LastRebootReason", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, DeviceInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_InActiveFirmware", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_OnBoarding_State", RBUS_ELEMENT_TYPE_PROPERTY, {DeviceInfo_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.PartnerId", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.TR69CertLocation", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.LocalUIBrandingTable", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.WifiUIBrandingTable", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.PauseScreenFileLocation", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.CMVoiceImageSelect", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.MeshRedirectorURL", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.AdvsecRedirectorURL", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.XconfURL", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.LogUploadURL", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.Telemetry", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.CrashPortal", RBUS_ELEMENT_TYPE_PROPERTY, {Syndication_GetParamStringValue_rbus, Syndication_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.WANsideSSH.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WANsideSSH_GetParamBoolValue_rbus, WANsideSSH_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_Control.ActivatePartnerId", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_Control_GetParamBoolValue_rbus, RDKB_Control_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_Control.ClearPartnerId", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_Control_GetParamBoolValue_rbus, RDKB_Control_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.AllowEthernetWAN", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_UIBranding_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.DefaultAdminIP", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_UIBranding_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.DefaultLocalIPv4SubnetRange", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_UIBranding_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.DefaultLanguage", RBUS_ELEMENT_TYPE_PROPERTY, {RDKB_UIBranding_GetParamStringValue_rbus, RDKB_UIBranding_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.PartnerLink", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.UserGuideLink", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.CustomerCentralLink", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.PartnerText", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.UserGuideText", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Footer.CustomerCentralText", RBUS_ELEMENT_TYPE_PROPERTY, {Footer_GetParamStringValue_rbus, Footer_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Connection.MSOmenu", RBUS_ELEMENT_TYPE_PROPERTY, {Connection_GetParamStringValue_rbus, Connection_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Connection.MSOinfo", RBUS_ELEMENT_TYPE_PROPERTY, {Connection_GetParamStringValue_rbus, Connection_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Connection.StatusTitle", RBUS_ELEMENT_TYPE_PROPERTY, {Connection_GetParamStringValue_rbus, Connection_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.Connection.StatusInfo", RBUS_ELEMENT_TYPE_PROPERTY, {Connection_GetParamStringValue_rbus, Connection_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.NetworkDiagnosticTools.ConnectivityTestURL", RBUS_ELEMENT_TYPE_PROPERTY, {NetworkDiagnosticTools_GetParamStringValue_rbus, NetworkDiagnosticTools_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.Support", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.SMSsupport", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamBoolValue_rbus, WiFiPersonalization_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.MyAccountAppSupport", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamBoolValue_rbus, WiFiPersonalization_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.PartnerHelpLink", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamStringValue_rbus, WiFiPersonalization_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.MSOLogo", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.Title", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.WelcomeMessage", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.WiFiPersonalization.WelcomeMessage_fre", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPersonalization_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.LocalUI.HomeNetworkControl", RBUS_ELEMENT_TYPE_PROPERTY, {LocalUI_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.LocalUI.MSOLogo", RBUS_ELEMENT_TYPE_PROPERTY, {LocalUI_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.LocalUI.DefaultLoginUsername", RBUS_ELEMENT_TYPE_PROPERTY, {LocalUI_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.LocalUI.DefaultLoginPassword", RBUS_ELEMENT_TYPE_PROPERTY, {LocalUI_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.LocalUI.MSOLogoTitle", RBUS_ELEMENT_TYPE_PROPERTY, {LocalUI_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.HelpTip.NetworkName", RBUS_ELEMENT_TYPE_PROPERTY, {HelpTip_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.CloudUI.brandname", RBUS_ELEMENT_TYPE_PROPERTY, {CloudUI_GetParamStringValue_rbus, CloudUI_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.CloudUI.productname", RBUS_ELEMENT_TYPE_PROPERTY, {CloudUI_GetParamStringValue_rbus, CloudUI_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_UIBranding.CloudUI.link", RBUS_ELEMENT_TYPE_PROPERTY, {CloudUI_GetParamStringValue_rbus, CloudUI_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.Logging.xOpsDMRetrieveConfigLogNow", RBUS_ELEMENT_TYPE_PROPERTY, {Logging_GetParamBoolValue_rbus, Logging_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.Logging.xOpsDMUploadLogsNow", RBUS_ELEMENT_TYPE_PROPERTY, {Logging_GetParamBoolValue_rbus, Logging_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.Logging.DmesgLogSyncInterval", RBUS_ELEMENT_TYPE_PROPERTY, {Logging_GetParamUlongValue_rbus, Logging_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.Logging.xOpsDMLogsUploadStatus", RBUS_ELEMENT_TYPE_PROPERTY, {Logging_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.ReverseSSH.xOpsReverseSshArgs", RBUS_ELEMENT_TYPE_PROPERTY, {ReverseSSH_GetParamStringValue_rbus, ReverseSSH_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.ReverseSSH.xOpsReverseSshTrigger", RBUS_ELEMENT_TYPE_PROPERTY, {ReverseSSH_GetParamStringValue_rbus, ReverseSSH_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.ReverseSSH.xOpsReverseSshStatus", RBUS_ELEMENT_TYPE_PROPERTY, {ReverseSSH_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.ForwardSSH.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {ForwardSSH_GetParamBoolValue_rbus, ForwardSSH_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.FirmwareDownloadCompletedNotification", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamBoolValue_rbus, RPC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.AbortReboot", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamBoolValue_rbus, RPC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.RebootPendingNotification", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamUlongValue_rbus, RPC_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.DeferFWDownloadReboot", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamUlongValue_rbus, RPC_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.RebootDevice", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamStringValue_rbus, RPC_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.FirmwareDownloadStartedNotification", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamStringValue_rbus, RPC_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xOpsDeviceMgmt.RPC.DeviceManageableNotification", RBUS_ELEMENT_TYPE_PROPERTY, {RPC_GetParamStringValue_rbus, RPC_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.ClearDB", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamBoolValue_rbus, Control_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.ClearDBEnd", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamBoolValue_rbus, Control_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.DisableNativeHostapd", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamBoolValue_rbus, Control_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.RetrieveNow", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamUlongValue_rbus, Control_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.XconfSelector", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamStringValue_rbus, Control_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.XconfUrl", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamStringValue_rbus, Control_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Control.XconfRecoveryUrl", RBUS_ELEMENT_TYPE_PROPERTY, {Control_GetParamStringValue_rbus, Control_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Identity.DeviceType", RBUS_ELEMENT_TYPE_PROPERTY, {Identity_GetParamStringValue_rbus, Identity_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.HomeNetworkIsolation", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.ContainerSupport", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.XfinityHealthCheck", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CodebigSupport", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLERadio", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Xupnp", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BridgeUtilsEnable", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPModeEnable", RBUS_ELEMENT_TYPE_PROPERTY, {Feature_GetParamBoolValue_rbus, Feature_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.TR104.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {TR104_GetParamBoolValue_rbus, TR104_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.ImageHealthChecker.OperatingMode", RBUS_ELEMENT_TYPE_PROPERTY, {IHC_GetParamStringValue_rbus, IHC_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SWDLDirect.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SWDLDirect_GetParamBoolValue_rbus, SWDLDirect_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WebUIRemoteMgtOption.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WebUIRemoteMgtOption_GetParamBoolValue_rbus, WebUIRemoteMgtOption_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WebUI.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WebUI_GetParamUlongValue_rbus_mapped, WebUI_SetParamUlongValue_rbus_mapped, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CognitiveMotionDetection.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {CognitiveMotionDetection_GetParamBoolValue_rbus, CognitiveMotionDetection_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MAP-T.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MAPT_DeviceInfo_GetParamBoolValue_rbus, MAPT_DeviceInfo_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MocaAccountIsolation.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MocaAccountIsolation_GetParamBoolValue_rbus, MocaAccountIsolation_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CaptivePortalForNoCableRF.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {CaptivePortalForNoCableRF_GetParamBoolValue_rbus, CaptivePortalForNoCableRF_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WMMdownstreamMap.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WMMdownstreamMap_GetParamBoolValue_rbus, WMMdownstreamMap_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WifiClient.ActiveMeasurements.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {ActiveMeasurements_RFC_GetParamBoolValue_rbus, ActiveMeasurements_RFC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WPA3_Personal_Transition.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WPA3_Personal_Transition_RFC_GetParamBoolValue_rbus, WPA3_Personal_Transition_RFC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.ErrorsReceived.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {ErrorsReceived_RFC_GetParamBoolValue_rbus, ErrorsReceived_RFC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CRL.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {EnableOCSPStapling_GetParamBoolValue_rbus, EnableOCSPStapling_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CRL.DirectOCSP", RBUS_ELEMENT_TYPE_PROPERTY, {EnableOCSPStapling_GetParamBoolValue_rbus, EnableOCSPStapling_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.OnboardingLogging.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {OnboardingLogging_GetParamBoolValue_rbus, OnboardingLogging_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CredDwnld.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {CredDwnld_GetParamBoolValue_rbus, CredDwnld_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CredDwnld.Use", RBUS_ELEMENT_TYPE_PROPERTY, {CredDwnld_GetParamStringValue_rbus, CredDwnld_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.DLCaStore.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {DLCaStore_RFC_GetParamBoolValue_rbus, DLCaStore_RFC_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SHORTS.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SHORTS_GetParamBoolValue_rbus, SHORTS_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Telemetry.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {Telemetry_GetParamBoolValue_rbus, Telemetry_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Telemetry.ConfigURL", RBUS_ELEMENT_TYPE_PROPERTY, {Telemetry_GetParamStringValue_rbus, Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Telemetry.Version", RBUS_ELEMENT_TYPE_PROPERTY, {Telemetry_GetParamStringValue_rbus, Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Telemetry.MessageBusSource.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MessageBusSource_GetParamBoolValue_rbus, MessageBusSource_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Telemetry.MTLS.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MTLS_GetParamBoolValue_rbus, MTLS_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SoftwareProcessManager.SelfHeal.AggressiveInterval", RBUS_ELEMENT_TYPE_PROPERTY, {SelfHeal_GetParamUlongValue_rbus, SelfHeal_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UPnP.Refactor.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {UPnPRefactor_GetParamBoolValue_rbus, UPnPRefactor_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.hwHealthTest.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {HwHealthTestEnable_GetParamBoolValue_rbus, HwHealthTestEnable_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.hwHealthTest.cpuThreshold", RBUS_ELEMENT_TYPE_PROPERTY, {HwHealthTest_GetParamUlongValue_rbus, HwHealthTest_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.hwHealthTest.dramThreshold", RBUS_ELEMENT_TYPE_PROPERTY, {HwHealthTest_GetParamUlongValue_rbus, HwHealthTest_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.hwHealthTest.periodicRun.enable", RBUS_ELEMENT_TYPE_PROPERTY, {HwHealthTestPTREnable_GetParamBoolValue_rbus, HwHealthTestPTREnable_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.hwHealthTest.periodicRun.frequency", RBUS_ELEMENT_TYPE_PROPERTY, {HwHealthTestPTRFrequency_GetParamUlongValue_rbus, HwHealthTestPTRFrequency_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.PresenceDetect.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {PresenceDetect_GetParamBoolValue_rbus, PresenceDetect_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BlockLostandFoundInternet.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {LostandFoundInternet_GetParamBoolValue_rbus, LostandFoundInternet_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CodeBigFirst.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {CodeBigFirst_GetParamBoolValue_rbus, CodeBig_First_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SSIDPSWDCTRL.SnmpEnable", RBUS_ELEMENT_TYPE_PROPERTY, {SSIDPSWDCTRL_GetParamBoolValue_rbus, SSIDPSWDCTRL_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SSIDPSWDCTRL.Tr069Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SSIDPSWDCTRL_GetParamBoolValue_rbus, SSIDPSWDCTRL_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.OAUTH.AuthMode", RBUS_ELEMENT_TYPE_PROPERTY, {OAUTH_GetParamStringValue_rbus, OAUTH_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.OAUTH.ServerUrl", RBUS_ELEMENT_TYPE_PROPERTY, {OAUTH_GetParamStringValue_rbus, OAUTH_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.EncryptCloudUpload.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {EncryptCloudUpload_GetParamBoolValue_rbus, EncryptCloudUpload_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UploadLogsOnUnscheduledReboot.Disable", RBUS_ELEMENT_TYPE_PROPERTY, {UploadLogsOnUnscheduledReboot_GetParamBoolValue_rbus, UploadLogsOnUnscheduledReboot_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MEMSWAP.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MEMSWAP_GetParamBoolValue_rbus, MEMSWAP_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SyndicationFlowControl.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SyndicationFlowControl_GetParamBoolValue_rbus, SyndicationFlowControl_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SyndicationFlowControl.InitialForwardedMark", RBUS_ELEMENT_TYPE_PROPERTY, {SyndicationFlowControl_GetParamStringValue_rbus, SyndicationFlowControl_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SyndicationFlowControl.InitialOutputMark", RBUS_ELEMENT_TYPE_PROPERTY, {SyndicationFlowControl_GetParamStringValue_rbus, SyndicationFlowControl_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.EasyConnect.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {EasyConnect_GetParamBoolValue_rbus, EasyConnect_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.EasyConnect.EnableAPISecurity", RBUS_ELEMENT_TYPE_PROPERTY, {EasyConnect_GetParamBoolValue_rbus, EasyConnect_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.DFS.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {DFS_GetParamBoolValue_rbus, DFS_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.DFSatBootUp.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {DFSatBootUp_GetParamBoolValue_rbus, DFSatBootUp_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.RBUS.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {RBUS_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SyseventTracer.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SyseventTracer_GetParamBoolValue_rbus, SyseventTracer_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLUEZ.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {BLUEZ_GetParamBoolValue_rbus, BLUEZ_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WANLinkHeal.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WANLinkHeal_GetParamBoolValue_rbus, WANLinkHeal_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SNMP.V3Support", RBUS_ELEMENT_TYPE_PROPERTY, {SNMP_GetParamBoolValue_rbus, SNMP_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SNMP.V2Support", RBUS_ELEMENT_TYPE_PROPERTY, {SNMP_GetParamBoolValue_rbus, SNMP_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SNMP.RestartMaintenanceEnable", RBUS_ELEMENT_TYPE_PROPERTY, {SNMP_GetParamBoolValue_rbus, SNMP_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.TDK.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {TDK_GetParamBoolValue_rbus, TDK_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.collectd.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {Collectd_GetParamBoolValue_rbus, Collectd_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.DNSStrictOrder.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {DNSSTRICTORDER_GetParamBoolValue_rbus, DNSSTRICTORDER_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.ShortsDL.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {ShortsDL_GetParamBoolValue_rbus, ShortsDL_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.FWUpdate.AutoExcluded.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {AutoExcluded_GetParamBoolValue_rbus, AutoExcluded_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.FWUpdate.AutoExcluded.XconfUrl", RBUS_ELEMENT_TYPE_PROPERTY, {AutoExcluded_GetParamStringValue_rbus, AutoExcluded_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.RDKFirmwareUpgrader.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {RDKFirmwareUpgrader_GetParamBoolValue_rbus, RDKFirmwareUpgrader_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.PeriodicFWCheck.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {PeriodicFWCheck_GetParamBoolValue_rbus, PeriodicFWCheck_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AllowOpenPorts.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {AllowOpenPorts_GetParamBoolValue_rbus, AllowOpenPorts_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLE.Discovery", RBUS_ELEMENT_TYPE_PROPERTY, {BLE_GetParamBoolValue_rbus, BLE_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLE.PeriodicBeacon.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {PeriodicBeacon_GetParamBoolValue_rbus, PeriodicBeacon_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLE.PeriodicBeacon.frequency", RBUS_ELEMENT_TYPE_PROPERTY, {PeriodicBeacon_GetParamUlongValue_rbus, PeriodicBeacon_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.BLE.Broadcast.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {Broadcast_GetParamBoolValue_rbus, Broadcast_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPv6subPrefix.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {IPv6subPrefix_GetParamBoolValue_rbus, IPv6subPrefix_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPv6onLnF.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {IPv6onLnF_GetParamBoolValue_rbus, IPv6onLnF_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPv6onXHS.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {IPv6onXHS_GetParamBoolValue_rbus, IPv6onXHS_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPv6onPOD.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {IPv6onPOD_GetParamBoolValue_rbus, IPv6onPOD_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.IPv6onMoCA.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {IPv6onMoCA_GetParamBoolValue_rbus, IPv6onMoCA_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.EvoStream_DirectConnect.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {EvoStream_DirectConnect_GetParamBoolValue_rbus, EvoStream_DirectConnect_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.TelemetryEndpoint.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {TelemetryEndpoint_GetParamBoolValue_rbus, TelemetryEndpoint_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.TelemetryEndpoint.URL", RBUS_ELEMENT_TYPE_PROPERTY, {TelemetryEndpoint_GetParamStringValue_rbus, TelemetryEndpoint_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AccountInfo.AccountID", RBUS_ELEMENT_TYPE_PROPERTY, {AccountInfo_GetParamStringValue_rbus, AccountInfo_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CDLDM.CDLModuleUrl", RBUS_ELEMENT_TYPE_PROPERTY, {CDLDM_GetParamStringValue_rbus, CDLDM_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WiFi-Interworking.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiInterworking_GetParamBoolValue_rbus, WiFiInterworking_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.OffChannelScan.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {off_channel_scan_GetParamBoolValue_rbus, off_channel_scan_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WiFi-Passpoint.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPasspoint_GetParamBoolValue_rbus, WiFiPasspoint_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.WiFi-PSM-DB.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {WiFiPsmDb_GetParamBoolValue_rbus, WiFiPsmDb_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.RadiusGreyList.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {RadiusGreyList_GetParamBoolValue_rbus, RadiusGreyList_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UniqueTelemetryId.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {UniqueTelemetryId_GetParamBoolValue_rbus, UniqueTelemetryId_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UniqueTelemetryId.TimingInterval", RBUS_ELEMENT_TYPE_PROPERTY, {UniqueTelemetryId_GetParamIntValue_rbus, UniqueTelemetryId_SetParamIntValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UniqueTelemetryId.TagString", RBUS_ELEMENT_TYPE_PROPERTY, {UniqueTelemetryId_GetParamStringValue_rbus, UniqueTelemetryId_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.LatencyMeasureTcpSetupIPv4.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {LatencyMeasureTcpSetupIPv4_GetParamBoolValue_rbus, LatencyMeasureTcpSetupIPv4_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.LatencyMeasureTcpSetupIPv6.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {LatencyMeasureTcpSetupIPv6_GetParamBoolValue_rbus, LatencyMeasureTcpSetupIPv6_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.ManageableNotification.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {ManageableNotification_GetParamBoolValue_rbus, ManageableNotification_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.RFCUpdateDone", RBUS_ELEMENT_TYPE_PROPERTY, {Snmpv3DHKickstart_GetParamBoolValue_rbus, Snmpv3DHKickstart_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Enabled", RBUS_ELEMENT_TYPE_PROPERTY, {Snmpv3DHKickstart_GetParamBoolValue_rbus, Snmpv3DHKickstart_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.KickstartTotal", RBUS_ELEMENT_TYPE_PROPERTY, {Snmpv3DHKickstart_GetParamUlongValue_rbus, Snmpv3DHKickstart_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.TableNumberOfEntries", RBUS_ELEMENT_TYPE_PROPERTY, {Snmpv3DHKickstart_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Table.{i}.", RBUS_ELEMENT_TYPE_TABLE, {NULL, NULL, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Table.{i}.SecurityName", RBUS_ELEMENT_TYPE_PROPERTY, {KickstartTable_GetParamStringValue_rbus, KickstartTable_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.Snmpv3DHKickstart.Table.{i}.SecurityNumber", RBUS_ELEMENT_TYPE_PROPERTY, {KickstartTable_GetParamStringValue_rbus, KickstartTable_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.TR069support.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {TR069support_GetParamBoolValue_rbus, TR069support_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.newNTP.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {newNTP_GetParamBoolValue_rbus, newNTP_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MACsecRequired.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {MACsecRequired_GetParamBoolValue_rbus, MACsecRequired_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SecureWebUI.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {SecureWebUI_GetParamBoolValue_rbus, SecureWebUI_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.SecureWebUI.LocalFqdn", RBUS_ELEMENT_TYPE_PROPERTY, {SecureWebUI_GetParamStringValue_rbus, SecureWebUI_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.UseXPKI.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {UseXPKI_GetParamBoolValue_rbus, UseXPKI_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.LnFUseXPKI.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {LnFUseXPKI_GetParamBoolValue_rbus, LnFUseXPKI_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.CrashUpload.S3SigningUrl", RBUS_ELEMENT_TYPE_PROPERTY, {CrashUpload_GetParamStringValue_rbus, CrashUpload_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MTLS.mTlsLogUpload.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {mTlsLogUpload_GetParamBoolValue_rbus, mTlsLogUpload_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.MTLS.mTlsCrashdumpUpload.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {mTlsCrashdumpUpload_GetParamBoolValue_rbus, mTlsCrashdumpUpload_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.NonRootSupport.ApparmorBlocklist", RBUS_ELEMENT_TYPE_PROPERTY, {NonRootSupport_GetParamStringValue_rbus, NonRootSupport_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.NonRootSupport.Blocklist", RBUS_ELEMENT_TYPE_PROPERTY, {NonRootSupport_GetParamStringValue_rbus, NonRootSupport_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AutoReboot.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {AutoReboot_GetParamBoolValue_rbus, AutoReboot_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.XHFW.Enable", RBUS_ELEMENT_TYPE_PROPERTY, {XHFW_GetParamBoolValue_rbus, XHFW_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_EthernetWAN.MACsec.OperationalStatus", RBUS_ELEMENT_TYPE_PROPERTY, {EthernetWAN_MACsec_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_xBlueTooth.LimitBeaconDetection", RBUS_ELEMENT_TYPE_PROPERTY, {xBlueTooth_GetParamBoolValue_rbus, xBlueTooth_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_MaintenanceWindow.FirmwareUpgradeStartTime", RBUS_ELEMENT_TYPE_PROPERTY, {MaintenanceWindow_GetParamStringValue_rbus, MaintenanceWindow_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        //{"Device.DeviceInfo.X_RDKCENTRAL-COM_MaintenanceWindow.FirmwareUpgradeEndTime", RBUS_ELEMENT_TYPE_PROPERTY, {MaintenanceWindow_GetParamStringValue_rbus, MaintenanceWindow_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.Iot.X_RDKCENTRAL-COM_ENABLEIOT", RBUS_ELEMENT_TYPE_PROPERTY, {Iot_GetParamBoolValue_rbus, Iot_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFile.{i}.", RBUS_ELEMENT_TYPE_TABLE, {NULL, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFile.{i}.Alias", RBUS_ELEMENT_TYPE_PROPERTY, {VendorConfigFile_GetParamStringValue_rbus, VendorConfigFile_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFile.{i}.Name", RBUS_ELEMENT_TYPE_PROPERTY, {VendorConfigFile_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFile.{i}.Version", RBUS_ELEMENT_TYPE_PROPERTY, {VendorConfigFile_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.VendorConfigFile.{i}.Description", RBUS_ELEMENT_TYPE_PROPERTY, {VendorConfigFile_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.MemoryStatus.Total", RBUS_ELEMENT_TYPE_PROPERTY, {MemoryStatus_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.MemoryStatus.Used", RBUS_ELEMENT_TYPE_PROPERTY, {MemoryStatus_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.MemoryStatus.Free", RBUS_ELEMENT_TYPE_PROPERTY, {MemoryStatus_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.MemoryStatus.X_RDKCENTRAL-COM_FreeMemThreshold", RBUS_ELEMENT_TYPE_PROPERTY, {MemoryStatus_GetParamUlongValue_rbus, MemoryStatus_SetParamUlongValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM.DhcpServDetectEnable", RBUS_ELEMENT_TYPE_PROPERTY, {X_RDKCENTRAL_COM_GetParamBoolValue_rbus, X_RDKCENTRAL_COM_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM.MultipleGW", RBUS_ELEMENT_TYPE_PROPERTY, {X_RDKCENTRAL_COM_GetParamBoolValue_rbus, X_RDKCENTRAL_COM_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM.InternetStatus", RBUS_ELEMENT_TYPE_PROPERTY, {X_RDKCENTRAL_COM_GetParamBoolValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM.Ops.UploadLogsNow", RBUS_ELEMENT_TYPE_PROPERTY, {Ops_GetParamBoolValue_rbus, Ops_SetParamBoolValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM.Ops.LogsUploadStatus", RBUS_ELEMENT_TYPE_PROPERTY, {Ops_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.ProcessNumberOfEntries", RBUS_ELEMENT_TYPE_PROPERTY, {ProcessStatus_GetEntryCount_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.", RBUS_ELEMENT_TYPE_TABLE, {NULL, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.PID", RBUS_ELEMENT_TYPE_PROPERTY, {Process_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.Size", RBUS_ELEMENT_TYPE_PROPERTY, {Process_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.CPUTime", RBUS_ELEMENT_TYPE_PROPERTY, {Process_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.State", RBUS_ELEMENT_TYPE_PROPERTY, {Process_GetParamUlongValue_rbus_mapped, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.ProcessStatus.Process.{i}.Command", RBUS_ELEMENT_TYPE_PROPERTY, {Process_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.NetworkProperties.MaxTCPWindowSize", RBUS_ELEMENT_TYPE_PROPERTY, {NetworkProperties_GetParamUlongValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.NetworkProperties.TCPImplementation", RBUS_ELEMENT_TYPE_PROPERTY, {NetworkProperties_GetParamStringValue_rbus, NULL, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_WIFI_TELEMETRY.NormalizedRssiList", RBUS_ELEMENT_TYPE_PROPERTY, {WiFi_Telemetry_GetParamStringValue_rbus, WiFi_Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_WIFI_TELEMETRY.CliStatList", RBUS_ELEMENT_TYPE_PROPERTY, {WiFi_Telemetry_GetParamStringValue_rbus, WiFi_Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_WIFI_TELEMETRY.TxRxRateList", RBUS_ELEMENT_TYPE_PROPERTY, {WiFi_Telemetry_GetParamStringValue_rbus, WiFi_Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}},
        {"Device.DeviceInfo.X_RDKCENTRAL-COM_WIFI_TELEMETRY.SNRList", RBUS_ELEMENT_TYPE_PROPERTY, {WiFi_Telemetry_GetParamStringValue_rbus, WiFi_Telemetry_SetParamStringValue_rbus, NULL, NULL, NULL, NULL}}
};

rbusError_t registerGeneratedDataElements(rbusHandle_t handle)
{
    rbusError_t rc;
    CcspTraceInfo(("Calling regsitering data elements\n"));

    rc = rbus_regDataElements(handle, 277, dataElements);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rtLog_Error("rbus_regDataElements failed");
    }
    CcspTraceInfo(("REgister Data Elements success\n"));
    return rc;
}

rbusError_t de_registerGeneratedDataElements(rbusHandle_t handle)
{
    rbusError_t rc;
    CcspTraceInfo(("Calling de_regsitering data elements\n"));
    rc = rbus_unregDataElements(handle, 277, dataElements);
    if(rc != RBUS_ERROR_SUCCESS)
    {
        rtLog_Error("rbus_unregDataElements failed");
    }
    CcspTraceInfo(("DEregistered success\n"));
    return rc;
}

rbusError_t rbus_helper_Table_registerRow(rbusHandle_t handle,CcspRbusHelper_t helperctxt)
{
    ULONG i = 0;
    int rc = RBUS_ERROR_SUCCESS;
    CcspTraceInfo(("Inside function registerRow for table %s\n", helperctxt.table_name));
    for (i=0; i < helperctxt.cb_TableGetEntryCount(NULL) ;i++)
    {
        ULONG uInstanceNumber = 0;
        CcspTraceInfo(("Inside for loop\n"));
        if (!helperctxt.tableentry_cb.cb_TableGetEntry(NULL,i,&uInstanceNumber)){
            CcspTraceInfo(("Inside for loop and inside if condition\n"));
            continue;
        }
        CcspTraceInfo(("Registring row:%ld\n",uInstanceNumber));
        rc = rbusTable_registerRow(handle,helperctxt.table_name ,uInstanceNumber,NULL);
        if(rc!= RBUS_ERROR_SUCCESS)
        {
            CcspTraceError(("\n%s %d - ProcStatus Table (%s) Add failed, Error=%d \n",
                             __FUNCTION__, __LINE__,helperctxt.table_name,rc));
        }
        else
        {
            CcspTraceInfo(("\n%s %d - ProcStatus Table (%s) Added Successfully\n",
                               __FUNCTION__, __LINE__, helperctxt.table_name));
        }
    }
    return rc;
}

rbusError_t rbus_helper_Table_unregisterRow(rbusHandle_t handle,CcspRbusHelper_t helperctxt)
{
    ULONG i = 0;
    int rc = RBUS_ERROR_SUCCESS;
    char param_name[512] = {0};
    CcspTraceInfo(("Inside function unregisterRow for table %s\n", helperctxt.table_name));
    for (i=0; i < helperctxt.cb_TableGetEntryCount(NULL) ;i++)
    {
        ULONG uInstanceNumber = 0;
        memset(param_name,0,sizeof(param_name));
        CcspTraceInfo(("Inside for loop\n"));
        if (!helperctxt.tableentry_cb.cb_TableGetEntry(NULL,i,&uInstanceNumber)){
            CcspTraceInfo(("Inside for loop and inside if condition\n"));
            continue;
        }
        snprintf(param_name,sizeof(param_name),"%s%ld",helperctxt.table_name,uInstanceNumber);

        rc = rbusTable_unregisterRow(handle,param_name);
        if(rc!= RBUS_ERROR_SUCCESS)
        {
            CcspTraceError(("\n%s %d - ProcStatus Table (%s) Remove failed, Error=%d \n",
                             __FUNCTION__, __LINE__,helperctxt.table_name,rc));
        }
        else
        {
            CcspTraceInfo(("\n%s %d - ProcStatus Table (%s) Removed Successfully\n",
                               __FUNCTION__, __LINE__, param_name));
        }
    }
    return rc;
}

