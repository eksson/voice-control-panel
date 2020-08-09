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

#include <stdio.h>

#include "voice_control_panel_command.h"

voice_command_h voice_command_list_kr[MAX_VOICE_LIST + 1] = {
	//Quick command
	{"정지",						CMD_STOP},	// 0
	{"중지",						CMD_STOP},
	{"그만",						CMD_STOP},
	{"스탑",						CMD_STOP},
	{"스톱",						CMD_STOP},
	{"멈춰",						CMD_PAUSE},
	{"그래",						CMD_OK},
	{"오케",						CMD_OK},
	{"오케이",						CMD_OK},
	{"아니",						CMD_CANCLE},
	{"취소",						CMD_CANCLE},
	{"노우",						CMD_CANCLE},
	{"시작",						CMD_START},
	{"다시",						CMD_AGAIN},
	{"한번더",						CMD_AGAIN},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},	//	20

	//General command
	{"안마의자꺼",					CMD_POWER_OFF},
	{"전원꺼",						CMD_POWER_OFF},

	{"황실모드",					CMD_MSG_MODE_IMPERIAL},
	{"어깨모드",					CMD_MSG_MODE_SHOULDER},
	{"척추모드",					CMD_MSG_MODE_WAIST},
	{"무릎모드",					CMD_MSG_MODE_KNEE},
	{"무름모드",					CMD_MSG_MODE_KNEE},
	{"수동모드",					CMD_MSG_MODE_MANUAL},
	{"일번사용자",					CMD_MSG_MODE_USER1},
	{"일반사용자",					CMD_MSG_MODE_USER1},
	{"이번사용자",					CMD_MSG_MODE_USER2},
	{"이반사용자",					CMD_MSG_MODE_USER2},
	{"삼번사용자",					CMD_MSG_MODE_USER3},
	{"삼반사용자",					CMD_MSG_MODE_USER3},

	{"즐겨찾기",					CMD_UI_FAVORITE},

	{"무중력",						CMD_CHAIR_ANGLE_ZEROGRAVITY},
	{"무중령",						CMD_CHAIR_ANGLE_ZEROGRAVITY},
	{"원위치",						CMD_CHAIR_ANGLE_INIT},
	{"수면모드",					CMD_CHAIR_ANGLE_SLEEP},

	{"시간내려",					CMD_MSG_TIME_DOWN},
	{"시간올려",					CMD_MSG_TIME_UP},

	{"안마약하",					CMD_MSG_STRENGTH_DOWN},
	{"한마약하",					CMD_MSG_STRENGTH_DOWN},
	{"안마살",						CMD_MSG_STRENGTH_DOWN},
	{"한마살",						CMD_MSG_STRENGTH_DOWN},
	{"안마쎄게",					CMD_MSG_STRENGTH_UP},
	{"한마쎄게",					CMD_MSG_STRENGTH_UP},
	{"안마세개",					CMD_MSG_STRENGTH_UP},
	{"한마세개",					CMD_MSG_STRENGTH_UP},
	{"안마세계",					CMD_MSG_STRENGTH_UP},
	{"한마세계",					CMD_MSG_STRENGTH_UP},

	{"다리히터켜",					CMD_CHAIR_LEGHEATER_ON},
	{"다리온열켜",					CMD_CHAIR_LEGHEATER_ON},
	{"다리히터꺼",					CMD_CHAIR_LEGHEATER_OFF},
	{"다리온열꺼",					CMD_CHAIR_LEGHEATER_OFF},
	{"등히터켜",					CMD_CHAIR_BACKHEATER_ON},
	{"등온열켜",					CMD_CHAIR_BACKHEATER_ON},
	{"등히터꺼",					CMD_CHAIR_BACKHEATER_OFF},
	{"등온열꺼",					CMD_CHAIR_BACKHEATER_OFF},
	{"발롤러켜",					CMD_CHAIR_FOOTROLLER_ON},
	{"발바닥마사지켜",				CMD_CHAIR_FOOTROLLER_ON},
	{"발롤러꺼",					CMD_CHAIR_FOOTROLLER_OFF},
	{"발바닥마사지꺼",				CMD_CHAIR_FOOTROLLER_ON},

	{"볼륨내려",					CMD_SPEAKER_VOLUME_DOWN},
	{"볼륨올려",					CMD_SPEAKER_VOLUME_UP},
	{"볼륨켜",						CMD_SPEAKER_VOLUME_ON},
	{"볼륨꺼",						CMD_SPEAKER_VOLUME_MUTE},

	{"블루투스화면",				CMD_BT_SETTING},
	{"블루투스연결",				CMD_BT_CONNECT},
	{"일번블루투스연결",			CMD_BT_CONNECT_DEVICE1},
	{"일반블루투스연결",			CMD_BT_CONNECT_DEVICE1},
	{"이번블루투스연결",			CMD_BT_CONNECT_DEVICE2},
	{"이반블루투스연결",			CMD_BT_CONNECT_DEVICE2},
	{"삼번블루투스연결",			CMD_BT_CONNECT_DEVICE3},
	{"삼반블루투스연결",			CMD_BT_CONNECT_DEVICE3},
	{"블루투스끊어",				CMD_BT_CONNECT_OFF},
	{"블루투스끝",					CMD_BT_CONNECT_OFF},

	{"음악틀어",					CMD_MUSIC_PLAY},
	{"음악시작",					CMD_MUSIC_PLAY},
	{"노래틀어",					CMD_MUSIC_PLAY},
	{"노래시작",					CMD_MUSIC_PLAY},

	{"음악꺼",						CMD_MUSIC_STOP},
	{"노래꺼",						CMD_MUSIC_STOP},
	{"음악멈춰",					CMD_MUSIC_PAUSE},
	{"노래멈춰",					CMD_MUSIC_PAUSE},

	{"이전곡",						CMD_MUSIC_PREV},
	{"이전노래",					CMD_MUSIC_PREV},
	{"다음곡",						CMD_MUSIC_NEXT},
	{"다음노래",					CMD_MUSIC_NEXT},

	{"티브이리모",					CMD_UI_TV_REMOCON_VIEW_HIDE},
	{"티비리모",					CMD_UI_TV_REMOCON_VIEW_HIDE},

	{"티브이전원",					CMD_TV_POWER_ON_OFF},	//	{"티브이켜", CMD_TV_POWER_ON}, {"티브이꺼", CMD_TV_POWER_OFF},
	{"티비전원",					CMD_TV_POWER_ON_OFF},
	{"티브이볼륨내",				CMD_TV_VOLUME_DOWN},
	{"티비볼륨내",					CMD_TV_VOLUME_DOWN},
	{"티브이볼륨올",				CMD_TV_VOLUME_UP},
	{"티비볼륨올",					CMD_TV_VOLUME_UP},
	{"티브이볼륨켜",				CMD_TV_VOLUME_ON},
	{"티비볼륨켜",					CMD_TV_VOLUME_ON},
	{"티브이볼륨꺼",				CMD_TV_VOLUME_MUTE},
	{"티비볼륨꺼",					CMD_TV_VOLUME_MUTE},
	{"티브이채널내",				CMD_TV_CHANNEL_DOWN},
	{"티비채널내",					CMD_TV_CHANNEL_DOWN},
	{"채널내",						CMD_TV_CHANNEL_DOWN},
	{"티브이채널올",				CMD_TV_CHANNEL_UP},
	{"티비채널올",					CMD_TV_CHANNEL_UP},
	{"채널올",						CMD_TV_CHANNEL_UP},


	{"end of command list!",		CMD_LIST_END}
};

