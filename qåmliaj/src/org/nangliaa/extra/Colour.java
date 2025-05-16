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

package org.nangliaa.extra;

import static java.lang.Math.min;
import static org.nangliaa.extra.Extra.batia;
import static org.nangliaa.extra.Extra.btui;
import static org.nangliaa.extra.Extra.iatba;
import static org.nangliaa.extra.Extra.uits;

import java.util.Arrays;

public class Colour {
	public static final int BACKGROUND_COLOUR = 0xffe0e0e0;
	public static final int BASE_BACKGROUND_COLOUR = 0xffeeeeee;
	public static final int SNES_TRANS = 0xff002040;

	public static final int NULL = 0x01000000;

	public static final int BLACK = 0xff000000;

	public static final int WHITE = 0xffffffff;

	public static final int RED = 0xffff0000;
	public static final int BLUE = 0xff0000ff;

	public static final int GREEN = 0xff00ff00;
	public static final int YELLOW = 0xffffff00;
	public static final int CYAN = 0xff00ffff;
	public static final int MAGENTA = 0xffffff00;
	public static final int ORANGE = 0xffff8000;
	public static final int GREY = 0xff808080;
	public static final int LIGHT_GREY = 0xffc0c0c0;
	public static final int DARK_GREY = 0xff404040;

	public static final int PINK = 0xffff80c0;
	public static final int RED_PURPLE = 0xffff0080;
	public static final int WIND = 0xffc0c080;
	public static final int BEIGE = 0xffc08040;
	public static final int LIGHT_GREEN = 0xff80ff80;
	public static final int PURPLE = 0xff800080;
	public static final int DARK_RED = 0xff800000;
	public static final int DARK_BLUE = 0xff000080;
	public static final int TRANS = 0x00000000;
	public static final int ß000000 = 0xff000000, ß000040 = 0xff000040, ß000060 = 0xff000060, ß000080 = 0xff000080;
	public static final int ß0000A0 = 0xff0000a0, ß0000C0 = 0xff0000c0, ß0000FF = 0xff0000ff;
	public static final int ß002000 = 0xff002000, ß002020 = 0xff002020, ß002040 = 0xff002040, ß002060 = 0xff002060;
	public static final int ß002080 = 0xff002080, ß0020A0 = 0xff0020a0, ß0020C0 = 0xff0020c0, ß0020FF = 0xff0020ff;
	public static final int ß004000 = 0xff004000, ß004020 = 0xff004020, ß004040 = 0xff004040, ß004060 = 0xff004060;
	public static final int ß004080 = 0xff004080, ß0040A0 = 0xff0040a0, ß0040C0 = 0xff0040c0, ß0040FF = 0xff0040ff;
	public static final int ß006000 = 0xff006000, ß006020 = 0xff006020, ß006040 = 0xff006040, ß006060 = 0xff006060;
	public static final int ß006080 = 0xff006080, ß0060A0 = 0xff0060a0, ß0060C0 = 0xff0060c0, ß0060FF = 0xff0060ff;
	public static final int ß008000 = 0xff008000, ß008020 = 0xff008020, ß008040 = 0xff008040, ß008060 = 0xff008060;
	public static final int ß008080 = 0xff008080, ß0080A0 = 0xff0080a0, ß0080C0 = 0xff0080c0, ß0080FF = 0xff0080ff;
	public static final int ß00A000 = 0xff00a000, ß00A020 = 0xff00a020, ß00A040 = 0xff00a040, ß00A060 = 0xff00a060;
	public static final int ß00A080 = 0xff00a080, ß00A0A0 = 0xff00a0a0, ß00A0C0 = 0xff00a0c0, ß00A0FF = 0xff00a0ff;
	public static final int ß00C000 = 0xff00c000, ß00C020 = 0xff00c020, ß00C040 = 0xff00c040, ß00C060 = 0xff00c060;
	public static final int ß00C080 = 0xff00c080, ß00C0A0 = 0xff00c0a0, ß00C0C0 = 0xff00c0c0, ß00C0FF = 0xff00c0ff;
	public static final int ß00FF00 = 0xff00ff00, ß00FF20 = 0xff00ff20, ß00FF40 = 0xff00ff40, ß00FF60 = 0xff00ff60;

	public static final int ß00FF80 = 0xff00ff80, ß00FFA0 = 0xff00ffa0, ß00FFC0 = 0xff00ffc0, ß00FFFF = 0xff00ffff;
	public static final int ß200000 = 0xff200000, ß200020 = 0xff200020, ß200040 = 0xff200040, ß200060 = 0xff200060;
	public static final int ß200080 = 0xff200080, ß2000A0 = 0xff2000a0, ß2000C0 = 0xff2000c0, ß2000FF = 0xff2000ff;
	public static final int ß202000 = 0xff202000, ß202020 = 0xff202020, ß202040 = 0xff202040, ß202060 = 0xff202060;
	public static final int ß202080 = 0xff202080, ß2020A0 = 0xff2020a0, ß2020C0 = 0xff2020c0, ß2020FF = 0xff2020ff;
	public static final int ß204000 = 0xff204000, ß204020 = 0xff204020, ß204040 = 0xff204040, ß204060 = 0xff204060;
	public static final int ß204080 = 0xff204080, ß2040A0 = 0xff2040a0, ß2040C0 = 0xff2040c0, ß2040FF = 0xff2040ff;
	public static final int ß206000 = 0xff206000, ß206020 = 0xff206020, ß206040 = 0xff206040, ß206060 = 0xff206060;
	public static final int ß206080 = 0xff206080, ß2060A0 = 0xff2060a0, ß2060C0 = 0xff2060c0, ß2060FF = 0xff2060ff;
	public static final int ß208000 = 0xff208000, ß208020 = 0xff208020, ß208040 = 0xff208040, ß208060 = 0xff208060;
	public static final int ß208080 = 0xff208080, ß2080A0 = 0xff2080a0, ß2080C0 = 0xff2080c0, ß2080FF = 0xff2080ff;
	public static final int ß20A000 = 0xff20a000, ß20A020 = 0xff20a020, ß20A040 = 0xff20a040, ß20A060 = 0xff20a060;
	public static final int ß20A080 = 0xff20a080, ß20A0A0 = 0xff20a0a0, ß20A0C0 = 0xff20a0c0, ß20A0FF = 0xff20a0ff;
	public static final int ß20C000 = 0xff20c000, ß20C020 = 0xff20c020, ß20C040 = 0xff20c040, ß20C060 = 0xff20c060;
	public static final int ß20C080 = 0xff20c080, ß20C0A0 = 0xff20c0a0, ß20C0C0 = 0xff20c0c0, ß20C0FF = 0xff20c0ff;
	public static final int ß20FF00 = 0xff20ff00, ß20FF20 = 0xff20ff20, ß20FF40 = 0xff20ff40, ß20FF60 = 0xff20ff60;

