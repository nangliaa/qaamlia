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
