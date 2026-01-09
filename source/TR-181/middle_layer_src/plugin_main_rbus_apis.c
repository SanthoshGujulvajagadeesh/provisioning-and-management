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
  
    module: plugin_main_apis.c

        Implement COSA Data Model Library Init and Unload apis.
        This files will hold all data in it.
 
    ---------------------------------------------------------------

    description:

        This module implements the advanced state-access functions
        of the Dslh Var Record Object.

        *   CosaBackEndManagerCreate
        *   CosaBackEndManagerInitialize
        *   CosaBackEndManagerRemove
    ---------------------------------------------------------------

    author:

        COSA XML TOOL CODE GENERATOR 1.0

    ---------------------------------------------------------------

    revision:

        01/11/2011    initial revision.

**********************************************************************/
#include <syscfg/syscfg.h>
#include "dml_tr181_custom_cfg.h"
#include "plugin_main_apis.h"
#include "cosa_ethernet_apis.h"
//#include "cosa_moca_apis.h"
#include "cosa_time_apis.h"
#include "cosa_userinterface_apis.h"
#include "cosa_nat_apis.h"
#include "cosa_dhcpv4_apis.h"
#include "cosa_users_apis.h"
#include "cosa_deviceinfo_apis.h"
#include "cosa_firewall_internal.h"
#if !defined(DDNS_BROADBANDFORUM)
#include "cosa_x_cisco_com_ddns_internal.h"
#endif
#include "cosa_x_cisco_com_security_internal.h"
#include "cosa_ip_apis.h"
#include "cosa_hosts_apis.h"
#include "cosa_routing_apis.h"
#include "cosa_nat_internal.h"
#include "cosa_dhcpv4_internal.h"
#include "cosa_users_internal.h"
#include "cosa_ip_internal.h"
#include "cosa_hosts_internal.h"
#include "cosa_dns_internal.h"
#include "cosa_routing_internal.h"
#include "cosa_deviceinfo_internal.h"
#include "cosa_ethernet_internal.h"
//#include "cosa_moca_internal.h"
#include "cosa_time_internal.h"
#include "cosa_userinterface_internal.h"
#include "cosa_ppp_internal.h"
#include "cosa_bridging_internal.h"
#include "cosa_upnp_internal.h"
#include "cosa_interfacestack_internal.h"
/*#include "cosa_diagnostic_apis.h"*/
#include "cosa_x_cisco_com_devicecontrol_internal.h"
#include "cosa_ipv6rd_internal.h"
#include "cosa_x_cisco_com_mld_internal.h"
#include "cosa_x_cisco_com_multilan_apis.h"
#if defined(DDNS_BROADBANDFORUM)
#include "cosa_dynamicdns_apis.h"
#include "cosa_dynamicdns_internal.h"
#endif

#include "cosa_ra_internal.h"
#include "cosa_x_rdkcentral_com_xpc_internal.h"
#include "cosa_onboardlogging_internal.h"
#include "cosa_x_cisco_com_diagnostics_internal.h"
#include "cosa_lanmanagement_internal.h"
#include "cosa_x_comcast_com_parentalcontrol_internal.h"
#include "cosa_x_cisco_com_rlog_internal.h"
#include "cosa_x_cisco_com_hotspot_internal.h"
#ifndef NO_WIFI_FEATURE_SUPPORT
/*#include "libHotspotApi.h" */
#endif
#include <telemetry_busmessage_sender.h>

#ifdef DSLITE_FEATURE_SUPPORT
#include "cosa_dslite_apis.h"
#include "cosa_dslite_internal.h"
#endif
#if CONFIG_CISCO_TRUE_STATIC_IP
    #include "cosa_x_cisco_com_truestaticip_internal.h"
#endif
#if CONFIG_CISCO_FILE_TRANSFER
    #include "cosa_x_cisco_com_filetransfer_internal.h"
#endif
#if  CFG_USE_Common_Util
#include "cosa_common_util.h"
#endif

#if  defined  (WAN_FAILOVER_SUPPORTED) || defined(RDKB_EXTENDER_ENABLED) ||  defined(RBUS_BUILD_FLAG_ENABLE) || defined (_HUB4_PRODUCT_REQ_) || defined (_PLATFORM_RASPBERRYPI_)
#include "cosa_rbus_handler_apis.h"
#endif
#if defined (WIFI_MANAGE_SUPPORTED)
#include "cosa_managedwifi_webconfig_apis.h"
#endif /*WIFI_MANAGE_SUPPORTED*/

#include "plugin_main_rbus.h"

//static void CheckAndSetRebootReason();

#if defined(_PLATFORM_RASPBERRYPI_)
extern int sock;
#endif

#if defined (INTEL_PUMA7)
ANSC_HANDLE CosaGRECreate(VOID);
ANSC_STATUS CosaGRERemove(ANSC_HANDLE hThisObject);
#endif

#if 0
/*PCOSA_DIAG_PLUGIN_INFO             g_pCosaDiagPluginInfo;*/
COSAGetParamValueStringProc        g_GetParamValueString;
COSAGetParamValueUlongProc         g_GetParamValueUlong;
COSAGetParamValueIntProc           g_GetParamValueInt;
COSAGetParamValueBoolProc          g_GetParamValueBool;
COSASetParamValueStringProc        g_SetParamValueString;
COSASetParamValueUlongProc         g_SetParamValueUlong;
COSASetParamValueIntProc           g_SetParamValueInt;
COSASetParamValueBoolProc          g_SetParamValueBool;
COSAGetInstanceNumbersProc         g_GetInstanceNumbers;

COSAValidateHierarchyInterfaceProc g_ValidateInterface;
COSAGetInterfaceByNameProc         g_GetInterfaceByName;
COSAGetHandleProc                  g_GetMessageBusHandle;
PCCSP_CCD_INTERFACE                g_pPnmCcdIf;
COSARegisterCallBackAfterInitDmlProc  g_RegisterCallBackAfterInitDml;
COSARepopulateTableProc            g_COSARepopulateTable;
#endif

