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
 * @file	: buf.cpp
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include "vks.h"
#include <deque>

struct DecisionRecord {
	us vk;
	bool block;

	DecisionRecord (us _virtualKeyCode, bool _decision) {
		vk = _virtualKeyCode;
		block = _decision;
	}
};

std::deque<DecisionRecord> decisionBuffer;

void clearBuffer () {
	decisionBuffer.clear();
}

void bufPush (us vk, bool breaka) {
	decisionBuffer.push_back(DecisionRecord(vk, breaka));
}

sb searchBuffer (us vk) {
	us index = 0;
	if (!decisionBuffer.empty()) {
		for (auto iterator = decisionBuffer.begin(); iterator != decisionBuffer.end(); iterator++, ++index) { // Search the buffer for the matching record
			if (iterator->vk == vk) {
				for (int i = 0; i < index; ++i)
					decisionBuffer.pop_front(); // Remove this and all preceding messages from the buffer
				return (iterator->block ? 1 : 0);
			}
		}
	}
	return (-1);
}
