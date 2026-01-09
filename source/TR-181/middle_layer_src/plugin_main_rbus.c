/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
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

/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/*********************************************************************** 
  
    module: plugin_main.c

        Implement COSA Data Model Library Init and Unload apis.
 
    ---------------------------------------------------------------

    author:

        COSA XML TOOL CODE GENERATOR 1.0

    ---------------------------------------------------------------

    revision:

        01/14/2011    initial revision.

**********************************************************************/
//balaji
#include "ansc_platform.h"
#include "ansc_load_library.h"
#include "cosa_plugin_api.h"
#include "plugin_main_rbus.h"
#include "plugin_main_apis.h"
#include "poam_irepfo_interface.h"
#include "poam_irepfo_exported_api.h"
#if 0
#include "cosa_com_cisco_spvtg_ccsp_pam_dml.h"
#include "cosa_deviceinfo_dml.h"
/*#include "cosa_softwaremodules_dml.h"*/
#include "cosa_gatewayinfo_dml.h"
#include "cosa_time_dml.h"
#include "cosa_userinterface_dml.h"
#include "cosa_interfacestack_dml.h"
#include "cosa_ethernet_dml.h"
//#include "cosa_moca_dml.h"
#include "cosa_ip_dml.h"
#include "cosa_routing_dml.h"
#include "cosa_hosts_dml.h"
#include "cosa_dns_dml.h"
#include "cosa_firewall_dml.h"
#include "cosa_nat_dml.h"
#include "cosa_dhcpv4_dml.h"
#include "cosa_dhcpv6_dml.h"
#include "cosa_users_dml.h"
#include "cosa_upnp_dml.h"
#include "cosa_bridging_dml.h"
#include "cosa_x_cisco_com_ddns_dml.h"
#include "cosa_x_cisco_com_security_dml.h"
/*#include "cosa_softwaremodules_config.h"*/
#include "cosa_ppp_dml.h"
#include "cosa_x_cisco_com_devicecontrol_dml.h"
#include "cosa_ipv6rd_dml.h"
#include "cosa_ra_dml.h"
#include "cosa_neighdisc_dml.h"
#include "cosa_x_cisco_com_mld_dml.h"
#endif
//#include "cosa_moca_internal.h"
#include "safec_lib_common.h"

void *dlhandle_users = NULL;
void *dlhandle_deviceinfo = NULL;
PCOSA_BACKEND_MANAGER_OBJECT g_pCosaBEManager;
void *                       g_pDslhDmlAgent;
extern ANSC_HANDLE     g_MessageBusHandle_Irep;
extern char            g_SubSysPrefix_Irep[32];
extern char                   g_Subsystem[32];
extern COSARepopulateTableProc            g_COSARepopulateTable;

