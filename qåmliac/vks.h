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
 * @file	: vks.h
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once
#include <stdint.h>
#include <string>

typedef int8_t sb;
typedef uint8_t ub;
typedef int16_t ss;
typedef uint16_t us;
typedef int32_t si;
typedef uint32_t ui;
typedef int64_t sl;
typedef uint64_t ul;

typedef size_t sz;
typedef float fl;
typedef double df;
typedef bool bl;
typedef void vo;

typedef wchar_t wc;
typedef char ch;
typedef std::wstring ws;
typedef std::string st;

typedef ws const wsc;

typedef wsc &wcr;
typedef st const &scr;
typedef char const *cca;
typedef wchar_t const *const wca;
typedef std::array<st, 3> carga;

struct WSHash {
	sz operator() (wcr wstr) const {
		std::hash<ws> hasher;
		return (hasher(wstr));
	}
};

struct SHash {
	sz operator() (scr str) const {
		std::hash<st> hasher;
		return (hasher(str));
	}
};

constexpr const ch *nullDevice = "췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍﷽﷽";
constexpr const ch *anyKB = "";

constexpr us BIN = 2;
constexpr us OCT = 8;
constexpr us DEC = 10;
constexpr us HEX = 16;

constexpr us BYTEMASK = 0xff;
constexpr us BYTESHIFT1 = 8;
constexpr us BYTESHIFT2 = 16;
constexpr us BYTESHIFT3 = 24;

constexpr us DOWNENO = 4;

constexpr us KEYMASK = 0x3ff;
constexpr us DOWNESHIFT1 = 10;
constexpr us DOWNESHIFT2 = 20;
constexpr us DOWNESHIFT3 = 30;
constexpr us DOWNESHIFT4 = 40;

constexpr us BUFSIZE = 4096;
constexpr us SMALLBUFSIZE = 256;
constexpr ul DOWNWAITMS = 500;

constexpr us COMMANDSHIFT = 54;
constexpr ul CRUN = 0x1; //CMD run
constexpr ul CPASTE = 0x2; //paste text
constexpr ul CPASTES = 0x3; //paste text
constexpr ul CCALC = 0x4; //calculate marked //TODO
constexpr ul CEXIT = 0x5; //eXITS THIS
constexpr ul CAUTH = 0x6; //paste auth
constexpr ul CWINDOW = 0x7; //paste in window
constexpr ul CROBOT = 0x8; //robot (not implemented)
constexpr ul CLIA = 0x9; //lia (built-in programs)
constexpr ul CRELOAD = 0xa; //reload script
constexpr ul CMUSIC = 0xb; //reload script
constexpr ul CREMAP = 0xc; //remap key
constexpr ul CLLCTRLBLOCK = 0xfe; //CTRL LL BLOCK
constexpr ul CLLBLOCK = 0xff; //LL BLOCK

constexpr ul RI_MWD = 0xff880400ULL;
constexpr ul RI_MWU = 0x780400ULL;

/// <summary>
/// VKS
/// </summary>

constexpr us VMMOVE = 0x0100; //MOUSE MOVE
constexpr us VMWD = 0x0101; //WHEEL DOWN
constexpr us VMWU = 0x0102; //WHEEL UP

//reserved? 0x00
constexpr us VML = 0x01; // B1 VK_LBUTTON
constexpr us VMR = 0x02; // B3 VK_RBUTTON

constexpr us VCANCELCTRLSCRLK = 0x03;
constexpr us VCANCEL = 0x03;
constexpr us VCTRLSCRLLK = 0x03; //CTRL+SCROLLOCK
constexpr us VBREAK = 0x103; //FLAG 2, CTRL+PAUSE

constexpr us VMM = 0x04; // B2 VK_MBUTTON
constexpr us VM4 = 0x05; // B4 VK_XBUTTON1
constexpr us VM5 = 0x06; // B5 VK_XBUTTON2
//reserved 0x07
constexpr us VBS = 0x08;
constexpr us VTAB = 0x09;
//reserved 0x0a 0x0b
constexpr us VNUMCLEAR = 0x0c; //FLAG 0

constexpr us VRETURN = 0x0d; //FLAG 0 //OPPOSITE OF ALL OTHER NUMPAD STUFF VK_RETURN
constexpr us VENTER = 0x10d; //FLAG 2 ON NUMPAD
//reserved 0x0e 0x0f
constexpr us VSHIFT = 0x10; //NOT USED VK_SHIFT
constexpr us VCTRL = 0x11; //NOT USED VK_CONTROL
constexpr us VALT = 0x12; //NOT USED VK_MENU

