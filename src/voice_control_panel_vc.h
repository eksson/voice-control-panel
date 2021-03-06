/*
*  Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved 
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*  http://www.apache.org/licenses/LICENSE-2.0
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

#ifndef __VOICE_CONTROL_PANEL_VC_H
#define __VOICE_CONTROL_PANEL_VC_H

#ifdef __cplusplus
extern "C" {
#endif

int vc_panel_vc_start(void *data);
int vc_panel_vc_cancel(void *data);
int vc_panel_vc_init(void *data);
int vc_panel_vc_deinit(void *data);
int vc_panel_vc_deactivate(void *data, double delay);
int vc_panel_vc_activate(void *data);
int vc_panel_vc_finalize(void *data);

#ifdef __cplusplus
}
#endif

#endif /* __VOICE_CONTROL_PANEL_VC_H */

/*
vi:ts=4:ai:nowrap:expandtab
*/
