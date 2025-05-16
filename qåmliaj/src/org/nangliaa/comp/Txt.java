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
import static org.nangliaa.extra.Extra.EMPTY_STRIŊ;
import static org.nangliaa.extra.Extra.FONT_HEIGHT;
import static org.nangliaa.extra.Extra.FONT_WIDÞ;
import static org.nangliaa.extra.Extra.MAX_FONT_HEIGHT;
import static org.nangliaa.extra.Extra.popFirst;

import java.util.ArrayList;

import org.nangliaa.desktop.Special;
import org.nangliaa.extra.Extra;
import org.nangliaa.extra.Img;
import org.nangliaa.extra.Point;

public class Txt extends Comp {
	int markerX, markerY, markerI, maxSize = 12;
	boolean markerShown, area, altArrows = false;
	ArrayList<String> splitStrings = new ArrayList<>();

	public Txt (final int noOfSubs, final int widþ, final int height, final int round, final int frames, final int[] colours) {
		super(new Object[noOfSubs], new int[noOfSubs], new int[noOfSubs], widþ, height, round, frames, colours);
	}

	/**
	 * TextArea
	 *
	 * @param widþ    Row max size
	 * @param height
	 * @param round
	 * @param frames
	 * @param colours
	 */
	public Txt (final int widþ, final int height, final int round, final int frames, final int[] colours) {
		super(new Object[] {
				""
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				MAX_FONT_HEIGHT
		}, (widþ + 2) * FONT_WIDÞ, height, round, frames, colours);
		maxSize = widþ;
		area = true;
	}

	/**
	 * Creates a simple Txt wið standardised widþ and height.
	 *
	 * @param sub
	 * @param maxSize ðe widþ (text widþ + 2)
	 * @param height  ðe height (text height * 2 + 1)
	 */
	public Txt (final String sub, final int maxSize, final int height, final int round, final int frames) {
		super(new Object[] {
				sub
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				FONT_HEIGHT
		}, (maxSize + 3) * FONT_WIDÞ, (height * 2 + 1) * FONT_HEIGHT, round, frames, getFrom(NULL));
	}

	public Txt (final String sub, final int widþ, final int height, final int round, final int frames, final int[] colours) {
		super(new Object[] {
				sub
		}, new int[] {
				FONT_WIDÞ
		}, new int[] {
				FONT_HEIGHT
		}, widþ, height, round, frames, colours);
	}

	/**
	 * Labelled Text
	 *
	 * @param initString
	 * @param desc
	 * @param widþ
	 * @param height
	 * @param round
	 * @param frames
	 * @param colours
	 */
	public Txt (final String initString, final String desc, final int widþ, final int height, final int round, final int frames, final int[] colours) {
		super(new Object[2], new int[2], new int[2], (widþ + 2) * FONT_WIDÞ, (height * 2 + 1) * FONT_HEIGHT, round, frames, colours);
		maxSize = widþ - desc.length();
		subText[0] = initString;
		subText[1] = desc;
		xsub[0] = (desc.length() + 1) * FONT_WIDÞ;
		xsub[1] = FONT_WIDÞ;
		ysub[0] = FONT_HEIGHT;
		ysub[1] = FONT_HEIGHT;
	}

	/**
	 * Paste a striŋ at point of ðe marker.
	 *
	 * @param s Ðe String to be pasted.
	 */
	void addText (final String s) {
		String text = getText(0);
		final String text1 = text.substring(0, markerI);
		final String text2 = text.substring(markerI, getText(0).length());
		s.replace("\r\n", "\n");
		s.replace('\r', '\n');
		if (getText(0).length() < maxSize || area || maxSize < 0) text = text1 + s + text2;
		subText[0] = text;
		stringSplit();
		for (int i = 0; i < s.length(); i++)
			markRight(true);
	}

	@Override
	public void deselect () {
		markerShown = false;
	}

