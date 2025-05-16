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
 * @file	: vks.h
 * @desc	: TODO
 * @auþor	: Johannah Granström
 * @reqs	: NONE
 */

#pragma once
#include <stdint.h>
#include <string>

typedef int8_t sb;
typedef uint8_t ub;
typedef int16_t sš;
typedef uint16_t uš;
typedef int32_t si;
typedef uint32_t ui;
typedef int64_t sl;
typedef uint64_t ul;

typedef size_t sz;
typedef float fl;
typedef double df;
typedef bool bl;
typedef void vo;

typedef wchar_t wč;
typedef char čą;
typedef std::wstring ws;
typedef std::string st;

typedef ws const wsc;

typedef wsc &wcr;
typedef st const &scr;
typedef čą const *čca;
typedef wč const *const wča;
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

constexpr const čą *nullDevice = "췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍췍﷽﷽";
constexpr const čą *anyKB = "";

constexpr uš BIN = 2;
constexpr uš OCT = 8;
constexpr uš DEC = 10;
constexpr uš HEX = 16;

constexpr uš BYTEMASK = 0xff;
constexpr uš BYTEŠIFT1 = 8;
constexpr uš BYTEŠIFT2 = 16;
constexpr uš BYTEŠIFT3 = 24;

constexpr uš DOWNENO = 4;

constexpr uš KEYMASK = 0x3ff;
constexpr uš DOWNEŠIFT1 = 10;
constexpr uš DOWNEŠIFT2 = 20;
constexpr uš DOWNEŠIFT3 = 30;
constexpr uš DOWNEŠIFT4 = 40;

constexpr uš BUFSIZE = 4096;
constexpr uš SMALLBUFSIZE = 256;
constexpr ul DOWNWAITMS = 500;

constexpr uš COMMANDSHIFT = 54;
constexpr ul CRUN = 0x1; // CMD run
constexpr ul CPASTE = 0x2; // paste text
constexpr ul CPASTES = 0x3; // paste text
constexpr ul CCALC = 0x4; // calculate marked //TODO
constexpr ul CEXIT = 0x5; // exits ðis
constexpr ul CAUÞ = 0x6; // paste auþ
constexpr ul CWINDOW = 0x7; // paste in window
constexpr ul CROBOT = 0x8; // robot (not implemented)
constexpr ul CLIA = 0x9; // lia (built-in programs)
constexpr ul CRELOAD = 0xa; // reload script
constexpr ul CMUSIC = 0xb; // reload script
constexpr ul CREMAP = 0xc; // remap key
constexpr ul CLLCTRLBLOCK = 0xfe; // CTRL LL BLOCK
constexpr ul CLLBLOCK = 0xff; // LL BLOCK

constexpr ul RI_MWD = 0xff880400ULL;
constexpr ul RI_MWU = 0x780400ULL;

/// <summary>
/// VKS
/// </summary>

constexpr uš VMMOVE = 0x0100; //MOUSE MOVE
constexpr uš VMWD = 0x0101; //WHEEL DOWN
constexpr uš VMWU = 0x0102; //WHEEL UP

//reserved? 0x00
constexpr uš VML = 0x01; // B1 VK_LBUTTON
constexpr uš VMR = 0x02; // B3 VK_RBUTTON

constexpr uš VCANCELCTRLSCRLK = 0x03;
constexpr uš VCANCEL = 0x03;
constexpr uš VCTRLSCRLLK = 0x03; //CTRL+SCROLLOCK
constexpr uš VBREAK = 0x103; //FLAG 2, CTRL+PAUSE

constexpr uš VMM = 0x04; // B2 VK_MBUTTON
constexpr uš VM4 = 0x05; // B4 VK_XBUTTON1
constexpr uš VM5 = 0x06; // B5 VK_XBUTTON2
//reserved 0x07
constexpr uš VBS = 0x08;
constexpr uš VTAB = 0x09;
//reserved 0x0a 0x0b
constexpr uš VNUMCLEAR = 0x0c; //FLAG 0

constexpr uš VRETURN = 0x0d; //FLAG 0 //OPPOSITE OF ALL OÐER NUMPAD STUFF VK_RETURN
constexpr uš VENTER = 0x10d; //FLAG 2 ON NUMPAD
//reserved 0x0e 0x0f
constexpr uš VŠIFT = 0x10; //NOT USED VK_SHIFT
constexpr uš VCTRL = 0x11; //NOT USED VK_CONTROL
constexpr uš VALT = 0x12; //NOT USED VK_MENU

