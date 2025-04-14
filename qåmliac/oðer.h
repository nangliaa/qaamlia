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
 * @file	: oðer.h
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once

#include "vks.h"
#include "org_nangliaa_qaamlia_Qaamlia.h"

void initFile (wcr lpaþ);
bool functionLL (us vk, int flag);
bool mouseFunction (ul vk, sl mx, sl my, cca deviceName);
sb function (us vk, int flag, int make, cca deviceName);
void initJava (JNIEnv *en, jobject obj);

void clearBuffer ();
void bufPush (us vk, bool breaka);
sb searchBuffer (us vk);

df calc (wcr str);
ul cmdCode (wcr cc);
void enterInit ();
void exitInit ();
us chari (wc cc);
us chari (wc a, wc b);
void setAllowQueue (us key1);
void setAllowQueue (us key1, us key2);
void setAllowQueue (us key1, us key2, us key3);
bl checkAllowQueue (us key);
void popAllowQueue ();
us frontAllowQueue ();
void setPreAllowQueue (us key1);
void setRelAllowQueue (us key1);

void startSound (wcr arg);
void destroySound ();
bool playOnDev (cca dev, us key, bool llAlreadyDown, bool start);
