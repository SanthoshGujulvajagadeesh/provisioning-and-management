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


/**********************************************************************

    module: plugin_main.h

        For Advanced Networking Service Container (ANSC),
        BroadWay Service Delivery System

    ---------------------------------------------------------------

    description:

        This wrapper file defines the exported apis for SNMP plugin.

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Bin Zhu

    ---------------------------------------------------------------

    revision:

        06/25/03    initial revision.

**********************************************************************/


#ifndef  _PLUGIN_MAIN_H
#define  _PLUGIN_MAIN_H

#define ANSC_EXPORT_API

#ifdef __cplusplus 
extern "C"{
#endif

#define  RBUS_DATAMODEL_AGENT_CLASS_CONTENT                                                 \
    ANSC_HANDLE                     hIrepFolderCOSA;                                        \
    BOOL                            bActive;                                                \
    rbusHandle_t                    rbus_handle;                                            \
    /* end of object class content */                                                       \

typedef  struct
_RBUS_DATAMODEL_AGENT_OBJECT
{
    RBUS_DATAMODEL_AGENT_CLASS_CONTENT
}
RBUS_DATAMODEL_AGENT_OBJECT,  *PRBUS_DATAMODEL_AGENT_OBJECT;

/***************************************************************************
 *
 *  BMEL stands for "Broadway MIB Extension Library"
 *
 ***************************************************************************/
int plugin_init_rbus(CCSP_MESSAGE_BUS_INFO *);
int plugin_rbus_handle_event(rbusHandle_t );
int plugin_rbus_handle_event_unload(rbusHandle_t );
int plugin_deviceinfo_handle_event(rbusHandle_t );
int plugin_deviceinfo_handle_event_unload(rbusHandle_t );
  
#ifdef __cplusplus 
}
#endif
#endif