int plugin_init_rbus(CCSP_MESSAGE_BUS_INFO *bus_info)
{
    ANSC_STATUS returnStatus = ANSC_STATUS_SUCCESS;
    PRBUS_DATAMODEL_AGENT_OBJECT pDmlAgent = NULL;
    errno_t                                 rc        = -1;
    pDmlAgent = (PRBUS_DATAMODEL_AGENT_OBJECT)AnscAllocateMemory(sizeof(RBUS_DATAMODEL_AGENT_OBJECT));
    memset(pDmlAgent,0,sizeof(RBUS_DATAMODEL_AGENT_OBJECT));
    
        PPOAM_IREP_FOLDER_OBJECT        pPoamIrepFoRoot        = (PPOAM_IREP_FOLDER_OBJECT   )NULL;
        PPOAM_IREP_FOLDER_OBJECT        pPoamIrepFoProvision   = (PPOAM_IREP_FOLDER_OBJECT   )NULL;
        PPOAM_IREP_FOLDER_OBJECT        pPoamIrepFoCOSA        = (PPOAM_IREP_FOLDER_OBJECT   )NULL;
        pPoamIrepFoRoot =
            (PPOAM_IREP_FOLDER_OBJECT)PoamIrepFoCreate(NULL, NULL, ""); 

        if ( !pPoamIrepFoRoot )
        {
            CcspTraceInfo(("DslhDataModelAgent: Cannot access Root Folder!!\n"));

            returnStatus = ANSC_STATUS_FAILURE;

            goto  EXIT2;
        }

        pPoamIrepFoProvision =
            (PPOAM_IREP_FOLDER_OBJECT)pPoamIrepFoRoot->GetFolder
                (
                    (ANSC_HANDLE)pPoamIrepFoRoot,
                    "Provision"
                );

        if ( !pPoamIrepFoProvision )
        {
            CcspTraceInfo(("DslhDataModelAgent: Cannot access /Configuration/Provision folder!!\n"));

            returnStatus = ANSC_STATUS_FAILURE;

            goto  EXIT3;
        }

        pPoamIrepFoCOSA =
            (PPOAM_IREP_FOLDER_OBJECT)pPoamIrepFoProvision->GetFolder
                (
                    (ANSC_HANDLE)pPoamIrepFoProvision,
                    COSA_IREP_FOLDER_NAME
                );

        if ( !pPoamIrepFoCOSA )
        {
            pPoamIrepFoCOSA =
                pPoamIrepFoProvision->AddFolder
                    (
                        (ANSC_HANDLE)pPoamIrepFoProvision,
                        COSA_IREP_FOLDER_NAME,
                        0
                    );
        }

        if ( !pPoamIrepFoCOSA )
        {
            CcspTraceInfo(("DslhDataModelAgent: Cannot access /Configuration/Provision/%s folder!!\n", COSA_IREP_FOLDER_NAME));

            returnStatus = ANSC_STATUS_FAILURE;

            goto  EXIT4;
        }
        else
        {
            pDmlAgent->hIrepFolderCOSA = (ANSC_HANDLE)pPoamIrepFoCOSA;
        }

	pDmlAgent->bActive = TRUE;
	pDmlAgent->rbus_handle = bus_info->rbus_handle;

        returnStatus = ANSC_STATUS_SUCCESS;

	g_pDslhDmlAgent = pDmlAgent;
	g_MessageBusHandle_Irep = bus_info;
	g_MessageBusHandle = bus_info;
	rc = STRCPY_S_NOCLOBBER(g_SubSysPrefix_Irep, sizeof(g_SubSysPrefix_Irep), g_Subsystem);
	ERR_CHK(rc);

	g_pCosaBEManager = (PCOSA_BACKEND_MANAGER_OBJECT)CosaBackEndManagerCreate();

/*	
	if ( g_pCosaBEManager && g_pCosaBEManager->Initialize )
        {
           // g_pCosaBEManager->hCosaPluginInfo = pPlugInfo;

            g_pCosaBEManager->Initialize   ((ANSC_HANDLE)g_pCosaBEManager);
        }
*/

EXIT4:

    if ( pPoamIrepFoProvision )
    {
        pPoamIrepFoProvision->Remove((ANSC_HANDLE)pPoamIrepFoProvision);
    }

EXIT3:

    if ( pPoamIrepFoRoot )
    {
        pPoamIrepFoRoot->Remove((ANSC_HANDLE)pPoamIrepFoRoot);
    }

EXIT2:

    return  returnStatus;

}

rbusError_t dm_init_users_rbus(rbusHandle_t rbusHandle);

int plugin_rbus_handle_event(rbusHandle_t rbus_handle)
{
    rbusError_t (*dm_init_users_rbus)(rbusHandle_t);
    ANSC_HANDLE (*dm_create_users)();
    dlhandle_users = dlopen("/usr/lib/libtr181_users.so",RTLD_GLOBAL|RTLD_NOW);
    //dlhandle = dlopen("/var/tmp/libtr181_users.so",RTLD_GLOBAL|RTLD_NOW);
    if (dlhandle_users == NULL)
            CcspTraceError(("dlopen failed for tr181_users :%s\n",dlerror()));


    CcspTraceInfo(("Entering init users rbus\n"));
    dm_init_users_rbus = dlsym(dlhandle_users, "dm_init_users_rbus");
    if (dm_init_users_rbus)
    {
       CcspTraceInfo(("DM init Users rbus\n"));
       dm_init_users_rbus(rbus_handle);
    }

    CcspTraceInfo(("Entering users create\n"));
    dm_create_users = dlsym(dlhandle_users, "CosaUsersCreate");

    if (dm_create_users)
    {
       CcspTraceInfo(("dm_create_users\n"));
       g_pCosaBEManager->hUsers = (ANSC_HANDLE)dm_create_users();
    }


    return ANSC_STATUS_SUCCESS;
}

