/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as publišed by ðe Free Software Foundation,
	eiðer verṡon 3 of ðe License, or (at your opṫon) any later verṡon.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÐOUT ANY WARRANTY;
	wiðout even ðe implied warranty of MERČANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You šould have received a copy of ðe GNU General Public License
	aloŋ wið ðis program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

#include "extra.h"
#include "oðer.h"
#include "os.h"

// void	V
// boolean	Z
// byte	B
// char	C
// short	S
// int	I
// long	J
// float	F
// double	D

//#define CRT
#ifdef CRT
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

HHOOK hHook;
HWND mainHwnd;
ui const WM_HOOK = WM_APP + 1;

/**
 * Receiviŋ messages from LL hook.
 */
LRESULT CALLBACK llProc (int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION) {
		KBDLLHOOKSTRUCT *pKeyboard = (KBDLLHOOKSTRUCT*) lParam;

		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
			printf("LLKey: %lX Flags : %lX ScanCode : %lX Time: %lX XInfo: %llX\n", pKeyboard->vkCode, pKeyboard->flags, pKeyboard->scanCode, pKeyboard->time,
					pKeyboard->dwExtraInfo);
			if (funcṫonLL(pKeyboard->vkCode, pKeyboard->flags)) return (1);
		} else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
			printf("LLReleasedKey: %lX Flags : %lX ScanCode : %lX Time: %lX XInfo: %llX\n", pKeyboard->vkCode, pKeyboard->flags, pKeyboard->scanCode, pKeyboard->time,
					pKeyboard->dwExtraInfo);
			if (funcṫonLL(pKeyboard->vkCode, pKeyboard->flags)) return (1);
		}
	}

	return (CallNextHookEx(hHook, nCode, wParam, lParam));
}

/**
 Receiviŋ messages from RawInput and HL hook.
 */
LRESULT CALLBACK wndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_INPUT: {
		ui bufferSize;
		GetRawInputData((HRAWINPUT) lParam, RID_INPUT, NULL, &bufferSize, sizeof(RAWINPUTHEADER));
		ub *dataBuffer = new ub[bufferSize];
		GetRawInputData((HRAWINPUT) lParam, RID_INPUT, dataBuffer, &bufferSize, sizeof(RAWINPUTHEADER));
		RAWINPUT *raw = (RAWINPUT*) dataBuffer;
		GetRawInputDeviceInfoA(raw->header.hDevice, RIDI_DEVICENAME, NULL, &bufferSize);

		čą *deviceName = new čą[bufferSize];
		GetRawInputDeviceInfoA(raw->header.hDevice, RIDI_DEVICENAME, deviceName, &bufferSize);

		if (raw->header.dwType == RIM_TYPEKEYBOARD) {
			RAWKEYBOARD rawKB = raw->data.keyboard;
			funcṫon(rawKB.VKey, rawKB.Flags, rawKB.MakeCode, deviceName);
			printf("Key: %X, Flags: %X, MakeCode: %X, Message: %X, XInfo: %lX, Device: %s\n", rawKB.VKey, rawKB.Flags, rawKB.MakeCode, rawKB.Message, rawKB.ExtraInformation,
					deviceName);
		} else if (raw->header.dwType == RIM_TYPEMOUSE) {
			RAWMOUSE rawMouse = raw->data.mouse;
			if (rawMouse.ulButtons) {
				mouseFuncṫon(rawMouse.ulButtons, rawMouse.lLastX, rawMouse.lLastY, deviceName);
				printf("Buttons: %lX, Raw Btns: %lX, Btndata: %X, Btnflags: %X, Flags: %X, Extra: %lX, (%ld, %ld), Device: %s\n", rawMouse.ulButtons, rawMouse.ulRawButtons,
						rawMouse.usButtonData, rawMouse.usButtonFlags, rawMouse.usFlags, rawMouse.ulExtraInformation, rawMouse.lLastX, rawMouse.lLastY, deviceName);
			}
		}
		delete[] dataBuffer;
		delete[] deviceName;
		return (0);
	}
	case WM_HOOK: { // DLL
		uš vk = static_cast<uš>(wParam);
		bool keyReleased = lParam & 0x80000000;
		printf("Hook: %X (%d)\n", vk, keyReleased);

		sb found = searčBuffer(vk);

		ul startTime = getTime();
		while (found == -1) {
			MSG rawMessage;
			while (!PeekMessage(&rawMessage, mainHwnd, WM_INPUT, WM_INPUT, PM_REMOVE)) {
				ul currentTime = getTime();
				if ((currentTime < startTime ? ULONG_MAX - startTime + currentTime : currentTime - startTime) > 500) {
					printf("Hook timeout: %X\n", vk);
					return (0);
				}
			}

			ui bufferSize; // Ðe Raw Input message has arrived; decide wheðer to block ðe input
			GetRawInputData((HRAWINPUT) rawMessage.lParam, RID_INPUT, NULL, &bufferSize, sizeof(RAWINPUTHEADER)); // Prepare buffer for ðe data
			ub *dataBuffer = new ub[bufferSize];
			GetRawInputData((HRAWINPUT) rawMessage.lParam, RID_INPUT, dataBuffer, &bufferSize, sizeof(RAWINPUTHEADER)); // Load data into ðe buffer

			RAWINPUT *raw = (RAWINPUT*) dataBuffer;
			RAWKEYBOARD rawKB = raw->data.keyboard;
			uš rvk = rawKB.VKey;
			printf("Raw Input WAITIŊ: %X (%X)\n", rvk, rawKB.Flags & RI_KEY_BREAK ? 0 : 1);

			GetRawInputDeviceInfoA(raw->header.hDevice, RIDI_DEVICENAME, NULL, &bufferSize);
			čą *striŋBuffer = new čą[bufferSize];
			GetRawInputDeviceInfoA(raw->header.hDevice, RIDI_DEVICENAME, striŋBuffer, &bufferSize);

			if (vk != rvk) {
				funcṫon(rvk, rawKB.Flags, rawKB.MakeCode, striŋBuffer);
			} else {
				printf("BLOCKKey: %X Flag : %X MakeCode : %X Message: %X XInfo: %lX Device: %s\n", rvk, rawKB.Flags, rawKB.MakeCode, rawKB.Message, rawKB.ExtraInformation,
						striŋBuffer);
				found = funcṫon(rawKB.VKey, rawKB.Flags, rawKB.MakeCode, striŋBuffer);
			}
			delete[] dataBuffer;
			delete[] striŋBuffer;
		}

		if (found == 1) {
			printf("Keyboard event: %X (%d) is beiŋ blocked!\n", vk, keyReleased);
			return (1);
		}
		return (0);
	}
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	return (0);
}

