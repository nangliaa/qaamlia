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

	DecisionRecord (us vkc, bool blk) {
		vk = vkc;
		block = blk;
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
