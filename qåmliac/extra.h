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
 * @file	: extra.h
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once

#include "vks.h"
#include <vector>

void replaceAll (ws &str, wcr from, wcr to);
void replaceFirst (ws &str, wcr from, wcr to);
wsc formatStriŋ (wcr str, čca dev);
wsc itws (si value, si leŋþ, ub radix);
wsc ltws (sl value, si leŋþ, ub radix);
sl wstui ();
std::vector<st> split (scr s, čą del);
std::vector<st> splitBetween (scr s, čą start, čą end);

wsc weekdayName (uš day);
wsc weekdayShortName (uš day);
wsc monþName (uš day);
wsc monþShortName (uš day);
wsc getPaþ ();

wsc tws (ub i);
wsc tws (uš i);
wsc tws (ui i);
wsc tws (ul i);
wsc tws (sb i);
wsc tws (sš i);
wsc tws (si i);
wsc tws (sl i);
wsc tws (fl i);
wsc tws (df i);