int plugin_rbus_handle_event_unload(rbusHandle_t rbus_handle)
{
    rbusError_t (*dm_de_init_users_rbus)(rbusHandle_t);
    ANSC_STATUS (*dm_remove_users)(ANSC_HANDLE);


    CcspTraceInfo(("Entering de_init users rbus\n"));
    dm_de_init_users_rbus = dlsym(dlhandle_users, "dm_de_init_users_rbus");
    if (dm_de_init_users_rbus)
    {
       CcspTraceInfo(("DM de_init Users rbus\n"));
       dm_de_init_users_rbus(rbus_handle);
    }

    CcspTraceInfo(("Entering users remove\n"));
    dm_remove_users = dlsym(dlhandle_users, "CosaUsersRemove");

    if (dm_remove_users)
    {
       CcspTraceInfo(("dm_remove_users\n"));
       dm_remove_users(g_pCosaBEManager->hUsers);
    }

    if (dlclose(dlhandle_users) != 0) {
        CcspTraceError(("dlclose failed for tr181_users :%s\n",dlerror()));
        return 1;
    }
    CcspTraceInfo(("Users Unloaded successfully...\n"));
    return ANSC_STATUS_SUCCESS;
}

rbusError_t dm_init_deviceinfo_rbus(rbusHandle_t rbusHandle);

int plugin_deviceinfo_handle_event(rbusHandle_t rbus_handle)
{
    rbusError_t (*dm_init_deviceinfo_rbus)(rbusHandle_t);
    ANSC_HANDLE (*dm_create_deviceinfo)();
    ANSC_HANDLE (*dm_create_onboardlogging)();
    ANSC_HANDLE (*dm_create_ProcStatus)();
    dlhandle_deviceinfo = dlopen("/usr/lib/libtr181_deviceinfo.so",RTLD_LAZY);
    //dlhandle = dlopen("/var/tmp/libtr181_users.so",RTLD_GLOBAL|RTLD_NOW);
    if (dlhandle_deviceinfo == NULL)
            CcspTraceError(("dlopen failed for tr181_deviceinfo :%s\n",dlerror()));


    CcspTraceInfo(("Entering init deviceinfo rbus\n"));
    dm_init_deviceinfo_rbus = dlsym(dlhandle_deviceinfo, "dm_init_deviceinfo_rbus");
    if (dm_init_deviceinfo_rbus)
    {
       CcspTraceInfo(("DM init deviceinfo rbus\n"));
       dm_init_deviceinfo_rbus(rbus_handle);
    }

    CcspTraceInfo(("Entering deviceinfo create\n"));
    dm_create_deviceinfo = dlsym(dlhandle_deviceinfo, "CosaDeviceInfoCreate");

    if (dm_create_deviceinfo)
    {
       CcspTraceInfo(("dm_create_deviceinfo\n"));
       g_pCosaBEManager->hDeviceInfo = (ANSC_HANDLE)dm_create_deviceinfo();
    }

    CcspTraceInfo(("Entering onboardlogging create\n"));
    dm_create_onboardlogging = dlsym(dlhandle_deviceinfo, "CosaOnboardLoggingCreate");

    if (dm_create_onboardlogging)
    {
       CcspTraceInfo(("dm_create_onboardlogging\n"));
       g_pCosaBEManager->hOnboardLogging = (ANSC_HANDLE)dm_create_onboardlogging();
    }

    CcspTraceInfo(("Entering CosaProcStatus create\n"));
    dm_create_ProcStatus = dlsym(dlhandle_deviceinfo, "CosaProcStatusCreate");

    if (dm_create_ProcStatus)
    {
       CcspTraceInfo(("dm_create_ProcStatus\n"));
       g_pCosaBEManager->hProcStatus = (ANSC_HANDLE)dm_create_ProcStatus();
    }

    return ANSC_STATUS_SUCCESS;
}

