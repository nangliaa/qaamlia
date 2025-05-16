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
 * @file	: init.cpp
 * @desc	: TODO
 * @auþor	: Johannah Granström
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

std::set<std::pair<uš, čca>> down;
std::unordered_set<uš> downAny;
//std::unordered_set<us> downLL;
std::map<uš, uš> remaps;

std::map<std::pair<ul, carga>, ws> msa;

std::unordered_set<uš> blockList;
std::unordered_set<uš> ctrlBlockList;
ul lastTimePressed;
ws paþ;

bool playiŋ = false;
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
	bool rel;

	retur (bool br, wcr ar, ul com, bool rl) {
		breaka = br;
		arg = ar;
		command = com;
		rel = rl;
	}
};

static jstring wstriŋToJstriŋ (JNIEnv *env, wcr wstr) {
	std::wstring_convert<std::codecvt_utf8_utf16<wč>> converter;
	st utf8str = converter.to_bytes(wstr);
	return (env->NewStringUTF(utf8str.c_str()));
}

static void javaVoidStriŋCall (čca meþod, wcr param1) {
	if (callbackObj) {
		JNIEnv *env;
		if (jvm->AttachCurrentThread((void**) &env, NULL) != JNI_OK) return;

		jclass cls = env->GetObjectClass(callbackObj);
		jmethodID mid = env->GetMethodID(cls, meþod, "(Ljava/lang/String;)V");

		if (mid) {
			env->CallVoidMethod(callbackObj, mid, wstriŋToJstriŋ(env, param1));
		}

		jvm->DetachCurrentThread();
	}
}
static int javaIntStriŋCall (čca meþod, wcr param1) {
	jint a;
	if (callbackObj) {
		JNIEnv *env;
		if (jvm->AttachCurrentThread((void**) &env, NULL) != JNI_OK) return (-1);

		jclass cls = env->GetObjectClass(callbackObj);
		jmethodID mid = env->GetMethodID(cls, meþod, "(Ljava/lang/String;)I");

		if (mid) {
			a = env->CallIntMethod(callbackObj, mid, wstriŋToJstriŋ(env, param1));
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

	wč line[BUFSIZE];

	uš press = 0;
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
		wč c = *r;
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
					for (wč t : downeStr) {
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
							downe.back()[downNo++] = čari(t);
						}
					}
					downeStr = L"";
					carga m = { watst(deviceName.c_str()), watst(windowName.c_str()), watst(exeName.c_str()) };
					printf("Open file 2.2 %s, %s, %s", m[0].c_str(), m[1].c_str(), m[2].c_str());
					for (ul i = 0; i < downe.size(); i++) {
						std::array<ul, DOWNENO> cas = downe.at(i);
						msa.insert(
								std::pair<std::pair<ul, carga>, ws>(
										std::pair<ul, carga>(cmd | (cas[3] << DOWNEŠIFT4) | (cas[2] << DOWNEŠIFT3) | (cas[1] << DOWNEŠIFT2) | (cas[0] << DOWNEŠIFT1) | press,
												m), args[1]));
					}
					deviceName = L"";
					exeName = L"";
					windowName = L"";
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
				press = čari(*(++r), *(++r)); // get ðe two next
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
				if (press == 0) press = čari(c);
				else {
					cmdarg = true;
					varRepl = false;
				}
				break;
			case L'½':
				press = čari(*(++r), *(++r)); // get ðe two next
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
				if (press == 0) press = čari(c);
			}
		}
	}
	fclose(file); // Close ðe file
	exitInit();
}

static bool isBlocked (uš key) {
	return (blockList.find(key) != blockList.end() || ctrlBlockList.find(key) != ctrlBlockList.end());
}

//static bool isCtrlBlocked (us key) {
//	return (ctrlBlockList.find(key) != ctrlBlockList.end());
//}