	public static final int ß20FF80 = 0xff20ff80, ß20FFA0 = 0xff20ffa0, ß20FFC0 = 0xff20ffc0, ß20FFFF = 0xff20ffff;
	public static final int ß400000 = 0xff400000, ß400020 = 0xff400020, ß400040 = 0xff400040, ß400060 = 0xff400060;
	public static final int ß400080 = 0xff400080, ß4000A0 = 0xff4000a0, ß4000C0 = 0xff4000c0, ß4000FF = 0xff4000ff;
	public static final int ß402000 = 0xff402000, ß402020 = 0xff402020, ß402040 = 0xff402040, ß402060 = 0xff402060;
	public static final int ß402080 = 0xff402080, ß4020A0 = 0xff4020a0, ß4020C0 = 0xff4020c0, ß4020FF = 0xff4020ff;
	public static final int ß404000 = 0xff404000, ß404020 = 0xff404020, ß404040 = 0xff404040, ß404060 = 0xff404060;
	public static final int ß404080 = 0xff404080, ß4040A0 = 0xff4040a0, ß4040C0 = 0xff4040c0, ß4040FF = 0xff4040ff;
	public static final int ß406000 = 0xff406000, ß406020 = 0xff406020, ß406040 = 0xff406040, ß406060 = 0xff406060;
	public static final int ß406080 = 0xff406080, ß4060A0 = 0xff4060a0, ß4060C0 = 0xff4060c0, ß4060FF = 0xff4060ff;
	public static final int ß408000 = 0xff408000, ß408020 = 0xff408020, ß408040 = 0xff408040, ß408060 = 0xff408060;
	public static final int ß408080 = 0xff408080, ß4080A0 = 0xff4080a0, ß4080C0 = 0xff4080c0, ß4080FF = 0xff4080ff;
	public static final int ß40A000 = 0xff40a000, ß40A020 = 0xff40a020, ß40A040 = 0xff40a040, ß40A060 = 0xff40a060;
	public static final int ß40A080 = 0xff40a080, ß40A0A0 = 0xff40a0a0, ß40A0C0 = 0xff40a0c0, ß40A0FF = 0xff40a0ff;
	public static final int ß40C000 = 0xff40c000, ß40C020 = 0xff40c020, ß40C040 = 0xff40c040, ß40C060 = 0xff40c060;
	public static final int ß40C080 = 0xff40c080, ß40C0A0 = 0xff40c0a0, ß40C0C0 = 0xff40c0c0, ß40C0FF = 0xff40c0ff;
	public static final int ß40FF00 = 0xff40ff00, ß40FF20 = 0xff40ff20, ß40FF40 = 0xff40ff40, ß40FF60 = 0xff40ff60;

	public static final int ß40FF80 = 0xff40ff80, ß40FFA0 = 0xff40ffa0, ß40FFC0 = 0xff40ffc0, ß40FFFF = 0xff40ffff;
	public static final int ß600000 = 0xff600000, ß600020 = 0xff600020, ß600040 = 0xff600040, ß600060 = 0xff600060;
	public static final int ß600080 = 0xff600080, ß6000A0 = 0xff6000a0, ß6000C0 = 0xff6000c0, ß6000FF = 0xff6000ff;
	public static final int ß602000 = 0xff602000, ß602020 = 0xff602020, ß602040 = 0xff602040, ß602060 = 0xff602060;
	public static final int ß602080 = 0xff602080, ß6020A0 = 0xff6020a0, ß6020C0 = 0xff6020c0, ß6020FF = 0xff6020ff;
	public static final int ß604000 = 0xff604000, ß604020 = 0xff604020, ß604040 = 0xff604040, ß604060 = 0xff604060;
	public static final int ß604080 = 0xff604080, ß6040A0 = 0xff6040a0, ß6040C0 = 0xff6040c0, ß6040FF = 0xff6040ff;
	public static final int ß606000 = 0xff606000, ß606020 = 0xff606020, ß606040 = 0xff606040, ß606060 = 0xff606060;
	public static final int ß606080 = 0xff606080, ß6060A0 = 0xff6060a0, ß6060C0 = 0xff6060c0, ß6060FF = 0xff6060ff;
	public static final int ß608000 = 0xff608000, ß608020 = 0xff608020, ß608040 = 0xff608040, ß608060 = 0xff608060;
	public static final int ß608080 = 0xff608080, ß6080A0 = 0xff6080a0, ß6080C0 = 0xff6080c0, ß6080FF = 0xff6080ff;
	public static final int ß60A000 = 0xff60a000, ß60A020 = 0xff60a020, ß60A040 = 0xff60a040, ß60A060 = 0xff60a060;
	public static final int ß60A080 = 0xff60a080, ß60A0A0 = 0xff60a0a0, ß60A0C0 = 0xff60a0c0, ß60A0FF = 0xff60a0ff;
	public static final int ß60C000 = 0xff60c000, ß60C020 = 0xff60c020, ß60C040 = 0xff60c040, ß60C060 = 0xff60c060;
	public static final int ß60C080 = 0xff60c080, ß60C0A0 = 0xff60c0a0, ß60C0C0 = 0xff60c0c0, ß60C0FF = 0xff60c0ff;
	public static final int ß60FF00 = 0xff60ff00, ß60FF20 = 0xff60ff20, ß60FF40 = 0xff60ff40, ß60FF60 = 0xff60ff60;

