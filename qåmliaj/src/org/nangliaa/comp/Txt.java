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

package org.nangliaa.comp;

import static org.nangliaa.extra.Codes.CTRL_MASK;
import static org.nangliaa.extra.Codes.V_DEL;
import static org.nangliaa.extra.Codes.V_DOWN;
import static org.nangliaa.extra.Codes.V_LEFT;
import static org.nangliaa.extra.Codes.V_RIGHT;
import static org.nangliaa.extra.Codes.V_UP;
import static org.nangliaa.extra.Codes.V_V;
import static org.nangliaa.extra.Colour.NULL;
import static org.nangliaa.extra.Colour.getFrom;
import static org.nangliaa.extra.Extra.EMPTY_STRING;
import static org.nangliaa.extra.Extra.FONT_HEIGHT;
import static org.nangliaa.extra.Extra.FONT_WIDÞ;
import static org.nangliaa.extra.Extra.MAX_FONT_HEIGHT;

import java.util.ArrayList;

import org.nangliaa.desktop.Special;
import org.nangliaa.extra.Extra;
import org.nangliaa.extra.Img;
import org.nangliaa.extra.Point;

public class Txt extends Comp {
	int markerX, markerY, markerI, maxSize = 12;
	boolean markerShown, area;
	ArrayList<String> splitStrings = new ArrayList<>();

	public Txt (int noOfSubs, int width, int height, int round, int frames, int[] colours) {
		super(new Object[noOfSubs], new int[noOfSubs], new int[noOfSubs], width, height, round, frames, colours);
	}

	/**
	 * TextArea
	 *
	 * @param width   Row max size
	 * @param height
	 * @param round
	 * @param frames
	 * @param colours
	 */

	public Txt (int width, int height, int round, int frames, int[] colours) {
		super(new Object[] {
				""
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				MAX_FONT_HEIGHT
		}, (width + 2) * FONT_WIDÞ, height, round, frames, colours);
		maxSize = width;
		area = true;
	}

	/**
	 * Creates a simple Txt with standardised width and height.
	 *
	 * @param sub
	 * @param maxSize The width (text width + 2)
	 * @param height  The height (text height * 2 + 1)
	 */

	public Txt (String sub, int maxSize, int height, int round, int frames) {
		super(new Object[] {
				sub
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				FONT_HEIGHT
		}, (maxSize + 3) * FONT_WIDÞ, (height * 2 + 1) * FONT_HEIGHT, round, frames, getFrom(NULL));
	}

	public Txt (String sub, int width, int height, int round, int frames, int[] colours) {
		super(new Object[] {
				sub
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				FONT_HEIGHT
		}, width, height, round, frames, colours);
	}

	/**
	 * Labelled Text
	 *
	 * @param initString
	 * @param desc
	 * @param width
	 * @param height
	 * @param round
	 * @param frames
	 * @param colours
	 */

	public Txt (String initString, String desc, int width, int height, int round, int frames, int[] colours) {
		super(new Object[2], new int[2], new int[2], (width + 2) * FONT_WIDÞ, (height * 2 + 1) * FONT_HEIGHT, round, frames, colours);
		maxSize = width - desc.length();
		subText[0] = initString;
		subText[1] = desc;
		xsub[0] = (desc.length() + 1) * FONT_WIDÞ;
		xsub[1] = FONT_WIDÞ;
		ysub[0] = FONT_HEIGHT;
		ysub[1] = FONT_HEIGHT;
	}

	private void addText (String s) {
		String text1 = getText(0).substring(0, markerI);
		String text2 = getText(0).substring(markerI, getText(0).length());
		s.replaceAll("\r\n", "\n");
		s.replaceAll("\r", "\n");
		if (getText(0).length() < maxSize || area || maxSize < 0) subText[0] = text1 + s + text2;
		stringSplit();
		for (int i = 0; i < s.length(); i++)
			markRight(true);
	}

	@Override
	public void deselect () {
		markerShown = false;
	}