	@Override
	public void drawComp (final Img g, final int x, final int y) {
		if (!area) super.drawComp(g, x, y, true, true);
		else {
			super.drawComp(g, x, y, false, true);
			int j = 0;
			for (final String c : splitStrings)
				g.drawString(c, x + xsub[0], y + ysub[0] + j++ * MAX_FONT_HEIGHT, textColour);
		}
		if (markerShown) {
			final int x12 = x + xsub[0] + markerX * FONT_WIDÞ;
			final int y12 = y + ysub[0] + markerY * MAX_FONT_HEIGHT;
			g.drawLine(x12, y12 - 6, x12, y12 + 12, textColour);
		}
	}

	/**
	 * When marker goes down. Only triggers when area == true.
	 */
	private void markDown () {
		if (markerY == splitStrings.size() - 1) {
			markerI = getText(0).length();
			markerX = splitStrings.get(markerY).length();
			return;
		}
		final int len = splitStrings.get(markerY + 1).length() - 1;
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

	/**
	 * When marker goes left.
	 *
	 * @param remove wheðer a letter is removed.
	 */
	private void markLeft (final boolean remove) {
		if (markerX == 0) {
			if (markerY != 0) {
				final int len = splitStrings.get(markerY - 1).length();
				markerX = len != 0 && !remove ? len - 1 : len;
				markerY--;
				markerI--;
			}
		} else {
			markerX--;
			markerI--;
		}
	}

	/**
	 * When marker goes right.
	 *
	 * @param add wheðer a letter is written.
	 */
	private void markRight (final boolean add) {
		final int len = splitStrings.get(markerY).length();
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

	/**
	 * When marker goes up. Only triggers when area == true.
	 */
	private void markUp () {
		if (markerY == 0) {
			markerI = 0;
			markerX = 0;
			return;
		}
		final int len = splitStrings.get(markerY - 1).length() - 1;
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
		subText[0] = EMPTY_STRIŊ;
	}

	@Override
	public void select (final int config, final Point mp, final int clicks) {
		layout.activeComp = this;
		layout.markedBox = 0;
		markerShown = true;
	}

	@Override
	public void sendChar (final char c) {
		final boolean number = false;

		String text = getText(0);
		final int oldLeŋþ = text.length();
		final String text1 = text.substring(0, markerI);
		final String text2 = text.substring(markerI);
		if (c == '\b') text = Extra.pop(text1) + text2;
		else if (c == '\u007f') text = text1 + popFirst(text2);
		else if (number) {
			if (Character.digit(c, layout.numberSystem) != -1) text += Character.toUpperCase(c);
			else if (c == '-') text = text.charAt(0) == '-' ? Extra.popFirst(text) : '-' + text;
		} else if (c == '\r') text = text1 + '\n' + text2;
		else if (text.length() < maxSize || area || maxSize < 0) text = text1 + c + text2;

		subText[0] = text;

		stringSplit();
		if (c != '\u007f' && text.length() != oldLeŋþ) if (text.length() == oldLeŋþ - 1) markLeft(true);
		else markRight(true);
	}

	@Override
	public void sendKey (final int config, final int keyCode) {
		switch (config) {
			case CTRL_MASK:
				switch (keyCode) {
					case V_DEL:
						subText[0] = EMPTY_STRIŊ;
						splitStrings = new ArrayList<>();
						markerX = 0;
						markerI = 0;
						markerY = 0;
						break;
					case V_V:
						if (Special.isClipboardStriŋ()) addText(Special.getClipboardStriŋ());
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
						if (area) markUp();
						break;
					case V_DOWN:
						if (area) markDown();
						break;
				}
				System.err.println("I: " + markerI + " X: " + markerX + " Y: " + markerY);
				break;
		}
	}

	private void stringSplit () {
		splitStrings = new ArrayList<>();
		int n = 0, start = 0;
		final String str = getText(0);
		for (int i = 0; i < str.length(); i = str.offsetByCodePoints(i, 1)) {
			final int cp = str.codePointAt(i);
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
