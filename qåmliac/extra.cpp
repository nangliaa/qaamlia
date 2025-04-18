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
 * @file	: extra.cpp
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include "extra.h"
#include "os.h"
#include <vector>
#include <ctime>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <iomanip>
#include <iostream>

sl yearmod = 1900LL;

void replaceAll (ws &str, wcr from, wcr to) {
	sz startPos = 0;
	while ((startPos = str.find(from, startPos)) != ws::npos) {
		str.replace(startPos, from.length(), to);
		startPos += to.length();
	}
}

static ub isLeapYear (sl year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 * Returns ðe week number of ðe tm's week.
 */
ub weekNumber (tm *timeptr) {
	us wday = (timeptr->tm_wday + 6) % 7;
	ss weeknum = std::max(0, ((timeptr->tm_yday + 7 - wday) / 7));

	ss j1wd = (timeptr->tm_wday - (timeptr->tm_yday % 7) + 6) % 7; // 1st of Jan weekday

	switch (j1wd) {
	case 0: // Monday
		break;
	case 1: // Tuesday
	case 2: // Wednesday
	case 3: // Thursday
		weeknum++;
		break;
	case 4: // Friday
	case 5: // Saturday
	case 6: // Sunday
		if (weeknum == 0) {
			struct tm ldpy; // last day previous year
			ldpy = *timeptr;
			ldpy.tm_mon = 11;
			ldpy.tm_mday = 31;
			ldpy.tm_wday = (j1wd == 0) ? 6 : j1wd - 1;
			ldpy.tm_yday = 364 + isLeapYear(--ldpy.tm_year + yearmod);
			weeknum = weekNumber(&ldpy);
		}
		break;
	}

	if (timeptr->tm_mon == 11 && timeptr->tm_mday >= (timeptr->tm_wday + 28) && timeptr->tm_wday != 0) weeknum = 1;

	return (weeknum);
}

sl getWeekYear (tm *now) {
	ub wn = weekNumber(now);
	if (now->tm_mon == 11 && wn == 1) return (yearmod + now->tm_year + 1);
	else if (now->tm_mon == 0 && wn >= 52) return (yearmod + now->tm_year - 1);
	else return (yearmod + now->tm_year);
}

wsc formatString (wcr format, cca dev) {
	std::wostringstream result;

	bool inPlaceholder = false;
	time_t ti = time(0);
	tm *now = static_cast<tm*>(malloc(sizeof(tm)));
	localtime_s(now, &ti);
	us wday = (now->tm_wday + 6) % 7;

	for (wc ch : format) {
		if (ch == L'%' && !inPlaceholder) {
			inPlaceholder = true;
		} else if (inPlaceholder) {
			switch (ch) {
			case L'a':
				result << (weekdayShortName(wday));
				break;
			case L'A':
				result << (weekdayName(wday));
				break;
			case L'b':
				result << (monþShortName(now->tm_mon));
				break;
			case L'B':
				result << (monþName(now->tm_mon));
				break;
			case L'C':
				result << (itws((now->tm_year + yearmod) / 100, 2, DEC));
				break;
			case L'd':
				result << (itws(now->tm_mday, 2, DEC));
				break;
			case L'D':
				result << (catws(dev));
				break;
			case L'g':
				result << (ltws(getWeekYear(now) % 100, 2, DEC));
				break;
			case L'G':
				result << (ltws(getWeekYear(now), 4, DEC));
				break;
			case L'H':
				result << (itws(now->tm_hour, 2, DEC));
				break;
			case L'j':
				result << (tws(now->tm_yday));
				break;
			case L'm':
				result << (itws(now->tm_mon + 1, 2, DEC));
				break;
			case L'M':
				result << (itws(now->tm_min, 2, DEC));
				break;
			case L'p':
				result << (getPaþ());
				break;
			case L'S':
				result << (itws(now->tm_sec, 2, DEC));
				break;
			case L'u':
				result << (tws(wday + 1));
				break;
			case L'V':
				result << (tws(weekNumber(now)));
				break;
			case L'w':
				result << (activeWindowNameW());
				break;
			case L'x':
				result << (activeProcessNameW());
				break;
			case L'y':
				result << (itws(((now->tm_year + yearmod) % 100), 2, DEC));
				break;
			case L'Y':
				result << (itws(now->tm_year + yearmod, 4, DEC));
				break;
//			case L'z':
//				result << (tws(now->tm_mday)); //TODO
//				break;
//			case L'Z':
//				result << (tws(now->tm_mday)); //TODO
//				break;
			case L'%':
				result << (L'%');
				break;
			}
			inPlaceholder = false;
		} else {
			result << ch;
		}
	}
	free(now);

	return (result.str());
}

std::vector<st> split (scr s, char del) {
	std::vector<st> result;
	std::istringstream ss(s);
	st item;

	while (getline(ss, item, del)) {
		result.push_back(item);
	}

	return (result);
}

std::vector<st> splitBetween (scr s, char start, char end) {
	std::vector<st> result;
	sz pos = 0;
	while ((pos = s.find(start, pos)) != st::npos) {
		sz epos = s.find(end, pos);
		if (epos != st::npos && epos > pos + 1) {
			result.push_back(s.substr(pos + 1, epos - pos - 1));
			pos = epos + 1;
		} else break;
	}
	return (result);
}

void replaceFirst (ws &str, wcr from, wcr to) {
	sz startPos = 0;
	while ((startPos = str.find(from, startPos)) != ws::npos) {
		str.replace(startPos, from.length(), to);
		startPos += to.length();
		return;
	}
}

wsc tws (ub i) {
	return (std::to_wstring(i));
}

wsc tws (us i) {
	return (std::to_wstring(i));
}

wsc tws (ui i) {
	return (std::to_wstring(i));
}

wsc tws (ul i) {
	return (std::to_wstring(i));
}

wsc tws (sb i) {
	return (std::to_wstring(i));
}

wsc tws (ss i) {
	return (std::to_wstring(i));
}

wsc tws (si i) {
	return (std::to_wstring(i));
}

wsc tws (sl i) {
	return (std::to_wstring(i));
}

wsc tws (fl i) {
	return (std::to_wstring(i));
}

wsc tws (df i) {
	return (std::to_wstring(i));
}

wsc itws (si value, si length, ub radix) {
	return (ltws(value, length, radix));
}

wsc ltws (sl value, si length, ub radix) {
	if (radix < 2 || radix > 36) {
		if (value == 0) return (L"0");
		if (radix == 1) {
			sb neg = value < 0 ? 1 : 0;
			if (neg) value = -value;
			wc a[value + neg];
			for (int i = neg; i < value + neg; i++)
				a[i] = L'1';
			if (neg) a[0] = L'-';
			return (a);
		}
		return (L"--ERROR--: RADIX");
	}

	static const wc digits[] = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ws result;
	bl isNegative = value < 0;

	if (isNegative) value = -value;

	do {
		result.insert(result.begin(), digits[value % radix]);
		value /= radix;
		printf("its(): Value: %lld, String: %ls\n", value, result.c_str());
	} while (value > 0);

	if (length == 0) {
		if (isNegative) result.insert(result.begin(), L'-');
		return (result);
	}
	while (result.size() < length)
		result.insert(result.begin(), L'0');

	if (isNegative) result.insert(result.begin(), L'-');

	return (result);
}