constexpr us VCTRLNUMLOCK = 0x13; //CTRL+NUMLOCK
constexpr us VPAUSE = 0x113; //FLAG 4, FOLLOWED BY FF

constexpr us VCAPS = 0x14; //VK_CAPITAL

constexpr us VKANAHANGUL = 0x15;
constexpr us VKANA = 0x15; //SAME
constexpr us VHANGUL = 0x15; //SAME
constexpr us VIMEON = 0x16;
constexpr us VJUNJA = 0x17;
constexpr us VFINAL = 0x18;
constexpr us VHANJAKANJI = 0x19;
constexpr us VHANJA = 0x19; //SAME
constexpr us VKANJI = 0x19; //SAME
constexpr us VIMEOFF = 0x1a;

constexpr us VESC = 0x1b;

constexpr us VCONVERT = 0x1c;
constexpr us VNONCONVERT = 0x1d;
constexpr us VACCEPT = 0x1e;
constexpr us VMODECHANGE = 0x1f;

constexpr us VSPACE = 0x20;

constexpr us VNUMPGUP = 0x21; //FLAG 0
constexpr us VPGUP = 0x121; //FLAG 2

constexpr us VNUMPGDN = 0x22; //FLAG 0
constexpr us VPGDN = 0x122; //FLAG 2

constexpr us VNUMEND = 0x23; //FLAG 0
constexpr us VEND = 0x123; //FLAG 2

constexpr us VNUMHOME = 0x24; //FLAG 0
constexpr us VHOME = 0x124; //FLAG 2

constexpr us VNUMLEFT = 0x25; //FLAG 0
constexpr us VLEFT = 0x125; //FLAG 2

constexpr us VNUMUP = 0x26; //FLAG 0
constexpr us VUP = 0x126; //FLAG 2

constexpr us VNUMRIGHT = 0x27; //FLAG 0
constexpr us VRIGHT = 0x127; //FLAG 2

constexpr us VNUMDOWN = 0x28; //FLAG 0
constexpr us VDOWN = 0x128; //FLAG 2

constexpr us VSELECT = 0x29;
constexpr us VPRINT = 0x2a;
constexpr us VEXECUTE = 0x2b;

constexpr us VSYSRQPRTSC = 0x2c; // NOT DISTINGUISHED YET
constexpr us VSYSRQ = 0x2c; //FLAG 2 NO FF //VK_SNAPSHOT
constexpr us VPRTSC = 0x12c; //FLAG 2 SURROUNDED BY FF (FFP PP FFP PP PR FFR)

constexpr us VNUMINS = 0x2d; //FLAG 0
constexpr us VINS = 0x12d; //FLAG 2

constexpr us VNUMDEL = 0x2e; //FLAG 0
constexpr us VDEL = 0x12e; //FLAG 2

constexpr us VHELP = 0x2f;

constexpr us V0 = 0x30;
constexpr us V1 = 0x31;
constexpr us V2 = 0x32;
constexpr us V3 = 0x33;
constexpr us V4 = 0x34;
constexpr us V5 = 0x35;
constexpr us V6 = 0x36;
constexpr us V7 = 0x37;
constexpr us V8 = 0x38;
constexpr us V9 = 0x39;
//unassigned 0x3a 0x3b 0x3c 0x3d 0x3e 0x3f 0x40
constexpr us VA = 0x41;
constexpr us VB = 0x42;
constexpr us VC = 0x43;
constexpr us VD = 0x44;
constexpr us VE = 0x45;
constexpr us VF = 0x46;
constexpr us VG = 0x47;
constexpr us VH = 0x48;
constexpr us VI = 0x49;
constexpr us VJ = 0x4a;
constexpr us VK = 0x4b;
constexpr us VL = 0x4c;
constexpr us VM = 0x4d;
constexpr us VN = 0x4e;
constexpr us VO = 0x4f;
constexpr us VP = 0x50;
constexpr us VQ = 0x51;
constexpr us VR = 0x52;
constexpr us VS = 0x53;
constexpr us VT = 0x54;
constexpr us VU = 0x55;
constexpr us VV = 0x56;
constexpr us VW = 0x57;
constexpr us VX = 0x58;
constexpr us VY = 0x59;
constexpr us VZ = 0x5a;

