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
 * @file	: init.cpp
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include "os.h"
#include "oðer.h"
#include "extra.h"
#include <vector>
#include <array>
#include <codecvt>
#include <locale>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

JavaVM *jvm;
JNIEnv *env;
jobject callbackObj;

std::set<std::pair<us, cca>> down;
std::unordered_set<us> downAny;
//std::unordered_set<us> downLL;
std::map<us, us> remaps;

std::map<std::pair<ul, carga>, ws> msa;

std::unordered_set<us> blockList;
std::unordered_set<us> ctrlBlockList;
ul lastTimePressed;
ws paþ;

bool playing = false;
bool llAlreadyDown = false;
bool ctrlDown;
bool ffDown;
wsc EMPTY_STRING = L"";

wsc getPaþ () {
	return (paþ);
}

void clearContainers (bool delJava) {
	if (delJava && callbackObj) {
		env->DeleteGlobalRef(callbackObj);
		callbackObj = NULL;
	}
	down.clear();
	downAny.clear();
	//downLL.clear();
	remaps.clear();
	msa.clear();
	blockList.clear();
	ctrlBlockList.clear();
}

struct retur {
	bool breaka;
	ws arg;
	ul command;

	retur (bool br, wcr ar, ul com) {
		breaka = br;
		arg = ar;
		command = com;
	}
};

static jstring wstringToJstring (JNIEnv *env, wcr wstr) {
	std::wstring_convert<std::codecvt_utf8_utf16<wc>> converter;
	st utf8str = converter.to_bytes(wstr);
	return (env->NewStringUTF(utf8str.c_str()));
}

static void javaVoidStringCall (cca meþod, wcr param1) {
	if (callbackObj) {
		JNIEnv *env;
		if (jvm->AttachCurrentThread((void**) &env, NULL) != JNI_OK) return;

		jclass cls = env->GetObjectClass(callbackObj);
		jmethodID mid = env->GetMethodID(cls, meþod, "(Ljava/lang/String;)V");

		if (mid) {
			env->CallVoidMethod(callbackObj, mid, wstringToJstring(env, param1));
		}

		jvm->DetachCurrentThread();
	}
}
static int javaIntStringCall (cca meþod, wcr param1) {
	jint a;
	if (callbackObj) {
		JNIEnv *env;
		if (jvm->AttachCurrentThread((void**) &env, NULL) != JNI_OK) return (-1);

		jclass cls = env->GetObjectClass(callbackObj);
		jmethodID mid = env->GetMethodID(cls, meþod, "(Ljava/lang/String;)I");

		if (mid) {
			a = env->CallIntMethod(callbackObj, mid, wstringToJstring(env, param1));
		}

		jvm->DetachCurrentThread();
	}
	printf("JNI int: %d\n", a);
	return (a);
}

void initJava (JNIEnv *en, jobject obj) {
	env = en;
	env->GetJavaVM(&jvm);
	callbackObj = env->NewGlobalRef(obj);  // Store callback object globally
}