voice_command_h voice_command_list_en[MAX_VOICE_LIST + 1] = {
	//Quick command
	{"stop",						CMD_STOP},	//	0
	{"pause",						CMD_PAUSE},
	{"break",						CMD_STOP},
	{"start",						CMD_START},
	{"star",						CMD_START},
	{"again",						CMD_RESTART},
	{"yes",							CMD_OK},
	{"okay",						CMD_OK},
	{"cancel",						CMD_CANCLE},
	{"no",							CMD_CANCLE},
	{"off",							CMD_CANCLE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},
	{"-",							CMD_NONE},	// 20

	//General command
	{"poweroff",					CMD_POWER_OFF},
	{"massageoff",					CMD_POWER_OFF},
	{"massagechairoff",				CMD_POWER_OFF},


	{"tvpower",						CMD_TV_POWER_ON_OFF},	//	{"tvon", CMD_TV_POWER_ON}, {"tvoff", CMD_TV_POWER_OFF},

	{"end of command list!",		CMD_LIST_END}
};


char* g_command_1st[NUM_COMMAND_1ST] = {
	"IDS_HOMESCREEN", "IDS_INTERNET", "IDS_TASK_MANAGER", "IDS_SETTINGS", "IDS_HELP", "IDS_CLOSE",
	"IDS_SCROLL_UP", "IDS_SCROLL_DOWN", "IDS_SWIPE_FORWARD", "IDS_SWIPE_BACKWARD", "IDS_BACK", "IDS_POWER_OFF"
};

#if 0
char *g_hint_1st[NUM_COMMAND_1ST] = {
	"IDS_HINT_HOMESCREEN", "IDS_HINT_INTERNET", "IDS_HINT_TASK_MANAGER", "IDS_HINT_SETTINGS", "IDS_HINT_HELP", "IDS_HINT_CLOSE",
	"IDS_HINT_SCROLL_UP", "IDS_HINT_SCROLL_DOWN", "IDS_HINT_SWIPE_FORWARD", "IDS_HINT_SWIPE_BACKWARD", "IDS_HINT_BACK", "IDS_HINT_POWER_OFF"
};

char* g_command_2nd[NUM_COMMAND_1ST][NUM_COMMAND_2ND] = {
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{"IDS_WIFI", "IDS_BLUETOOTH", "IDS_GPS", "IDS_SOUND", "IDS_MORE", "IDS_PREVIOUS", "IDS_HELP", "IDS_CLOSE"},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
};
char* g_hint_2nd[NUM_COMMAND_1ST][NUM_COMMAND_2ND] = {
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{"IDS_HINT_WIFI", "IDS_HINT_BLUETOOTH", "IDS_HINT_GPS", "IDS_HINT_SOUND", "IDS_HINT_MORE", "IDS_HINT_PREVIOUS", "IDS_HINT_HELP", "IDS_HINT_CLOSE"},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
};
#endif

/*
vi:ts=4:ai:nowrap:expandtab
*/