constexpr us VLWIN = 0x5b;
constexpr us VRWIN = 0x5c;
constexpr us VMENU = 0x5d;
//reserved 0x5e
constexpr us VSLEEP = 0x5f;
constexpr us VNUM0 = 0x60; //VK_NUMPAD0
constexpr us VNUM1 = 0x61;
constexpr us VNUM2 = 0x62;
constexpr us VNUM3 = 0x63;
constexpr us VNUM4 = 0x64;
constexpr us VNUM5 = 0x65;
constexpr us VNUM6 = 0x66;
constexpr us VNUM7 = 0x67;
constexpr us VNUM8 = 0x68;
constexpr us VNUM9 = 0x69;

constexpr us VNUMMULT = 0x6a; //VK_MULTIPLY
constexpr us VNUMPLUS = 0x6b; //VK_ADD
constexpr us VNUMSEPARATOR = 0x6c; //NOT ON MINE
constexpr us VNUMMINUS = 0x6d; //VK_SUBTRACT
constexpr us VNUMDECIMAL = 0x6e;
constexpr us VNUMDIV = 0x6f; //VK_DIVIDE

constexpr us VF1 = 0x70;
constexpr us VF2 = 0x71;
constexpr us VF3 = 0x72;
constexpr us VF4 = 0x73;
constexpr us VF5 = 0x74;
constexpr us VF6 = 0x75;
constexpr us VF7 = 0x76;
constexpr us VF8 = 0x77;
constexpr us VF9 = 0x78;
constexpr us VF10 = 0x79;
constexpr us VF11 = 0x7a;
constexpr us VF12 = 0x7b;

constexpr us VF13 = 0x7c;
constexpr us VF14 = 0x7d;
constexpr us VF15 = 0x7e;
constexpr us VF16 = 0x7f;
constexpr us VF17 = 0x80;
constexpr us VF18 = 0x81;
constexpr us VF19 = 0x82;
constexpr us VF20 = 0x83;
constexpr us VF21 = 0x84;
constexpr us VF22 = 0x85;
constexpr us VF23 = 0x86;
constexpr us VF24 = 0x87;

constexpr us VNAVVIEW = 0x88;
constexpr us VNAVMENU = 0x89;
constexpr us VNAVUP = 0x8a;
constexpr us VNAVDOWN = 0x8b;
constexpr us VNAVLEFT = 0x8c;
constexpr us VNAVRIGHT = 0x8d;
constexpr us VNAVACCEPT = 0x8e;
constexpr us VNAVCANCEL = 0x8f;

constexpr us VNUMLK = 0x90;
constexpr us VSCRLLK = 0x91;

constexpr us VOEMNECEQUALFJJISHO = 0x92;
constexpr us VOEMNECEQUAL = 0x92; //SAME
constexpr us VOEMFJJISHO = 0x92; //SAME
constexpr us VOEMFJMASSHOU = 0x93;
constexpr us VOEMFJTOUROKU = 0x94;
constexpr us VOEMFJLOYA = 0x95;
constexpr us VOEMFJROYA = 0x96;
//reserved 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f
constexpr us VLSHIFT = 0xa0; //MC 42
constexpr us VRSHIFT = 0xa1; //MC 54
constexpr us VLCTRL = 0xa2; //FLAG 0
constexpr us VRCTRL = 0xa3; //FLAG 2
constexpr us VLALT = 0xa4; //FLAG 0 //VK_LMENU
constexpr us VRALT = 0xa5; //FLAG 2 //VK_RMENU

constexpr us VALTGR = 0x112; //alt gr, special, doesn't trigger ctrl or alt, but actually

constexpr us VBROWSERBACK = 0xa6;
constexpr us VBROWSERFORWARD = 0xa7;
constexpr us VBROWSERREFRESH = 0xa8;
constexpr us VBROWSERSTOP = 0xa9;
constexpr us VBROWSERSEARCH = 0xaa;
constexpr us VBROWSERFAVORITES = 0xab;
constexpr us VBROWSERHOME = 0xac;