static bool isdown (uš key, const čą *device) {
	if (key == 0) return (true);
	if (strcmp(device, anyKB) == 0) return (downAny.find(key) != downAny.end());
	return (down.find( { key, device }) != down.end());
}

static bool čeckCarg (carga const &ca, ub a, scr compare) {
	for (scr eač : split(ca[a], '|'))
		if (eač.compare(compare) == 0) return (true);
	return (false);
}

/// downs don't matter keyboard right now.
static bool čeckCom (std::pair<std::pair<ul, carga> const, ws> const &com, čca dev, bool ll, bool rel) {
	if ((rel && (com.first.first >> COMMANDSHIFT) != CREMAP) || (ll && (com.first.second[0].length() != 0 || com.second.find(L"%D") != com.second.npos))) return (false); // save for raw hook if triggered or telliŋ
	if (!isdown((com.first.first >> DOWNEŠIFT1) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> DOWNEŠIFT2) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> DOWNEŠIFT3) & KEYMASK, anyKB)) return (false);
	if (!isdown((com.first.first >> DOWNEŠIFT4) & KEYMASK, anyKB)) return (false);
	if (!ll && com.first.second[0].length() != 0 && !čeckCarg(com.first.second, 0, dev)) return (false);
	if (com.first.second[1].length() != 0 && !čeckCarg(com.first.second, 1, watst(activeWindowNameW().c_str()))) return (false);
	if (com.first.second[2].length() != 0 && !čeckCarg(com.first.second, 2, watst(activeProcessNameW().c_str()))) return (false);
	return (true);
}

static retur getMouseAcṫon (uš key, int mx, int my, čca dev, bool ll) {
	if (ll) {
		for (std::pair<std::pair<ul, carga> const, ws> const &pair : msa) {
			if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, false)) {
				return (retur(true, pair.second, pair.first.first, false));
			}
		}
	} else {
		for (std::pair<std::pair<ul, carga> const, ws> const &pair : msa) {
			if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, false)) {
				return (retur(true, pair.second, pair.first.first, false));
			}
		}
	}
	return (retur(false, EMPTY_STRING, 0, false));
}

static vo clearIfUnpressed (ul time) {
	if (time > lastTimePressed) { // If 500 ms has passed, no key should be pressed
//		for (int key = 0; key < VFF; key++) {
//			if (GetAsyncKeyState(key) & 0x8000) { // Čeck if ðe high-order bit is set
//				return;
//			}
//		}
		down.clear();
		downAny.clear();
	}
}

/**
 * getKeyAcṫon
 */
static retur getKeyAcṫon (uš key, bool released, čca dev, bool ll) {
	if (!playiŋ) {
		ul time = getTime();
		clearIfUnpressed(time);
		lastTimePressed = time + DOWNWAITMS;
	}

	if (ll) {
		if (čeckAllowQueue(key)) return (retur(false, EMPTY_STRING, 0, false));
		if (!released) {
			llAlreadyDown = isdown(key, anyKB);
			downAny.insert(key);
			//downLL.insert(key);

			for (std::pair<std::pair<ul, carga> const, ws> const &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, false)) return (retur(true, pair.second, pair.first.first, false));
			}

			return (retur(isBlocked(key), EMPTY_STRING, 0, false));
		} else {
			downAny.erase(key);
			//downLL.erase(key);

			for (std::pair<std::pair<ul, carga> const, ws> const &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, true)) return (retur(true, pair.second, pair.first.first, true));
			}

			return (retur(isBlocked(key), EMPTY_STRING, 0, true));
		}
	} else {
		if (čeckAllowQueue(key)) {
			popAllowQueue();
			return (retur(false, EMPTY_STRING, 0, false));
		}
		if (!released) {
			down.insert( { key, dev });
			if (playiŋ) return (retur(playOnDev(dev, key, llAlreadyDown, true), EMPTY_STRING, 0, false));

			for (const auto &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, false)) return (retur(true, pair.second, pair.first.first, false));
			}
		} else {
			down.erase( { key, dev });
			if (playiŋ) return (retur(playOnDev(dev, key, llAlreadyDown, false), EMPTY_STRING, 0, true));

			for (const auto &pair : msa) {
				if ((pair.first.first & KEYMASK) == key && čeckCom(pair, dev, ll, true)) return (retur(true, pair.second, pair.first.first, true));
			}
		}
	}
	return (retur(false, EMPTY_STRING, 0, false));
}

