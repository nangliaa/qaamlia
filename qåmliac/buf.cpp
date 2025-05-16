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
 * @file	: buf.cpp
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#include "vks.h"
#include <deque>
#include <queue>

struct Hooked {
	uš vk;
	bool block;

	Hooked (uš _vk, bool _block) {
		vk = _vk;
		block = _block;
	}
};

std::deque<Hooked> hookBuffer;

void clearBuffer () {
	hookBuffer.clear();
}

void bufPush (uš vk, bool breaka) {
	hookBuffer.push_back(Hooked(vk, breaka));
}

sb searčBuffer (uš vk) {
	uš index = 0;
	if (!hookBuffer.empty()) {
		for (auto iterator = hookBuffer.begin(); iterator != hookBuffer.end(); iterator++, ++index) { // Searč ðe buffer for ðe matčiŋ record
			if (iterator->vk == vk) {
				for (int i = 0; i < index; ++i)
					hookBuffer.pop_front(); // Remove ðis and all precediŋ messages from ðe buffer
				return (iterator->block ? 1 : 0);
			}
		}
	}
	return (-1);
}


std::queue<uš> f;
void setAllowQueue (uš key1) {
	f.push(key1);
	f.push(key1);
}

void setPreAllowQueue (uš key1) {
	f.push(key1);
}

void setRelAllowQueue (uš key1) {
	f.push(key1);
}

void setAllowQueue (uš key1, uš key2) {
	f.push(key1);
	f.push(key2);
	f.push(key2);
	f.push(key1);
}

void setAllowQueue (uš key1, uš key2, uš key3) {
	f.push(key1);
	f.push(key2);
	f.push(key3);
	f.push(key3);
	f.push(key2);
	f.push(key1);
}

bool čeckAllowQueue (uš key) {
	if (f.empty()) return (false);
	return (f.front() == key);
}

void popAllowQueue () {
	f.pop();
}

uš frontAllowQueue () {
	return (f.front());
}
