/* =============================================================================================
	Qåmlia - a program for doing stuff usiŋ only normal keypresses from anywhere.
	Copyright (C) 2025 Johannah Granström

	This program is free software: you can redistribute it and/or modify it under
	the terms of the GNU General Public License as published by the Free Software Foundation,
	either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

/**
 * @file	: hookDLL.c
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: WIN32
 */

#include "hookDLL.h"

#pragma data_seg (".SHARED")
UINT const WM_HOOK = WM_APP + 1;
HWND hwndServer = NULL;
#pragma data_seg ()
#pragma comment (linker, "/section:.SHARED,RWS")

HINSTANCE instanceHandle;
HHOOK hookHandle;

BOOL APIENTRY DllMain (HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		instanceHandle = hModule;
		hookHandle = NULL;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return (TRUE);
}

static LRESULT CALLBACK KeyboardProc (int code, WPARAM wParam, LPARAM lParam) {
	if (code < 0) {
		return CallNextHookEx (hookHandle, code, wParam, lParam);
	}

	if (SendMessage (hwndServer, WM_HOOK, wParam, lParam)) {
		return 1;
	}

	return CallNextHookEx (hookHandle, code, wParam, lParam);
}

BOOL installHookDLL (HWND hwndParent) {
	hookHandle = SetWindowsHookEx (WH_KEYBOARD, (HOOKPROC)KeyboardProc, instanceHandle, 0);
	if (hookHandle == NULL) {
		return (FALSE);
	}
	hwndServer = hwndParent;
	return (TRUE);
}

BOOL uninstallHookDLL () {
	if (hookHandle == NULL) {
		return (TRUE);
	}
	if (!UnhookWindowsHookEx (hookHandle)) {
		DWORD error = GetLastError ();
		if (error != ERROR_INVALID_HOOK_HANDLE) {
			return (FALSE);
		}
	}
	hwndServer = NULL;
	hookHandle = NULL;
	return (TRUE);
}