COSAGetHandleProc                  g_GetRegistryRootFolder;
COSAGetSubsystemPrefixProc         g_GetSubsystemPrefix;
ANSC_HANDLE                        g_MessageBusHandle;
char*                              g_SubsystemPrefix;
extern char 			   g_Subsystem[32];
COSAGetParamValueStringProc        g_GetParamValueString;
COSAGetParamValueUlongProc         g_GetParamValueUlong;
COSAGetParamValueIntProc           g_GetParamValueInt;
COSAGetParamValueBoolProc          g_GetParamValueBool;
COSASetParamValueStringProc        g_SetParamValueString;
COSASetParamValueUlongProc         g_SetParamValueUlong;
COSASetParamValueIntProc           g_SetParamValueInt;
COSASetParamValueBoolProc          g_SetParamValueBool;
COSAGetInstanceNumbersProc         g_GetInstanceNumbers;
COSAGetInstanceNumberByIndexProc   g_GetInstanceNumberByIndex;
COSAGetParamValueByPathNameProc    g_GetParamValueByPathNameProc;
COSASetParamValueByPathNameProc    g_SetParamValueByPathNameProc;

ANSC_HANDLE CosaDhcpv6Create(VOID);
ANSC_STATUS CosaDhcpv6Remove(ANSC_HANDLE hThisObject);
ANSC_HANDLE CosaNeighdiscCreate(VOID);
ANSC_STATUS CosaNeighdiscRemove(ANSC_HANDLE hThisObject);
ANSC_HANDLE CosaGreTunnelCreate ();
ANSC_HANDLE CosaCGreCreate(VOID);
ANSC_STATUS CosaCGreRemove(ANSC_HANDLE hThisObject);
ANSC_STATUS CosaGreTunnelRemove( ANSC_HANDLE hThisObject );
ANSC_HANDLE CosaGreCreate(VOID);
ANSC_STATUS CosaGreRemove(ANSC_HANDLE hThisObject);
void initparodusTask();
//static void SetAutoreboot( ANSC_HANDLE  hThisObject);
void *GetRegistryRootFolder(void *hDmlAgent);

/**********************************************************************

    caller:     owner of the object

    prototype:

        ANSC_HANDLE
        CosaBackEndManagerCreate
            (
            );

    description:

        This function constructs cosa datamodel object and return handle.

    argument:  

    return:     newly created nat object.

**********************************************************************/

ANSC_HANDLE
CosaBackEndManagerCreate
    (
        VOID
    )
{
    PCOSA_BACKEND_MANAGER_OBJECT    pMyObject    = (PCOSA_BACKEND_MANAGER_OBJECT)NULL;

    /*
        * We create object by first allocating memory for holding the variables and member functions.
        */
    pMyObject = (PCOSA_BACKEND_MANAGER_OBJECT)AnscAllocateMemory(sizeof(COSA_BACKEND_MANAGER_OBJECT));

    if ( !pMyObject )
    {
        return  (ANSC_HANDLE)NULL;
    }

    /*
     * Initialize the common variables and functions for a container object.
     */
    pMyObject->Oid               = COSA_DATAMODEL_BASE_OID;
    pMyObject->Create            = CosaBackEndManagerCreate;
    pMyObject->Remove            = CosaBackEndManagerRemove;
    pMyObject->Initialize        = CosaBackEndManagerInitialize;
printf("-- %s %d\n", __func__, __LINE__);
    CcspTraceWarning(("RDKB_SYSTEM_BOOT_UP_LOG : Entering %s %d\n", __func__, __LINE__));
    /*pMyObject->Initialize   ((ANSC_HANDLE)pMyObject);*/

    return  (ANSC_HANDLE)pMyObject;
}

/**********************************************************************

    caller:     self

    prototype:

        ANSC_STATUS
        CosaBackEndManagerInitialize
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function initiate cosa manager object and return handle.

    argument:   ANSC_HANDLE                 hThisObject
            This handle is actually the pointer of this object
            itself.

    return:     operation status.

**********************************************************************/