void initFile (wcr lpaþ) {
	paþ = lpaþ;
	enterInit();

	wc line[BUFSIZE];

	us press = 0;
	ws args[2] { };
	ws device;

	bool cmdarg = false;
	bool paran = false;
	bool curly = false;
	bool colon = false;
	bool bs = false;
	bool var = false;
	bool varRepl = false;
	bool comment = false;
	ui inputStep = 0;
	ws str = L"";
	ws fileContent = L"";
	ws downeStr = L"";
	ws firstStr = L"";
	ws secondStr = L"";

	ws deviceName = L"";
	ws exeName = L"";
	ws windowName = L"";

	std::unordered_map<ws, std::reference_wrapper<ws>, WSHash> cases = { { L"win", windowName }, { L"exe", exeName }, { L"dev", deviceName } };

	FILE *file = nullptr;
	errno_t err = _wfopen_s(&file, (paþ + L"qåmlia.qlia").c_str(), L"r, ccs=UTF-8");
	if (file == NULL) {
		printf("Error openiŋ file, Errno: %d\n", err);
		return;
	}

	while (fgetws(line, sizeof(line), file)) {
		fileContent += line;
	}

	for (auto r = fileContent.begin(); r != fileContent.end(); r++) {
		wc c = *r;
		if (curly) {
			switch (c) {
			case L'$':
				if (bs) str += L'$';
				bs = !bs;
				break;
			case L';': {
				args[inputStep++] = str;
				str = L"";
				ul cmd = cmdCode(args[0]);
				if (cmd < (0xf0ULL << COMMANDSHIFT)) { //normal command
					std::vector<std::array<ul, DOWNENO>> downe;
					ub downNo = 0;
					std::array<ul, DOWNENO> a = { };
					downe.push_back(a);
					for (wc t : downeStr) {
						switch (t) {
						case L'\t':
						case L'\n':
						case L' ':
							break;
						case L'|': {
							std::array<ul, DOWNENO> b = { };
							downe.push_back(b);
							downNo = 0;
						}
							break;
						default:
							downe.back()[downNo++] = chari(t);
						}
					}
					downeStr = L"";
					carga m = { watst(deviceName.c_str()), watst(windowName.c_str()), watst(exeName.c_str()) };
					printf("Open file 2.2 %s, %s, %s", m[0].c_str(), m[1].c_str(), m[2].c_str());
					for (ul i = 0; i < downe.size(); i++) {
						std::array<ul, DOWNENO> cas = downe.at(i);
						msa.insert(
								std::pair<std::pair<ul, carga>, ws>(
										std::pair<ul, carga>(cmd | (cas[3] << DOWNESHIFT4) | (cas[2] << DOWNESHIFT3) | (cas[1] << DOWNESHIFT2) | (cas[0] << DOWNESHIFT1) | press,
												m), args[1]));
					}
					deviceName = L"";
					exeName = L"";
					windowName = L"";
				} else if (cmd == (CREMAP << COMMANDSHIFT)) { //remap
					if (args[1].length() == 1) remaps.insert( { press, chari(args[1][0]) });
					else if (args[1].length() == 3) remaps.insert( { press, chari(args[1][2], args[1][1]) });
					else printf("ERROR REMAP ONLY WORKS FOR 1 KEY");
				} else if (cmd == (CLLCTRLBLOCK << COMMANDSHIFT)) { //ctrlblock
					ctrlBlockList.insert(press);
					blockList.insert(press);
				} else { //block
					blockList.insert(press);
				}
				for (sz i = 0; i < 2; i++) {
					args[i] = L"";
				}
				if (colon) {
					colon = false;
					curly = false;
				}
				str = L"";
				comment = true;
				press = 0;
			}
				break;
			case L'}':
				if (!colon && wcscmp(str.c_str(), L"") == 0) {
					curly = false; //if after ; and after a {.
				} else str += c;
				break;
			case L' ':
				if (str.length() != 0) {
					if (inputStep == 0) {
						args[inputStep++] = str;
						str = L"";
					} else {
						str += c;
					}
				}
				break;
			case L'n':
				str += (bs ? '\n' : c);
				break;
			case L't':
				str += (bs ? '\t' : c);
				break;
			case L'b':
				str += (bs ? '\b' : c);
				break;
			case L'S':
				str += (bs ? ';' : c);
				break;
			default:
				str += c;
			}
			if (c != L'$') bs = false;
		} else if (cmdarg) {
			switch (c) {
			case L':':
				colon = true;
				inputStep = 0;
				curly = true;
			case L';':
				if (cases.find(firstStr) != cases.end()) {
					cases.at(firstStr).get() = secondStr;
				}
				printf("Open file 2e42e2e %ls %ls\n", firstStr.c_str(), exeName.c_str());
				cmdarg = false;
				firstStr = L"";
				secondStr = L"";
				break;
			case L' ':
				if (!varRepl) varRepl = true;
				else secondStr += c;
				break;
			case L'\t':
			case L'\n':
				break;
			default:
				if (varRepl) secondStr += c;
				else firstStr += c;
			}
		} else if (var) {
			switch (c) {
			case L';':
				replaceAll(fileContent, L'@' + firstStr, secondStr);
				var = false;
				firstStr = L"";
				secondStr = L"";
				comment = true;
				break;
			case L' ':
				varRepl = true;
				break;
			case L'\t':
			case L'\n':
				break;
			default:
				if (varRepl) secondStr += c;
				else firstStr += c;
			}
		} else if (comment) {
			if (c == L'\n') comment = false;
			else continue;
		} else if (paran) {
			switch (c) {
			case L'½':
				press = chari(*(++r), *(++r)); // get ðe two next
				break;
			case L')':
				paran = false;
				break;
			case L'\t':
			case L'\n':
			case L' ':
				continue;
			default:
				downeStr += c;
			}
		} else {
			switch (c) {
			case L'/':
				comment = true;
				break;
			case L'#':
				var = true;
				varRepl = false;
				break;
			case L'-':
				if (press == 0) press = chari(c);
				else {
					cmdarg = true;
					varRepl = false;
				}
				break;
			case L'½':
				press = chari(*(++r), *(++r)); // get ðe two next
				break;
			case L'(':
				paran = true;
				break;
			case L')':
				paran = false;
				break;
			case L':':
				colon = true;
			case L'{':
				inputStep = 0;
				curly = true;
				break;
			case L'\t':
			case L'\n':
			case L' ':
				continue;
			default:
				if (press == 0) press = chari(c);
			}
		}
	}
	fclose(file); // Close ðe file
	exitInit();
}

