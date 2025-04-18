/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as published by ðe Free Software Foundation,
	eiðer version 3 of ðe License, or (at your option) any later version.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÞOUT ANY WARRANTY;
	wiþout even ðe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You should have received a copy of ðe GNU General Public License
	aloŋ wiþ ðis program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

package org.nangliaa.extra;

public class Codes {
	public static final int OLD_SHIFT_MASK = 0x1; // Event.SHIFT_MASK
	public static final int OLD_CTRL_MASK = 0x2; // Event.CTRL_MASK
	public static final int OLD_META_MASK = 0x4; // Event.META_MASK
	public static final int OLD_ALT_MASK = 0x8; // Event.ALT_MASK
	public static final int OLD_M1_MASK = 0x10; // InputEvent.BUTTON1_MASK
	public static final int OLD_ALTGR_MASK = 0x20; // InputEvent.ALT_GRAPH_MASK

	public static final int SHIFT_MASK = 0x40; // SHIFT_DOWN_MASK
	public static final int CTRL_MASK = 0x80; // CTRL_DOWN_MASK; // 80
	public static final int META_MASK = 0x100; // META_DOWN_MASK; // 100
	public static final int ALT_MASK = 0x200; // ALT_DOWN_MASK; // 200
	public static final int M1_MASK = 0x400; // BUTTON1_DOWN_MASK; // 400
	public static final int M2_MASK = 0x800; // BUTTON2_DOWN_MASK; // 800
	public static final int M3_MASK = 0x1000; // BUTTON3_DOWN_MASK; // 1000
	public static final int ALTGR_MASK = 0x2000; // ALT_GRAPH_DOWN_MASK; // 2000
	public static final int ALTGR_COMBINED_MASK = ALTGR_MASK | ALT_MASK | CTRL_MASK;
	public static final int M4_MASK = 1 << 14; // 4000
	public static final int M5_MASK = 1 << 15; // 8000

	public static final int CARON_MASK = 0x10000; // 10000
	public static final int ACUTE_MASK = 0x20000; // 20000
	public static final int DIERESIS_MASK = 0x40000; // 40000
	public static final int CIRCUMFLEX_MASK = 0x80000; // 80000
	public static final int MENU_MASK = 0x100000; // 100000
	public static final int aCARON_MASK = 0x200000; // 200000
	public static final int aDIERESIS_MASK = 0x400000; // 400000
	public static final int aCIRCUMFLEX_MASK = 0x800000; // 800000
	public static final int bACUTE_MASK = 0x1000000; // 1000000
	public static final int bCARON_MASK = 0x2000000; // 2000000
	public static final int bDIERESIS_MASK = 0x4000000; // 4000000
	public static final int bCIRCUMFLEX_MASK = 0x8000000; // 8000000
	public static final int cACUTE_MASK = 0x10000000; // 10000000
	public static final int cCARON_MASK = 0x20000000; // 20000000
	public static final int cDIERESIS_MASK = 0x40000000; // 40000000
	public static final int FIRST_HIGH_BIT = 0x80000000; // 80000000

	public static final int V_PARAGRAPH = 0x5c; // VK_BACK_SLASH
	public static final int V_PLUS = 0x209; // VK_PLUS
	public static final int V_ACUTE = 0x81; // VK_DEAD_ACUTE
	public static final int V_CARON = 0x8a; // VK_DEAD_CARON
	public static final int V_CIRCUMFLEX = 0x82; // VK_DEAD_CIRCUMFLEX
	public static final int V_Å = 0x5d; // VK_CLOSE_BRACKET
	public static final int V_DIARAESIS = 0x87; // VK_SEMICOLON 3b / dead dieresis 87
	public static final int V_Ö = 0xc0; // VK_BACK_QUOTE
	public static final int V_Ä = 0xde; // VK_QUOTE
	public static final int V_APOSTROPHE = 0x2f; // VK_SLASH
	public static final int V_LESSER = 0x99; // VK_LESS
	public static final int V_PERIOD = 0x2e; // VK_PERIOD
	public static final int V_MINUS = 0x2d; // VK_MINUS

	public static final int V_SCROLL_UP = 0x780400;
	public static final int V_SCROLL_DN = 0xff880400;