ANSC_STATUS
CosaBackEndManagerInitialize
    (
        ANSC_HANDLE                 hThisObject
    )
{
 
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PCOSA_BACKEND_MANAGER_OBJECT  pMyObject    = (PCOSA_BACKEND_MANAGER_OBJECT)hThisObject;
#if defined(_PLATFORM_RASPBERRYPI_)
	int id=0;
	id=getuid();
#endif
#ifdef _COSA_SIM_
        pMyObject->has_moca_slap  = 0;
#endif

    AnscTraceWarning(("%s...\n", __FUNCTION__));
    CcspTraceWarning(("RDKB_SYSTEM_BOOT_UP_LOG : PandM DM initialize...\n"));
    if (pMyObject)
        printf("PandM DM initialize...\n");

    /* Create all object */
#if 0
    pMyObject->hNat           = (ANSC_HANDLE)CosaNatCreate();
    AnscTraceWarning(("  CosaNatCreate done!\n"));
    pMyObject->hProcStatus    = (ANSC_HANDLE)CosaProcStatusCreate();    
    AnscTraceWarning(("  CosaProcStatusCreate done!\n"));

    pMyObject->hDeviceInfo    = (ANSC_HANDLE)CosaDeviceInfoCreate();
    AnscTraceWarning(("  CosaDeviceInfoCreate done!\n"));
#endif

    
   // pMyObject->hUsers         = (ANSC_HANDLE)CosaUsersCreate();
   // AnscTraceWarning(("  CosaUsersCreate done!\n"));
#if 0
    pMyObject->hUserinterface = (ANSC_HANDLE)CosaUserinterfaceCreate();
    AnscTraceWarning(("  CosaUserinterfaceCreate done!\n"));
    pMyObject->hEthernet      = (ANSC_HANDLE)CosaEthernetCreate();
    AnscTraceWarning(("  CosaEthernetCreate done!\n"));

#if !defined(DDNS_BROADBANDFORUM)
    pMyObject->hDdns          = (ANSC_HANDLE)CosaDdnsCreate();
    AnscTraceWarning(("  CosaDdnsCreate done!\n"));
#endif
#if defined(DDNS_BROADBANDFORUM)
   pMyObject->hDynamicDns    = (ANSC_HANDLE)CosaDynamicDnsCreate();
    AnscTraceWarning(("  CosaDynamicDnsCreate done!\n"));
#endif
    pMyObject->hFirewall      = (ANSC_HANDLE)CosaFirewallCreate();
    AnscTraceWarning(("  CosaFirewallCreate done!\n"));
    pMyObject->hSecurity      = (ANSC_HANDLE)CosaSecurityCreate();
    AnscTraceWarning(("  CosaSecurityCreate done!\n"));
    pMyObject->hIP            = (ANSC_HANDLE)CosaIPCreate();
    AnscTraceWarning(("  CosaIPCreate done!\n"));
#ifdef FEATURE_RDKB_DHCP_MANAGER
    AnscTraceWarning(("  CosaDhcpv4Create not done will be created from dhcp manager!\n"));
#else
    pMyObject->hDhcpv4        = (ANSC_HANDLE)CosaDhcpv4Create();
    AnscTraceWarning(("  CosaDhcpv4Create done!\n"));
#endif
    pMyObject->hHosts         = (ANSC_HANDLE)CosaHostsCreate();
    AnscTraceWarning(("  CosaHostsCreate done!\n"));
    pMyObject->hDNS           = (ANSC_HANDLE)CosaDNSCreate();
    AnscTraceWarning(("  CosaDNSCreate done!\n"));
    pMyObject->hRouting       = (ANSC_HANDLE)CosaRoutingCreate();
    AnscTraceWarning(("  CosaRoutingCreate done!\n"));
    pMyObject->hBridging      = (ANSC_HANDLE)CosaBridgingCreate();
    AnscTraceWarning(("  CosaBridgingCreate done!\n"));
    pMyObject->hInterfaceStack = (ANSC_HANDLE)CosaIFStackCreate();
    AnscTraceWarning(("  CosaIFStackCreate done!\n"));
#ifndef FEATURE_RDKB_XDSL_PPP_MANAGER
    pMyObject->hPPP           = (ANSC_HANDLE)CosaPPPCreate();
    AnscTraceWarning(("  CosaPPPCreate done!\n"));
#endif

#ifdef FEATURE_RDKB_DHCP_MANAGER
    AnscTraceWarning(("  CosaDhcpv6Create not done will be created from dhcp manager!\n"));
#else
    pMyObject->hDhcpv6        = (ANSC_HANDLE)CosaDhcpv6Create();
    AnscTraceWarning(("  CosaDhcpv6Create done!\n"));
#endif
    pMyObject->hDeviceControl  = (ANSC_HANDLE)CosaDeviceControlCreate();
    AnscTraceWarning(("  CosaDeviceControlCreate done!\n"));
    pMyObject->hIPv6rd        = (ANSC_HANDLE)CosaIPv6rdCreate();
    AnscTraceWarning(("  CosaIPv6rdCreate done!\n"));
    pMyObject->hRA            = (ANSC_HANDLE)CosaRACreate();
    AnscTraceWarning(("  CosaRACreate done!\n"));
#ifdef DSLITE_FEATURE_SUPPORT
    pMyObject->hDslite         = (ANSC_HANDLE)CosaDsliteCreate();
    AnscTraceWarning(("  CosaDsliteCreate done!\n"));
#endif
    pMyObject->hNeighdisc     = (ANSC_HANDLE)CosaNeighdiscCreate();
    AnscTraceWarning(("  CosaNeighdiscCreate done!\n"));
    pMyObject->hMld           = (ANSC_HANDLE)CosaMldCreate();
    AnscTraceWarning(("  CosaMldCreate done!\n"));

    /*
#ifdef CONFIG_TI_PACM
    pMyObject->hMTA           = (ANSC_HANDLE)CosaMTACreate();
    AnscTraceWarning(("  CosaMTACreate done!\n"));
#endif
    */

    returnStatus = CosaDmlMlanInit((ANSC_HANDLE)pMyObject, &pMyObject->hMultiLan);
    AnscTraceWarning(("  CosaDmlMlanInit -- status %lu!\n", returnStatus));
#endif

#if !defined(INTEL_PUMA7) && !defined(_COSA_BCM_MIPS_) && !defined(_COSA_BCM_ARM_) && !defined(_PLATFORM_TURRIS_)
    printf("pnm-status is renamed to bring-lan and set in PSM for XB3\n");
#else
   printf("**************** sysevent set pnm-status up \n");
   fflush(stdout);

#if defined(_PLATFORM_RASPBERRYPI_)
if(id != 0)
{
    char *lxcevt = "sysevent set pnm-status up";
    printf("Sending  lxc event ............ \n");
    send(sock , lxcevt , strlen(lxcevt) , 0 );
}
#endif
#if !defined(LAN_MANAGER_SUPPORTED)   
    system("sysevent set pnm-status up");
#endif
#endif

#if 0
    pMyObject->hDiag          = (ANSC_HANDLE)CosaDiagnosticsCreate();
    AnscTraceWarning(("  CosaDiagnosticsCreate done!\n"));
    pMyObject->hTime          = (ANSC_HANDLE)CosaTimeCreate();
    AnscTraceWarning(("  CosaTimeCreate done!\n"));
#if defined(CUSTOM_ULA)     
    pMyObject->hLanMngm          = (ANSC_HANDLE)CosaLanManagementCreate();
#endif
    AnscTraceWarning(("  CosaLanManagementCreate done!\n"));
#if !defined(_PLATFORM_IPQ_)
    //pMyObject->hMoCA          = (ANSC_HANDLE)CosaMoCACreate();
    //AnscTraceWarning(("  CosaMoCACreate done!\n"));
    pMyObject->hUpnp          = (ANSC_HANDLE)CosaUpnpCreate();
    AnscTraceWarning(("  CosaUpnpCreate done!\n"));

    pMyObject->hParentalControl = (ANSC_HANDLE)TR181_ParentalControlCreate();
    AnscTraceWarning(("  CosaParentalControlCreate done - hParentalControl = 0x%p!\n", pMyObject->hParentalControl));
#endif
    pMyObject->hRLog          = (ANSC_HANDLE)CosaRLogCreate();
    AnscTraceWarning(("  CosaRLogCreate done!\n"));

#if  defined  (WAN_FAILOVER_SUPPORTED) || defined(RDKB_EXTENDER_ENABLED) ||  defined(RBUS_BUILD_FLAG_ENABLE) || defined (_HUB4_PRODUCT_REQ_) || defined (_PLATFORM_RASPBERRYPI_)
    // Device Control Networking Mode init
    devCtrlRbusInit();
#endif

#if !defined(HOTSPOT_DISABLE)
//#ifdef CONFIG_CISCO_HOTSPOT
	
    pMyObject->hGRE           = (ANSC_HANDLE)CosaGreCreate();
    AnscTraceWarning(("  CosaGreCreate done!\n"));
	//zqiu>>
	printf("-- %s %d CosaGreTunnelCreate\n", __func__, __LINE__);
    pMyObject->hTGRE       = (ANSC_HANDLE)CosaGreTunnelCreate();
    AnscTraceWarning(("  CosaGreTunnelCreate done!\n"));	
   // register_callbackHotspot(callbackWCConfirmVap);
	//zqiu<<
    pMyObject->hCGRE           = (ANSC_HANDLE)CosaCGreCreate();
    AnscTraceWarning(("  CosaCGreCreate done!\n"));
    pMyObject->hHotspot       = (ANSC_HANDLE)CosaHotspotCreate();
    AnscTraceWarning(("  CosaHotspotCreate done!\n"));
	
//#endif
#endif
#if CONFIG_CISCO_FILE_TRANSFER
    pMyObject->hFileTransfer  = (ANSC_HANDLE)CosaFileTransferCreate();
    AnscTraceWarning(("  CosaFileTransferCreate done!\n"));
#endif

#if CONFIG_CISCO_TRUE_STATIC_IP
    pMyObject->hTSIP          = (ANSC_HANDLE)CosaTSIPCreate();
    AnscTraceWarning(("  CosaTSIPCreate done!\n"));
#endif
    

#if CFG_USE_Event_Displatch

    /*create a thread to handle the sysevent asynchronously after all of the dmls created
     *
     * when a specified event trigger, the related functions which are registered previously
     * will run step by step.
     */
    EvtDispterHandleEventAsync();
#endif



#ifdef FEATURE_SUPPORT_ONBOARD_LOGGING
    pMyObject->hXpc         = (ANSC_HANDLE)CosaXpcCreate();
    AnscTraceWarning(("  CosaXpcCreate done!\n"));

    pMyObject->hOnboardLogging         = (ANSC_HANDLE)CosaOnboardLoggingCreate();
    AnscTraceWarning(("  CosaOnboardLoggingCreate done!\n"));
#endif

    AnscTraceWarning(("  Initializing WebConfig Framework!\n"));
 
    webConfigFrameworkInit();
    
    AnscTraceWarning(("  Initializing WebConfig Framework done!\n"));


    printf("PandM DM initialization done!\n");
    CcspTraceWarning(("RDKB_SYSTEM_BOOT_UP_LOG : PandM DM initialization done!\n"));
    //Unknown Reboot Reason 
    
    CheckAndSetRebootReason();

    printf("Calling PARODUS!\n");
    CcspTraceWarning(("RDKB_SYSTEM_BOOT_UP_LOG : PARODUS call!\n")); 
    initparodusTask();
    SetAutoreboot((ANSC_HANDLE)pMyObject->hDeviceInfo);
#if defined (WIFI_MANAGE_SUPPORTED)
    initManageWiFiBacupStruct();
#endif /*WIFI_MANAGE_SUPPORTED*/
#endif

    return returnStatus;
}