static bool isBlocked (us key) {
	return (blockList.find(key) != blockList.end() || ctrlBlockList.find(key) != ctrlBlockList.end());
}

//static bool isCtrlBlocked (us key) {
//	return (ctrlBlockList.find(key) != ctrlBlockList.end());
//}

static bool isdown (us key, const ch *device) {
	if (key == 0) return (true);
	if (strcmp(device, anyKB) == 0) return (downAny.find(key) != downAny.end());
	return (down.find( { key, device }) != down.end());
}

static bool checkCarg (carga const &ca, ub a, std::string compare) {
	for (scr each : split(ca[a], '|'))
		if (each.compare(compare) == 0) return (true);
	return (false);
}

/// downs don't matter keyboard right now.
static bool checkCom (std::pair<std::pair<ul, carga>, ws> const &com, cca dev, bool ll) {
	if (ll && (com.first.second[0].length() != 0 || com.second.find(L"%D") != com.second.npos)) return (false); // save for raw hook if triggered or telliŋ
	if (!isdown((com.first.first >> 10) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> 20) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> 30) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> 40) & KEYMASK, anyKB)) return (false);
	if (!ll && com.first.second[0].length() != 0 && !checkCarg(com.first.second, 0, dev)) return (false);
	if (com.first.second[1].length() != 0 && !checkCarg(com.first.second, 1, watst(activeWindowNameW().c_str()))) return (false);
	if (com.first.second[2].length() != 0 && !checkCarg(com.first.second, 2, watst(activeProcessNameW().c_str()))) return (false);
	return (true);
}

static retur getMouseAction (us key, int mx, int my, char const *dev, bool ll) {
	if (ll) {
		for (const auto &pair : msa) {
			if ((pair.first.first & KEYMASK) == key && checkCom(pair, dev, ll)) {
				return (retur(true, pair.second, pair.first.first));
			}
		}
	} else {
		for (const auto &pair : msa) {
			if ((pair.first.first & KEYMASK) == key && checkCom(pair, dev, ll)) {
				return (retur(true, pair.second, pair.first.first));
			}
		}
	}
	return (retur(false, EMPTY_STRING, 0));
}

//static vo clearIfUnpressed (ul time) {
//	if (time > lastTimePressed) { // If 500 ms has passed, no key should be pressed
//		for (int key = 0; key < VFF; key++) {
//			if (GetAsyncKeyState(key) & 0x8000) { // Check if ðe high-order bit is set
//				return;
//			}
//		}
//		down.clear();
//		downAny.clear();
//	}
//}

/**
 * getKeyAction
 */
static retur getKeyAction (us key, bool released, char const *dev, bool ll) {
//	ul time = getTime();
//
//	clearIfUnpressed(time);
//	lastTimePressed = time + DOWNWAITMS;

	if (ll) {
		if (checkAllowQueue(key)) return (retur(false, EMPTY_STRING, 0));
		if (!released) {
			llAlreadyDown = isdown(key, anyKB);
			downAny.insert(key);
			//downLL.insert(key);

			for (const auto &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && checkCom(pair, dev, ll)) return (retur(true, pair.second, pair.first.first));
			}
			if (remaps.find(key) != remaps.end()) return (retur(true, EMPTY_STRING, (CREMAP << COMMANDSHIFT) | remaps.at(key))); // TODO RAW

			return (retur(isBlocked(key), EMPTY_STRING, 0));
		} else {
			downAny.erase(key);
			//downLL.erase(key);
			if (remaps.find(key) != remaps.end()) return (retur(true, EMPTY_STRING, (CREMAP << COMMANDSHIFT) | (static_cast<ul>(1) << (COMMANDSHIFT - 1)) | remaps.at(key)));
			return (retur(isBlocked(key), EMPTY_STRING, 0));
		}
	} else {
		if (checkAllowQueue(key)) {
			popAllowQueue();
			return (retur(false, EMPTY_STRING, 0));
		}
		if (!released) {
			down.insert( { key, dev });
			if (playing) return (retur(playOnDev(dev, key, llAlreadyDown, true), EMPTY_STRING, 0));

			for (const auto &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && checkCom(pair, dev, ll)) return (retur(true, pair.second, pair.first.first));
			}

			if (strcmp(nullDevice, dev) != 0) { //artificials are not blocked
				for (us a : ctrlBlockList) {
					if (isdown(a, anyKB)) return (retur(true, EMPTY_STRING, 0));
				}
			}
		} else {
			down.erase( { key, dev });
			if (playing) return (retur(playOnDev(dev, key, llAlreadyDown, false), EMPTY_STRING, 0));

			if (strcmp(nullDevice, dev) != 0) { //artificials are not blocked
				for (us a : ctrlBlockList) {
					if (isdown(a, anyKB)) return (retur(true, EMPTY_STRING, 0));
				}
			}
		}
	}
	return (retur(false, EMPTY_STRING, 0));
}