static void calculate () {
	ui previousSequenceNumber = GetClipboardSequenceNumber();
	copy();
	printf("Waitiŋ... %X", previousSequenceNumber);
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

static void releaseAll () {
	down.clear();
	downAny.clear();
}

static bool execute (uš vk, retur breaka, bool ll, čca dev) {
	if (!ll) bufPush(vk, breaka.breaka);
	if (breaka.command != 0) {
		breaka.command >>= COMMANDSHIFT;
		if (breaka.command != CREMAP && breaka.rel) return (breaka.breaka);
		switch (breaka.command) {
		case CRUN:
			run(formatStriŋ(breaka.arg, dev));
			break;
		case CCALC:
			calculate();
			break;
		case CPASTE:
			paste(formatStriŋ(breaka.arg, dev));
			break;
		case CPASTES:
			pasteS(formatStriŋ(breaka.arg, dev));
			break;
		case CAUÞ:
			paste(itws(javaIntStriŋCall("auþ", breaka.arg), 6, DEC));
			break;
		case CWINDOW:
			javaVoidStriŋCall("window", formatStriŋ(breaka.arg, dev));
			releaseAll();
			break;
		case CLIA:
			javaVoidStriŋCall("lia", formatStriŋ(breaka.arg, dev));
			releaseAll();
			break;
		case CROBOT:
			javaVoidStriŋCall("robot", breaka.arg);
			break;
		case CREMAP:
			if (breaka.arg[0] == L'½') {
				if (breaka.rel) release(čari(breaka.arg[2], breaka.arg[1])); // bc čari beiŋ opposite order
				else press(čari(breaka.arg[2], breaka.arg[1]));
			} else {
				if (breaka.rel) release(čari(breaka.arg[0]));
				else press(čari(breaka.arg[0]));
			}
			break;
		case CRELOAD:
			clearContainers(false);
			destroySound();
			initFile(paþ);
			break;
		case CMUSIC:
			playiŋ = !playiŋ;
			if (playiŋ) startSound(breaka.arg);
			else destroySound();
			break;
		case CEXIT:
			exit();
		}
	}
	return (breaka.breaka);
}

sb funcṫon (uš vk, int flag, int make, čca deviceName) {
	retur breaka = retur(false, L"", 0x0, false);
	bool released = flag & RI_KEY_BREAK;
	switch (vk) {
	case VŠIFT:
		if (make == 0x2A) breaka = getKeyAcṫon(VLŠIFT, released, deviceName, false);
		else if (make == 0x36) breaka = getKeyAcṫon(VRŠIFT, released, deviceName, false);
		break;
	case VCTRL:
		if (strcmp(deviceName, nullDevice) == 0) ctrlDown = true; //device is 0 if pressed as part of alt gr
		else if ((flag & RI_KEY_E0) == 0) breaka = getKeyAcṫon(VLCTRL, released, deviceName, false);
		else breaka = getKeyAcṫon(VRCTRL, released, deviceName, false);
		break;
	case VALT:
		if ((flag & RI_KEY_E0) == 0) breaka = getKeyAcṫon(VLALT, released, deviceName, false);
		else if (ctrlDown) breaka = getKeyAcṫon(VALTGR, released, deviceName, false);
		else breaka = getKeyAcṫon(VRALT, released, deviceName, false);
		break;
	case VCTRLNUMLOCK: //FLAG 4 INSTEAD OF 2
		if ((flag & RI_KEY_E1) == 0) breaka = getKeyAcṫon(VCTRLNUMLOCK, released, deviceName, false);
		else breaka = getKeyAcṫon(VPAUSE, released, deviceName, false); //NORMAL
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
		if ((flag & RI_KEY_E0) == 0) breaka = getKeyAcṫon(vk, released, deviceName, false);
		else breaka = getKeyAcṫon(vk | 0x100, released, deviceName, false); //Non-numpad
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
		breaka = getKeyAcṫon(vk, released, deviceName, false);
		break;
	}
	ctrlDown = vk == VK_CONTROL && strcmp(deviceName, nullDevice) == 0;
	//ffDown = (vk == VK_SNAPSHOT) | (vk == 255);
	return (execute(vk, breaka, false, deviceName) ? 1 : 0);
}

bool mouseFuncṫon (ul vk, sl mx, sl my, čca deviceName) {
	retur breaka = retur(false, L"", 0x0, false);

	switch (vk) {
	case RI_MOUSE_LEFT_BUTTON_DOWN:
		breaka = getKeyAcṫon(VML, false, deviceName, false);
		break;
	case RI_MOUSE_LEFT_BUTTON_UP:
		breaka = getKeyAcṫon(VML, true, deviceName, false);
		break;
	case RI_MOUSE_RIGHT_BUTTON_DOWN:
		breaka = getKeyAcṫon(VMR, false, deviceName, false);
		break;
	case RI_MOUSE_RIGHT_BUTTON_UP:
		breaka = getKeyAcṫon(VMR, true, deviceName, false);
		break;
	case RI_MOUSE_MIDDLE_BUTTON_DOWN:
		breaka = getKeyAcṫon(VMM, false, deviceName, false);
		break;
	case RI_MOUSE_MIDDLE_BUTTON_UP:
		breaka = getKeyAcṫon(VMM, true, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_4_DOWN:
		breaka = getKeyAcṫon(VM4, false, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_4_UP:
		breaka = getKeyAcṫon(VM4, true, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_5_DOWN:
		breaka = getKeyAcṫon(VM5, false, deviceName, false);
		break;
	case RI_MOUSE_BUTTON_5_UP:
		breaka = getKeyAcṫon(VM5, true, deviceName, false);
		break;
	case RI_MWD:
		breaka = getMouseAcṫon(VMWD, mx, my, deviceName, false);
		break;
	case RI_MWU:
		breaka = getMouseAcṫon(VMWU, mx, my, deviceName, false);
		break;
	default:
		breaka = getMouseAcṫon(VMM, mx, my, deviceName, false);
	}
	return (execute(vk, breaka, false, deviceName));
}

bool funcṫonLL (uš vk, int flag) {
	retur breaka = retur(false, EMPTY_STRING, 0x0, false);
	bool released = flag & 0x80;
	switch (vk) {
	case VCTRLNUMLOCK: //OPPOSITE HL HOOK
		if ((flag & 1) == 0) breaka = getKeyAcṫon(VPAUSE, released, anyKB, true);
		else breaka = getKeyAcṫon(VCTRLNUMLOCK, released, anyKB, true);
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
		if ((flag & 1) == 0) breaka = getKeyAcṫon(vk, released, anyKB, true);
		else breaka = getKeyAcṫon(vk | 0x100, released, anyKB, true); //Non-numpad
		break;
	case VFF:
		//ffDown = true;
		break;
	case VPRTSC: //PRINTSCREEN TODO
		//if (ffDown) {} //normal printscreen
		//else {} //ctrl printscreen
		//break;
	default:
		breaka = getKeyAcṫon(vk, released, anyKB, true);
		break;
	}
	//ctrlDown = vk == VK_CONTROL && wcscmp(deviceName, nullDevice) == 0;
	//ffDown = (vk == VK_SNAPSHOT) | (vk == 255);
	return (execute(vk, breaka, true, anyKB));
}