	public static final int ß60FF80 = 0xff60ff80, ß60FFA0 = 0xff60ffa0, ß60FFC0 = 0xff60ffc0, ß60FFFF = 0xff60ffff;
	public static final int ß800000 = 0xff800000, ß800020 = 0xff800020, ß800040 = 0xff800040, ß800060 = 0xff800060;
	public static final int ß800080 = 0xff800080, ß8000A0 = 0xff8000a0, ß8000C0 = 0xff8000c0, ß8000FF = 0xff8000ff;
	public static final int ß802000 = 0xff802000, ß802020 = 0xff802020, ß802040 = 0xff802040, ß802060 = 0xff802060;
	public static final int ß802080 = 0xff802080, ß8020A0 = 0xff8020a0, ß8020C0 = 0xff8020c0, ß8020FF = 0xff8020ff;
	public static final int ß804000 = 0xff804000, ß804020 = 0xff804020, ß804040 = 0xff804040, ß804060 = 0xff804060;
	public static final int ß804080 = 0xff804080, ß8040A0 = 0xff8040a0, ß8040C0 = 0xff8040c0, ß8040FF = 0xff8040ff;
	public static final int ß806000 = 0xff806000, ß806020 = 0xff806020, ß806040 = 0xff806040, ß806060 = 0xff806060;
	public static final int ß806080 = 0xff806080, ß8060A0 = 0xff8060a0, ß8060C0 = 0xff8060c0, ß8060FF = 0xff8060ff;
	public static final int ß808000 = 0xff808000, ß808020 = 0xff808020, ß808040 = 0xff808040, ß808060 = 0xff808060;
	public static final int ß808080 = 0xff808080, ß8080A0 = 0xff8080a0, ß8080C0 = 0xff8080c0, ß8080FF = 0xff8080ff;
	public static final int ß80A000 = 0xff80a000, ß80A020 = 0xff80a020, ß80A040 = 0xff80a040, ß80A060 = 0xff80a060;
	public static final int ß80A080 = 0xff80a080, ß80A0A0 = 0xff80a0a0, ß80A0C0 = 0xff80a0c0, ß80A0FF = 0xff80a0ff;
	public static final int ß80C000 = 0xff80c000, ß80C020 = 0xff80c020, ß80C040 = 0xff80c040, ß80C060 = 0xff80c060;
	public static final int ß80C080 = 0xff80c080, ß80C0A0 = 0xff80c0a0, ß80C0C0 = 0xff80c0c0, ß80C0FF = 0xff80c0ff;
	public static final int ß80FF00 = 0xff80ff00, ß80FF20 = 0xff80ff20, ß80FF40 = 0xff80ff40, ß80FF60 = 0xff80ff60;

	public static final int ß80FF80 = 0xff80ff80, ß80FFA0 = 0xff80ffa0, ß80FFC0 = 0xff80ffc0, ß80FFFF = 0xff80ffff;
	public static final int ßA00000 = 0xffa00000, ßA00020 = 0xffa00020, ßA00040 = 0xffa00040, ßA00060 = 0xffa00060;
	public static final int ßA00080 = 0xffa00080, ßA000A0 = 0xffa000a0, ßA000C0 = 0xffa000c0, ßA000FF = 0xffa000ff;
	public static final int ßA02000 = 0xffa02000, ßA02020 = 0xffa02020, ßA02040 = 0xffa02040, ßA02060 = 0xffa02060;
	public static final int ßA02080 = 0xffa02080, ßA020A0 = 0xffa020a0, ßA020C0 = 0xffa020c0, ßA020FF = 0xffa020ff;
	public static final int ßA04000 = 0xffa04000, ßA04020 = 0xffa04020, ßA04040 = 0xffa04040, ßA04060 = 0xffa04060;
	public static final int ßA04080 = 0xffa04080, ßA040A0 = 0xffa040a0, ßA040C0 = 0xffa040c0, ßA040FF = 0xffa040ff;
	public static final int ßA06000 = 0xffa06000, ßA06020 = 0xffa06020, ßA06040 = 0xffa06040, ßA06060 = 0xffa06060;
	public static final int ßA06080 = 0xffa06080, ßA060A0 = 0xffa060a0, ßA060C0 = 0xffa060c0, ßA060FF = 0xffa060ff;
	public static final int ßA08000 = 0xffa08000, ßA08020 = 0xffa08020, ßA08040 = 0xffa08040, ßA08060 = 0xffa08060;
	public static final int ßA08080 = 0xffa08080, ßA080A0 = 0xffa080a0, ßA080C0 = 0xffa080c0, ßA080FF = 0xffa080ff;
	public static final int ßA0A000 = 0xffa0a000, ßA0A020 = 0xffa0a020, ßA0A040 = 0xffa0a040, ßA0A060 = 0xffa0a060;
	public static final int ßA0A080 = 0xffa0a080, ßA0A0A0 = 0xffa0a0a0, ßA0A0C0 = 0xffa0a0c0, ßA0A0FF = 0xffa0a0ff;
	public static final int ßA0C000 = 0xffa0c000, ßA0C020 = 0xffa0c020, ßA0C040 = 0xffa0c040, ßA0C060 = 0xffa0c060;
	public static final int ßA0C080 = 0xffa0c080, ßA0C0A0 = 0xffa0c0a0, ßA0C0C0 = 0xffa0c0c0, ßA0C0FF = 0xffa0c0ff;
	public static final int ßA0FF00 = 0xffa0ff00, ßA0FF20 = 0xffa0ff20, ßA0FF40 = 0xffa0ff40, ßA0FF60 = 0xffa0ff60;

