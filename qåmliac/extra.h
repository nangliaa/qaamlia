/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as published by ðe Free Software Foundation,
	eiðer version 3 of ðe License, or (at your option) any later version.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÐOUT ANY WARRANTY;
	wiðout even ðe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You should have received a copy of ðe GNU General Public License
	aloŋ wið ðis program. If not, see <https://www.gnu.org/licenses/>.
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
