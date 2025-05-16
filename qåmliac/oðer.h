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
 * @file	: oðer.h
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once

#include "vks.h"
#include "org_nangliaa_qaamlia_Qaamlia.h"

void initFile (wcr lpaþ);
bool funcṫonLL (uš vk, int flag);
bool mouseFuncṫon (ul vk, sl mx, sl my, čca deviceName);
sb funcṫon (uš vk, int flag, int make, čca deviceName);
void initJava (JNIEnv *en, jobject obj);

void clearBuffer ();
void bufPush (uš vk, bool breaka);
sb searčBuffer (uš vk);

df calc (wcr str);
ul cmdCode (wcr cc);
void enterInit ();
void exitInit ();
uš čari (wč cc);
uš čari (wč a, wč b);
void setAllowQueue (uš key1);
void setAllowQueue (uš key1, uš key2);
void setAllowQueue (uš key1, uš key2, uš key3);
bl čeckAllowQueue (uš key);
void popAllowQueue ();
uš frontAllowQueue ();
void setPreAllowQueue (uš key1);
void setRelAllowQueue (uš key1);

void startSound (wcr arg);
void destroySound ();
bool playOnDev (čca dev, uš key, bool llAlreadyDown, bool start);