	public static final int ßA0FF80 = 0xffa0ff80, ßA0FFA0 = 0xffa0ffa0, ßA0FFC0 = 0xffa0ffc0, ßA0FFFF = 0xffa0ffff;
	public static final int ßC00000 = 0xffc00000, ßC00020 = 0xffc00020, ßC00040 = 0xffc00040, ßC00060 = 0xffc00060;
	public static final int ßC00080 = 0xffc00080, ßC000A0 = 0xffc000a0, ßC000C0 = 0xffc000c0, ßC000FF = 0xffc000ff;
	public static final int ßC02000 = 0xffc02000, ßC02020 = 0xffc02020, ßC02040 = 0xffc02040, ßC02060 = 0xffc02060;
	public static final int ßC02080 = 0xffc02080, ßC020A0 = 0xffc020a0, ßC020C0 = 0xffc020c0, ßC020FF = 0xffc020ff;
	public static final int ßC04000 = 0xffc04000, ßC04020 = 0xffc04020, ßC04040 = 0xffc04040, ßC04060 = 0xffc04060;
	public static final int ßC04080 = 0xffc04080, ßC040A0 = 0xffc040a0, ßC040C0 = 0xffc040c0, ßC040FF = 0xffc040ff;
	public static final int ßC06000 = 0xffc06000, ßC06020 = 0xffc06020, ßC06040 = 0xffc06040, ßC06060 = 0xffc06060;
	public static final int ßC06080 = 0xffc06080, ßC060A0 = 0xffc060a0, ßC060C0 = 0xffc060c0, ßC060FF = 0xffc060ff;
	public static final int ßC08000 = 0xffc08000, ßC08020 = 0xffc08020, ßC08040 = 0xffc08040, ßC08060 = 0xffc08060;
	public static final int ßC08080 = 0xffc08080, ßC080A0 = 0xffc080a0, ßC080C0 = 0xffc080c0, ßC080FF = 0xffc080ff;
	public static final int ßC0A000 = 0xffc0a000, ßC0A020 = 0xffc0a020, ßC0A040 = 0xffc0a040, ßC0A060 = 0xffc0a060;
	public static final int ßC0A080 = 0xffc0a080, ßC0A0A0 = 0xffc0a0a0, ßC0A0C0 = 0xffc0a0c0, ßC0A0FF = 0xffc0a0ff;
	public static final int ßC0C000 = 0xffc0c000, ßC0C020 = 0xffc0c020, ßC0C040 = 0xffc0c040, ßC0C060 = 0xffc0c060;
	public static final int ßC0C080 = 0xffc0c080, ßC0C0A0 = 0xffc0c0a0, ßC0C0C0 = 0xffc0c0c0, ßC0C0FF = 0xffc0c0ff;
	public static final int ßC0FF00 = 0xffc0ff00, ßC0FF20 = 0xffc0ff20, ßC0FF40 = 0xffc0ff40, ßC0FF60 = 0xffc0ff60;

	public static final int ßC0FF80 = 0xffc0ff80, ßC0FFA0 = 0xffc0ffa0, ßC0FFC0 = 0xffc0ffc0, ßC0FFFF = 0xffc0ffff;
	public static final int ßFF0000 = 0xffff0000, ßFF0020 = 0xffff0020, ßFF0040 = 0xffff0040, ßFF0060 = 0xffff0060;
	public static final int ßFF0080 = 0xffff0080, ßFF00A0 = 0xffff00a0, ßFF00C0 = 0xffff00c0, ßFF00FF = 0xffff00ff;
	public static final int ßFF2000 = 0xffff2000, ßFF2020 = 0xffff2020, ßFF2040 = 0xffff2040, ßFF2060 = 0xffff2060;
	public static final int ßFF2080 = 0xffff2080, ßFF20A0 = 0xffff20a0, ßFF20C0 = 0xffff20c0, ßFF20FF = 0xffff20ff;
	public static final int ßFF4000 = 0xffff4000, ßFF4020 = 0xffff4020, ßFF4040 = 0xffff4040, ßFF4060 = 0xffff4060;
	public static final int ßFF4080 = 0xffff4080, ßFF40A0 = 0xffff40a0, ßFF40C0 = 0xffff40c0, ßFF40FF = 0xffff40ff;
	public static final int ßFF6000 = 0xffff6000, ßFF6020 = 0xffff6020, ßFF6040 = 0xffff6040, ßFF6060 = 0xffff6060;
	public static final int ßFF6080 = 0xffff6080, ßFF60A0 = 0xffff60a0, ßFF60C0 = 0xffff60c0, ßFF60FF = 0xffff60ff;
	public static final int ßFF8000 = 0xffff8000, ßFF8020 = 0xffff8020, ßFF8040 = 0xffff8040, ßFF8060 = 0xffff8060;
	public static final int ßFF8080 = 0xffff8080, ßFF80A0 = 0xffff80a0, ßFF80C0 = 0xffff80c0, ßFF80FF = 0xffff80ff;
	public static final int ßFFA000 = 0xffffa000, ßFFA020 = 0xffffa020, ßFFA040 = 0xffffa040, ßFFA060 = 0xffffa060;
	public static final int ßFFA080 = 0xffffa080, ßFFA0A0 = 0xffffa0a0, ßFFA0C0 = 0xffffa0c0, ßFFA0FF = 0xffffa0ff;
	public static final int ßFFC000 = 0xffffc000, ßFFC020 = 0xffffc020, ßFFC040 = 0xffffc040, ßFFC060 = 0xffffc060;
	public static final int ßFFC080 = 0xffffc080, ßFFC0A0 = 0xffffc0a0, ßFFC0C0 = 0xffffc0c0, ßFFC0FF = 0xffffc0ff;
	public static final int ßFFFF00 = 0xffffff00, ßFFFF20 = 0xffffff20, ßFFFF40 = 0xffffff40, ßFFFF60 = 0xffffff60;

	public static final int ßFFFF80 = 0xffffff80, ßFFFFA0 = 0xffffffa0, ßFFFFC0 = 0xffffffc0, ßFFFFFF = 0xffffffff;
	/**
	 * Already sorted.
	 */

	public static final int[] BASIC_PALETTE = {
			ß000000, ß000080, ß0000FF, ß008000, ß00FF00, ß200000, ß402000, ß604000, ß806000, ß8080FF, ß80FF80, ßA08000, ßC0A000, ßFFC000, ßFFFFFF, TRANS
	};
	/**
	 * 256 COLOURS, less blue
	 */