static void calculate () {
	ui previousSequenceNumber = GetClipboardSequenceNumber();
	copy();
	printf("Waiting... %X", previousSequenceNumber);
	int i = 0;
	while (i < 10) {
		++i;
		ui currentSequenceNumber = GetClipboardSequenceNumber();
		Sleep(40);
		printf("Not yet");

		if (currentSequenceNumber != previousSequenceNumber) {
			double result = calc(getFromClipboard());
			if (result == INFINITY - 1) paste(L"Bad data");
			else paste(tws(result));
			return;
		}
	}
	//print((tws(calc(L"3.5/2.5*-2")) + L'\n').c_str());
}

static void exit () {
//	if (hHook) {
//		UnhookWindowsHookEx(hHook);
//		hHook = NULL;
//		printf("Low-level keyboard hook uninstalled.\n");
//	}
	destroySound();

	uninstallHookDLL();

	clearContainers(true);
	clearBuffer();

#ifdef CRT
	_CrtDumpMemoryLeaks();
#endif
	osExit(0);
}

static bool execute (us vk, retur breaka, bool ll, cca dev) {
	if (!ll) bufPush(vk, breaka.breaka);
	if (breaka.command != 0) {
		ul oðer = breaka.command;
		breaka.command >>= COMMANDSHIFT;
		switch (breaka.command) {
		case CRUN:
			run(formatString(breaka.arg, dev));
			break;
		case CCALC:
			calculate();
			break;
		case CPASTE:
			paste(formatString(breaka.arg, dev));
			break;
		case CPASTES:
			pasteS(formatString(breaka.arg, dev));
			break;
		case CAUTH:
			paste(itws(javaIntStringCall("auth", breaka.arg), 6, DEC));
			break;
		case CWINDOW:
			javaVoidStringCall("window", formatString(breaka.arg, dev));
			break;
		case CLIA:
			javaVoidStringCall("lia", formatString(breaka.arg, dev));
			break;
		case CROBOT:
			javaVoidStringCall("robot", breaka.arg);
			break;
		case CREMAP:
			if (oðer & (1ULL << (COMMANDSHIFT - 1))) release(oðer & KEYMASK);
			else press(oðer & KEYMASK);
			break;
		case CRELOAD:
			clearContainers(false);
			destroySound();
			initFile(paþ);
			break;
		case CMUSIC:
			playing = !playing;
			if (playing) startSound(breaka.arg);
			else destroySound();
			break;
		case CEXIT:
			exit();
		}
	}
	return (breaka.breaka);
}

