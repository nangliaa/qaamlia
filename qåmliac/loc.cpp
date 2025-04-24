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
 * @file	: loc.cpp
 * @desc	: Contains localisation of time terms.
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include "extra.h"

constexpr us sv = 1;
constexpr us enð = 2;
constexpr us enth = 3;

us locale = sv; //sv-SE

static wsc weekDays[][7] = { { L"Måndag", L"Tisdag", L"Onsdag", L"Torsdag", L"Fredag", L"Lördag", L"Söndag" }, // nagolima
		{ L"Måndag", L"Tisdag", L"Onsdag", L"Torsdag", L"Fredag", L"Lördag", L"Söndag" }, // sv
		{ L"Monday", L"Tuesday", L"Wednesday", L"Þursday", L"Friday", L"Saturday", L"Sunday" }, // enþ
		{ L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday", L"Saturday", L"Sunday" }, // enth
		};

static wsc shortWeekDays[][7] = { { L"Mån", L"Tis", L"Ons", L"Tor", L"Fre", L"Lör", L"Sön" }, // nagolima
		{ L"Mån", L"Tis", L"Ons", L"Tor", L"Fre", L"Lör", L"Sön" }, // sv
		{ L"Mon", L"Tue", L"Wed", L"Þur", L"Fri", L"Sat", L"Sun" }, // enþ
		{ L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat", L"Sun" }, // enth
		};

static wsc monþs[][12] = { { L"J", L"F", L"M", L"A", L"M", L"J", L"J", L"A", L"S", L"O", L"N", L"D" }, // nagolima
		{ L"Januari", L"Februari", L"Mars", L"April", L"Maj", L"Juni", L"Juli", L"Augusti", L"September", L"Oktober", L"November", L"December" }, // sv
		{ L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December" }, // enþ
		{ L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December" }, // enth
		};

static wsc shortMonþs[][12] = { { L"J", L"F", L"M", L"A", L"M", L"J", L"J", L"A", L"S", L"O", L"N", L"D" }, // nagolima
		{ L"Jan", L"Feb", L"Mar", L"Apr", L"Maj", L"Jun", L"Jul", L"Aug", L"Sep", L"Okt", L"Nov", L"Dec" }, // sv
		{ L"Jan", L"Feb", L"Mar", L"Apr", L"Maj", L"Jun", L"Jul", L"Aug", L"Sep", L"Okt", L"Nov", L"Dec" }, // enþ
		{ L"Jan", L"Feb", L"Mar", L"Apr", L"Maj", L"Jun", L"Jul", L"Aug", L"Sep", L"Okt", L"Nov", L"Dec" }, // enth
		};

wsc weekdayName (us day) {
	return (weekDays[locale][day]);
}

wsc weekdayShortName (us day) {
	return (shortWeekDays[locale][day]);
}

wsc monþName (us monþ) {
	return (monþs[locale][monþ]);
}

wsc monþShortName (us monþ) {
	return (shortMonþs[locale][monþ]);
}