	public static final int[] SNES_PALETTE = {
			0xff000000, 0xff000040, 0xff000080, 0xff0000ff, 0xff002000, /* 0xff002040, */0xff002080, 0xff0020ff, 0xff004000, 0xff004040, 0xff004080, 0xff0040ff, 0xff006000, 0xff006040, 0xff006080, 0xff0060ff,
			0xff008000, 0xff008040, 0xff008080, 0xff0080ff, 0xff00a000, 0xff00a040, 0xff00a080, 0xff00a0ff, 0xff00c000, 0xff00c040, 0xff00c080, 0xff00c0ff, 0xff00ff00, 0xff00ff40, 0xff00ff80, 0xff00ffff,
			0xff200000, 0xff200040, 0xff200080, 0xff2000ff, 0xff202000, 0xff202040, 0xff202080, 0xff2020ff, 0xff204000, 0xff204040, 0xff204080, 0xff2040ff, 0xff206000, 0xff206040, 0xff206080, 0xff2060ff,
			0xff208000, 0xff208040, 0xff208080, 0xff2080ff, 0xff20a000, 0xff20a040, 0xff20a080, 0xff20a0ff, 0xff20c000, 0xff20c040, 0xff20c080, 0xff20c0ff, 0xff20ff00, 0xff20ff40, 0xff20ff80, 0xff20ffff,
			0xff400000, 0xff400040, 0xff400080, 0xff4000ff, 0xff402000, 0xff402040, 0xff402080, 0xff4020ff, 0xff404000, 0xff404040, 0xff404080, 0xff4040ff, 0xff406000, 0xff406040, 0xff406080, 0xff4060ff,
			0xff408000, 0xff408040, 0xff408080, 0xff4080ff, 0xff40a000, 0xff40a040, 0xff40a080, 0xff40a0ff, 0xff40c000, 0xff40c040, 0xff40c080, 0xff40c0ff, 0xff40ff00, 0xff40ff40, 0xff40ff80, 0xff40ffff,
			0xff600000, 0xff600040, 0xff600080, 0xff6000ff, 0xff602000, 0xff602040, 0xff602080, 0xff6020ff, 0xff604000, 0xff604040, 0xff604080, 0xff6040ff, 0xff606000, 0xff606040, 0xff606080, 0xff6060ff,
			0xff608000, 0xff608040, 0xff608080, 0xff6080ff, 0xff60a000, 0xff60a040, 0xff60a080, 0xff60a0ff, 0xff60c000, 0xff60c040, 0xff60c080, 0xff60c0ff, 0xff60ff00, 0xff60ff40, 0xff60ff80, 0xff60ffff,
			0xff800000, 0xff800040, 0xff800080, 0xff8000ff, 0xff802000, 0xff802040, 0xff802080, 0xff8020ff, 0xff804000, 0xff804040, 0xff804080, 0xff8040ff, 0xff806000, 0xff806040, 0xff806080, 0xff8060ff,
			0xff808000, 0xff808040, 0xff808080, 0xff8080ff, 0xff80a000, 0xff80a040, 0xff80a080, 0xff80a0ff, 0xff80c000, 0xff80c040, 0xff80c080, 0xff80c0ff, 0xff80ff00, 0xff80ff40, 0xff80ff80, 0xff80ffff,
			0xffa00000, 0xffa00040, 0xffa00080, 0xffa000ff, 0xffa02000, 0xffa02040, 0xffa02080, 0xffa020ff, 0xffa04000, 0xffa04040, 0xffa04080, 0xffa040ff, 0xffa06000, 0xffa06040, 0xffa06080, 0xffa060ff,
			0xffa08000, 0xffa08040, 0xffa08080, 0xffa080ff, 0xffa0a000, 0xffa0a040, 0xffa0a080, 0xffa0a0ff, 0xffa0c000, 0xffa0c040, 0xffa0c080, 0xffa0c0ff, 0xffa0ff00, 0xffa0ff40, 0xffa0ff80, 0xffa0ffff,
			0xffc00000, 0xffc00040, 0xffc00080, 0xffc000ff, 0xffc02000, 0xffc02040, 0xffc02080, 0xffc020ff, 0xffc04000, 0xffc04040, 0xffc04080, 0xffc040ff, 0xffc06000, 0xffc06040, 0xffc06080, 0xffc060ff,
			0xffc08000, 0xffc08040, 0xffc08080, 0xffc080ff, 0xffc0a000, 0xffc0a040, 0xffc0a080, 0xffc0a0ff, 0xffc0c000, 0xffc0c040, 0xffc0c080, 0xffc0c0ff, 0xffc0ff00, 0xffc0ff40, 0xffc0ff80, 0xffc0ffff,
			0xffff0000, 0xffff0040, 0xffff0080, 0xffff00ff, 0xffff2000, 0xffff2040, 0xffff2080, 0xffff20ff, 0xffff4000, 0xffff4040, 0xffff4080, 0xffff40ff, 0xffff6000, 0xffff6040, 0xffff6080, 0xffff60ff,
			0xffff8000, 0xffff8040, 0xffff8080, 0xffff80ff, 0xffffa000, 0xffffa040, 0xffffa080, 0xffffa0ff, 0xffffc000, 0xffffc040, 0xffffc080, 0xffffc0ff, 0xffffff00, 0xffffff40, 0xffffff80, 0xffffffff,

			TRANS
	};
	public static final int[] PALETTE_9 = {
			ß000000, ß000040, ß000060, ß000080, ß0000A0, ß0000C0, ß0000FF, ß002000, ß002020, ß002040, ß002060, ß002080, ß0020A0, ß0020C0, ß0020FF, ß004000, ß004020, ß004040, ß004060, ß004080, ß0040A0, ß0040C0,
			ß0040FF, ß006000, ß006020, ß006040, ß006060, ß006080, ß0060A0, ß0060C0, ß0060FF, ß008000, ß008020, ß008040, ß008060, ß008080, ß0080A0, ß0080C0, ß0080FF, ß00A000, ß00A020, ß00A040, ß00A060, ß00A080,
			ß00A0A0, ß00A0C0, ß00A0FF, ß00C000, ß00C020, ß00C040, ß00C060, ß00C080, ß00C0A0, ß00C0C0, ß00C0FF, ß00FF00, ß00FF20, ß00FF40, ß00FF60, ß00FF80, ß00FFA0, ß00FFC0, ß00FFFF,

			ß200000, ß200020, ß200040, ß200060, ß200080, ß2000A0, ß2000C0, ß2000FF, ß202000, ß202020, ß202040, ß202060, ß202080, ß2020A0, ß2020C0, ß2020FF, ß204000, ß204020, ß204040, ß204060, ß204080, ß2040A0,
			ß2040C0, ß2040FF, ß206000, ß206020, ß206040, ß206060, ß206080, ß2060A0, ß2060C0, ß2060FF, ß208000, ß208020, ß208040, ß208060, ß208080, ß2080A0, ß2080C0, ß2080FF, ß20A000, ß20A020, ß20A040, ß20A060,
			ß20A080, ß20A0A0, ß20A0C0, ß20A0FF, ß20C000, ß20C020, ß20C040, ß20C060, ß20C080, ß20C0A0, ß20C0C0, ß20C0FF, ß20FF00, ß20FF20, ß20FF40, ß20FF60, ß20FF80, ß20FFA0, ß20FFC0, ß20FFFF,

			ß400000, ß400020, ß400040, ß400060, ß400080, ß4000A0, ß4000C0, ß4000FF, ß402000, ß402020, ß402040, ß402060, ß402080, ß4020A0, ß4020C0, ß4020FF, ß404000, ß404020, ß404040, ß404060, ß404080, ß4040A0,
			ß4040C0, ß4040FF, ß406000, ß406020, ß406040, ß406060, ß406080, ß4060A0, ß4060C0, ß4060FF, ß408000, ß408020, ß408040, ß408060, ß408080, ß4080A0, ß4080C0, ß4080FF, ß40A000, ß40A020, ß40A040, ß40A060,
			ß40A080, ß40A0A0, ß40A0C0, ß40A0FF, ß40C000, ß40C020, ß40C040, ß40C060, ß40C080, ß40C0A0, ß40C0C0, ß40C0FF, ß40FF00, ß40FF20, ß40FF40, ß40FF60, ß40FF80, ß40FFA0, ß40FFC0, ß40FFFF,

			ß600000, ß600020, ß600040, ß600060, ß600080, ß6000A0, ß6000C0, ß6000FF, ß602000, ß602020, ß602040, ß602060, ß602080, ß6020A0, ß6020C0, ß6020FF, ß604000, ß604020, ß604040, ß604060, ß604080, ß6040A0,
			ß6040C0, ß6040FF, ß606000, ß606020, ß606040, ß606060, ß606080, ß6060A0, ß6060C0, ß6060FF, ß608000, ß608020, ß608040, ß608060, ß608080, ß6080A0, ß6080C0, ß6080FF, ß60A000, ß60A020, ß60A040, ß60A060,
			ß60A080, ß60A0A0, ß60A0C0, ß60A0FF, ß60C000, ß60C020, ß60C040, ß60C060, ß60C080, ß60C0A0, ß60C0C0, ß60C0FF, ß60FF00, ß60FF20, ß60FF40, ß60FF60, ß60FF80, ß60FFA0, ß60FFC0, ß60FFFF,

			ß800000, ß800020, ß800040, ß800060, ß800080, ß8000A0, ß8000C0, ß8000FF, ß802000, ß802020, ß802040, ß802060, ß802080, ß8020A0, ß8020C0, ß8020FF, ß804000, ß804020, ß804040, ß804060, ß804080, ß8040A0,
			ß8040C0, ß8040FF, ß806000, ß806020, ß806040, ß806060, ß806080, ß8060A0, ß8060C0, ß8060FF, ß808000, ß808020, ß808040, ß808060, ß808080, ß8080A0, ß8080C0, ß8080FF, ß80A000, ß80A020, ß80A040, ß80A060,
			ß80A080, ß80A0A0, ß80A0C0, ß80A0FF, ß80C000, ß80C020, ß80C040, ß80C060, ß80C080, ß80C0A0, ß80C0C0, ß80C0FF, ß80FF00, ß80FF20, ß80FF40, ß80FF60, ß80FF80, ß80FFA0, ß80FFC0, ß80FFFF,

			ßA00000, ßA00020, ßA00040, ßA00060, ßA00080, ßA000A0, ßA000C0, ßA000FF, ßA02000, ßA02020, ßA02040, ßA02060, ßA02080, ßA020A0, ßA020C0, ßA020FF, ßA04000, ßA04020, ßA04040, ßA04060, ßA04080, ßA040A0,
			ßA040C0, ßA040FF, ßA06000, ßA06020, ßA06040, ßA06060, ßA06080, ßA060A0, ßA060C0, ßA060FF, ßA08000, ßA08020, ßA08040, ßA08060, ßA08080, ßA080A0, ßA080C0, ßA080FF, ßA0A000, ßA0A020, ßA0A040, ßA0A060,
			ßA0A080, ßA0A0A0, ßA0A0C0, ßA0A0FF, ßA0C000, ßA0C020, ßA0C040, ßA0C060, ßA0C080, ßA0C0A0, ßA0C0C0, ßA0C0FF, ßA0FF00, ßA0FF20, ßA0FF40, ßA0FF60, ßA0FF80, ßA0FFA0, ßA0FFC0, ßA0FFFF,

			ßC00000, ßC00020, ßC00040, ßC00060, ßC00080, ßC000A0, ßC000C0, ßC000FF, ßC02000, ßC02020, ßC02040, ßC02060, ßC02080, ßC020A0, ßC020C0, ßC020FF, ßC04000, ßC04020, ßC04040, ßC04060, ßC04080, ßC040A0,
			ßC040C0, ßC040FF, ßC06000, ßC06020, ßC06040, ßC06060, ßC06080, ßC060A0, ßC060C0, ßC060FF, ßC08000, ßC08020, ßC08040, ßC08060, ßC08080, ßC080A0, ßC080C0, ßC080FF, ßC0A000, ßC0A020, ßC0A040, ßC0A060,
			ßC0A080, ßC0A0A0, ßC0A0C0, ßC0A0FF, ßC0C000, ßC0C020, ßC0C040, ßC0C060, ßC0C080, ßC0C0A0, ßC0C0C0, ßC0C0FF, ßC0FF00, ßC0FF20, ßC0FF40, ßC0FF60, ßC0FF80, ßC0FFA0, ßC0FFC0, ßC0FFFF,

			ßFF0000, ßFF0020, ßFF0040, ßFF0060, ßFF0080, ßFF00A0, ßFF00C0, ßFF00FF, ßFF2000, ßFF2020, ßFF2040, ßFF2060, ßFF2080, ßFF20A0, ßFF20C0, ßFF20FF, ßFF4000, ßFF4020, ßFF4040, ßFF4060, ßFF4080, ßFF40A0,
			ßFF40C0, ßFF40FF, ßFF6000, ßFF6020, ßFF6040, ßFF6060, ßFF6080, ßFF60A0, ßFF60C0, ßFF60FF, ßFF8000, ßFF8020, ßFF8040, ßFF8060, ßFF8080, ßFF80A0, ßFF80C0, ßFF80FF, ßFFA000, ßFFA020, ßFFA040, ßFFA060,
			ßFFA080, ßFFA0A0, ßFFA0C0, ßFFA0FF, ßFFC000, ßFFC020, ßFFC040, ßFFC060, ßFFC080, ßFFC0A0, ßFFC0C0, ßFFC0FF, ßFFFF00, ßFFFF20, ßFFFF40, ßFFFF60, ßFFFF80, ßFFFFA0, ßFFFFC0, ßFFFFFF,

			TRANS
	};
	static int[] al = {
			0xff000000, 0xff200000, 0xff400000, 0xff600000, 0xff800000, 0xffa00000, 0xffc00000, 0xffff0000, 0xffff2000, 0xffc02000, 0xffa02000, 0xff802000, 0xff602000, 0xff402000, 0xff202000, 0xff002000,
			0xff004000, 0xff204000, 0xff404000, 0xff604000, 0xff804000, 0xffa04000, 0xffc04000, 0xffff4000, 0xffff6000, 0xffc06000, 0xffa06000, 0xff806000, 0xff606000, 0xff406000, 0xff206000, 0xff006000,
			0xff008000, 0xff208000, 0xff408000, 0xff608000, 0xff808000, 0xffa08000, 0xffc08000, 0xffff8000, 0xffffa000, 0xffc0a000, 0xffa0a000, 0xff80a000, 0xff60a000, 0xff40a000, 0xff20a000, 0xff00a000,
			0xff00c000, 0xff20c000, 0xff40c000, 0xff60c000, 0xff80c000, 0xffa0c000, 0xffc0c000, 0xffffc000, 0xffffff00, 0xffc0ff00, 0xffa0ff00, 0xff80ff00, 0xff60ff00, 0xff40ff00, 0xff20ff00, 0xff00ff00,

			0xff000040, 0xff200040, 0xff400040, 0xff600040, 0xff800040, 0xffa00040, 0xffc00040, 0xffff0040, 0xffff2040, 0xffc02040, 0xffa02040, 0xff802040, 0xff602040, 0xff402040, 0xff202040, 0xff002040,
			0xff004040, 0xff204040, 0xff404040, 0xff604040, 0xff804040, 0xffa04040, 0xffc04040, 0xffff4040, 0xffff6040, 0xffc06040, 0xffa06040, 0xff806040, 0xff606040, 0xff406040, 0xff206040, 0xff006040,
			0xff008040, 0xff208040, 0xff408040, 0xff608040, 0xff808040, 0xffa08040, 0xffc08040, 0xffff8040, 0xffffa040, 0xffc0a040, 0xffa0a040, 0xff80a040, 0xff60a040, 0xff40a040, 0xff20a040, 0xff00a040,
			0xff00c040, 0xff20c040, 0xff40c040, 0xff60c040, 0xff80c040, 0xffa0c040, 0xffc0c040, 0xffffc040, 0xffffff40, 0xffc0ff40, 0xffa0ff40, 0xff80ff40, 0xff60ff40, 0xff40ff40, 0xff20ff40, 0xff00ff40,

			0xff000080, 0xff200080, 0xff400080, 0xff600080, 0xff800080, 0xffa00080, 0xffc00080, 0xffff0080, 0xffff2080, 0xffc02080, 0xffa02080, 0xff802080, 0xff602080, 0xff402080, 0xff202080, 0xff002080,
			0xff004080, 0xff204080, 0xff404080, 0xff604080, 0xff804080, 0xffa04080, 0xffc04080, 0xffff4080, 0xffff6080, 0xffc06080, 0xffa06080, 0xff806080, 0xff606080, 0xff406080, 0xff206080, 0xff006080,
			0xff008080, 0xff208080, 0xff408080, 0xff608080, 0xff808080, 0xffa08080, 0xffc08080, 0xffff8080, 0xffffa080, 0xffc0a080, 0xffa0a080, 0xff80a080, 0xff60a080, 0xff40a080, 0xff20a080, 0xff00a080,
			0xff00c080, 0xff20c080, 0xff40c080, 0xff60c080, 0xff80c080, 0xffa0c080, 0xffc0c080, 0xffffc080, 0xffffff80, 0xffc0ff80, 0xffa0ff80, 0xff80ff80, 0xff60ff80, 0xff40ff80, 0xff20ff80, 0xff00ff80,

			0xff0000ff, 0xff2000ff, 0xff4000ff, 0xff6000ff, 0xff8000ff, 0xffa000ff, 0xffc000ff, 0xffff00ff, 0xffff20ff, 0xffc020ff, 0xffa020ff, 0xff8020ff, 0xff6020ff, 0xff4020ff, 0xff2020ff, 0xff0020ff,
			0xff0040ff, 0xff2040ff, 0xff4040ff, 0xff6040ff, 0xff8040ff, 0xffa040ff, 0xffc040ff, 0xffff40ff, 0xffff60ff, 0xffc060ff, 0xffa060ff, 0xff8060ff, 0xff6060ff, 0xff4060ff, 0xff2060ff, 0xff0060ff,
			0xff0080ff, 0xff2080ff, 0xff4080ff, 0xff6080ff, 0xff8080ff, 0xffa080ff, 0xffc080ff, 0xffff80ff, 0xffffa0ff, 0xffc0a0ff, 0xffa0a0ff, 0xff80a0ff, 0xff60a0ff, 0xff40a0ff, 0xff20a0ff, 0xff00a0ff,
			0xff00c0ff, 0xff20c0ff, 0xff40c0ff, 0xff60c0ff, 0xff80c0ff, 0xffa0c0ff, 0xffc0c0ff, 0xffffc0ff, 0xffffffff, 0xffc0ffff, 0xffa0ffff, 0xff80ffff, 0xff60ffff, 0xff40ffff, 0xff20ffff, 0xff00ffff,
	};
	public static final int[] NO_PALETTE = {};

