##########################################################################
# If not stated otherwise in this file or this component's Licenses.txt
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
#CcspPandMSsp_LDFLAGS += -ltr181 
AM_CFLAGS =

ACLOCAL_AMFLAGS = -I m4

noinst_LTLIBRARIES = libCcspPandM_rbus_wrapper_users.la libCcspPandM_rbus_wrapper_deviceinfo.la libCcspPandM_rbus_wrapper_common.la

libCcspPandM_rbus_wrapper_users_la_CPPFLAGS = -I$(top_srcdir)/source/TR-181/rbus_wrappers \
                                        -I$(top_srcdir)/source/TR-181/board_sbapi \
                                       -I$(top_srcdir)/source/TR-181/middle_layer_src \
                                       -I$(top_srcdir)/source-arm/TR-181/board_include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I$(top_srcdir)/source-arm/TR-181/board_sbapi \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_include \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_ml \
                                       -I$(top_srcdir)/custom/comcast \
                                       -I$(top_srcdir)/source/TR-181/include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage

libCcspPandM_rbus_wrapper_deviceinfo_la_CPPFLAGS = -I$(top_srcdir)/source/TR-181/rbus_wrappers \
                                        -I$(top_srcdir)/source/TR-181/board_sbapi \
                                       -I$(top_srcdir)/source/TR-181/middle_layer_src \
                                       -I$(top_srcdir)/source-arm/TR-181/board_include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I$(top_srcdir)/source-arm/TR-181/board_sbapi \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_include \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_ml \
                                       -I$(top_srcdir)/custom/comcast \
                                       -I$(top_srcdir)/source/TR-181/include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage

libCcspPandM_rbus_wrapper_common_la_CPPFLAGS = -I$(top_srcdir)/source/TR-181/rbus_wrappers \
                                        -I$(top_srcdir)/source/TR-181/board_sbapi \
                                       -I$(top_srcdir)/source/TR-181/middle_layer_src \
                                       -I$(top_srcdir)/source-arm/TR-181/board_include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I$(top_srcdir)/source-arm/TR-181/board_sbapi \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_include \
                                       -I$(top_srcdir)/custom/comcast/source/TR-181/custom_ml \
                                       -I$(top_srcdir)/custom/comcast \
                                       -I$(top_srcdir)/source/TR-181/include \
                                       -I$(top_srcdir)/source-arm/TR-181/board_ml \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
                                       -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage

libCcspPandM_rbus_wrapper_users_la_SOURCES = rbus_wrapper_apis_users.c rbus_context_helpers.c

libCcspPandM_rbus_wrapper_users_la_LDFLAGS = -lCcspPandM_rbus_wrapper_common -rdynamic -ldl -lrbus -lrtMessage -shared -fPIC

libCcspPandM_rbus_wrapper_deviceinfo_la_SOURCES = rbus_wrapper_apis_deviceinfo.c rbus_context_helpers.c

libCcspPandM_rbus_wrapper_deviceinfo_la_LDFLAGS = -lCcspPandM_rbus_wrapper_common -rdynamic -ldl -lrbus -lrtMessage -shared -fPIC

libCcspPandM_rbus_wrapper_common_la_SOURCES = rbus_wrapper_common_apis.c rbus_wrapper_common_apis.h

libCcspPandM_rbus_wrapper_common_la_LDFLAGS = -rdynamic -ldl -lrbus -lrtMessage -shared -fPIC