	public static final int V_BS = 0x08; // VK_BACK_SPACE
	public static final int V_TAB = 0x09; // VK_TAB
	public static final int V_ENTER = 0x0a; // VK_ENTER
	public static final int V_LSHIFT = 0x10; // VK_SHIFT
	public static final int V_CTRL = 0x11; // VK_CONTROL
	public static final int V_ALT = 0x12; // VK_ALT
	public static final int V_PAUSE = 0x13; // VK_PAUSE
	public static final int V_CAPS = 0x14; // VK_CAPS_LOCK
	public static final int V_ESC = 0x1b; // VK_ESCAPE
	public static final int V_SPACE = 0x20; // VK_SPACE
	public static final int V_PG_UP = 0x21; // VK_PAGE_UP
	public static final int V_PG_DN = 0x22; // VK_PAGE_DOWN
	public static final int V_END = 0x23; // VK_END
	public static final int V_HOME = 0x24; // VK_HOME
	public static final int V_LEFT = 0x25; // VK_LEFT
	public static final int V_UP = 0x26; // VK_UP
	public static final int V_RIGHT = 0x27; // VK_RIGHT
	public static final int V_DOWN = 0x28; // VK_DOWN
	public static final int V_COMMA = 0x2c; // VK_COMMA
	public static final int V_INS = 0x9b; // VK_INSERT
	public static final int V_DEL = 0x7f; // VK_DELETE

	public static final int V_0 = 0x30; // VK_0
	public static final int V_1 = 0x31; // VK_1
	public static final int V_2 = 0x32; // VK_2
	public static final int V_3 = 0x33; // VK_3
	public static final int V_4 = 0x34; // VK_4
	public static final int V_5 = 0x35; // VK_5
	public static final int V_6 = 0x36; // VK_6
	public static final int V_7 = 0x37; // VK_7
	public static final int V_8 = 0x38; // VK_8
	public static final int V_9 = 0x39; // VK_9

	public static final int V_A = 0x41; // VK_A
	public static final int V_B = 0x42; // VK_B
	public static final int V_C = 0x43; // VK_C
	public static final int V_D = 0x44; // VK_D
	public static final int V_E = 0x45; // VK_E
	public static final int V_F = 0x46; // VK_F
	public static final int V_G = 0x47; // VK_G
	public static final int V_H = 0x48; // VK_H
	public static final int V_I = 0x49; // VK_I
	public static final int V_J = 0x4A; // VK_J
	public static final int V_K = 0x4B; // VK_K
	public static final int V_L = 0x4C; // VK_L
	public static final int V_M = 0x4D; // VK_M
	public static final int V_N = 0x4E; // VK_N
	public static final int V_O = 0x4F; // VK_O
	public static final int V_P = 0x50; // VK_P
	public static final int V_Q = 0x51; // VK_Q
	public static final int V_R = 0x52; // VK_R
	public static final int V_S = 0x53; // VK_S
	public static final int V_T = 0x54; // VK_T
	public static final int V_U = 0x55; // VK_U
	public static final int V_V = 0x56; // VK_V
	public static final int V_W = 0x57; // VK_W
	public static final int V_X = 0x58; // VK_X
	public static final int V_Y = 0x59; // VK_Y
	public static final int V_Z = 0x5A; // VK_Z

	public static final int V_MENU = 0x20d; // VK_CONTEXT_MENU

	public static final int V_PRTSC = 0x9a; // VK_PRINTSCREEN

	public static final int V_ALTGR = 0xff7e; // VK_ALT_GR
	public static final int V_WIN = 0x9d; // VK_META
	public static final int V_F1 = 0x70; // VK_F1
	public static final int V_F2 = 0x71; // VK_F2
	public static final int V_F3 = 0x72; // VK_F3
	public static final int V_F4 = 0x73; // VK_F4
	public static final int V_F5 = 0x74; // VK_F5
	public static final int V_F6 = 0x75; // VK_F6
	public static final int V_F7 = 0x76; // VK_F7
	public static final int V_F8 = 0x77; // VK_F8
	public static final int V_F9 = 0x78; // VK_F9
	public static final int V_F10 = 0x79; // VK_F10
	public static final int V_F11 = 0x7A; // VK_F11
	public static final int V_F12 = 0x7B; // VK_F12

	public static final int V_NUM_LOCK = 0x90; // VK_NUM_LOCK
	public static final int V_SCROLL_LOCK = 0x91; // VK_SCROLL_LOCK

//	public static final int V_VOL_UP = VK_VOLUME_UP;
//	public static final int V_VOL_DOWN = VK_VOLUME_DOWN;
//	public static final int V_VOL_MUTE = VK_VOLUME_MUTE;
//	public static final int V_NUM_PLUS = 0xe4e;
//	public static final int V_NUM_MINUS = 0xe4a;
}