/**********************************************************************

    caller:     self

    prototype:

        ANSC_STATUS
        CosaBackEndManagerRemove
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function remove cosa manager object and return handle.

    argument:   ANSC_HANDLE                 hThisObject
            This handle is actually the pointer of this object
            itself.

    return:     operation status.

**********************************************************************/

ANSC_STATUS
CosaBackEndManagerRemove
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PCOSA_BACKEND_MANAGER_OBJECT  pMyObject    = (PCOSA_BACKEND_MANAGER_OBJECT)hThisObject;

#if 0
    /* Remove all objects */
    if ( pMyObject->hMultiLan )
    {
        CosaDmlMlanUnload(pMyObject->hMultiLan);
    }

    if ( pMyObject->hNat )
    {
        CosaNatRemove((ANSC_HANDLE)pMyObject->hNat);
    }

    if ( pMyObject->hDiag )
    {
        CosaDiagnosticsRemove((ANSC_HANDLE)pMyObject->hDiag);
    }

    if ( pMyObject->hDeviceInfo )
    {
        CosaDeviceInfoRemove((ANSC_HANDLE)pMyObject->hDeviceInfo);
    }
    
    if ( pMyObject->hTime )
    {
        CosaTimeRemove((ANSC_HANDLE)pMyObject->hTime);
    }

#if defined(CUSTOM_ULA)
    if ( pMyObject->hLanMngm )
    {
        CosaLanManagementRemove((ANSC_HANDLE)pMyObject->hLanMngm);
    }
#endif

    if ( pMyObject->hUserinterface )
    {
        CosaUserinterfaceRemove((ANSC_HANDLE)pMyObject->hUserinterface);
    }

    if ( pMyObject->hEthernet )
    {
        CosaEthernetRemove((ANSC_HANDLE)pMyObject->hEthernet);
    }
/*
    if ( pMyObject->hMoCA )
    {
        CosaMoCARemove((ANSC_HANDLE)pMyObject->hMoCA);
    }
*/
    if ( pMyObject->hDhcpv4 )
    {
        CosaDhcpv4Remove((ANSC_HANDLE)pMyObject->hDhcpv4);
    }

    if ( pMyObject->hDhcpv6 )
    {
        CosaDhcpv6Remove((ANSC_HANDLE)pMyObject->hDhcpv6);
    }
    
    if ( pMyObject->hUsers )
    {
        CosaUsersRemove((ANSC_HANDLE)pMyObject->hUsers);
    }
    
    if ( pMyObject->hProcStatus )
    {
        COSADmlRemoveProcessInfo((ANSC_HANDLE)pMyObject->hProcStatus);
    }
#if !defined(DDNS_BROADBANDFORUM)
    if ( pMyObject->hDdns )
    {
        CosaDdnsRemove((ANSC_HANDLE)pMyObject->hDdns);
    }
#endif

#if defined(DDNS_BROADBANDFORUM)

    if ( pMyObject->hDynamicDns )
    {
        CosaDynamicDnsRemove((ANSC_HANDLE)pMyObject->hDynamicDns);
    }
#endif

    if ( pMyObject->hFirewall )
    {
        CosaFirewallRemove((ANSC_HANDLE)pMyObject->hFirewall);
    }

    if ( pMyObject->hSecurity )
    {
        CosaSecurityRemove((ANSC_HANDLE)pMyObject->hSecurity);
    }
    
    if ( pMyObject->hIP )
    {
        CosaIPRemove((ANSC_HANDLE)pMyObject->hIP);
    }
    
    if ( pMyObject->hHosts )
    {
        CosaHostsRemove((ANSC_HANDLE)pMyObject->hHosts);
    }

    if ( pMyObject->hDNS )
    {
        CosaDNSRemove((ANSC_HANDLE)pMyObject->hDNS);
    }

    if( pMyObject->hRouting )
    {
        CosaRoutingRemove((ANSC_HANDLE)pMyObject->hRouting);
    }

    if( pMyObject->hBridging )
    {
        CosaBridgingRemove((ANSC_HANDLE)pMyObject->hBridging);
    }

    if ( pMyObject->hUpnp )
    {
        CosaUpnpRemove((ANSC_HANDLE)pMyObject->hUpnp);
    }
    
    if ( pMyObject->hInterfaceStack )
    {
        CosaIFStackRemove((ANSC_HANDLE)pMyObject->hInterfaceStack);
    }