	@Override
	public void drawComp (Img g, int x, int y) {
		if (!area) super.drawComp(g, x, y, true, true);
		else {
			super.drawComp(g, x, y, false, true);
			int j = 0;
			for (String c : splitStrings)
				g.drawString(c, x + xsub[0], y + ysub[0] + j++ * MAX_FONT_HEIGHT, textColour);
		}
		if (markerShown) {
			int x12 = x + xsub[0] + markerX * FONT_WIDÞ;
			int y12 = y + ysub[0] + markerY * MAX_FONT_HEIGHT;
			g.drawLine(x12, y12 - 6, x12, y12 + 12, textColour);
		}
	}

	private void markDown () {
		if (markerY == splitStrings.size() - 1) {
			markerI = getText(0).length();
			markerX = splitStrings.get(markerY).length();
			return;
		}
		int len = splitStrings.get(markerY + 1).length() - 1;
		if (len < markerX) {
			markerI += splitStrings.get(markerY).length() - (markerX - len);
			markerY++;
			markerX = len;
			if (markerY == splitStrings.size() - 1) {
				markerI++;
				markerX++;
			}
		} else {
			markerI += splitStrings.get(markerY).length();
			markerY++;
		}
	}

	private void markLeft (boolean remove) {
		if (markerX == 0) {
			if (markerY != 0) {
				int len = splitStrings.get(markerY - 1).length();
				markerX = len != 0 && !remove ? len - 1 : len;
				markerY--;
				markerI--;
			}
		} else {
			markerX--;
			markerI--;
		}
	}

	private void markRight (boolean add) {
		int len = splitStrings.get(markerY).length();
		if (area && markerX == len - 1 && (len == maxSize || markerY != splitStrings.size() - 1)) {
			if (markerY != splitStrings.size() - 1 || add) {
				markerX = 0;
				markerY++;
				markerI++;
			}
		} else if ((markerI != getText(0).length() || add) && markerX != maxSize) {
			markerX++;
			markerI++;
		}
	}

	private void markUp () {
		if (markerY == 0) {
			markerI = 0;
			markerX = 0;
			return;
		}
		int len = splitStrings.get(markerY - 1).length() - 1;
		if (len < markerX) {
			markerY--;
			markerI -= markerX + 1;
			markerX = len;
		} else {
			markerY--;
			markerI -= len + 1;
		}
	}

	@Override
	public void onMarked () {

	}

	public void resetText () {
		markerX = 0;
		subText[0] = EMPTY_STRING;
	}

	@Override
	public void select (int config, Point mp) {
		layout.activeComp = this;
		layout.markedBox = 0;
		markerShown = true;
	}

	@Override
	public void sendChar (char c) {
		String text1 = getText(0).substring(0, markerI);
		String text2 = getText(0).substring(markerI, getText(0).length());
		if (c == '') subText[0] = Extra.pop(text1) + text2;
		else if (c == '\r') subText[0] = text1 + '\n' + text2;
		else if (getText(0).length() < maxSize || area || maxSize < 0) subText[0] = text1 + c + text2;

		stringSplit();
		if (c == '\b') markLeft(true);
		else markRight(true);
	}

	@Override
	public void sendKey (int config, int keyCode) {
		switch (config) {
			case CTRL_MASK:
				switch (keyCode) {
					case V_V:
						if (Special.isClipboardString()) addText(Special.getClipboardString());
						break;
				}
				break;
			case 0:
				switch (keyCode) {
					case V_LEFT:
						markLeft(false);
						break;
					case V_RIGHT:
						markRight(false);
						break;
					case V_UP:
						markUp();
						break;
					case V_DOWN:
						markDown();
						break;
					case V_DEL:
						subText[0] = EMPTY_STRING;
						splitStrings = new ArrayList<>();
						markerX = 0;
						markerI = 0;
						markerY = 0;
						break;
				}
				break;
		}
	}

	private void stringSplit () {
		splitStrings = new ArrayList<>();
		int n = 0, start = 0;
		String str = getText(0);
		for (int i = 0; i < str.length(); i = str.offsetByCodePoints(i, 1)) {
			int cp = str.codePointAt(i);
			if (cp == '\n') {
				splitStrings.add(str.substring(start, i + 1));
				start = i + 1;
				n = 1;
			} else if (n == maxSize) {
				splitStrings.add(str.substring(start, i));
				start = i;
				n = 1;
			} else n++;
		}
		splitStrings.add(str.substring(start));
	}
}