constexpr us VMUTE = 0xad;
constexpr us VVOLDN = 0xae;
constexpr us VVOLUP = 0xaf;
constexpr us VNEXTTRACK = 0xb0;
constexpr us VPREVTRACK = 0xb1;
constexpr us VMEDIASTOP = 0xb2;
constexpr us VMEDIAPLAYPAUSE = 0xb3;
constexpr us VLAUNCHMAIL = 0xb4;
constexpr us VLAUNCHMEDIASELECT = 0xb5;
constexpr us VLAUNCHAPP1 = 0xb6;
constexpr us VLAUNCHAPP2 = 0xb7;
//reserved 0xb8 0xb9
constexpr us VDIERESIS = 0xba; //VK_OEM_1
constexpr us VPLUS = 0xbb;
constexpr us VCOMMA = 0xbc;
constexpr us VMINUS = 0xbd;
constexpr us VPERIOD = 0xbe;
constexpr us VAPOSTROPHE = 0xbf; //VK_OEM_2
constexpr us VÖ = 0xc0; //VK_OEM_3
//reserved 0xc1 0xc2
constexpr us VGAMEPADA = 0xc3;
constexpr us VGAMEPADB = 0xc4;
constexpr us VGAMEPADX = 0xc5;
constexpr us VGAMEPADY = 0xc6;
constexpr us VGAMEPADR = 0xc7;
constexpr us VGAMEPADL = 0xc8;
constexpr us VGAMEPADLTRIGGER = 0xc9;
constexpr us VGAMEPADRTRIGGER = 0xca;
constexpr us VGAMEPADUP = 0xcb;
constexpr us VGAMEPADDOWN = 0xcc;
constexpr us VGAMEPADLEFT = 0xcd;
constexpr us VGAMEPADRIGHT = 0xce;
constexpr us VGAMEPADMENU = 0xcf;
constexpr us VGAMEPADVIEW = 0xd0;
constexpr us VGAMEPADLTHUMBSTICKBTN = 0xd1;
constexpr us VGAMEPADRTHUMBSTICKBTN = 0xd2;
constexpr us VGAMEPAD_LTS_UP = 0xd3;
constexpr us VGAMEPAD_LTS_DOWN = 0xd4;
constexpr us VGAMEPAD_LTS_RIGHT = 0xd5;
constexpr us VGAMEPAD_LTS_LEFT = 0xd6;
constexpr us VGAMEPAD_RTS_UP = 0xd7;
constexpr us VGAMEPAD_RTS_DOWN = 0xd8;
constexpr us VGAMEPAD_RTS_RIGHT = 0xd9;
constexpr us VGAMEPAD_RTS_LEFT = 0xda;

constexpr us VACUTE = 0xdb; //VK_OEM_4
constexpr us VPARA = 0xdc; //VK_OEM_5
constexpr us VÅ = 0xdd; //VK_OEM_6
constexpr us VÄ = 0xde; //VK_OEM_7
constexpr us VOEM8 = 0xdf;
//reserved 0xe0
constexpr us VOEMAX = 0xe1; //VK_OEM_AX
constexpr us VLESSER = 0xe2; //VK_OEM_102
constexpr us VICOHELP = 0xe3; //VK_ICO_HELP
constexpr us VICO00 = 0xe4; //VK_ICO_00
constexpr us VPROCESSKEY = 0xe5;
constexpr us VICOCLEAR = 0xe6;
constexpr us VPACKET = 0xe7;
//unassigned 0xe8
constexpr us VOEMRESET = 0xe9;
constexpr us VOEMJUMP = 0xea;
constexpr us VOEMPA1 = 0xeb;
constexpr us VOEMPA2 = 0xec;
constexpr us VOEMPA3 = 0xed;
constexpr us VOEMWSCTRL = 0xee;
constexpr us VOEMCUSEL = 0xef;
constexpr us VOEMATTN = 0xf0;
constexpr us VOEMFINISH = 0xf1;
constexpr us VOEMCOPY = 0xf2;
constexpr us VOEMAUTO = 0xf3;
constexpr us VOEMENLW = 0xf4;
constexpr us VOEMBACKTAB = 0xf5;

constexpr us VATTN = 0xf6;
constexpr us VCRSEL = 0xf7;
constexpr us VEXSEL = 0xf8;
constexpr us VEREOF = 0xf9;
constexpr us VPLAY = 0xfa;
constexpr us VZOOM = 0xfb;
constexpr us VNONAME = 0xfc;
constexpr us VPA1 = 0xfd;
constexpr us VOEMCLEAR = 0xfe;
//reserved 0xff
constexpr us VFF = 0xff;