	/*
	 * TRANS, ß008000, ß00FF00, ß80FF80, WHITE, ß000080, ß0000FF, ß8080FF, ß000000, ß200000, ß402000, ß604000, ß806000, ßA08000, ßC0A000, ßFFC000,
	 */
	public static int blueMinus (final int rgb) {
		switch (rgb & 0xff) {
			case 0x40:
			case 0x80:
				return rgb - 0x40;
			case 0xff:
				return rgb - 0x7f;
			default:
				return rgb;
		}
	}

	public static int bluePlus (final int rgb) {
		switch (rgb & 0xff) {
			case 0x00:
			case 0x40:
				return rgb + 0x40;
			case 0x80:
				return rgb + 0x7f;
			default:
				return rgb;
		}
	}

	public static String getARGB (final int argb) {
		return uits(argb, 8, 16);
	}

	public static int[] getDefaultBackgroundColours () {
		return new int[] {
				BASE_BACKGROUND_COLOUR, BLACK, BLACK, ORANGE
		};
	}

	public static int[] getDefaultColours () {
		return new int[] {
				WHITE, BLACK, BLACK, ORANGE
		};
	}

	public static int[] getFrom (final int frameTextColour) {
		if (frameTextColour != NULL) return new int[] {
				NULL, frameTextColour, frameTextColour, NULL
		};
		return new int[] {
				NULL, NULL, NULL, NULL
		};
	}

