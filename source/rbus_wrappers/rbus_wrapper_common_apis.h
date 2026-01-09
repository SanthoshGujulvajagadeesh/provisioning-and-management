#ifndef RBUS_WRAPPER_COMMON_APIS_H
#define RBUS_WRAPPER_COMMON_APIS_H
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

#endif