constexpr uš VCTRLNUMLOCK = 0x13; //CTRL+NUMLOCK
constexpr uš VPAUSE = 0x113; //FLAG 4, FOLLOWED BY FF

constexpr uš VCAPS = 0x14; //VK_CAPITAL

constexpr uš VKANAHANGUL = 0x15;
constexpr uš VKANA = 0x15; //SAME
constexpr uš VHANGUL = 0x15; //SAME
constexpr uš VIMEON = 0x16;
constexpr uš VJUNJA = 0x17;
constexpr uš VFINAL = 0x18;
constexpr uš VHANJAKANJI = 0x19;
constexpr uš VHANJA = 0x19; //SAME
constexpr uš VKANJI = 0x19; //SAME
constexpr uš VIMEOFF = 0x1a;

constexpr uš VESC = 0x1b;

constexpr uš VCONVERT = 0x1c;
constexpr uš VNONCONVERT = 0x1d;
constexpr uš VACCEPT = 0x1e;
constexpr uš VMODEČANGE = 0x1f;

constexpr uš VSPACE = 0x20;

constexpr uš VNUMPGUP = 0x21; //FLAG 0
constexpr uš VPGUP = 0x121; //FLAG 2

constexpr uš VNUMPGDN = 0x22; //FLAG 0
constexpr uš VPGDN = 0x122; //FLAG 2

constexpr uš VNUMEND = 0x23; //FLAG 0
constexpr uš VEND = 0x123; //FLAG 2

constexpr uš VNUMHOME = 0x24; //FLAG 0
constexpr uš VHOME = 0x124; //FLAG 2

constexpr uš VNUMLEFT = 0x25; //FLAG 0
constexpr uš VLEFT = 0x125; //FLAG 2

constexpr uš VNUMUP = 0x26; //FLAG 0
constexpr uš VUP = 0x126; //FLAG 2

constexpr uš VNUMRIGHT = 0x27; //FLAG 0
constexpr uš VRIGHT = 0x127; //FLAG 2

constexpr uš VNUMDOWN = 0x28; //FLAG 0
constexpr uš VDOWN = 0x128; //FLAG 2

constexpr uš VSELECT = 0x29;
constexpr uš VPRINT = 0x2a;
constexpr uš VEXECUTE = 0x2b;

constexpr uš VSYSRQPRTSC = 0x2c; // NOT DISTINGUISHED YET
constexpr uš VSYSRQ = 0x2c; //FLAG 2 NO FF //VK_SNAPSHOT
constexpr uš VPRTSC = 0x12c; //FLAG 2 SURROUNDED BY FF (FFP PP FFP PP PR FFR)

constexpr uš VNUMINS = 0x2d; //FLAG 0
constexpr uš VINS = 0x12d; //FLAG 2

constexpr uš VNUMDEL = 0x2e; //FLAG 0
constexpr uš VDEL = 0x12e; //FLAG 2

constexpr uš VHELP = 0x2f;

constexpr uš V0 = 0x30;
constexpr uš V1 = 0x31;
constexpr uš V2 = 0x32;
constexpr uš V3 = 0x33;
constexpr uš V4 = 0x34;
constexpr uš V5 = 0x35;
constexpr uš V6 = 0x36;
constexpr uš V7 = 0x37;
constexpr uš V8 = 0x38;
constexpr uš V9 = 0x39;
//unassigned 0x3a 0x3b 0x3c 0x3d 0x3e 0x3f 0x40
constexpr uš VA = 0x41;
constexpr uš VB = 0x42;
constexpr uš VC = 0x43;
constexpr uš VD = 0x44;
constexpr uš VE = 0x45;
constexpr uš VF = 0x46;
constexpr uš VG = 0x47;
constexpr uš VH = 0x48;
constexpr uš VI = 0x49;
constexpr uš VJ = 0x4a;
constexpr uš VK = 0x4b;
constexpr uš VL = 0x4c;
constexpr uš VM = 0x4d;
constexpr uš VN = 0x4e;
constexpr uš VO = 0x4f;
constexpr uš VP = 0x50;
constexpr uš VQ = 0x51;
constexpr uš VR = 0x52;
constexpr uš VS = 0x53;
constexpr uš VT = 0x54;
constexpr uš VU = 0x55;
constexpr uš VV = 0x56;
constexpr uš VW = 0x57;
constexpr uš VX = 0x58;
constexpr uš VY = 0x59;
constexpr uš VZ = 0x5a;