#ifndef FEATURE_RDKB_XDSL_PPP_MANAGER
    if ( pMyObject->hPPP )
    {
        CosaPPPRemove((ANSC_HANDLE)pMyObject->hPPP);
    }
#endif
    if ( pMyObject->hDeviceControl )
    {
        CosaDeviceControlRemove((ANSC_HANDLE)pMyObject->hDeviceControl);
    }

    if ( pMyObject->hIPv6rd )
    {
        CosaIPv6rdRemove((ANSC_HANDLE)pMyObject->hIPv6rd);
    }

    if ( pMyObject->hRA )
    {
        CosaRARemove((ANSC_HANDLE)pMyObject->hRA);
    }

#ifdef DSLITE_FEATURE_SUPPORT
    if ( pMyObject->hDslite )
    {
        CosaDsliteRemove((ANSC_HANDLE)pMyObject->hDslite);
    }
#endif
    if ( pMyObject->hNeighdisc )
    {
        CosaNeighdiscRemove((ANSC_HANDLE)pMyObject->hNeighdisc);
    }

    if ( pMyObject->hMld )
    {
        CosaMldRemove((ANSC_HANDLE)pMyObject->hMld);
    }
    /*
#ifdef CONFIG_TI_PACM
    if ( pMyObject->hMTA )
    {
        CosaMTARemove((ANSC_HANDLE)pMyObject->hMTA);
    }
#endif
    */
    if ( pMyObject->hParentalControl )
    {
        TR181_ParentalControlRemove((ANSC_HANDLE)pMyObject->hParentalControl);
    }

#ifdef CONFIG_CISCO_HOTSPOT
    if ( pMyObject->hGRE )
    {
        CosaGreRemove((ANSC_HANDLE)pMyObject->hGRE);
    }

    if ( pMyObject->hCGRE )
    {
        CosaCGreRemove((ANSC_HANDLE)pMyObject->hCGRE);
    }

    if ( pMyObject->hHotspot )
    {
        CosaHotspotRemove((ANSC_HANDLE)pMyObject->hHotspot);
    }
	//zqiu>>
	if ( pMyObject->hTGRE )
    {		
		CosaGreTunnelRemove((ANSC_HANDLE)pMyObject->hTGRE);
    }
	//zqiu<<
#endif

#if CONFIG_CISCO_TRUE_STATIC_IP
    if ( pMyObject->hTSIP )
    {
        CosaTSIPRemove((ANSC_HANDLE)pMyObject->hTSIP);
    }
#endif

#if CONFIG_CISCO_FILE_TRANSFER
    if ( pMyObject->hFileTransfer )
    {
        CosaFileTransferRemove((ANSC_HANDLE)pMyObject->hFileTransfer);
    }
#endif
#endif
    /* Remove self */
    AnscFreeMemory((ANSC_HANDLE)pMyObject);

    return returnStatus;
}

#if 0
static void CheckAndSetRebootReason()
{
    int value = -1;
    FILE *fpLastReboot;

    fpLastReboot = fopen("/var/tmp/lastrebootreason","r");
    if(fpLastReboot == NULL)
    {
        char rebootReason[64] = "unknown";
        char BOOT_TIME_LOG_FILE[32] = "/rdklogs/logs/BootTime.log";
        FILE *fpBootLogFile = NULL;

        CcspTraceWarning((" /var/tmp/lastrebootreason File doesn't exist --Create new file\n"));
        system("touch /var/tmp/lastrebootreason");
        //Check for Rebootcounter value--GET & SET
        value = getRebootCounter();
        if(value == -1)
        {
            CcspTraceWarning(("Error to GET Counter Value\n"));
        }
        else
        {
            value = value -1;
            if(value<0)
            {
                //SET unknown as reason 
                if(-1 == setUnknownRebootReason())
                     CcspTraceWarning(("Error to SET unknown reboot reason \n"));
            }
            else
            {
                syscfg_get( NULL, "X_RDKCENTRAL-COM_LastRebootReason", rebootReason, sizeof(rebootReason));
            }
                // reset counter to 0 for both known and unknown reason
                if(-1 == setRebootCounter())
                    CcspTraceWarning(("Error to SET reboot counter \n"));
        }

        fpBootLogFile = fopen(BOOT_TIME_LOG_FILE, "a+");
        if (NULL != fpBootLogFile)
        {
            fprintf(fpBootLogFile, "Received reboot_reason as:%s\n", rebootReason);
	    t2_event_s("rdkb_rebootreason_split", rebootReason);
            fclose(fpBootLogFile);
        }
        else
        {
            CcspTraceWarning(("Fail to open BootTime.log to write reboot reason \n"));
        }
           
    }
    else
    {
        CcspTraceWarning(("/var/tmp/lastrebootreason File exists\n"));
        fclose(fpLastReboot);
    }
}

static void SetAutoreboot( ANSC_HANDLE  hThisObject)
{
     PCOSA_DATAMODEL_DEVICEINFO      pMyObject    = (PCOSA_DATAMODEL_DEVICEINFO)hThisObject;
    char buf[8] = {0};
    int defualtConfigureDays=120;
    /*CID: 278277 - Array Compared against null - fixed*/
    if(!syscfg_get( NULL, "AutoReboot", buf, sizeof(buf)))
    {
         /*CID: 278277 - Array Compared against null - fixed*/
         if( buf[0] != '\0' )
         {
            if( 0 == strcmp( buf, "true"))
            {
                pMyObject->AutoReboot.Enable = TRUE;
                CcspTraceWarning(("Auto reboot parameter value during bootup %s \n", buf));
                CosaDmlScheduleAutoReboot(defualtConfigureDays, TRUE);
            }
            else
            {
                pMyObject->AutoReboot.Enable = FALSE;
                CcspTraceWarning(("No need to schedule as default value is set to %s \n", buf));
            }
         }
    }
}
#endif
void *GetRegistryRootFolder(void *hDmlAgent)
{
     PRBUS_DATAMODEL_AGENT_OBJECT    pDslhDmlAgent = (PRBUS_DATAMODEL_AGENT_OBJECT)hDmlAgent;
     return (void *)pDslhDmlAgent->hIrepFolderCOSA;
}
COSAGetHandleProc g_GetRegistryRootFolder = GetRegistryRootFolder;