	public static int[] getFrom (final int backgroundColour, final int frameTextColour) {
		return new int[] {
				backgroundColour, frameTextColour, frameTextColour, NULL
		};
	}

	public static int[] getFrom (final int backgroundColour, final int frameColour, final int textColour) {
		return new int[] {
				backgroundColour, frameColour, textColour, NULL
		};
	}

	public static int greenMinus (final int rgb) {
		switch (rgb & 0x00ff00) {
			case 0x2000:
			case 0x4000:
			case 0x6000:
			case 0x8000:
			case 0xa000:
			case 0xc000:
				return rgb - 0x2000;
			case 0xff00:
				return rgb - 0x3f00;
			default:
				return rgb;
		}
	}

	public static int greenPlus (final int rgb) {
		switch (rgb & 0x00ff00) {
			case 0x0000:
			case 0x2000:
			case 0x4000:
			case 0x6000:
			case 0x8000:
			case 0xa000:
				return rgb + 0x2000;
			case 0xc000:
				return rgb + 0x3f00;
			default:
				return rgb;
		}
	}

	private static int interpolateColor (final int cTL, final int cTR, final int cBL, final int cBR, final float dx, final float dy) {
		final float top = cTL + dx * (cTR - cTL);
		final float bottom = cBL + dx * (cBR - cBL);

		return Math.round(top + dy * (bottom - top));
	}