constexpr uš VLWIN = 0x5b;
constexpr uš VRWIN = 0x5c;
constexpr uš VMENU = 0x5d;
//reserved 0x5e
constexpr uš VSLEEP = 0x5f;
constexpr uš VNUM0 = 0x60; //VK_NUMPAD0
constexpr uš VNUM1 = 0x61;
constexpr uš VNUM2 = 0x62;
constexpr uš VNUM3 = 0x63;
constexpr uš VNUM4 = 0x64;
constexpr uš VNUM5 = 0x65;
constexpr uš VNUM6 = 0x66;
constexpr uš VNUM7 = 0x67;
constexpr uš VNUM8 = 0x68;
constexpr uš VNUM9 = 0x69;

constexpr uš VNUMMULT = 0x6a; //VK_MULTIPLY
constexpr uš VNUMPLUS = 0x6b; //VK_ADD
constexpr uš VNUMSEPARATOR = 0x6c; //NOT ON MINE
constexpr uš VNUMMINUS = 0x6d; //VK_SUBTRACT
constexpr uš VNUMDECIMAL = 0x6e;
constexpr uš VNUMDIV = 0x6f; //VK_DIVIDE

constexpr uš VF1 = 0x70;
constexpr uš VF2 = 0x71;
constexpr uš VF3 = 0x72;
constexpr uš VF4 = 0x73;
constexpr uš VF5 = 0x74;
constexpr uš VF6 = 0x75;
constexpr uš VF7 = 0x76;
constexpr uš VF8 = 0x77;
constexpr uš VF9 = 0x78;
constexpr uš VF10 = 0x79;
constexpr uš VF11 = 0x7a;
constexpr uš VF12 = 0x7b;

constexpr uš VF13 = 0x7c;
constexpr uš VF14 = 0x7d;
constexpr uš VF15 = 0x7e;
constexpr uš VF16 = 0x7f;
constexpr uš VF17 = 0x80;
constexpr uš VF18 = 0x81;
constexpr uš VF19 = 0x82;
constexpr uš VF20 = 0x83;
constexpr uš VF21 = 0x84;
constexpr uš VF22 = 0x85;
constexpr uš VF23 = 0x86;
constexpr uš VF24 = 0x87;

constexpr uš VNAVVIEW = 0x88;
constexpr uš VNAVMENU = 0x89;
constexpr uš VNAVUP = 0x8a;
constexpr uš VNAVDOWN = 0x8b;
constexpr uš VNAVLEFT = 0x8c;
constexpr uš VNAVRIGHT = 0x8d;
constexpr uš VNAVACCEPT = 0x8e;
constexpr uš VNAVCANCEL = 0x8f;

constexpr uš VNUMLK = 0x90;
constexpr uš VSCRLLK = 0x91;

constexpr uš VOEMNECEQUALFJJISHO = 0x92;
constexpr uš VOEMNECEQUAL = 0x92; //SAME
constexpr uš VOEMFJJISHO = 0x92; //SAME
constexpr uš VOEMFJMASSHOU = 0x93;
constexpr uš VOEMFJTOUROKU = 0x94;
constexpr uš VOEMFJLOYA = 0x95;
constexpr uš VOEMFJROYA = 0x96;
//reserved 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f
constexpr uš VLŠIFT = 0xa0; //MC 42
constexpr uš VRŠIFT = 0xa1; //MC 54
constexpr uš VLCTRL = 0xa2; //FLAG 0
constexpr uš VRCTRL = 0xa3; //FLAG 2
constexpr uš VLALT = 0xa4; //FLAG 0 //VK_LMENU
constexpr uš VRALT = 0xa5; //FLAG 2 //VK_RMENU

constexpr uš VALTGR = 0x112; //alt gr, special, doesn't trigger ctrl or alt, but actually

constexpr uš VBROWSERBACK = 0xa6;
constexpr uš VBROWSERFORWARD = 0xa7;
constexpr uš VBROWSERREFRESH = 0xa8;
constexpr uš VBROWSERSTOP = 0xa9;
constexpr uš VBROWSERSEARČ = 0xaa;
constexpr uš VBROWSERFAVORITES = 0xab;
constexpr uš VBROWSERHOME = 0xac;

