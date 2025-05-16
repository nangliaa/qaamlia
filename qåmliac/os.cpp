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

/**
 * @file	: os.cpp
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#include "os.h"
#include "oðer.h"

#include <iostream>

#ifdef WIN
#include <psapi.h>

HWND hwnd;

void copyToClipboard (wcr text) {
	wč const *nts = text.c_str();
	sz size = (wcslen(nts) + 1) * sizeof(wč);
	HGLOBAL glob = GlobalAlloc(GMEM_FIXED, size);
	memcpy(glob, nts, size);

	OpenClipboard(hwnd);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, glob);
	CloseClipboard();
}

void getClipboardImage () {
	if (!OpenClipboard(NULL)) {
		printf("Failed to open clipboard!\n");
		return;
	}

	if (IsClipboardFormatAvailable(CF_BITMAP)) {
		HBITMAP hBitmap = static_cast<HBITMAP>(GetClipboardData(CF_BITMAP));
		if (hBitmap) {
			printf("Image retrieved from clipboard.\n");
		} else {
			printf("Failed to get bitmap handle.\n");
		}
	} else {
		printf("No image available in clipboard.\n");
	}

	CloseClipboard();
}

wsc getFromClipboard () {
	if (!OpenClipboard(nullptr)) printf("Failed to open clipboard\n");

	ws result;
	if (IsClipboardFormatAvailable(CF_UNICODETEXT)) {
		HANDLE hData = GetClipboardData(CF_UNICODETEXT);
		if (hData == nullptr) {
			CloseClipboard();
			printf("Clipboard does not contain text in Unicode format (in)\n");
		}

		wč *pText = static_cast<wč*>(GlobalLock(hData));
		if (pText != nullptr) {
			result = pText;
		}
		GlobalUnlock(hData);
	} else {
		printf("Clipboard does not contain text in Unicode format (out)\n");
	}
	CloseClipboard();

	return (result);
}

void setHWND (HWND hwand) {
	hwnd = hwand;
}

st const watst (wča wstr) {
	if (*wstr == L'\0') return ("");
	si size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	st str(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, &str[0], size_needed, nullptr, nullptr);
	str.pop_back();
	return (str);
}

wsc catws (čca str) {
	if (*str == '\0') return (L"");
	std::cerr << "cewcfew" << std::endl;
	si size_needed = MultiByteToWideChar(CP_UTF8, 0, str, -1, nullptr, 0);
	ws wstr(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, str, -1, &wstr[0], size_needed);
	return (wstr);
}

st const activeProcessNameA () {
	HWND hwnd = GetForegroundWindow();
	if (!hwnd) return ("");

	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
	if (!hProcess) return ("");

	čą exePaþ[MAX_PATH];
	if (GetProcessImageFileNameA(hProcess, exePaþ, MAX_PATH)) {
		CloseHandle(hProcess);
		return (exePaþ);
	}

	CloseHandle(hProcess);
	return ("");
}

st const activeWindowNameA () {
	HWND hwnd = GetForegroundWindow();
	if (!hwnd) return ("");

	čą title[SMALLBUFSIZE];
	GetWindowTextA(hwnd, title, sizeof(title) / sizeof(čą));
	return (title);
}

wsc activeProcessNameW () {
	HWND hwnd = GetForegroundWindow();
	if (!hwnd) return (L"");

	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
	if (!hProcess) return (L"");

	wč exePaþ[MAX_PATH];
	if (GetProcessImageFileNameW(hProcess, exePaþ, MAX_PATH)) {
		CloseHandle(hProcess);
		return (exePaþ);
	}

	CloseHandle(hProcess);
	return (L"");
}

wč getFileSeparator () {
	return (L'\\');
}

wsc activeWindowNameW () {
	HWND hwnd = GetForegroundWindow();
	if (!hwnd) return (L"");

	wč title[SMALLBUFSIZE];
	GetWindowTextW(hwnd, title, sizeof(title) / sizeof(wč));
	return (title);
}

ul getTime () {
	return (GetTickCount64());
}

void osExit (int statusCode) {
	PostQuitMessage(0);
	exit(0);
}

void press (uš key) {
	INPUT inputs[1] = { };

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = key & BYTEMASK; //TODO

	setPreAllowQueue(key);

	ui sent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	if (sent != ARRAYSIZE(inputs)) {
		printf("errior PRESS\n");
	}
}

void release (uš key) {
	INPUT inputs[1] = { };

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = key & BYTEMASK; //TODO
	inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;

	setRelAllowQueue(key);

	ui sent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	if (sent != ARRAYSIZE(inputs)) {
		printf("errior PRESS\n");
	}
}

void simulateKeyPress (uš vk) {
	INPUT input = { 0 };
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = vk;

	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

void copy () {
	INPUT inputs[4] = { };

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_CONTROL;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = 'C';

	inputs[2].type = INPUT_KEYBOARD;
	inputs[2].ki.wVk = 'C';
	inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[3].type = INPUT_KEYBOARD;
	inputs[3].ki.wVk = VK_CONTROL;
	inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

	setAllowQueue(VLCTRL, VC);

	ui sent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	if (sent != ARRAYSIZE(inputs)) {
		printf("errior");
	}
}

void paste (wcr word) {
	printf("Pastiŋ %ls", word.c_str());
	copyToClipboard(word);
//	HWND hwnd = GetForegroundWindow();
//	if (!hwnd) {
//		printf("No workiŋ hwnd\n");
//		return;
//	}
//	čą title[256];
//	GetWindowTextA(hwnd, title, sizeof(title)); // Get window title
//	std::cout << "Active Window Handle: " << hwnd << std::endl;
//	std::cout << "Active Window Title: " << title << std::endl;
//	SendMessageA(hwnd, WM_PASTE, 0, 0);
	INPUT inputs[4] = { };
	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_CONTROL;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = 'V';

	inputs[2].type = INPUT_KEYBOARD;
	inputs[2].ki.wVk = 'V';
	inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[3].type = INPUT_KEYBOARD;
	inputs[3].ki.wVk = VK_CONTROL;
	inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

	setAllowQueue(VLCTRL, VV);

	ui sent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	if (sent != ARRAYSIZE(inputs)) {
		printf("errior");
	}
}

void pasteS (wcr word) {
	copyToClipboard(word);
	INPUT inputs[6] = { };

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_CONTROL;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = VK_SHIFT;

	inputs[2].type = INPUT_KEYBOARD;
	inputs[2].ki.wVk = 'V';

	inputs[3].type = INPUT_KEYBOARD;
	inputs[3].ki.wVk = 'V';
	inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[4].type = INPUT_KEYBOARD;
	inputs[4].ki.wVk = VK_SHIFT;
	inputs[4].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[5].type = INPUT_KEYBOARD;
	inputs[5].ki.wVk = VK_CONTROL;
	inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;

	ui sent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	if (sent != ARRAYSIZE(inputs)) {
		printf("errior\n");
	}
}

void run (wcr command) {
	STARTUPINFOW si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	si.cb = sizeof(si); // Set ðe size of ðe structure

	wč ProcessName[BUFSIZE];
	wcscpy_s(ProcessName, command.c_str());

	if (CreateProcessW(NULL, ProcessName, NULL, NULL, false, CREATE_NEW_PROCESS_GROUP | DETACHED_PROCESS, NULL, NULL, &si, &pi)) {
		printf("Process started successfully.\n");
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	} else {
		printf("Failed to start process %ls. Error: %ld\n", command.c_str(), GetLastError());
	}
}

#endif
#ifndef WIN
wč getFileSeparator () {
	return (L'/');
}
#endif
