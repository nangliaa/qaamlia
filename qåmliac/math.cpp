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
 * @file	: math.cpp
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include <list>
#include <cmath>

#include "oðer.h"

df calc (ws const &str) {
	std::list<df> numbers;
	std::list<wc> ops;
	ws s;
	ui parans = 0;
	bl lastNumber = false; //if starts with -, always negative number
	printf("Calc str: %ls", str.c_str());
	for (wc c : str) {
		if (parans != 0) {
			if (c == L'(') ++parans;
			else if (c == L')') {
				if (--parans == 0) {
					numbers.push_back(calc(s));
					continue;
				}
			}
			s += c;
		} else {
			switch (c) {
			case L'0':
			case L'1':
			case L'2':
			case L'3':
			case L'4':
			case L'5':
			case L'6':
			case L'7':
			case L'8':
			case L'9':
			case L'.':
				s += c;
				lastNumber = true;
				break;
			case L'⁰':
			case L'¹':
			case L'²':
			case L'³':
			case L'⁴':
			case L'⁵':
			case L'⁶':
			case L'⁷':
			case L'⁸':
			case L'⁹':
				s += c;
				lastNumber = true;
				break;
			case L'(':
				if (!s.empty()) {
					numbers.push_back(stod(s));
					s.clear();
					//ops.push_back('*');
				}
				++parans;
				break;
			case L' ':
				if (!s.empty()) {
					numbers.push_back(stod(s));
					s.clear();
				}
				break;
			case L'-':
				if (!lastNumber) {
					s += c;
					break;
				}
			case L'+':
			case L'*':
			case L'/':
				if (!lastNumber) return (INFINITY - 1);
				ops.push_back(c);
				if (!s.empty()) {
					numbers.push_back(stod(s));
					s.clear();
				}
				lastNumber = false;
			}
		}
	}
	if (!s.empty()) numbers.push_back(stod(s));
	if (numbers.size() != ops.size() + 1) return (INFINITY - 1);
	auto it = numbers.begin();
	auto opit = ops.begin();
	si nitle = -1;
	for (auto a : numbers) {
		printf("%lf ", a);
		++nitle;
	}

	for (df a : numbers)
		printf("%lf ", a);
	printf("\n");
	for (wc a : ops)
		printf("%lc ", a);
	printf("\n");

	si nitle2 = nitle;
	for (si i = 0; i < nitle; i++) {
		df v1 = *it;
		switch (*opit) {
		case L'*':
			it = numbers.erase(it);
			printf("%lf * %lf; ", v1, *it);
			*it = v1 * *it;
			--nitle2;
			opit = ops.erase(opit);
			break;
		case L'/':
			it = numbers.erase(it);
			printf("%lf / %lf; ", v1, *it);
			*it = v1 / *it;
			--nitle2;
			opit = ops.erase(opit);
			break;
		default:
			++it;
			++opit;
		}
	}

	it = numbers.begin();
	opit = ops.begin();

	for (si i = 0; i < nitle2; i++) {
		df v1 = *it;
		switch (*opit) {
		case L'+':
			it = numbers.erase(it);
			printf("%lf + %lf; ", v1, *it);
			*it = v1 + *it;
			break;
		case L'-':
			it = numbers.erase(it);
			printf("%lf - %lf; ", v1, *it);
			*it = v1 - *it;
			break;
		}
		opit++;
	}

	return (*it);
}
