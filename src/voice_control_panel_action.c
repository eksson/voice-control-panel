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

#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>

#include <app.h>
#include <aul.h>
#include <dlog.h>
#include <vconf.h>

#include "voice_control_panel_main.h"
#include "voice_control_panel_action.h"
#include "voice_control_panel_command.h"
#include "voice_control_panel_view.h"
#include "voice_control_panel_touchevent.h"

#if 0 /* NOT USED - if needed, reactivate*/
static void __vc_panel_action_send_key_event(void *data, Ecore_Thread *thread)
{
	LOGD("==== Send Key Event ====");

	int keynum = (int)data;
	LOGD("Key - %d", keynum);

	int fd;
	fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	if (0 > fd) {
		LOGE("[ERROR] Fail to open dev");
		return;
	}

	int ret;
	struct uinput_user_dev uidev;
	memset(&uidev, 0, sizeof(uidev));
	snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "vc-keyevent");
	uidev.id.bustype = BUS_USB;
	uidev.id.vendor = 1;
	uidev.id.product = 1;
	uidev.id.version = 1;

	ret = write(fd, &uidev, sizeof(uidev));
	if (sizeof(uidev) != ret) {
		LOGE("[ERROR] Fail to write info");
		close(fd);
		return;
	}

	ret = ioctl(fd, UI_SET_EVBIT, EV_KEY);
	if (0 != ret) {
		LOGE("[ERROR] Fail to ioctl");
		close(fd);
		return;
	}

	ret = ioctl(fd, UI_SET_EVBIT, EV_SYN);
	if (0 != ret) {
		LOGE("[ERROR] Fail to ioctl");
		close(fd);
		return;
	}

	ret = ioctl(fd, UI_SET_KEYBIT, keynum);
	if (0 != ret) {
		LOGE("[ERROR] Fail to register key");
		close(fd);
		return;
	}

	ret = ioctl(fd, UI_DEV_CREATE);
	if (0 != ret) {
		LOGE("[ERROR] Fail to create");
		close(fd);
		return;
	}

	usleep(1000000);

	struct input_event ev;
	memset(&ev, 0, sizeof(ev));
	ev.type = EV_KEY;
	ev.code = keynum;
	ev.value = 1;

	ret = write(fd, &ev, sizeof(ev));
	if (0 > ret) {
		LOGE("[ERROR] Fail to send key event");
		close(fd);
		return;
	}

	memset(&ev, 0, sizeof(ev));
	ev.type = EV_SYN;
	ev.code = 0;
	ev.value = 0;

	ret = write(fd, &ev, sizeof(ev));
	if (0 > ret) {
		LOGE("[ERROR] Fail to send sync event");
		close(fd);
		return;
	}

	usleep(1000000);

	ret = ioctl(fd, UI_DEV_DESTROY);
	if (0 != ret) {
		LOGE("[ERROR] Fail to destroy");
		close(fd);
		return;
	}

	LOGD("====");
	LOGD(" ");

	close(fd);
	return;
}
#endif

static void __vc_panel_action_launch_app(const char* app_id)
{
	LOGD("==== Launch app(%s) ====", app_id);
	app_control_h app_control;
	app_control_create(&app_control);
	app_control_set_app_id(app_control, app_id);
	app_control_send_launch_request(app_control, NULL, NULL);
	app_control_destroy(app_control);
	LOGD("====");
	LOGD("");
}

void __launch_poweroff_popup()
{
	LOGD("--");
	DBusError err;
	dbus_error_init(&err);

	DBusConnection *conn = NULL;
	conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
	if (dbus_error_is_set(&err)) {
		dbus_error_free(&err);
	}

	DBusMessage* msg;
	msg = dbus_message_new_method_call(
		"org.tizen.system.popup",
		"/Org/Tizen/System/Popup/Powerkey",
		"org.tizen.system.popup.Powerkey",
		"PopupLaunch");

	const char *tmp1 = "_SYSPOPUP_CONTENT_";
	const char *tmp2 = "powerkey";
	dbus_message_append_args(msg,
		DBUS_TYPE_STRING, &tmp1,
		DBUS_TYPE_STRING, &tmp2,
		DBUS_TYPE_INVALID);

	dbus_connection_send(conn, msg, NULL);
	dbus_message_unref(msg);

	LOGD("++");

	return;
}

bool vc_panel_action(const char* result, void *data)
{
	if (NULL == result)
		return false;

	LOGD("==== Action - %s ====", result);

	appdata *ad = (appdata *)data;

	if (1 == ad->current_depth) {
		if (!strcasecmp(result, _("IDS_HOMESCREEN"))) {
			char *path = NULL;
			path = vconf_get_str(VCONFKEY_SETAPPL_SELECTED_PACKAGE_NAME);
			if (NULL != path) {
				__vc_panel_action_launch_app(path);
				free(path);
			}
			return true;
		} else if (!strcasecmp(result, _("IDS_NOTIFICATION"))) {
			__vc_panel_action_launch_app("org.tizen.quickpanel");
			return true;
		} else if (!strcasecmp(result, _("IDS_INTERNET"))) {
			__vc_panel_action_launch_app("org.tizen.browser");
			return true;
		} else if (!strcasecmp(result, _("IDS_TASK_MANAGER"))) {
			__vc_panel_action_launch_app("org.tizen.task-mgr");
			return true;
		} else if (!strcasecmp(result, _("IDS_SCROLL_UP"))) {
			vc_panel_touch_swipe(VC_PANEL_TOUCH_SWIPE_DOWN, data);
			return true;
		} else if (!strcasecmp(result, _("IDS_SCROLL_DOWN"))) {
			vc_panel_touch_swipe(VC_PANEL_TOUCH_SWIPE_UP, data);
			return true;
		} else if (!strcasecmp(result, _("IDS_SWIPE_FORWARD"))) {
			vc_panel_touch_swipe(VC_PANEL_TOUCH_SWIPE_LEFT, data);
			return true;
		} else if (!strcasecmp(result, _("IDS_SWIPE_BACKWARD"))) {
			vc_panel_touch_swipe(VC_PANEL_TOUCH_SWIPE_RIGHT, data);
			return true;
		} else if (!strcasecmp(result, _("IDS_BACK"))) {
			vc_panel_touch_back(data);
			return true;
		} else if (!strcasecmp(result, _("IDS_HELP"))) {
			vc_panel_view_show_help(ad);
			return true;
		} else if (!strcasecmp(result, _("IDS_CLOSE"))) {
			return false;
		} else if (!strcasecmp(result, _("IDS_POWER_OFF"))) {
			__launch_poweroff_popup();
			return true;
		}

		int i;
		for (i = 0; i < NUM_COMMAND_1ST; i++) {
			if (NULL == g_command_1st[i])
				continue;

			if (!strcasecmp(result, _(g_command_1st[i]))) {
				ad->current_path[0] = i;
				ad->current_depth = 2;
			}
		}
	}

	LOGD("====");
	LOGD(" ");

	return true;
}

/*
vi:ts=4:ai:nowrap:expandtab
*/
