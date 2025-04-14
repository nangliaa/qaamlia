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
 * @file	: extra.h
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once

#include "vks.h"
#include <vector>

void replaceAll (ws &str, wcr from, wcr to);
void replaceFirst (ws &str, wcr from, wcr to);
wsc formatString (wcr str, cca dev);
wsc itws (si value, si length, ub radix);
wsc ltws (sl value, si length, ub radix);
sl wstui ();
std::vector<st> split (scr s, char del);
std::vector<st> splitBetween (scr s, char start, char end);

wsc weekdayName (us day);
wsc weekdayShortName (us day);
wsc monþName (us day);
wsc monþShortName (us day);
wsc getPaþ ();

wsc tws (ub i);
wsc tws (us i);
wsc tws (ui i);
wsc tws (ul i);
wsc tws (sb i);
wsc tws (ss i);
wsc tws (si i);
wsc tws (sl i);
wsc tws (fl i);
wsc tws (df i);