char *GetSubsystemPrefix(void *hDmlAgent)
{
     UNREFERENCED_PARAMETER(hDmlAgent);
     return g_Subsystem;
}
COSAGetSubsystemPrefixProc  g_GetSubsystemPrefix = GetSubsystemPrefix;

ULONG
GetParamValueUlong(void*                       hDmlAgent,
		   char*                       pParamName)
{
    UNREFERENCED_PARAMETER(hDmlAgent);
    int size = 0;
    ULONG result = 0;
    int ret = 0;
    char *parameterNames[1] = {};
    parameterNames[0] = pParamName;
    parameterValStruct_t **parameterVal = NULL;
    ret = CcspBaseIf_getParameterValues_rbus( bus_handle,
                			 NULL,
                			 NULL,
                			 parameterNames,
                			 1,
                			 &size ,
                			 &parameterVal
            				);
    if (ret == CCSP_SUCCESS && parameterVal[0]->parameterValue)
    {
       result = strtoul(parameterVal[0]->parameterValue, NULL, 10);
       free_parameterValStruct_t (bus_handle, size, parameterVal);
       parameterVal = NULL;
    }
    return result;
}
COSAGetParamValueUlongProc         g_GetParamValueUlong = GetParamValueUlong;

int GetParamValueString(void*  hDmlAgent,char* pParamName,char*  pBuffer,
		        PULONG pulSize)
{
    UNREFERENCED_PARAMETER(hDmlAgent);
    int size = 0;    
    int result = 0;
    unsigned long len = 0;
    int ret = 0;
    char *parameterNames[1] = {};
    parameterNames[0] = pParamName;
    parameterValStruct_t **parameterVal = NULL;
    ret = CcspBaseIf_getParameterValues_rbus( bus_handle,
                                         NULL,
                                         NULL,
                                         parameterNames,
                                         1,
                                         &size ,
                                         &parameterVal
                                        );
    if (ret == CCSP_SUCCESS && parameterVal[0]->parameterValue)
    {
       len = strlen(parameterVal[0]->parameterValue);

       if (len >= *pulSize)
       {
        // AnscTraceWarning(("GetParamValueString: output buffer too small '%s'\n", pParamName));
           result = 1;
       }
       else
       {
           memcpy(pBuffer, parameterVal[0]->parameterValue, len + 1);
           result = 0;
           free_parameterValStruct_t (bus_handle, size, parameterVal);
       	   parameterVal = NULL;
       }

    }

    /*
       Warning: inconsisent API. The passed in value is a buffer size, the
       returned value is a string length (ie one less then the required
       buffer size).
    */
       *pulSize = len;

       return result;
}
COSAGetParamValueStringProc        g_GetParamValueString = GetParamValueString;

BOOL GetParamValueBool(void* hDmlAgent,char* pParamName)
{
    UNREFERENCED_PARAMETER(hDmlAgent);
    int size = 0;
    int ret = 0;
    char *parameterNames[1] = {};
    parameterNames[0] = pParamName;
    parameterValStruct_t **parameterVal = NULL;
    ret = CcspBaseIf_getParameterValues_rbus( bus_handle,
                                         NULL,
                                         NULL,
                                         parameterNames,
                                         1,
                                         &size ,
                                         &parameterVal
                                        );
    if (ret == CCSP_SUCCESS && parameterVal[0]->parameterValue)
    {	
       if(!strncmp("True",parameterVal[0]->parameterValue,strlen("True")))
	  return TRUE;
    }
    return FALSE;
     
}
COSAGetParamValueBoolProc          g_GetParamValueBool = GetParamValueBool;

int GetParamValueInt (void* hDmlAgent,char*  pParamName)
{
    UNREFERENCED_PARAMETER(hDmlAgent);
    int size = 0;
    int result = 0;
    int ret = 0;
    char *parameterNames[1] = {};
    parameterNames[0] = pParamName;
    parameterValStruct_t **parameterVal = NULL;
    ret = CcspBaseIf_getParameterValues_rbus( bus_handle,
                                         NULL,
                                         NULL,
                                         parameterNames,
                                         1,
                                         &size ,
                                         &parameterVal
                                        );
    if (ret == CCSP_SUCCESS && parameterVal[0]->parameterValue)
    {
       result = (int)strtol(parameterVal[0]->parameterValue, NULL, 10);
       free_parameterValStruct_t (bus_handle, size, parameterVal);
       parameterVal = NULL;
    }
    return result;
}
COSAGetParamValueIntProc           g_GetParamValueInt = GetParamValueInt;

ANSC_STATUS SetParamValueUlong (char* pParamName,ULONG ulParamValue)
{
    parameterValStruct_t pVal[1];
    char str[256] = {0};
    char*                faultParam     = NULL;
    int                  ret            = 0;
    CCSP_MESSAGE_BUS_INFO *bus_info     = (CCSP_MESSAGE_BUS_INFO *)bus_handle;

    snprintf(str,sizeof(str),"%lu",ulParamValue);
    pVal[0].parameterName  = pParamName;
    pVal[0].parameterValue = str;
    pVal[0].type           = ccsp_unsignedLong;

    /*?? check writeID need to be set*/
    ret = CcspBaseIf_setParameterValues_rbus(
                  bus_handle,
                  NULL,
                  NULL,
                  0,
                  0,
                  pVal,
                  1,
                  TRUE,
                  &faultParam
              );

    if (ret != CCSP_SUCCESS)
    {
        CcspTraceError(("%s - %d - Failed to set - Error [%s]\n", __FUNCTION__, __LINE__, faultParam));
        bus_info->freefunc(faultParam);
        return ANSC_STATUS_FAILURE;
    }
    return ANSC_STATUS_SUCCESS;
}
COSASetParamValueUlongProc         g_SetParamValueUlong = SetParamValueUlong;

