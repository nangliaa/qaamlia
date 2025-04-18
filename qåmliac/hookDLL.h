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
 * @file	: hookDLL.h
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: WIN32
 */

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef HOOKDLL_EXPORTS
#define HOOKDLL_API __declspec(dllexport)
#else
#define HOOKDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
HOOKDLL_API BOOL installHookDLL (HWND hwndParent);
HOOKDLL_API BOOL uninstallHookDLL ();
#ifdef __cplusplus
}
#endif