int plugin_deviceinfo_handle_event_unload(rbusHandle_t rbus_handle)
{
    rbusError_t (*dm_de_init_deviceinfo_rbus)(rbusHandle_t);
    ANSC_STATUS (*dm_remove_deviceinfo)(ANSC_HANDLE);
    ANSC_STATUS (*dm_remove_ProcStatus)(ANSC_HANDLE);


    CcspTraceInfo(("Entering de_init deviceinfo rbus\n"));
    dm_de_init_deviceinfo_rbus = dlsym(dlhandle_deviceinfo, "dm_de_init_deviceinfo_rbus");
    if (dm_de_init_deviceinfo_rbus)
    {
       CcspTraceInfo(("DM de_init deviceinfo rbus\n"));
       dm_de_init_deviceinfo_rbus(rbus_handle);
    }

    CcspTraceInfo(("Entering deviceinfo remove\n"));
    dm_remove_deviceinfo = dlsym(dlhandle_deviceinfo, "CosaDeviceInfoRemove");

    if (dm_remove_deviceinfo)
    {
       CcspTraceInfo(("dm_remove_deviceinfo\n"));
       dm_remove_deviceinfo(g_pCosaBEManager->hDeviceInfo);
    }

    CcspTraceInfo(("Entering ProcStatus remove\n"));
    dm_remove_ProcStatus = dlsym(dlhandle_deviceinfo, "COSADmlRemoveProcessInfo");

    if (dm_remove_ProcStatus)
    {
       CcspTraceInfo(("dm_remove_ProcStatus\n"));
       dm_remove_ProcStatus(g_pCosaBEManager->hProcStatus);
    }

    if (dlclose(dlhandle_deviceinfo) != 0) {
        CcspTraceError(("dlclose failed for tr181_deviceinfo :%s\n",dlerror()));
        return 1;
    }
    CcspTraceInfo(("deviceinfo Unloaded successfully...\n"));
    return ANSC_STATUS_SUCCESS;
}

#if 0
g_pDslhDmlAgent                 = pPlugInfo->hDmlAgent;

g_GetParamValueByPathNameProc = pGetParamValueByPathNameProc;   
g_SetParamValueByPathNameProc = pSetParamValueByPathNameProc;   
g_GetParamValueString = pGetStringProc;   
g_GetParamValueUlong = pGetParamValueUlongProc;   

        g_GetParamValueInt = pGetParamValueIntProc;   
        g_GetParamValueBool = pGetParamValueBoolProc;   
        g_SetParamValueString = pSetStringProc;   
        g_SetParamValueUlong = pSetParamValueUlongProc;   
        g_SetParamValueInt = pSetParamValueIntProc;   
        g_SetParamValueBool = pSetParamValueBoolProc;   


        g_ValidateInterface = pValInterfaceProc;

        g_GetRegistryRootFolder = pGetRegistryRootFolder;

        g_GetInstanceNumberByIndex = pGetInsNumberByIndexProc;
        g_GetInterfaceByName = pGetInterfaceByNameProc;



    g_MessageBusHandle = (ANSC_HANDLE)g_GetMessageBusHandle(g_pDslhDmlAgent);
    g_MessageBusHandle_Irep = g_MessageBusHandle;
    
    /* Get Subsystem prefix */
    g_GetSubsystemPrefix = (COSAGetSubsystemPrefixProc)pPlugInfo->AcquireFunction("COSAGetSubsystemPrefix");
    if ( g_GetSubsystemPrefix != NULL )
    {
        /* retrieve the subsystem prefix */
        g_SubsystemPrefix = g_GetSubsystemPrefix(g_pDslhDmlAgent);
        if (g_SubsystemPrefix) {
            rc = STRCPY_S_NOCLOBBER(g_SubSysPrefix_Irep, sizeof(g_SubSysPrefix_Irep), g_SubsystemPrefix);
            ERR_CHK(rc);
        }
    }

    /* Create backend framework */
    g_pCosaBEManager = (PCOSA_BACKEND_MANAGER_OBJECT)CosaBackEndManagerCreate();

    if ( g_pCosaBEManager && g_pCosaBEManager->Initialize )
    {
        g_pCosaBEManager->hCosaPluginInfo = pPlugInfo;

        g_pCosaBEManager->Initialize   ((ANSC_HANDLE)g_pCosaBEManager);
    }
    



void ANSC_EXPORT_API
COSA_Unload
    (
        void
    )
{
    ANSC_STATUS                     returnStatus            = ANSC_STATUS_SUCCESS;

    /* unload the memory here */

    returnStatus  =  CosaBackEndManagerRemove(g_pCosaBEManager);
        
    if ( returnStatus == ANSC_STATUS_SUCCESS )
    {
        g_pCosaBEManager = NULL;
    }
    else
    {
        /* print error trace*/
        g_pCosaBEManager = NULL;
    }
}
#endif