ANSC_STATUS SetParamValueString (char* pParamName,char* pParamValue)
{
    parameterValStruct_t pVal[1];
    char*                faultParam     = NULL;
    int                  ret            = 0;
    CCSP_MESSAGE_BUS_INFO *bus_info     = (CCSP_MESSAGE_BUS_INFO *)bus_handle;

    pVal[0].parameterName  = pParamName;
    pVal[0].parameterValue = pParamValue;
    pVal[0].type           = ccsp_string;

    /*?? check writeID need to be set*/
    ret = CcspBaseIf_setParameterValues_rbus(
                  bus_handle,
                  NULL,
                  NULL,
                  0,
                  0,
                  pVal,
                  1,
                  TRUE,
                  &faultParam
              );

    if (ret != CCSP_SUCCESS)
    {
        CcspTraceError(("%s - %d - Failed to set - Error [%s]\n", __FUNCTION__, __LINE__, faultParam));
        bus_info->freefunc(faultParam);
        return ANSC_STATUS_FAILURE;
    }
    return ANSC_STATUS_SUCCESS;
}
COSASetParamValueStringProc        g_SetParamValueString = SetParamValueString;

ANSC_STATUS SetParamValueInt (char* pParamName,int iParamValue)
{
    parameterValStruct_t pVal[1];
    char str[256] = {0};
    char*                faultParam     = NULL;
    int                  ret            = 0;
    CCSP_MESSAGE_BUS_INFO *bus_info     = (CCSP_MESSAGE_BUS_INFO *)bus_handle;

    snprintf(str,sizeof(str),"%d",iParamValue);
    pVal[0].parameterName  = pParamName;
    pVal[0].parameterValue = str;
    pVal[0].type           = ccsp_int;

    /*?? check writeID need to be set*/
    ret = CcspBaseIf_setParameterValues_rbus(
                  bus_handle,
                  NULL,
                  NULL,
                  0,
                  0,
                  pVal,
                  1,
                  TRUE,
                  &faultParam
              );

    if (ret != CCSP_SUCCESS)
    {
        CcspTraceError(("%s - %d - Failed to set - Error [%s]\n", __FUNCTION__, __LINE__, faultParam));
        bus_info->freefunc(faultParam);
        return ANSC_STATUS_FAILURE;
    }
    return ANSC_STATUS_SUCCESS;
}
COSASetParamValueIntProc         g_SetParamValueInt = SetParamValueInt;

ANSC_STATUS SetParamValueBool(char* pParamName,BOOL  bParamValue)
{
    parameterValStruct_t pVal[1];
    char*                faultParam     = NULL;
    int                  ret            = 0;
    CCSP_MESSAGE_BUS_INFO *bus_info     = (CCSP_MESSAGE_BUS_INFO *)bus_handle;

    char *str = bParamValue? "true" : "false";
    pVal[0].parameterName  = pParamName;
    pVal[0].parameterValue = str;
    pVal[0].type           = ccsp_boolean;

    /*?? check writeID need to be set*/
    ret = CcspBaseIf_setParameterValues_rbus(
                  bus_handle,
                  NULL,
                  NULL,
                  0,
                  0,
                  pVal,
                  1,
                  TRUE,
                  &faultParam
              );

    if (ret != CCSP_SUCCESS)
    {
        CcspTraceError(("%s - %d - Failed to set - Error [%s]\n", __FUNCTION__, __LINE__, faultParam));
        bus_info->freefunc(faultParam);
        return ANSC_STATUS_FAILURE;
    }
    return ANSC_STATUS_SUCCESS;
}
COSASetParamValueBoolProc          g_SetParamValueBool = SetParamValueBool;

ANSC_STATUS GetInstanceNumbers (char*                      pObjName,
		                ULONG*                     pInsList,
				ULONG*                     pInsCnt)
{
    componentStruct_t       **compStructs = NULL;
    int                     compNum = 0;   
    parameterInfoStruct_t   **infoStructs = NULL;
    int                     infoNum = 0;
    char                    *peerCompId, *peerDbusPath;
    int                     i;
    ULONG                   tmp;

    if (!pObjName && !pInsList && !pInsCnt)
	return ANSC_STATUS_FAILURE;

    /* Some destinations can be with multiple components,Not sure this is really
     * needed, can be removed later*/
    if (CcspBaseIf_discComponentSupportingNamespace_rbus(bus_handle,NULL,
                pObjName,g_Subsystem, &compStructs, &compNum) != CCSP_SUCCESS)
    {
        CcspTraceError(("fail to find component: %s", pObjName));
        return ANSC_STATUS_FAILURE;
    }

    if (compNum != 1)
    {
        CcspTraceError(("no component found (or too many): %s", pObjName));
        free_componentStruct_t(bus_handle, compNum, compStructs);
        return ANSC_STATUS_FAILURE;
    }

    peerCompId = compStructs[0]->componentName;
    peerDbusPath = compStructs[0]->dbusPath;


    if (CcspBaseIf_getParameterNames_rbus(bus_handle, peerCompId, peerDbusPath,
            pObjName, TRUE, &infoNum, &infoStructs) != CCSP_SUCCESS)
    {
        CcspTraceError(("get instance list error: %s", pObjName));
        free_componentStruct_t(bus_handle, compNum, compStructs);
        return ANSC_STATUS_FAILURE;
    }

    for (i = 0; i < infoNum ; i++)
    {
        /*
         * skip the path which is not an instance.
         * A object prefix is like "IP.Device.Interface."
         * and a instance is like "IP.Device.Interface.1."
         * so the format of instance path must be "<prefix>.%d."
         */
        if (strncmp(infoStructs[i]->parameterName, pObjName, strlen(pObjName)) != 0
                || sscanf(infoStructs[i]->parameterName + strlen(pObjName), "%lu.", &tmp) != 1)
        {
            CcspTraceWarning(("The path %s is not a instance", infoStructs[i]->parameterName));
            continue;
        }
	pInsList[i] = tmp;
     }
     *pInsCnt = i;

    free_parameterInfoStruct_t(bus_handle, infoNum, infoStructs);
    free_componentStruct_t(bus_handle, compNum, compStructs);
    return ANSC_STATUS_SUCCESS;
}
COSAGetInstanceNumbersProc         g_GetInstanceNumbers = GetInstanceNumbers;

