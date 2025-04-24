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
 * @file	: init.cpp
 * @desc	: TODO
 * @author	: Johannah Granström
 * @reqs	: NONE
 */

#include "oðer.h"
#include <unordered_map>
#include <map>
#include <queue>

static std::map<std::pair<wc, wc>, us> keys;
static std::unordered_map<wc, us> skeys;
static std::unordered_map<wc, us> ckeys;

static std::unordered_map<ws, ul, WSHash> cases;

void enterInit () {
	cases = { { L"run", CRUN }, { L"calc", CCALC }, { L"paste", CPASTE }, { L"pastes", CPASTES }, { L"exit", CEXIT }, { L"auth", CAUTH }, { L"window", CWINDOW },
			{ L"robot", CROBOT }, { L"lia", CLIA }, { L"reload", CRELOAD }, { L"music", CMUSIC }, { L"remap", CREMAP }, { L"block", CLLBLOCK }, { L"ctrlblock", CLLCTRLBLOCK } };
	keys = { { { L'ṿ', (L'M' << BYTESHIFT1) | L'V' }, VMMOVE }, // 100 NOT
			{ { L'ḷ', (L'M' << BYTESHIFT1) | L'L' }, VML }, // 01 NOT
			{ { L'ḍ', (L'W' << BYTESHIFT1) | L'D' }, VMWD }, // 101 NOT
			{ { L'ṛ', (L'M' << BYTESHIFT1) | L'R' }, VMR }, // 02 NOT
			{ { L'ụ', (L'W' << BYTESHIFT1) | L'U' }, VMWU }, // 102 NOT
			{ { L'ç', (L'C' << BYTESHIFT1) | L'C' }, VCANCELCTRLSCRLK }, // 03, SAME
			{ { L'ʙ', (L'B' << BYTESHIFT1) | L'R' }, VBREAK }, // 103 CTRL + PAUSE
			{ { L'ṃ', (L'M' << BYTESHIFT1) | L'W' }, VMM }, // 04 NOT
			{ { L'ẋ', (L'M' << BYTESHIFT1) | L'4' }, VM4 }, // 05 NOT AKA X1
			{ { L'ẍ', (L'M' << BYTESHIFT1) | L'5' }, VM5 }, // 06 NOT AKA X2
			{ { L'B', (L'B' << BYTESHIFT1) | L'S' }, VBS }, // 08
			{ { L'T', (L'T' << BYTESHIFT1) | L'A' }, VTAB }, // 09
			{ { L'Č', (L'N' << BYTESHIFT1) | L'C' }, VNUMCLEAR }, // 0C
			{ { L'ž', (L'R' << BYTESHIFT1) | L'N' }, VRETURN }, // 0D
			{ { L'Ž', (L'E' << BYTESHIFT1) | L'T' }, VENTER }, // 10D NUM RETURN~
			{ { L'š', (L'S' << BYTESHIFT1) | L'H' }, VSHIFT }, // 10
			{ { L'č', (L'C' << BYTESHIFT1) | L'T' }, VCTRL }, // 11
			{ { L'ǎ', (L'A' << BYTESHIFT1) | L'L' }, VALT }, // 12
			{ { L'ņ', (L'C' << BYTESHIFT1) | L'N' }, VCTRLNUMLOCK }, // 13
			{ { L'P', (L'P' << BYTESHIFT1) | L'A' }, VPAUSE }, // 113 (F4) FOLLOWED BY FF
			{ { L'C', (L'C' << BYTESHIFT1) | L'A' }, VCAPS }, // 14
			{ { L'K', (L'K' << BYTESHIFT1) | L'H' }, VKANAHANGUL }, // 15 SAME
			{ { L'í', (L'I' << BYTESHIFT1) | L'O' }, VIMEON }, // 16
			{ { L'ǰ', (L'J' << BYTESHIFT1) | L'U' }, VJUNJA }, // 17
			{ { L'ḟ', (L'I' << BYTESHIFT1) | L'A' }, VFINAL }, // 18
			{ { L'ñ', (L'N' << BYTESHIFT1) | L'J' }, VHANJAKANJI }, // 19 SAME
			{ { L'ì', (L'I' << BYTESHIFT1) | L'F' }, VIMEOFF }, // 1A
			{ { L'E', (L'E' << BYTESHIFT1) | L'S' }, VESC }, // 1B
			{ { L'ć', (L'C' << BYTESHIFT1) | L'O' }, VCONVERT }, // 1C
			{ { L'ń', (L'N' << BYTESHIFT1) | L'C' }, VNONCONVERT }, // 1D
			{ { L'á', (L'A' << BYTESHIFT1) | L'C' }, VACCEPT }, // 1E
			{ { L'ḿ', (L'M' << BYTESHIFT1) | L'C' }, VMODECHANGE }, // 1F
			{ { L'_', (L'S' << BYTESHIFT1) | L'P' }, VSPACE }, // 20
			{ { L'Ĝ', (L'G' << BYTESHIFT1) | L'U' }, VNUMPGUP }, // 21
			{ { L'ĝ', (L'P' << BYTESHIFT1) | L'U' }, VPGUP }, // 121
			{ { L'Ǧ', (L'G' << BYTESHIFT1) | L'D' }, VNUMPGDN }, // 22
			{ { L'ǧ', (L'P' << BYTESHIFT1) | L'D' }, VPGDN }, // 122
			{ { L'Ě', (L'N' << BYTESHIFT1) | L'E' }, VNUMEND }, // 23
			{ { L'ě', (L'E' << BYTESHIFT1) | L'N' }, VEND }, // 123
			{ { L'Ȟ', (L'N' << BYTESHIFT1) | L'H' }, VNUMHOME }, // 24
			{ { L'ȟ', (L'H' << BYTESHIFT1) | L'O' }, VHOME }, // 124
			{ { L'Ľ', (L'N' << BYTESHIFT1) | L'L' }, VNUMLEFT }, // 25
			{ { L'ľ', (L'L' << BYTESHIFT1) | L'E' }, VLEFT }, // 125
			{ { L'Ǔ', (L'N' << BYTESHIFT1) | L'U' }, VNUMUP }, // 26
			{ { L'ǔ', (L'U' << BYTESHIFT1) | L'P' }, VUP }, // 126
			{ { L'Ř', (L'N' << BYTESHIFT1) | L'R' }, VNUMRIGHT }, // 27
			{ { L'ř', (L'R' << BYTESHIFT1) | L'I' }, VRIGHT }, // 127
			{ { L'Ď', (L'N' << BYTESHIFT1) | L'D' }, VNUMDOWN }, // 28
			{ { L'ď', (L'D' << BYTESHIFT1) | L'O' }, VDOWN }, // 128
			{ { L'ś', (L'S' << BYTESHIFT1) | L'E' }, VSELECT }, // 29
			{ { L'ṕ', (L'P' << BYTESHIFT1) | L'R' }, VPRINT }, // 2A
			{ { L'X', (L'E' << BYTESHIFT1) | L'X' }, VEXECUTE }, // 2B
			{ { L'Q', (L'P' << BYTESHIFT1) | L'S' }, VSYSRQPRTSC }, // 2C SAME, NOT YET DISTINGUISHED TODO
			{ { L'Ǐ', (L'N' << BYTESHIFT1) | L'I' }, VNUMINS }, // 2D
			{ { L'ǐ', (L'I' << BYTESHIFT1) | L'N' }, VINS }, // 12D
			{ { L'Ť', (L'N' << BYTESHIFT1) | L'T' }, VNUMDEL }, // 2E
			{ { L'ť', (L'D' << BYTESHIFT1) | L'T' }, VDEL }, // 12E
			{ { L'H', (L'H' << BYTESHIFT1) | L'E' }, VHELP }, // 2F
			{ { L'0', (L'0' << BYTESHIFT1) | L'X' }, V0 }, // 30
			{ { L'1', (L'1' << BYTESHIFT1) | L'X' }, V1 }, // 31
			{ { L'2', (L'2' << BYTESHIFT1) | L'X' }, V2 }, // 32
			{ { L'3', (L'3' << BYTESHIFT1) | L'X' }, V3 }, // 33
			{ { L'4', (L'4' << BYTESHIFT1) | L'X' }, V4 }, // 34
			{ { L'5', (L'5' << BYTESHIFT1) | L'X' }, V5 }, // 35
			{ { L'6', (L'6' << BYTESHIFT1) | L'X' }, V6 }, // 36
			{ { L'7', (L'7' << BYTESHIFT1) | L'X' }, V7 }, // 37
			{ { L'8', (L'8' << BYTESHIFT1) | L'X' }, V8 }, // 38
			{ { L'9', (L'9' << BYTESHIFT1) | L'X' }, V9 }, // 39
			{ { L'a', (L'A' << BYTESHIFT1) | L'X' }, VA }, // 41
			{ { L'b', (L'B' << BYTESHIFT1) | L'X' }, VB }, // 42
			{ { L'c', (L'C' << BYTESHIFT1) | L'X' }, VC }, // 43
			{ { L'd', (L'D' << BYTESHIFT1) | L'X' }, VD }, // 44
			{ { L'e', (L'E' << BYTESHIFT1) | L'X' }, VE }, // 45
			{ { L'f', (L'F' << BYTESHIFT1) | L'X' }, VF }, // 46
			{ { L'g', (L'G' << BYTESHIFT1) | L'X' }, VG }, // 47
			{ { L'h', (L'H' << BYTESHIFT1) | L'X' }, VH }, // 48
			{ { L'i', (L'I' << BYTESHIFT1) | L'X' }, VI }, // 49
			{ { L'j', (L'J' << BYTESHIFT1) | L'X' }, VJ }, // 4A
			{ { L'k', (L'K' << BYTESHIFT1) | L'X' }, VK }, // 4B
			{ { L'l', (L'L' << BYTESHIFT1) | L'X' }, VL }, // 4C
			{ { L'm', (L'M' << BYTESHIFT1) | L'X' }, VM }, // 4D
			{ { L'n', (L'N' << BYTESHIFT1) | L'X' }, VN }, // 4E
			{ { L'o', (L'O' << BYTESHIFT1) | L'X' }, VO }, // 4F
			{ { L'p', (L'P' << BYTESHIFT1) | L'X' }, VP }, // 50
			{ { L'q', (L'Q' << BYTESHIFT1) | L'X' }, VQ }, // 51
			{ { L'r', (L'R' << BYTESHIFT1) | L'X' }, VR }, // 52
			{ { L's', (L'S' << BYTESHIFT1) | L'X' }, VS }, // 53
			{ { L't', (L'T' << BYTESHIFT1) | L'X' }, VT }, // 54
			{ { L'u', (L'U' << BYTESHIFT1) | L'X' }, VU }, // 55
			{ { L'v', (L'V' << BYTESHIFT1) | L'X' }, VV }, // 56
			{ { L'w', (L'W' << BYTESHIFT1) | L'X' }, VW }, // 57
			{ { L'x', (L'X' << BYTESHIFT1) | L'X' }, VX }, // 58
			{ { L'y', (L'Y' << BYTESHIFT1) | L'X' }, VY }, // 59
			{ { L'z', (L'Z' << BYTESHIFT1) | L'X' }, VZ }, // 5A
			{ { L'ŵ', (L'L' << BYTESHIFT1) | L'W' }, VLWIN }, // 5B
			{ { L'Ŵ', (L'R' << BYTESHIFT1) | L'W' }, VRWIN }, // 5C
			{ { L'M', (L'M' << BYTESHIFT1) | L'E' }, VMENU }, // 5D
			{ { L'S', (L'S' << BYTESHIFT1) | L'L' }, VSLEEP }, // 5F
			{ { L'₀', (L'N' << BYTESHIFT1) | L'0' }, VNUM0 }, // 60
			{ { L'₁', (L'N' << BYTESHIFT1) | L'1' }, VNUM1 }, // 61
			{ { L'₂', (L'N' << BYTESHIFT1) | L'2' }, VNUM2 }, // 62
			{ { L'₃', (L'N' << BYTESHIFT1) | L'3' }, VNUM3 }, // 63
			{ { L'₄', (L'N' << BYTESHIFT1) | L'4' }, VNUM4 }, // 64
			{ { L'₅', (L'N' << BYTESHIFT1) | L'5' }, VNUM5 }, // 65
			{ { L'₆', (L'N' << BYTESHIFT1) | L'6' }, VNUM6 }, // 66
			{ { L'₇', (L'N' << BYTESHIFT1) | L'7' }, VNUM7 }, // 67
			{ { L'₈', (L'N' << BYTESHIFT1) | L'8' }, VNUM8 }, // 68
			{ { L'₉', (L'N' << BYTESHIFT1) | L'9' }, VNUM9 }, // 69
			{ { L'×', (L'M' << BYTESHIFT1) | L'U' }, VNUMMULT }, // 6A
			{ { L'₊', (L'A' << BYTESHIFT1) | L'D' }, VNUMPLUS }, // 6B
			{ { L'`', (L'N' << BYTESHIFT1) | L'S' }, VNUMSEPARATOR }, // 6C
			{ { L'₋', (L'S' << BYTESHIFT1) | L'U' }, VNUMMINUS }, // 6D
			{ { L'·', (L'D' << BYTESHIFT1) | L'C' }, VNUMDECIMAL }, // 6E
			{ { L'÷', (L'D' << BYTESHIFT1) | L'V' }, VNUMDIV }, // 6F
			{ { L'¹', (L'F' << BYTESHIFT1) | L'1' }, VF1 }, // 70
			{ { L'²', (L'F' << BYTESHIFT1) | L'2' }, VF2 }, // 71
			{ { L'³', (L'F' << BYTESHIFT1) | L'3' }, VF3 }, // 72
			{ { L'⁴', (L'F' << BYTESHIFT1) | L'4' }, VF4 }, // 73
			{ { L'⁵', (L'F' << BYTESHIFT1) | L'5' }, VF5 }, // 74
			{ { L'⁶', (L'F' << BYTESHIFT1) | L'6' }, VF6 }, // 75
			{ { L'⁷', (L'F' << BYTESHIFT1) | L'7' }, VF7 }, // 76
			{ { L'⁸', (L'F' << BYTESHIFT1) | L'8' }, VF8 }, // 77
			{ { L'⁹', (L'F' << BYTESHIFT1) | L'9' }, VF9 }, // 78
			{ { L'ᵃ', (L'F' << BYTESHIFT1) | L'A' }, VF10 }, // 79
			{ { L'ᵇ', (L'F' << BYTESHIFT1) | L'B' }, VF11 }, // 7A
			{ { L'ᶜ', (L'F' << BYTESHIFT1) | L'C' }, VF12 }, // 7B
			{ { L'ᵈ', (L'F' << BYTESHIFT1) | L'D' }, VF13 }, // 7C
			{ { L'ᵉ', (L'F' << BYTESHIFT1) | L'E' }, VF14 }, // 7D
			{ { L'ᶠ', (L'F' << BYTESHIFT1) | L'F' }, VF15 }, // 7E
			{ { L'ᵍ', (L'F' << BYTESHIFT1) | L'G' }, VF16 }, // 7F
			{ { L'ʰ', (L'F' << BYTESHIFT1) | L'H' }, VF17 }, // 80
			{ { L'ⁱ', (L'F' << BYTESHIFT1) | L'I' }, VF18 }, // 81
			{ { L'ʲ', (L'F' << BYTESHIFT1) | L'J' }, VF19 }, // 82
			{ { L'ᵏ', (L'F' << BYTESHIFT1) | L'K' }, VF20 }, // 83
			{ { L'ˡ', (L'F' << BYTESHIFT1) | L'L' }, VF21 }, // 84
			{ { L'ᵐ', (L'F' << BYTESHIFT1) | L'M' }, VF22 }, // 85
			{ { L'ⁿ', (L'F' << BYTESHIFT1) | L'N' }, VF23 }, // 86
			{ { L'ᵒ', (L'F' << BYTESHIFT1) | L'O' }, VF24 }, // 87
			{ { L'Ṽ', (L'V' << BYTESHIFT1) | L'V' }, VNAVVIEW }, // 88
			{ { L'Ñ', (L'V' << BYTESHIFT1) | L'M' }, VNAVMENU }, // 89
			{ { L'Ũ', (L'V' << BYTESHIFT1) | L'U' }, VNAVUP }, // 8A
			{ { L'Õ', (L'V' << BYTESHIFT1) | L'D' }, VNAVDOWN }, // 8B
			{ { L'Ẽ', (L'V' << BYTESHIFT1) | L'L' }, VNAVLEFT }, // 8C
			{ { L'Ĩ', (L'V' << BYTESHIFT1) | L'R' }, VNAVRIGHT }, // 8D
			{ { L'Ã', (L'V' << BYTESHIFT1) | L'A' }, VNAVACCEPT }, // 8E
			{ { L'Ỹ', (L'V' << BYTESHIFT1) | L'C' }, VNAVCANCEL }, // 8F
			{ { L'Ň', (L'N' << BYTESHIFT1) | L'K' }, VNUMLK }, // 90
			{ { L'Š', (L'S' << BYTESHIFT1) | L'K' }, VSCRLLK }, // 91
			{ { L'ᴊ', (L'J' << BYTESHIFT1) | L'J' }, VOEMNECEQUALFJJISHO }, // 92
			{ { L'ᴍ', (L'J' << BYTESHIFT1) | L'M' }, VOEMFJMASSHOU }, // 93
			{ { L'ᴛ', (L'J' << BYTESHIFT1) | L'T' }, VOEMFJTOUROKU }, // 94
			{ { L'ʟ', (L'J' << BYTESHIFT1) | L'L' }, VOEMFJLOYA }, // 95
			{ { L'ʀ', (L'J' << BYTESHIFT1) | L'R' }, VOEMFJROYA }, // 96
			{ { L'ŝ', (L'L' << BYTESHIFT1) | L'S' }, VLSHIFT }, // A0
			{ { L'Ŝ', (L'R' << BYTESHIFT1) | L'S' }, VRSHIFT }, // A1
			{ { L'ĉ', (L'L' << BYTESHIFT1) | L'C' }, VLCTRL }, // A2
			{ { L'Ĉ', (L'R' << BYTESHIFT1) | L'C' }, VRCTRL }, // A3
			{ { L'â', (L'L' << BYTESHIFT1) | L'A' }, VLALT }, // A4
			{ { L'Â', (L'R' << BYTESHIFT1) | L'A' }, VRALT }, // A5
			{ { L'Ǎ', (L'A' << BYTESHIFT1) | L'G' }, VALTGR }, // 112 SPECIAL SOMETIMES RIGHT ALT
			{ { L'ḃ', (L'B' << BYTESHIFT1) | L'B' }, VBROWSERBACK }, // A6
			{ { L'ḟ', (L'B' << BYTESHIFT1) | L'F' }, VBROWSERFORWARD }, // A7
			{ { L'ṙ', (L'B' << BYTESHIFT1) | L'R' }, VBROWSERREFRESH }, // A8
			{ { L'ṗ', (L'B' << BYTESHIFT1) | L'P' }, VBROWSERSTOP }, // A9
			{ { L'ṡ', (L'B' << BYTESHIFT1) | L'S' }, VBROWSERSEARCH }, // AA
			{ { L'ȧ', (L'B' << BYTESHIFT1) | L'A' }, VBROWSERFAVORITES }, // AB
			{ { L'ḣ', (L'B' << BYTESHIFT1) | L'H' }, VBROWSERHOME }, // AC
			{ { L'ḿ', (L'M' << BYTESHIFT1) | L'U' }, VMUTE }, // AD
			{ { L'ẁ', (L'W' << BYTESHIFT1) | L'D' }, VVOLDN }, // AE
			{ { L'ẃ', (L'W' << BYTESHIFT1) | L'U' }, VVOLUP }, // AF
			{ { L'Ṭ', (L'X' << BYTESHIFT1) | L'T' }, VNEXTTRACK }, // B0
			{ { L'ṭ', (L'P' << BYTESHIFT1) | L'T' }, VPREVTRACK }, // B1
			{ { L'Ṃ', (L'M' << BYTESHIFT1) | L'P' }, VMEDIASTOP }, // B2
			{ { L'Þ', (L'P' << BYTESHIFT1) | L'P' }, VMEDIAPLAYPAUSE }, // B3
			{ { L'Ḷ', (L'L' << BYTESHIFT1) | L'M' }, VLAUNCHMAIL }, // B4
			{ { L'Ṁ', (L'M' << BYTESHIFT1) | L'S' }, VLAUNCHMEDIASELECT }, // B5
			{ { L'ł', (L'L' << BYTESHIFT1) | L'1' }, VLAUNCHAPP1 }, // B6
			{ { L'Ł', (L'L' << BYTESHIFT1) | L'2' }, VLAUNCHAPP2 }, // B7
			{ { L'¨', (L'O' << BYTESHIFT1) | L'1' }, VDIERESIS }, // BA OEM_1
			{ { L'+', (L'P' << BYTESHIFT1) | L'L' }, VPLUS }, // BB
			{ { L',', (L'C' << BYTESHIFT1) | L'O' }, VCOMMA }, // BC
			{ { L'-', (L'M' << BYTESHIFT1) | L'I' }, VMINUS }, // BD
			{ { L'.', (L'P' << BYTESHIFT1) | L'E' }, VPERIOD }, // BE
			{ { L'\'', (L'O' << BYTESHIFT1) | L'2' }, VAPOSTROPHE }, // BF OEM_2
			{ { L'ö', (L'O' << BYTESHIFT1) | L'3' }, VÖ }, // C0 OEM_3
			{ { L'Ȧ', (L'G' << BYTESHIFT1) | L'A' }, VGAMEPADA }, // C3
			{ { L'Ḃ', (L'G' << BYTESHIFT1) | L'B' }, VGAMEPADB }, // C4
			{ { L'Ẋ', (L'G' << BYTESHIFT1) | L'X' }, VGAMEPADX }, // C5
			{ { L'Ẏ', (L'G' << BYTESHIFT1) | L'Y' }, VGAMEPADY }, // C6
			{ { L'Ṙ', (L'G' << BYTESHIFT1) | L'R' }, VGAMEPADR }, // C7
			{ { L'Ė', (L'G' << BYTESHIFT1) | L'L' }, VGAMEPADL }, // C8
			{ { L'æ', (L'L' << BYTESHIFT1) | L'G' }, VGAMEPADLTRIGGER }, // C9
			{ { L'Æ', (L'R' << BYTESHIFT1) | L'G' }, VGAMEPADRTRIGGER }, // CA
			{ { L'Ü', (L'D' << BYTESHIFT1) | L'U' }, VGAMEPADUP }, // CB
			{ { L'Ö', (L'D' << BYTESHIFT1) | L'D' }, VGAMEPADDOWN }, // CC
			{ { L'Ë', (L'D' << BYTESHIFT1) | L'L' }, VGAMEPADLEFT }, // CD
			{ { L'Ï', (L'D' << BYTESHIFT1) | L'R' }, VGAMEPADRIGHT }, // CE
			{ { L'ẗ', (L'G' << BYTESHIFT1) | L'M' }, VGAMEPADMENU }, // CF
			{ { L'ẅ', (L'G' << BYTESHIFT1) | L'V' }, VGAMEPADVIEW }, // D0
			{ { L'Ḷ', (L'L' << BYTESHIFT1) | L'T' }, VGAMEPADLTHUMBSTICKBTN }, // D1
			{ { L'Ṛ', (L'R' << BYTESHIFT1) | L'T' }, VGAMEPADRTHUMBSTICKBTN }, // D2
			{ { L'ū', (L'L' << BYTESHIFT1) | L'U' }, VGAMEPAD_LTS_UP }, // D3
			{ { L'ḏ', (L'L' << BYTESHIFT1) | L'D' }, VGAMEPAD_LTS_DOWN }, // D4
			{ { L'ṟ', (L'L' << BYTESHIFT1) | L'R' }, VGAMEPAD_LTS_RIGHT }, // D5
			{ { L'ḻ', (L'L' << BYTESHIFT1) | L'L' }, VGAMEPAD_LTS_LEFT }, // D6
			{ { L'Ū', (L'R' << BYTESHIFT1) | L'U' }, VGAMEPAD_RTS_UP }, // D7
			{ { L'Ḏ', (L'R' << BYTESHIFT1) | L'D' }, VGAMEPAD_RTS_DOWN }, // D8
			{ { L'Ṟ', (L'R' << BYTESHIFT1) | L'R' }, VGAMEPAD_RTS_RIGHT }, // D9
			{ { L'Ḻ', (L'R' << BYTESHIFT1) | L'L' }, VGAMEPAD_RTS_LEFT }, // DA
			{ { L'´', (L'O' << BYTESHIFT1) | L'4' }, VACUTE }, // DB OEM_4
			{ { L'§', (L'O' << BYTESHIFT1) | L'5' }, VPARA }, // DC OEM_5 AKA SECTION
			{ { L'å', (L'O' << BYTESHIFT1) | L'6' }, VÅ }, // DD OEM_6
			{ { L'ä', (L'O' << BYTESHIFT1) | L'7' }, VÄ }, // DE OEM_7
			{ { L'Ŏ', (L'O' << BYTESHIFT1) | L'8' }, VOEM8 }, // DF OEM_8
			{ { L'Ẍ', (L'O' << BYTESHIFT1) | L'A' }, VOEMAX }, // E1 OEM_AX
			{ { L'<', (L'O' << BYTESHIFT1) | L'0' }, VLESSER }, // E2 OEM_102 LAST NORMAL
			{ { L'ḧ', (L'I' << BYTESHIFT1) | L'H' }, VICOHELP }, // E3 ICO_HELP
			{ { L'⁰', (L'0' << BYTESHIFT1) | L'0' }, VICO00 }, // E4 ICO_00
			{ { L'Ṕ', (L'P' << BYTESHIFT1) | L'K' }, VPROCESSKEY }, // E5
			{ { L'Ć', (L'I' << BYTESHIFT1) | L'C' }, VICOCLEAR }, // E6 ICO_CLEAR
			{ { L'Ṗ', (L'P' << BYTESHIFT1) | L'C' }, VPACKET }, // E7
			{ { L'ɹ', (L'O' << BYTESHIFT1) | L'R' }, VOEMRESET }, // E9
			{ { L'J', (L'O' << BYTESHIFT1) | L'J' }, VOEMJUMP }, // EA
			{ { L'Ā', (L'P' << BYTESHIFT1) | L'1' }, VOEMPA1 }, // EB
			{ { L'Ä', (L'P' << BYTESHIFT1) | L'2' }, VOEMPA2 }, // EC
			{ { L'Ǟ', (L'P' << BYTESHIFT1) | L'3' }, VOEMPA3 }, // ED
			{ { L'W', (L'O' << BYTESHIFT1) | L'W' }, VOEMWSCTRL }, // EE
			{ { L'Ś', (L'O' << BYTESHIFT1) | L'S' }, VOEMCUSEL }, // EF
			{ { L'Ă', (L'O' << BYTESHIFT1) | L'T' }, VOEMATTN }, // F0
			{ { L'Ḟ', (L'O' << BYTESHIFT1) | L'F' }, VOEMFINISH }, // F1
			{ { L'Ċ', (L'O' << BYTESHIFT1) | L'Y' }, VOEMCOPY }, // F2
			{ { L'Ạ', (L'O' << BYTESHIFT1) | L'U' }, VOEMAUTO }, // F3
			{ { L'Ê', (L'O' << BYTESHIFT1) | L'E' }, VOEMENLW }, // F4
			{ { L'Ḇ', (L'O' << BYTESHIFT1) | L'B' }, VOEMBACKTAB }, // F5
			{ { L'ă', (L'A' << BYTESHIFT1) | L'T' }, VATTN }, // F6
			{ { L'ß', (L'C' << BYTESHIFT1) | L'R' }, VCRSEL }, // F7
			{ { L'ĕ', (L'X' << BYTESHIFT1) | L'S' }, VEXSEL }, // F8
			{ { L'ȇ', (L'E' << BYTESHIFT1) | L'R' }, VEREOF }, // F9
			{ { L'ÿ', (L'P' << BYTESHIFT1) | L'Y' }, VPLAY }, // FA
			{ { L'Z', (L'Z' << BYTESHIFT1) | L'O' }, VZOOM }, // FB
			{ { L'N', (L'N' << BYTESHIFT1) | L'O' }, VNONAME }, // FC
			{ { L'à', (L'A' << BYTESHIFT1) | L'1' }, VPA1 }, // FD
			{ { L'Ç', (L'O' << BYTESHIFT1) | L'C' }, VOEMCLEAR }, // FE
			{ { L'F', (L'V' << BYTESHIFT1) | L'F' }, VFF }, // FF DO NOT USE
			};

	for (std::pair<std::pair<wc, wc> const, us> const &s : keys) {
		ckeys.insert(std::pair<wc, us>(s.first.first, s.second));
		skeys.insert(std::pair<wc, us>(s.first.second, s.second));
	}
}