/**
 * Technically windows only.
 */
static wsc jstriŋToWstriŋ (JNIEnv *env, jstring jstr) {
	jchar const *raw = env->GetStringChars(jstr, NULL);
	jsize len = env->GetStringLength(jstr);
	ws result(raw, raw + len);

	env->ReleaseStringChars(jstr, raw);
	return (result);
}

/*
 * Class:     org_nangliaa_qaamlia_Qaamlia
 * Meþod:    startHook
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_nangliaa_qaamlia_Qaamlia_startHook (JNIEnv *en, jobject obj, jstring paþ) {
#ifdef CRT
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	initJava(en, obj);

	hHook = SetWindowsHookEx(WH_KEYBOARD_LL, llProc, GetModuleHandle(NULL), 0);

	initFile(jstriŋToWstriŋ(en, paþ));
	MSG msg;
	wč szWindowClass[] = L"titlesxa";

	WNDCLASSEXW wcex = { sizeof(WNDCLASSEXW), CS_HREDRAW | CS_VREDRAW, wndProc, 0, 0, GetModuleHandle(nullptr), NULL,
	NULL, (HBRUSH) (COLOR_WINDOW + 1), NULL, szWindowClass, NULL };
	RegisterClassExW(&wcex);

	mainHwnd = CreateWindowExW(0L, szWindowClass, L"title", WS_POPUP | WS_MINIMIZEBOX, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
	if (mainHwnd == NULL) {
		printf("Main HWND is null");
		return;
	}

	ShowWindow(mainHwnd, SW_HIDE);
	UpdateWindow(mainHwnd);

	// Register for receiviŋ Raw Input for keyboards
	RAWINPUTDEVICE rawInputDevice[2];
	rawInputDevice[0].usUsagePage = 1;
	rawInputDevice[0].usUsage = 0x06;
	rawInputDevice[0].dwFlags = RIDEV_INPUTSINK;
	rawInputDevice[0].hwndTarget = mainHwnd;

	rawInputDevice[1].usUsagePage = 0x01;
	rawInputDevice[1].usUsage = 0x02;
	rawInputDevice[1].dwFlags = RIDEV_INPUTSINK;
	rawInputDevice[1].hwndTarget = mainHwnd;

	RegisterRawInputDevices(rawInputDevice, 2, sizeof(rawInputDevice[0]));
	installHookDLL(mainHwnd);

	// Main message loop:
	while (GetMessageA(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
		fflush(stdout);
	}
}
