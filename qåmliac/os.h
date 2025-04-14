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