vo exitInit () {
	cases.clear();
	keys.clear();
	ckeys.clear();
	skeys.clear();
}

us chari (wc a, wc b) {
	wc cc = (b << BYTESHIFT1) | a;
	if (skeys.find(cc) != skeys.end()) {
		return (skeys.at(cc));
	}
	printf("Fail TO FIND %lc, %d", cc, cc);
	return (0);
}

us chari (wc cc) {
	if (ckeys.find(cc) != ckeys.end()) {
		return (ckeys.at(cc));
	}
	printf("Fail TO FIND %lc, %d", cc, cc);
	return (0);
}

ul cmdCode (wcr cc) {
	if (cases.find(cc) != cases.end()) {
		return (cases.at(cc) << COMMANDSHIFT);
	}
	printf("Fail TO FIND COMMAND");
	return (0);
}

std::queue<us> f;
void setAllowQueue (us key1) {
	f.push(key1);
	f.push(key1);
}

void setPreAllowQueue (us key1) {
	f.push(key1);
}

void setRelAllowQueue (us key1) {
	f.push(key1);
}

void setAllowQueue (us key1, us key2) {
	f.push(key1);
	f.push(key2);
	f.push(key2);
	f.push(key1);
}

void setAllowQueue (us key1, us key2, us key3) {
	f.push(key1);
	f.push(key2);
	f.push(key3);
	f.push(key3);
	f.push(key2);
	f.push(key1);
}

bool checkAllowQueue (us key) {
	return (f.front() == key);
}

void popAllowQueue () {
	f.pop();
}

uint16_t frontAllowQueue () {
	return (f.front());
}
