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

#include "oðer.h"
#include <unordered_map>
#include <map>

static std::map<std::pair<wč, wč>, uš> keys;
static std::unordered_map<wč, uš> skeys;
static std::unordered_map<wč, uš> ckeys;

static std::unordered_map<ws, ul, WSHash> cases;

void enterInit () {
	cases = { { L"run", CRUN }, { L"calc", CCALC }, { L"paste", CPASTE }, { L"pastes", CPASTES }, { L"exit", CEXIT }, { L"auth", CAUÞ }, { L"window", CWINDOW },
			{ L"robot", CROBOT }, { L"lia", CLIA }, { L"reload", CRELOAD }, { L"music", CMUSIC }, { L"remap", CREMAP }, { L"block", CLLBLOCK }, { L"ctrlblock", CLLCTRLBLOCK } };
	keys = { { { L'ṿ', (L'M' << BYTEŠIFT1) | L'V' }, VMMOVE }, // 100 NOT
			{ { L'ḷ', (L'M' << BYTEŠIFT1) | L'L' }, VML }, // 01 NOT
			{ { L'ḍ', (L'W' << BYTEŠIFT1) | L'D' }, VMWD }, // 101 NOT
			{ { L'ṛ', (L'M' << BYTEŠIFT1) | L'R' }, VMR }, // 02 NOT
			{ { L'ụ', (L'W' << BYTEŠIFT1) | L'U' }, VMWU }, // 102 NOT
			{ { L'ç', (L'C' << BYTEŠIFT1) | L'C' }, VCANCELCTRLSCRLK }, // 03, SAME
			{ { L'ʙ', (L'B' << BYTEŠIFT1) | L'R' }, VBREAK }, // 103 CTRL + PAUSE
			{ { L'ṃ', (L'M' << BYTEŠIFT1) | L'W' }, VMM }, // 04 NOT
			{ { L'ẋ', (L'M' << BYTEŠIFT1) | L'4' }, VM4 }, // 05 NOT AKA X1
			{ { L'ẍ', (L'M' << BYTEŠIFT1) | L'5' }, VM5 }, // 06 NOT AKA X2
			{ { L'B', (L'B' << BYTEŠIFT1) | L'S' }, VBS }, // 08
			{ { L'T', (L'T' << BYTEŠIFT1) | L'A' }, VTAB }, // 09
			{ { L'Č', (L'N' << BYTEŠIFT1) | L'C' }, VNUMCLEAR }, // 0C
			{ { L'ž', (L'R' << BYTEŠIFT1) | L'N' }, VRETURN }, // 0D
			{ { L'Ž', (L'E' << BYTEŠIFT1) | L'T' }, VENTER }, // 10D NUM RETURN~
			{ { L'š', (L'S' << BYTEŠIFT1) | L'H' }, VŠIFT }, // 10
			{ { L'č', (L'C' << BYTEŠIFT1) | L'T' }, VCTRL }, // 11
			{ { L'ǎ', (L'A' << BYTEŠIFT1) | L'L' }, VALT }, // 12
			{ { L'ņ', (L'C' << BYTEŠIFT1) | L'N' }, VCTRLNUMLOCK }, // 13
			{ { L'P', (L'P' << BYTEŠIFT1) | L'A' }, VPAUSE }, // 113 (F4) FOLLOWED BY FF
			{ { L'C', (L'C' << BYTEŠIFT1) | L'A' }, VCAPS }, // 14
			{ { L'K', (L'K' << BYTEŠIFT1) | L'H' }, VKANAHANGUL }, // 15 SAME
			{ { L'í', (L'I' << BYTEŠIFT1) | L'O' }, VIMEON }, // 16
			{ { L'ǰ', (L'J' << BYTEŠIFT1) | L'U' }, VJUNJA }, // 17
			{ { L'ḟ', (L'I' << BYTEŠIFT1) | L'A' }, VFINAL }, // 18
			{ { L'ñ', (L'N' << BYTEŠIFT1) | L'J' }, VHANJAKANJI }, // 19 SAME
			{ { L'ì', (L'I' << BYTEŠIFT1) | L'F' }, VIMEOFF }, // 1A
			{ { L'E', (L'E' << BYTEŠIFT1) | L'S' }, VESC }, // 1B
			{ { L'ć', (L'C' << BYTEŠIFT1) | L'O' }, VCONVERT }, // 1C
			{ { L'ń', (L'N' << BYTEŠIFT1) | L'C' }, VNONCONVERT }, // 1D
			{ { L'á', (L'A' << BYTEŠIFT1) | L'C' }, VACCEPT }, // 1E
			{ { L'ḿ', (L'M' << BYTEŠIFT1) | L'C' }, VMODEČANGE }, // 1F
			{ { L'_', (L'S' << BYTEŠIFT1) | L'P' }, VSPACE }, // 20
			{ { L'Ĝ', (L'G' << BYTEŠIFT1) | L'U' }, VNUMPGUP }, // 21
			{ { L'ĝ', (L'P' << BYTEŠIFT1) | L'U' }, VPGUP }, // 121
			{ { L'Ǧ', (L'G' << BYTEŠIFT1) | L'D' }, VNUMPGDN }, // 22
			{ { L'ǧ', (L'P' << BYTEŠIFT1) | L'D' }, VPGDN }, // 122
			{ { L'Ě', (L'N' << BYTEŠIFT1) | L'E' }, VNUMEND }, // 23
			{ { L'ě', (L'E' << BYTEŠIFT1) | L'N' }, VEND }, // 123
			{ { L'Ȟ', (L'N' << BYTEŠIFT1) | L'H' }, VNUMHOME }, // 24
			{ { L'ȟ', (L'H' << BYTEŠIFT1) | L'O' }, VHOME }, // 124
			{ { L'Ľ', (L'N' << BYTEŠIFT1) | L'L' }, VNUMLEFT }, // 25
			{ { L'ľ', (L'L' << BYTEŠIFT1) | L'E' }, VLEFT }, // 125
			{ { L'Ǔ', (L'N' << BYTEŠIFT1) | L'U' }, VNUMUP }, // 26
			{ { L'ǔ', (L'U' << BYTEŠIFT1) | L'P' }, VUP }, // 126
			{ { L'Ř', (L'N' << BYTEŠIFT1) | L'R' }, VNUMRIGHT }, // 27
			{ { L'ř', (L'R' << BYTEŠIFT1) | L'I' }, VRIGHT }, // 127
			{ { L'Ď', (L'N' << BYTEŠIFT1) | L'D' }, VNUMDOWN }, // 28
			{ { L'ď', (L'D' << BYTEŠIFT1) | L'O' }, VDOWN }, // 128
			{ { L'ś', (L'S' << BYTEŠIFT1) | L'E' }, VSELECT }, // 29
			{ { L'ṕ', (L'P' << BYTEŠIFT1) | L'R' }, VPRINT }, // 2A
			{ { L'X', (L'E' << BYTEŠIFT1) | L'X' }, VEXECUTE }, // 2B
			{ { L'Q', (L'P' << BYTEŠIFT1) | L'S' }, VSYSRQPRTSC }, // 2C SAME, NOT YET DISTINGUISHED TODO
			{ { L'Ǐ', (L'N' << BYTEŠIFT1) | L'I' }, VNUMINS }, // 2D
			{ { L'ǐ', (L'I' << BYTEŠIFT1) | L'N' }, VINS }, // 12D
			{ { L'Ť', (L'N' << BYTEŠIFT1) | L'T' }, VNUMDEL }, // 2E
			{ { L'ť', (L'D' << BYTEŠIFT1) | L'T' }, VDEL }, // 12E
			{ { L'H', (L'H' << BYTEŠIFT1) | L'E' }, VHELP }, // 2F
			{ { L'0', (L'0' << BYTEŠIFT1) | L'X' }, V0 }, // 30
			{ { L'1', (L'1' << BYTEŠIFT1) | L'X' }, V1 }, // 31
			{ { L'2', (L'2' << BYTEŠIFT1) | L'X' }, V2 }, // 32
			{ { L'3', (L'3' << BYTEŠIFT1) | L'X' }, V3 }, // 33
			{ { L'4', (L'4' << BYTEŠIFT1) | L'X' }, V4 }, // 34
			{ { L'5', (L'5' << BYTEŠIFT1) | L'X' }, V5 }, // 35
			{ { L'6', (L'6' << BYTEŠIFT1) | L'X' }, V6 }, // 36
			{ { L'7', (L'7' << BYTEŠIFT1) | L'X' }, V7 }, // 37
			{ { L'8', (L'8' << BYTEŠIFT1) | L'X' }, V8 }, // 38
			{ { L'9', (L'9' << BYTEŠIFT1) | L'X' }, V9 }, // 39
			{ { L'a', (L'A' << BYTEŠIFT1) | L'X' }, VA }, // 41
			{ { L'b', (L'B' << BYTEŠIFT1) | L'X' }, VB }, // 42
			{ { L'c', (L'C' << BYTEŠIFT1) | L'X' }, VC }, // 43
			{ { L'd', (L'D' << BYTEŠIFT1) | L'X' }, VD }, // 44
			{ { L'e', (L'E' << BYTEŠIFT1) | L'X' }, VE }, // 45
			{ { L'f', (L'F' << BYTEŠIFT1) | L'X' }, VF }, // 46
			{ { L'g', (L'G' << BYTEŠIFT1) | L'X' }, VG }, // 47
			{ { L'h', (L'H' << BYTEŠIFT1) | L'X' }, VH }, // 48
			{ { L'i', (L'I' << BYTEŠIFT1) | L'X' }, VI }, // 49
			{ { L'j', (L'J' << BYTEŠIFT1) | L'X' }, VJ }, // 4A
			{ { L'k', (L'K' << BYTEŠIFT1) | L'X' }, VK }, // 4B
			{ { L'l', (L'L' << BYTEŠIFT1) | L'X' }, VL }, // 4C
			{ { L'm', (L'M' << BYTEŠIFT1) | L'X' }, VM }, // 4D
			{ { L'n', (L'N' << BYTEŠIFT1) | L'X' }, VN }, // 4E
			{ { L'o', (L'O' << BYTEŠIFT1) | L'X' }, VO }, // 4F
			{ { L'p', (L'P' << BYTEŠIFT1) | L'X' }, VP }, // 50
			{ { L'q', (L'Q' << BYTEŠIFT1) | L'X' }, VQ }, // 51
			{ { L'r', (L'R' << BYTEŠIFT1) | L'X' }, VR }, // 52
			{ { L's', (L'S' << BYTEŠIFT1) | L'X' }, VS }, // 53
			{ { L't', (L'T' << BYTEŠIFT1) | L'X' }, VT }, // 54
			{ { L'u', (L'U' << BYTEŠIFT1) | L'X' }, VU }, // 55
			{ { L'v', (L'V' << BYTEŠIFT1) | L'X' }, VV }, // 56
			{ { L'w', (L'W' << BYTEŠIFT1) | L'X' }, VW }, // 57
			{ { L'x', (L'X' << BYTEŠIFT1) | L'X' }, VX }, // 58
			{ { L'y', (L'Y' << BYTEŠIFT1) | L'X' }, VY }, // 59
			{ { L'z', (L'Z' << BYTEŠIFT1) | L'X' }, VZ }, // 5A
			{ { L'ŵ', (L'L' << BYTEŠIFT1) | L'W' }, VLWIN }, // 5B
			{ { L'Ŵ', (L'R' << BYTEŠIFT1) | L'W' }, VRWIN }, // 5C
			{ { L'M', (L'M' << BYTEŠIFT1) | L'E' }, VMENU }, // 5D
			{ { L'S', (L'S' << BYTEŠIFT1) | L'L' }, VSLEEP }, // 5F
			{ { L'₀', (L'N' << BYTEŠIFT1) | L'0' }, VNUM0 }, // 60
			{ { L'₁', (L'N' << BYTEŠIFT1) | L'1' }, VNUM1 }, // 61
			{ { L'₂', (L'N' << BYTEŠIFT1) | L'2' }, VNUM2 }, // 62
			{ { L'₃', (L'N' << BYTEŠIFT1) | L'3' }, VNUM3 }, // 63
			{ { L'₄', (L'N' << BYTEŠIFT1) | L'4' }, VNUM4 }, // 64
			{ { L'₅', (L'N' << BYTEŠIFT1) | L'5' }, VNUM5 }, // 65
			{ { L'₆', (L'N' << BYTEŠIFT1) | L'6' }, VNUM6 }, // 66
			{ { L'₇', (L'N' << BYTEŠIFT1) | L'7' }, VNUM7 }, // 67
			{ { L'₈', (L'N' << BYTEŠIFT1) | L'8' }, VNUM8 }, // 68
			{ { L'₉', (L'N' << BYTEŠIFT1) | L'9' }, VNUM9 }, // 69
			{ { L'×', (L'M' << BYTEŠIFT1) | L'U' }, VNUMMULT }, // 6A
			{ { L'₊', (L'A' << BYTEŠIFT1) | L'D' }, VNUMPLUS }, // 6B
			{ { L'`', (L'N' << BYTEŠIFT1) | L'S' }, VNUMSEPARATOR }, // 6C
			{ { L'₋', (L'S' << BYTEŠIFT1) | L'U' }, VNUMMINUS }, // 6D
			{ { L'·', (L'D' << BYTEŠIFT1) | L'C' }, VNUMDECIMAL }, // 6E
			{ { L'÷', (L'D' << BYTEŠIFT1) | L'V' }, VNUMDIV }, // 6F
			{ { L'¹', (L'F' << BYTEŠIFT1) | L'1' }, VF1 }, // 70
			{ { L'²', (L'F' << BYTEŠIFT1) | L'2' }, VF2 }, // 71
			{ { L'³', (L'F' << BYTEŠIFT1) | L'3' }, VF3 }, // 72
			{ { L'⁴', (L'F' << BYTEŠIFT1) | L'4' }, VF4 }, // 73
			{ { L'⁵', (L'F' << BYTEŠIFT1) | L'5' }, VF5 }, // 74
			{ { L'⁶', (L'F' << BYTEŠIFT1) | L'6' }, VF6 }, // 75
			{ { L'⁷', (L'F' << BYTEŠIFT1) | L'7' }, VF7 }, // 76
			{ { L'⁸', (L'F' << BYTEŠIFT1) | L'8' }, VF8 }, // 77
			{ { L'⁹', (L'F' << BYTEŠIFT1) | L'9' }, VF9 }, // 78
			{ { L'ᵃ', (L'F' << BYTEŠIFT1) | L'A' }, VF10 }, // 79
			{ { L'ᵇ', (L'F' << BYTEŠIFT1) | L'B' }, VF11 }, // 7A
			{ { L'ᶜ', (L'F' << BYTEŠIFT1) | L'C' }, VF12 }, // 7B
			{ { L'ᵈ', (L'F' << BYTEŠIFT1) | L'D' }, VF13 }, // 7C
			{ { L'ᵉ', (L'F' << BYTEŠIFT1) | L'E' }, VF14 }, // 7D
			{ { L'ᶠ', (L'F' << BYTEŠIFT1) | L'F' }, VF15 }, // 7E
			{ { L'ᵍ', (L'F' << BYTEŠIFT1) | L'G' }, VF16 }, // 7F
			{ { L'ʰ', (L'F' << BYTEŠIFT1) | L'H' }, VF17 }, // 80
			{ { L'ⁱ', (L'F' << BYTEŠIFT1) | L'I' }, VF18 }, // 81
			{ { L'ʲ', (L'F' << BYTEŠIFT1) | L'J' }, VF19 }, // 82
			{ { L'ᵏ', (L'F' << BYTEŠIFT1) | L'K' }, VF20 }, // 83
			{ { L'ˡ', (L'F' << BYTEŠIFT1) | L'L' }, VF21 }, // 84
			{ { L'ᵐ', (L'F' << BYTEŠIFT1) | L'M' }, VF22 }, // 85
			{ { L'ⁿ', (L'F' << BYTEŠIFT1) | L'N' }, VF23 }, // 86
			{ { L'ᵒ', (L'F' << BYTEŠIFT1) | L'O' }, VF24 }, // 87
			{ { L'Ṽ', (L'V' << BYTEŠIFT1) | L'V' }, VNAVVIEW }, // 88
			{ { L'Ñ', (L'V' << BYTEŠIFT1) | L'M' }, VNAVMENU }, // 89
			{ { L'Ũ', (L'V' << BYTEŠIFT1) | L'U' }, VNAVUP }, // 8A
			{ { L'Õ', (L'V' << BYTEŠIFT1) | L'D' }, VNAVDOWN }, // 8B
			{ { L'Ẽ', (L'V' << BYTEŠIFT1) | L'L' }, VNAVLEFT }, // 8C
			{ { L'Ĩ', (L'V' << BYTEŠIFT1) | L'R' }, VNAVRIGHT }, // 8D
			{ { L'Ã', (L'V' << BYTEŠIFT1) | L'A' }, VNAVACCEPT }, // 8E
			{ { L'Ỹ', (L'V' << BYTEŠIFT1) | L'C' }, VNAVCANCEL }, // 8F
			{ { L'Ň', (L'N' << BYTEŠIFT1) | L'K' }, VNUMLK }, // 90
			{ { L'Š', (L'S' << BYTEŠIFT1) | L'K' }, VSCRLLK }, // 91
			{ { L'ᴊ', (L'J' << BYTEŠIFT1) | L'J' }, VOEMNECEQUALFJJISHO }, // 92
			{ { L'ᴍ', (L'J' << BYTEŠIFT1) | L'M' }, VOEMFJMASSHOU }, // 93
			{ { L'ᴛ', (L'J' << BYTEŠIFT1) | L'T' }, VOEMFJTOUROKU }, // 94
			{ { L'ʟ', (L'J' << BYTEŠIFT1) | L'L' }, VOEMFJLOYA }, // 95
			{ { L'ʀ', (L'J' << BYTEŠIFT1) | L'R' }, VOEMFJROYA }, // 96
			{ { L'ŝ', (L'L' << BYTEŠIFT1) | L'S' }, VLŠIFT }, // A0
			{ { L'Ŝ', (L'R' << BYTEŠIFT1) | L'S' }, VRŠIFT }, // A1
			{ { L'ĉ', (L'L' << BYTEŠIFT1) | L'C' }, VLCTRL }, // A2
			{ { L'Ĉ', (L'R' << BYTEŠIFT1) | L'C' }, VRCTRL }, // A3
			{ { L'â', (L'L' << BYTEŠIFT1) | L'A' }, VLALT }, // A4
			{ { L'Â', (L'R' << BYTEŠIFT1) | L'A' }, VRALT }, // A5
			{ { L'Ǎ', (L'A' << BYTEŠIFT1) | L'G' }, VALTGR }, // 112 SPECIAL SOMETIMES RIGHT ALT
			{ { L'ḃ', (L'B' << BYTEŠIFT1) | L'B' }, VBROWSERBACK }, // A6
			{ { L'ḟ', (L'B' << BYTEŠIFT1) | L'F' }, VBROWSERFORWARD }, // A7
			{ { L'ṙ', (L'B' << BYTEŠIFT1) | L'R' }, VBROWSERREFRESH }, // A8
			{ { L'ṗ', (L'B' << BYTEŠIFT1) | L'P' }, VBROWSERSTOP }, // A9
			{ { L'ṡ', (L'B' << BYTEŠIFT1) | L'S' }, VBROWSERSEARČ }, // AA
			{ { L'ȧ', (L'B' << BYTEŠIFT1) | L'A' }, VBROWSERFAVORITES }, // AB
			{ { L'ḣ', (L'B' << BYTEŠIFT1) | L'H' }, VBROWSERHOME }, // AC
			{ { L'ḿ', (L'M' << BYTEŠIFT1) | L'U' }, VMUTE }, // AD
			{ { L'ẁ', (L'W' << BYTEŠIFT1) | L'D' }, VVOLDN }, // AE
			{ { L'ẃ', (L'W' << BYTEŠIFT1) | L'U' }, VVOLUP }, // AF
			{ { L'Ṭ', (L'X' << BYTEŠIFT1) | L'T' }, VNEXTTRACK }, // B0
			{ { L'ṭ', (L'P' << BYTEŠIFT1) | L'T' }, VPREVTRACK }, // B1
			{ { L'Ṃ', (L'M' << BYTEŠIFT1) | L'P' }, VMEDIASTOP }, // B2
			{ { L'Þ', (L'P' << BYTEŠIFT1) | L'P' }, VMEDIAPLAYPAUSE }, // B3
			{ { L'Ḷ', (L'L' << BYTEŠIFT1) | L'M' }, VLAUNČMAIL }, // B4
			{ { L'Ṁ', (L'M' << BYTEŠIFT1) | L'S' }, VLAUNČMEDIASELECT }, // B5
			{ { L'ł', (L'L' << BYTEŠIFT1) | L'1' }, VLAUNČAPP1 }, // B6
			{ { L'Ł', (L'L' << BYTEŠIFT1) | L'2' }, VLAUNČAPP2 }, // B7
			{ { L'¨', (L'O' << BYTEŠIFT1) | L'1' }, VDIÆRESIS }, // BA OEM_1
			{ { L'+', (L'P' << BYTEŠIFT1) | L'L' }, VPLUS }, // BB
			{ { L',', (L'C' << BYTEŠIFT1) | L'O' }, VCOMMA }, // BC
			{ { L'-', (L'M' << BYTEŠIFT1) | L'I' }, VMINUS }, // BD
			{ { L'.', (L'P' << BYTEŠIFT1) | L'E' }, VPERIOD }, // BE
			{ { L'\'', (L'O' << BYTEŠIFT1) | L'2' }, VAPOSTROPHE }, // BF OEM_2
			{ { L'ö', (L'O' << BYTEŠIFT1) | L'3' }, VÖ }, // C0 OEM_3
			{ { L'Ȧ', (L'G' << BYTEŠIFT1) | L'A' }, VGAMEPADA }, // C3
			{ { L'Ḃ', (L'G' << BYTEŠIFT1) | L'B' }, VGAMEPADB }, // C4
			{ { L'Ẋ', (L'G' << BYTEŠIFT1) | L'X' }, VGAMEPADX }, // C5
			{ { L'Ẏ', (L'G' << BYTEŠIFT1) | L'Y' }, VGAMEPADY }, // C6
			{ { L'Ṙ', (L'G' << BYTEŠIFT1) | L'R' }, VGAMEPADR }, // C7
			{ { L'Ė', (L'G' << BYTEŠIFT1) | L'L' }, VGAMEPADL }, // C8
			{ { L'æ', (L'L' << BYTEŠIFT1) | L'G' }, VGAMEPADLTRIGGER }, // C9
			{ { L'Æ', (L'R' << BYTEŠIFT1) | L'G' }, VGAMEPADRTRIGGER }, // CA
			{ { L'Ü', (L'D' << BYTEŠIFT1) | L'U' }, VGAMEPADUP }, // CB
			{ { L'Ö', (L'D' << BYTEŠIFT1) | L'D' }, VGAMEPADDOWN }, // CC
			{ { L'Ë', (L'D' << BYTEŠIFT1) | L'L' }, VGAMEPADLEFT }, // CD
			{ { L'Ï', (L'D' << BYTEŠIFT1) | L'R' }, VGAMEPADRIGHT }, // CE
			{ { L'ẗ', (L'G' << BYTEŠIFT1) | L'M' }, VGAMEPADMENU }, // CF
			{ { L'ẅ', (L'G' << BYTEŠIFT1) | L'V' }, VGAMEPADVIEW }, // D0
			{ { L'Ḷ', (L'L' << BYTEŠIFT1) | L'T' }, VGAMEPADLÞUMBSTICKBTN }, // D1
			{ { L'Ṛ', (L'R' << BYTEŠIFT1) | L'T' }, VGAMEPADRÞUMBSTICKBTN }, // D2
			{ { L'ū', (L'L' << BYTEŠIFT1) | L'U' }, VGAMEPAD_LTS_UP }, // D3
			{ { L'ḏ', (L'L' << BYTEŠIFT1) | L'D' }, VGAMEPAD_LTS_DOWN }, // D4
			{ { L'ṟ', (L'L' << BYTEŠIFT1) | L'R' }, VGAMEPAD_LTS_RIGHT }, // D5
			{ { L'ḻ', (L'L' << BYTEŠIFT1) | L'L' }, VGAMEPAD_LTS_LEFT }, // D6
			{ { L'Ū', (L'R' << BYTEŠIFT1) | L'U' }, VGAMEPAD_RTS_UP }, // D7
			{ { L'Ḏ', (L'R' << BYTEŠIFT1) | L'D' }, VGAMEPAD_RTS_DOWN }, // D8
			{ { L'Ṟ', (L'R' << BYTEŠIFT1) | L'R' }, VGAMEPAD_RTS_RIGHT }, // D9
			{ { L'Ḻ', (L'R' << BYTEŠIFT1) | L'L' }, VGAMEPAD_RTS_LEFT }, // DA
			{ { L'´', (L'O' << BYTEŠIFT1) | L'4' }, VACUTE }, // DB OEM_4
			{ { L'§', (L'O' << BYTEŠIFT1) | L'5' }, VPARA }, // DC OEM_5 AKA SECTION
			{ { L'å', (L'O' << BYTEŠIFT1) | L'6' }, VÅ }, // DD OEM_6
			{ { L'ä', (L'O' << BYTEŠIFT1) | L'7' }, VÄ }, // DE OEM_7
			{ { L'Ŏ', (L'O' << BYTEŠIFT1) | L'8' }, VOEM8 }, // DF OEM_8
			{ { L'Ẍ', (L'O' << BYTEŠIFT1) | L'A' }, VOEMAX }, // E1 OEM_AX
			{ { L'<', (L'O' << BYTEŠIFT1) | L'0' }, VLESSER }, // E2 OEM_102 LAST NORMAL
			{ { L'ḧ', (L'I' << BYTEŠIFT1) | L'H' }, VICOHELP }, // E3 ICO_HELP
			{ { L'⁰', (L'0' << BYTEŠIFT1) | L'0' }, VICO00 }, // E4 ICO_00
			{ { L'Ṕ', (L'P' << BYTEŠIFT1) | L'K' }, VPROCESSKEY }, // E5
			{ { L'Ć', (L'I' << BYTEŠIFT1) | L'C' }, VICOCLEAR }, // E6 ICO_CLEAR
			{ { L'Ṗ', (L'P' << BYTEŠIFT1) | L'C' }, VPACKET }, // E7
			{ { L'ɹ', (L'O' << BYTEŠIFT1) | L'R' }, VOEMRESET }, // E9
			{ { L'J', (L'O' << BYTEŠIFT1) | L'J' }, VOEMJUMP }, // EA
			{ { L'Ā', (L'P' << BYTEŠIFT1) | L'1' }, VOEMPA1 }, // EB
			{ { L'Ä', (L'P' << BYTEŠIFT1) | L'2' }, VOEMPA2 }, // EC
			{ { L'Ǟ', (L'P' << BYTEŠIFT1) | L'3' }, VOEMPA3 }, // ED
			{ { L'W', (L'O' << BYTEŠIFT1) | L'W' }, VOEMWSCTRL }, // EE
			{ { L'Ś', (L'O' << BYTEŠIFT1) | L'S' }, VOEMCUSEL }, // EF
			{ { L'Ă', (L'O' << BYTEŠIFT1) | L'T' }, VOEMATTN }, // F0
			{ { L'Ḟ', (L'O' << BYTEŠIFT1) | L'F' }, VOEMFINISH }, // F1
			{ { L'Ċ', (L'O' << BYTEŠIFT1) | L'Y' }, VOEMCOPY }, // F2
			{ { L'Ạ', (L'O' << BYTEŠIFT1) | L'U' }, VOEMAUTO }, // F3
			{ { L'Ê', (L'O' << BYTEŠIFT1) | L'E' }, VOEMENLW }, // F4
			{ { L'Ḇ', (L'O' << BYTEŠIFT1) | L'B' }, VOEMBACKTAB }, // F5
			{ { L'ă', (L'A' << BYTEŠIFT1) | L'T' }, VATTN }, // F6
			{ { L'ß', (L'C' << BYTEŠIFT1) | L'R' }, VCRSEL }, // F7
			{ { L'ĕ', (L'X' << BYTEŠIFT1) | L'S' }, VEXSEL }, // F8
			{ { L'ȇ', (L'E' << BYTEŠIFT1) | L'R' }, VEREOF }, // F9
			{ { L'ÿ', (L'P' << BYTEŠIFT1) | L'Y' }, VPLAY }, // FA
			{ { L'Z', (L'Z' << BYTEŠIFT1) | L'O' }, VZOOM }, // FB
			{ { L'N', (L'N' << BYTEŠIFT1) | L'O' }, VNONAME }, // FC
			{ { L'à', (L'A' << BYTEŠIFT1) | L'1' }, VPA1 }, // FD
			{ { L'Ç', (L'O' << BYTEŠIFT1) | L'C' }, VOEMCLEAR }, // FE
			{ { L'F', (L'V' << BYTEŠIFT1) | L'F' }, VFF }, // FF DO NOT USE
			};

	skeys.clear();
	ckeys.clear();
	for (std::pair<std::pair<wč, wč> const, uš> const &s : keys) {
		ckeys.insert(std::pair<wč, uš>(s.first.first, s.second));
		skeys.insert(std::pair<wč, uš>(s.first.second, s.second));
	}
}

void exitInit () {
	cases.clear();
	keys.clear();
}

uš čari (wč a, wč b) {
	wč cc = (b << BYTEŠIFT1) | a;
	if (skeys.find(cc) != skeys.end()) {
		return (skeys.at(cc));
	}
	printf("Fail TO FIND %lc, %X", cc, cc);
	return (0);
}

uš čari (wč cc) {
	if (ckeys.find(cc) != ckeys.end()) {
		return (ckeys.at(cc));
	}
	printf("Fail TO FIND %lc, %X", cc, cc);
	return (0);
}

ul cmdCode (wcr cc) {
	if (cases.find(cc) != cases.end()) {
		return (cases.at(cc) << COMMANDSHIFT);
	}
	printf("Fail TO FIND COMMAND");
	return (0);
}
