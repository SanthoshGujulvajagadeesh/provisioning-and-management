##########################################################################
# If not stated otherwise in this file or this component's LICENSE
# file the following copyright and licenses apply:
#
# Copyright 2015 RDK Management
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##########################################################################
if UNIT_TEST_DOCKER_SUPPORT
SUBDIRS = source
else
SUBDIRS = source-arm custom source

lib_LTLIBRARIES = libtr181.la libtr181_users.la libtr181_deviceinfo.la


libtr181_la_SOURCES =

libtr181_users_la_SOURCES =

libtr181_deviceinfo_la_SOURCES =

libtr181_la_DEPENDENCIES = \
	source-arm/TR-181/board_ml/libCcspPandM_board_ml.la \
	source-arm/TR-181/board_sbapi/libCcspPandM_board_sbapi.la \
	custom/comcast/source/TR-181/custom_sbapi/libCcspPandM_comcast_sbapi.la \
	custom/comcast/source/TR-181/custom_ml/libCcspPandM_comcast_ml.la \
	source/TR-181/integration_src.shared/libCcspPandM_integration_src_shared.la \
	source/TR-181/middle_layer_src/libCcspPandM_middle_layer_src.la

libtr181_users_la_DEPENDENCIES = \
	source/rbus_wrappers/libCcspPandM_rbus_wrapper_users.la \
	source-arm/TR-181/board_sbapi/libCcspPandM_board_sbapi_users.la \
	source/TR-181/middle_layer_src/libCcspPandM_middle_layer_src_users.la

libtr181_deviceinfo_la_DEPENDENCIES = \
	source/rbus_wrappers/libCcspPandM_rbus_wrapper_deviceinfo.la \
	source-arm/TR-181/board_sbapi/libCcspPandM_board_sbapi_deviceinfo.la \
	custom/comcast/source/TR-181/custom_sbapi/libCcspPandM_comcast_sbapi_deviceinfo.la \
	custom/comcast/source/TR-181/custom_ml/libCcspPandM_comcast_ml_deviceinfo.la \
	source/TR-181/middle_layer_src/libCcspPandM_middle_layer_src_deviceinfo.la

libtr181_la_LIBADD = $(libtr181_la_DEPENDENCIES)
libtr181_users_la_LIBADD = $(libtr181_users_la_DEPENDENCIES)
libtr181_deviceinfo_la_LIBADD = $(libtr181_deviceinfo_la_DEPENDENCIES)

libtr181_la_LDFLAGS = -lsecure_wrapper -lwebconfig_framework -lhal_moca -lapi_dhcpv4c -lhal_msomgmt -lhal_platform -lhal_ethsw -llmapi -lccsp_common -lcm_mgnt -lutapi -lutctx -llibparodus -lcurl

libtr181_users_la_LDFLAGS = -lsecure_wrapper -lwebconfig_framework -lhal_moca -lapi_dhcpv4c -lhal_msomgmt -lhal_platform -lhal_ethsw -llmapi -lccsp_common_lite -lcm_mgnt -lutapi -lutctx -llibparodus -lcurl

libtr181_deviceinfo_la_LDFLAGS = -lsecure_wrapper -lwebconfig_framework -lhal_moca -lapi_dhcpv4c -lhal_msomgmt -lhal_platform -lhal_ethsw -lccsp_common_lite -lcm_mgnt -lutapi -lutctx -llibparodus -lcurl

#libtr181_la_LDFLAGS += -Wl,--no-undefined -Wl,--no-allow-shlib-undefined

bin_PROGRAMS = CcspPandMSsp_test
CcspPandMSsp_test_CPPFLAGS = -I$(top_srcdir)/source/TR-181/board_sbapi \
                        -I$(top_srcdir)/source/TR-181/middle_layer_src \
                        -I$(top_srcdir)/custom/comcast/source/TR-181/custom_include \
                        -I$(top_srcdir)/custom/comcast/source/TR-181/custom_ml \
                        -I$(top_srcdir)/custom/comcast \
                        -I$(top_srcdir)/source/TR-181/include \
                        -I$(top_srcdir)/source/Custom \
                        -I$(top_srcdir)/source-arm/TR-181/board_include \
                        -I$(top_srcdir)/source-arm/TR-181/board_sbapi \
                        -I$(top_srcdir)/source/TR-181/middle_layer_src \
                        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage
#CcspPandMSsp_SOURCES = ssp_messagebus_interface.c ssp_main.c ssp_action.c dm_pack_datamodel.c
CcspPandMSsp_test_SOURCES = $(top_srcdir)/source/PandMSsp/ssp_main_rbus.c
CcspPandMSsp_test_LDFLAGS = -lrtMessage -lwebconfig_framework -ltelemetry_msgsender -lsecure_wrapper $(SYSTEMD_LDFLAGS) -lsyscfg -lpthread -lccsp_common

CcspPandMSsp_test_LDFLAGS += -L$(PWD)/source/TR-181/middle_layer_src/.libs -lCcspPandM_plugin_rbus
CcspPandMSsp_test_LDFLAGS += -L${PWD}/.libs -ltr181_deviceinfo
endif