ULONG GetInstanceNumberByIndex ( void*  hDmlAgent,
		                     char*  pObjName,ULONG ulIndex)
{
    UNREFERENCED_PARAMETER(hDmlAgent);	
    componentStruct_t       **compStructs = NULL;
    int                     compNum = 0;
    parameterInfoStruct_t   **infoStructs = NULL;
    char                    *peerCompId, *peerDbusPath;
    int                     i,infoNum = 0;
    ULONG                   tmp = 0,InstNum = 0;

    if (!pObjName)
        return ANSC_STATUS_FAILURE;

    /* Some destinations can be with multiple components,Not sure this is really
     * needed, can be removed later*/
    if (CcspBaseIf_discComponentSupportingNamespace_rbus(bus_handle,NULL,
                pObjName,g_Subsystem, &compStructs, &compNum) != CCSP_SUCCESS)
    {
        CcspTraceError(("fail to find component: %s", pObjName));
        return ANSC_STATUS_FAILURE;
    }

    if (compNum != 1)
    {
        CcspTraceError(("no component found (or too many): %s", pObjName));
        free_componentStruct_t(bus_handle, compNum, compStructs);
        return ANSC_STATUS_FAILURE;
    }

    peerCompId = compStructs[0]->componentName;
    peerDbusPath = compStructs[0]->dbusPath;


    if (CcspBaseIf_getParameterNames_rbus(bus_handle, peerCompId, peerDbusPath,
			   pObjName, TRUE, &infoNum, &infoStructs) != CCSP_SUCCESS)
    {
        CcspTraceError(("get instance list error: %s", pObjName));
        free_componentStruct_t(bus_handle, compNum, compStructs);
        return ANSC_STATUS_FAILURE;
    }

    for (i = 0; i < infoNum ; i++)
    {
        /*
         * skip the path which is not an instance.
         * A object prefix is like "IP.Device.Interface."
         * and a instance is like "IP.Device.Interface.1."
         * so the format of instance path must be "<prefix>.%d."
         */
        if (strncmp(infoStructs[i]->parameterName, pObjName, strlen(pObjName)) != 0
                || sscanf(infoStructs[i]->parameterName + strlen(pObjName), "%lu.", &tmp) != 1)
        {
            CcspTraceWarning(("The path %s is not a instance", infoStructs[i]->parameterName));
            continue;
        }
        if (i == (int)ulIndex+1)
	{
           CcspTraceWarning(("The path %s found instance %lu", infoStructs[i]->parameterName,tmp)); 		
	   InstNum = tmp;
	   break;
	}
     }

    free_parameterInfoStruct_t(bus_handle, infoNum, infoStructs);
    free_componentStruct_t(bus_handle, compNum, compStructs);
    return InstNum;
}
COSAGetInstanceNumberByIndexProc   g_GetInstanceNumberByIndex = GetInstanceNumberByIndex;

ANSC_STATUS
GetParamValueByPathName
    (
        void*                       bus_handle,
        parameterValStruct_t        *val,
        ULONG                       *parameterValueLength
    )
{
    char * dst_componentid =  NULL;
    char * dst_pathname    =  NULL;
    int size2;
    int ret = 0;

    parameterValStruct_t **parameterVal = NULL;

    CcspTraceInfo(("Calling func:%s\n",__func__));


    ret = CcspBaseIf_getParameterValues_rbus(
        bus_handle,
        dst_componentid,
        dst_pathname,
        &(val->parameterName),
        1,
        &size2,
        &parameterVal
    );

    if ( ret == CCSP_SUCCESS  && size2 >= 1)
    {
        unsigned long len = strlen(parameterVal[0]->parameterValue);

        if (len >= *parameterValueLength)
        {
            // AnscTraceWarning(("COSAGetParamValueByPathName: buf size error '%s'\n", val->parameterName));
            memcpy(val->parameterValue, parameterVal[0]->parameterValue, *parameterValueLength - 1);
            val->parameterValue[*parameterValueLength - 1] = 0;
        }
        else
        {
            memcpy(val->parameterValue, parameterVal[0]->parameterValue, len + 1);
        }

        *parameterValueLength = len;
    }

    if(parameterVal)
      free_parameterValStruct_t(bus_handle, size2, parameterVal);

    return ANSC_STATUS_SUCCESS;
}

COSAGetParamValueByPathNameProc    g_GetParamValueByPathNameProc = GetParamValueByPathName;

#if 0
ANSC_STATUS SetParamValueByPathName ( void*  bus_handle,
                                      parameterValStruct_t       *val)
{
    char * dst_componentid =  NULL;
    char * dst_pathname    =  NULL;
    char * pFaultParameter = NULL;

    int ret = 0;

    ANSC_STATUS returnStatus = ANSC_STATUS_SUCCESS;
    
    ret = CcspBaseIf_setParameterValues_rbus(
                bus_handle,
                dst_componentid,
                dst_pathname,
                0,
                0xFFFFFFFF,
                val,
                1,
                1,
                &pFaultParameter
            );

    if ( CCSP_SUCCESS != ret )
    {
        CcspTraceWarning(("SetValue failed with %d\n", ret));
        returnStatus = ANSC_STATUS_BAD_NAME;
    }

    return  returnStatus;
}
COSASetParamValueByPathNameProc    g_SetParamValueByPathNameProc = SetParamValueByPathName;

#endif

#if 0
/* Get parameter value API */
ANSC_STATUS Rbus_GetParameterValue(const rbusHandle_t rbus_handle,  
				   const char *pParamName, char *pStrVal)
{
    int                    ret = 0;
    rbusValue_t            value;
    rbusValueType_t        rbusValueType ;

    /* rbus get parameter value */
    if(rbus_handle == NULL)
    {
        return ANSC_STATUS_FAILURE;
    }

    /* Init rbus variable */
    rbusValue_Init(&value);

    /* Get the value of a single parameter */
    ret = rbus_get(rbus_handle, pParamName, &value);

    if(ret != RBUS_ERROR_SUCCESS )
    {
        CcspTraceError(("%s-%d Rbus Error code:%d\n",__FUNCTION__,__LINE__, ret));
        return ANSC_STATUS_FAILURE;
    }

    rbusValueType = rbusValue_GetType(value);

    /* Update the parameter value */
    if(rbusValueType == RBUS_BOOLEAN)
    {
        if (rbusValue_GetBoolean(value)){
	    pStrVal = calloc(strlen("true")+1,1);
	    strncpy( pStrVal, "true", strlen( "true" ) + 1 );
        } else {
	    pStrVal = calloc(strlen("false")+1,1);
	    strncpy( pStrVal, "false", strlen( "false" ) + 1 );
        }
    }
    else
    {
        pStrVal = rbusValue_ToString(value, NULL, 0);
    }

    /* release rbus variable */
    rbusValue_Release(value);
    return ANSC_STATUS_SUCCESS;
}
#endif