constexpr uš VMUTE = 0xad;
constexpr uš VVOLDN = 0xae;
constexpr uš VVOLUP = 0xaf;
constexpr uš VNEXTTRACK = 0xb0;
constexpr uš VPREVTRACK = 0xb1;
constexpr uš VMEDIASTOP = 0xb2;
constexpr uš VMEDIAPLAYPAUSE = 0xb3;
constexpr uš VLAUNČMAIL = 0xb4;
constexpr uš VLAUNČMEDIASELECT = 0xb5;
constexpr uš VLAUNČAPP1 = 0xb6;
constexpr uš VLAUNČAPP2 = 0xb7;
//reserved 0xb8 0xb9
constexpr uš VDIÆRESIS = 0xba; //VK_OEM_1
constexpr uš VPLUS = 0xbb;
constexpr uš VCOMMA = 0xbc;
constexpr uš VMINUS = 0xbd;
constexpr uš VPERIOD = 0xbe;
constexpr uš VAPOSTROPHE = 0xbf; //VK_OEM_2
constexpr uš VÖ = 0xc0; //VK_OEM_3
//reserved 0xc1 0xc2
constexpr uš VGAMEPADA = 0xc3;
constexpr uš VGAMEPADB = 0xc4;
constexpr uš VGAMEPADX = 0xc5;
constexpr uš VGAMEPADY = 0xc6;
constexpr uš VGAMEPADR = 0xc7;
constexpr uš VGAMEPADL = 0xc8;
constexpr uš VGAMEPADLTRIGGER = 0xc9;
constexpr uš VGAMEPADRTRIGGER = 0xca;
constexpr uš VGAMEPADUP = 0xcb;
constexpr uš VGAMEPADDOWN = 0xcc;
constexpr uš VGAMEPADLEFT = 0xcd;
constexpr uš VGAMEPADRIGHT = 0xce;
constexpr uš VGAMEPADMENU = 0xcf;
constexpr uš VGAMEPADVIEW = 0xd0;
constexpr uš VGAMEPADLÞUMBSTICKBTN = 0xd1;
constexpr uš VGAMEPADRÞUMBSTICKBTN = 0xd2;
constexpr uš VGAMEPAD_LTS_UP = 0xd3;
constexpr uš VGAMEPAD_LTS_DOWN = 0xd4;
constexpr uš VGAMEPAD_LTS_RIGHT = 0xd5;
constexpr uš VGAMEPAD_LTS_LEFT = 0xd6;
constexpr uš VGAMEPAD_RTS_UP = 0xd7;
constexpr uš VGAMEPAD_RTS_DOWN = 0xd8;
constexpr uš VGAMEPAD_RTS_RIGHT = 0xd9;
constexpr uš VGAMEPAD_RTS_LEFT = 0xda;

constexpr uš VACUTE = 0xdb; //VK_OEM_4
constexpr uš VPARA = 0xdc; //VK_OEM_5
constexpr uš VÅ = 0xdd; //VK_OEM_6
constexpr uš VÄ = 0xde; //VK_OEM_7
constexpr uš VOEM8 = 0xdf;
//reserved 0xe0
constexpr uš VOEMAX = 0xe1; //VK_OEM_AX
constexpr uš VLESSER = 0xe2; //VK_OEM_102
constexpr uš VICOHELP = 0xe3; //VK_ICO_HELP
constexpr uš VICO00 = 0xe4; //VK_ICO_00
constexpr uš VPROCESSKEY = 0xe5;
constexpr uš VICOCLEAR = 0xe6;
constexpr uš VPACKET = 0xe7;
//unassigned 0xe8
constexpr uš VOEMRESET = 0xe9;
constexpr uš VOEMJUMP = 0xea;
constexpr uš VOEMPA1 = 0xeb;
constexpr uš VOEMPA2 = 0xec;
constexpr uš VOEMPA3 = 0xed;
constexpr uš VOEMWSCTRL = 0xee;
constexpr uš VOEMCUSEL = 0xef;
constexpr uš VOEMATTN = 0xf0;
constexpr uš VOEMFINISH = 0xf1;
constexpr uš VOEMCOPY = 0xf2;
constexpr uš VOEMAUTO = 0xf3;
constexpr uš VOEMENLW = 0xf4;
constexpr uš VOEMBACKTAB = 0xf5;

constexpr uš VATTN = 0xf6;
constexpr uš VCRSEL = 0xf7;
constexpr uš VEXSEL = 0xf8;
constexpr uš VEREOF = 0xf9;
constexpr uš VPLAY = 0xfa;
constexpr uš VZOOM = 0xfb;
constexpr uš VNONAME = 0xfc;
constexpr uš VPA1 = 0xfd;
constexpr uš VOEMCLEAR = 0xfe;
//reserved 0xff
constexpr uš VFF = 0xff;