	public static boolean isDarkColour (final int c) {
		return (c >> 16 & 0xff) < 0xa0 && (c >> 8 & 0xff) < 0xa0;
	}

	public static byte[] paletteColourToIndex (final int[] farray, final int[] palette) {
		if (palette == NO_PALETTE) return iatba(farray);
		if (palette.length == 256) {
			final byte[] narray = new byte[farray.length];
			for (int i = 0; i < narray.length; i++)
				narray[i] = (byte) Arrays.binarySearch(palette, farray[i]);
			return narray;
		}
		if (palette.length == 16) {
			final byte[] narray = new byte[farray.length + 1 >>> 1];
			for (int i = 0; i < narray.length; i++)
				narray[i] = (byte) (Arrays.binarySearch(palette, farray[i * 2]) << 4 | Arrays.binarySearch(palette, farray[i * 2 + 1]));
			return narray;
		}
		return null;
	}

	public static int[] paletteIndexToColour (final byte[] farray, final int[] palette) {
		if (palette == NO_PALETTE) return batia(farray);
		if (palette.length == 256) {
			final int[] narray = new int[farray.length]; // 8 bits per pixel
			for (int i = 0; i < farray.length; i++)
				narray[i] = palette[btui(farray[i])];
			return narray;
		}
		if (palette.length == 16) {
			final int[] narray = new int[farray.length << 1]; // 4 bits per pixel
			for (int i = 0; i < farray.length; i++) {
				narray[i * 2] = palette[farray[i] >>> 4 & 0xf];
				narray[i * 2 + 1] = palette[farray[i] & 0xf];
			}
			return narray;
		}
		return null;
	}

	/*
	 * public static void main (String[] args) { System.out.println(al.length); printInts(SNES_PALETTE); int[] old = Arrays.copyOf(SNES_PALETTE, SNES_PALETTE.length); Arrays.sort(SNES_PALETTE);
	 * printInts(SNES_PALETTE); System.out.println(Arrays.compare(old, SNES_PALETTE) + " " + SNES_PALETTE.length); }
	 */

	public static int redMinus (final int rgb) {
		switch (rgb & 0xff0000) {
			case 0x200000:
			case 0x400000:
			case 0x600000:
			case 0x800000:
			case 0xa00000:
			case 0xc00000:
				return rgb - 0x200000;
			case 0xff0000:
				return rgb - 0x3f0000;
			default:
				return rgb;
		}
	}

	public static int redPlus (final int rgb) {
		switch (rgb & 0xff0000) {
			case 0x000000:
			case 0x200000:
			case 0x400000:
			case 0x600000:
			case 0x800000:
			case 0xa00000:
				return rgb + 0x200000;
			case 0xc00000:
				return rgb + 0x3f0000;
			default:
				return rgb;
		}
	}

	public static int[] resizeImageBilinear (final int[] pixels, final int imgWidþ, final int newWidþ) {
		final int[] resizedPixels = new int[newWidþ * newWidþ];
		if (pixels.length == 0) return resizedPixels;

		for (int y = 0; y < newWidþ; y++)
			for (int x = 0; x < newWidþ; x++) {
				final float gx = (float) x / newWidþ * (imgWidþ - 1);
				final float gy = (float) y / newWidþ * (pixels.length / imgWidþ - 1);

				final int gxi = (int) gx;
				final int gyi = (int) gy;

				final float dx = gx - gxi;
				final float dy = gy - gyi;

				final int pixelTL = pixels[gyi * imgWidþ + gxi]; // Top-Left
				final int pixelTR = pixels[gyi * imgWidþ + min(gxi + 1, imgWidþ - 1)]; // Top-Right
				final int pixelBL = pixels[min(gyi + 1, pixels.length / imgWidþ - 1) * imgWidþ + gxi]; // Bottom-Left
				final int pixelBR = pixels[min(gyi + 1, pixels.length / imgWidþ - 1) * imgWidþ + min(gxi + 1, imgWidþ - 1)]; // Bottom-Right

				final int a = interpolateColor(pixelTL >> 24 & 0xFF, pixelTR >> 24 & 0xFF, pixelBL >> 24 & 0xFF, pixelBR >> 24 & 0xFF, dx, dy);
				final int r = interpolateColor(pixelTL >> 16 & 0xFF, pixelTR >> 16 & 0xFF, pixelBL >> 16 & 0xFF, pixelBR >> 16 & 0xFF, dx, dy);
				final int g = interpolateColor(pixelTL >> 8 & 0xFF, pixelTR >> 8 & 0xFF, pixelBL >> 8 & 0xFF, pixelBR >> 8 & 0xFF, dx, dy);
				final int b = interpolateColor(pixelTL & 0xFF, pixelTR & 0xFF, pixelBL & 0xFF, pixelBR & 0xFF, dx, dy);

				resizedPixels[y * newWidþ + x] = a << 24 | r << 16 | g << 8 | b;
			}
		return resizedPixels;
	}
}