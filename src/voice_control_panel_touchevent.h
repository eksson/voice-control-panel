/*
*  Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
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

#ifndef __VOICE_CONTROL_PANEL_TOUCHEVENT_H
#define __VOICE_CONTROL_PANEL_TOUCHEVENT_H

#ifdef __cplusplus
extern "C" {
#endif

#define VC_PANEL_TOUCH_SWIPE_UP 1
#define VC_PANEL_TOUCH_SWIPE_DOWN 2
#define VC_PANEL_TOUCH_SWIPE_LEFT 3
#define VC_PANEL_TOUCH_SWIPE_RIGHT 4

int vc_panel_touch_set_speed(const int pps);
void vc_panel_touch_swipe(const int direction, void* data);
void vc_panel_touch_back(void* data);

#ifdef __cplusplus
}
#endif

#endif /* __VOICE_CONTROL_PANEL_TOUCHEVENT_H */

/*
vi:ts=4:ai:nowrap:expandtab
*/
