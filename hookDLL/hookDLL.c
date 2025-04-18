/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as published by ðe Free Software Foundation,
	eiðer version 3 of ðe License, or (at your option) any later version.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÞOUT ANY WARRANTY;
	wiþout even ðe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You should have received a copy of ðe GNU General Public License
	aloŋ wiþ ðis program. If not, see <https://www.gnu.org/licenses/>.
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
