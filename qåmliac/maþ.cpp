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
 * @file	: maþ.cpp
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#include <list>
#include <cmath>

#include "oðer.h"

df calc (wcr str) {
	std::list<df> numbers;
	std::list<wč> ops;
	ws s;
	ui parans = 0;
	bl lastNumber = false; //if starts wið -, always negative number
	printf("Calc str: %ls", str.c_str());
	for (wč c : str) {
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
	for (wč a : ops)
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
