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
 * @file	: os.h
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once

#include "vks.h"

#if defined(_WIN64)
//64 bit windows
#define WIN
#elif defined(_WIN32)
//32 bit windows
#define WIN
#elif defined(__CYGWIN__)
//also windows I þink
#define WIN
#elif defined(__ANDROID__)
//android
#elif defined(__linux__)
//linux
#elif defined(__APPLE__) && defined(__MACH__)
//mac os
#elif defined(_WIN32)
//32 bit windows
#elif defined(_WIN32)
//32 bit windows
#elif defined(_WIN32)
//32 bit windows
#endif

#ifdef WIN
#include "hookDLL.h"

#endif

st const watst (wca wstr);
wsc catws (cca str);
st const activeProcessNameA ();
st const activeWindowNameA ();
wsc activeProcessNameW ();
wsc activeWindowNameW ();
ul getTime ();
wc getFileSeparator ();
void osExit (int statusCode);

void copyToClipboard (wcr text);
void getClipboardImage ();
wsc getFromClipboard ();
void setHWND (HWND hwand);

void press (us key);
void release (us key);
void copy ();
void paste (wcr word);
void pasteS (wcr word);
void run (wcr command);
void simulateKeyPress (us vk);