sb function (us vk, int flag, int make, cca deviceName) {
	retur breaka = retur(false, L"", 0x0);
	bool released = flag & RI_KEY_BREAK;
	switch (vk) {
	case VSHIFT:
		if (make == 0x2A) breaka = getKeyAction(VLSHIFT, released, deviceName, false);
		else if (make == 0x36) breaka = getKeyAction(VRSHIFT, released, deviceName, false);
		break;
	case VCTRL:
		if (strcmp(deviceName, nullDevice) == 0) ctrlDown = true; //device is 0 if pressed as part of alt gr
		else if ((flag & RI_KEY_E0) == 0) breaka = getKeyAction(VLCTRL, released, deviceName, false);
		else breaka = getKeyAction(VRCTRL, released, deviceName, false);
		break;
	case VALT:
		if ((flag & RI_KEY_E0) == 0) breaka = getKeyAction(VLALT, released, deviceName, false);
		else if (ctrlDown) breaka = getKeyAction(VALTGR, released, deviceName, false);
		else breaka = getKeyAction(VRALT, released, deviceName, false);
		break;
	case VCTRLNUMLOCK: //FLAG 4 INSTEAD OF 2
		if ((flag & RI_KEY_E1) == 0) breaka = getKeyAction(VCTRLNUMLOCK, released, deviceName, false);
		else breaka = getKeyAction(VPAUSE, released, deviceName, false); //NORMAL
		break;
	case VRETURN: //OPPOSITE NUM
	case VNUMPGUP:
	case VNUMPGDN:
	case VNUMEND:
	case VNUMHOME:
	case VNUMLEFT:
	case VNUMUP:
	case VNUMRIGHT:
	case VNUMDOWN:
	case VNUMINS:
	case VNUMDEL:
		if ((flag & RI_KEY_E0) == 0) breaka = getKeyAction(vk, released, deviceName, false);
		else breaka = getKeyAction(vk | 0x100, released, deviceName, false); //Non-numpad
		break;
	case VFF:
		ffDown = true;
		break;
	case VPRTSC: //PRINTSCREEN TODO
//		if (ffDown) {//normal printscreen
//		} else {//ctrl printscreen
//		}
//		break;
	default:
		breaka = getKeyAction(vk, released, deviceName, false);
		break;
	}
	ctrlDown = vk == VK_CONTROL && strcmp(deviceName, nullDevice) == 0;
	//ffDown = (vk == VK_SNAPSHOT) | (vk == 255);
	return (execute(vk, breaka, false, deviceName) ? 1 : 0);
}

bool mouseFunction (ul vk, sl mx, sl my, cca deviceName) {
	retur breaka = retur(false, L"", 0x0);

	switch (vk) {
	case RI_MOUSE_LEFT_BUTTON_DOWN:
		breaka = getKeyAction(VML, false, deviceName, false);
		break;
	case RI_MOUSE_LEFT_BUTTON_UP:
		breaka = getKeyAction(VML, true, deviceName, false);
		break;
	case RI_MOUSE_RIGHT_BUTTON_DOWN:
		breaka = getKeyAction(VMR, false, deviceName, false);
		break;
	case RI_MOUSE_RIGHT_BUTTON_UP:
		breaka = getKeyAction(VMR, true, deviceName, false);
		break;
	case RI_MOUSE_MIDDLE_BUTTON_DOWN:
		breaka = getKeyAction(VMM, false, deviceName, false);
		break;
	case RI_MOUSE_MIDDLE_BUTTON_UP:
		breaka = getKeyAction(VMM, true, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_4_DOWN:
		breaka = getKeyAction(VM4, false, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_4_UP:
		breaka = getKeyAction(VM4, true, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_5_DOWN:
		breaka = getKeyAction(VM5, false, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_5_UP:
		breaka = getKeyAction(VM5, true, deviceName, false);
		break;
	case RI_MWD:
		breaka = getMouseAction(VMWD, mx, my, deviceName, false);
		break;
	case RI_MWU:
		breaka = getMouseAction(VMWU, mx, my, deviceName, false);
		break;
	default:
		breaka = getMouseAction(VMM, mx, my, deviceName, false);
	}
	return (execute(vk, breaka, false, deviceName));
}

bool functionLL (us vk, int flag) {
	retur breaka = retur(false, EMPTY_STRING, 0x0);
	bool released = flag & 0x80;
	switch (vk) {
	case VCTRLNUMLOCK: //OPPOSITE HL HOOK
		if ((flag & 1) == 0) breaka = getKeyAction(VPAUSE, released, anyKB, true);
		else breaka = getKeyAction(VCTRLNUMLOCK, released, anyKB, true);
		break;
	case VRETURN: //OPPOSITE
	case VNUMPGUP:
	case VNUMPGDN:
	case VNUMEND:
	case VNUMHOME:
	case VNUMLEFT:
	case VNUMUP:
	case VNUMRIGHT:
	case VNUMDOWN:
	case VNUMINS:
	case VNUMDEL:
		if ((flag & 1) == 0) breaka = getKeyAction(vk, released, anyKB, true);
		else breaka = getKeyAction(vk | 0x100, released, anyKB, true); //Non-numpad
		break;
	case VFF:
		//ffDown = true;
		break;
	case VPRTSC: //PRINTSCREEN TODO
		//if (ffDown) {} //normal printscreen
		//else {} //ctrl printscreen
		//break;
	default:
		breaka = getKeyAction(vk, released, anyKB, true);
		break;
	}
	//ctrlDown = vk == VK_CONTROL && wcscmp(deviceName, nullDevice) == 0;
	//ffDown = (vk == VK_SNAPSHOT) | (vk == 255);
	return (execute(vk, breaka, true, anyKB));
}
