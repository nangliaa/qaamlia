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

import static org.nangliaa.extra.Colour.NULL;
import static org.nangliaa.extra.Colour.getFrom;
import static org.nangliaa.extra.Extra.EMPTY_STRING;
import static org.nangliaa.extra.Extra.FONT_HEIGHT;
import static org.nangliaa.extra.Extra.FONT_WIDÞ;
import static org.nangliaa.extra.Extra.HALF_HEIGHT;
import static org.nangliaa.extra.Extra.HALF_WIDÞ_INT;
import static org.nangliaa.extra.Extra.inBounds;

import org.nangliaa.extra.Img;
import org.nangliaa.extra.Nangliaa;
import org.nangliaa.extra.Point;

public class Comp extends Nangliaa {
	public Object[] subText;
	public Cont cont;
	private Comp left, right, up, down;
	public int[] xsub, ysub;
	public int x, y, width, height, round, contNo, markerWidth, markerHeight, xMod, yMod, marked;
	public int backgroundColour, frameColour, textColour, markedColour;
	public boolean drawItself;
	public CompLayout layout;
	protected int noOfFrames;
	public Point scrollPoint;
	private boolean triggerInit;
	protected boolean fillWidth;
	public boolean visible = true;
	private int oWidth;
	private int oHeight;

	public Comp () {}

	public Comp (Object nul) {
		width = 1;
		height = 1;
		subText = new Object[0];
		xsub = new int[0];
		ysub = new int[0];
		setColours(getFrom(NULL));
	}

	public Comp (Object[] subs, int[] xsub, int[] ysub, int width, int height) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		this.width = width;
		this.height = height;
		setColours(getFrom(NULL));
	}

	public Comp (Object[] subs, int[] xsub, int[] ysub, int width, int height, int round, int frames, int[] colours) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		this.width = width;
		this.height = height;
		this.round = round;
		noOfFrames = frames;
		setColours(colours);
	}

	public Comp (Object[] subs, int[] xsub, int[] ysub, int width, int height, int[] colours) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		this.width = width;
		this.height = height;
		setColours(colours);
	}

	public Comp (Object[] subs, int[] xsub, int[] ysub, int width, int height, int[] colours, int x, int y, int oWidth, int oHeight) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		this.width = width;
		this.height = height;
		setColours(colours);
		this.x = x * 7 + 12;
		this.y = y * 8 + 8;
		triggerInit = true;
		this.oHeight = oHeight;
		this.oWidth = oWidth;
	}

	public Comp (String string, int width, int height, int round, int[] colours) {
		subText = new String[] {
				string
		};
		xsub = new int[] {
				0
		};
		ysub = new int[] {
				0
		};
		this.width = width;
		this.round = round;
		this.height = height;
		setColours(colours);
		noOfFrames = 2;
	}

	public void actionA () {

	}

	public void deselect () {
		release(0, null);
	}

	public void drag (int config, Point point) {

	}

	public void drawComp (Img g, int i, int j) {
		drawComp(g, i, j, true, true);
	}

	public void drawComp (Img g, int x, int y, boolean drawSubText, boolean drawMarker) {
		g.rect(x, y, width, height, round, backgroundColour);
		g.frame(x, y, width, height, round, noOfFrames, frameColour, false);
		if (drawSubText) for (int i = 0; i < subText.length; i++)
			if (subText[i] == null) subText[i] = EMPTY_STRING;
			else g.drawString(getText(i), x + xsub[i], y + ysub[i], textColour);
		if (drawMarker && layout.activeComp == this) {
			int mh = getMarkerHeight(layout.markedBox);
			g.frame(x, y, width, height, round, 2, markedColour, false);
			if (inBounds(getMarkerX(x, layout.markedBox), getMarkerY(y, layout.markedBox), x, y + 2 * mh + 2, x + width, y + height - mh))
				g.drawRect(getMarkerX(x, layout.markedBox), getMarkerY(y, layout.markedBox), getMarkerWidth(layout.markedBox), getMarkerHeight(layout.markedBox), 4,
						markedColour);
		}
	}

	public Comp getDown () { return down; }

	public Comp getLeft () { return left; }

	private Comp getLinawe (int x, int y) {
		for (Comp comp : cont.subs) // System.out.println(x + " " + y + " " + comp.getText(0) + " x " + comp.x + " y " + comp.y + " " + (comp.x+comp.width) + " " + (comp.y+comp.height));
			if (inBounds(x, y, comp.x, comp.y, comp.x + comp.width, comp.y + comp.height)) return comp;
		return null;
	}

	public int getMarkerHeight (int i) {
		return FONT_HEIGHT << 1;
	}

	public int getMarkerWidth (int i) {
		return width - FONT_WIDÞ;
	}

	public int getMarkerX (int x, int i) {
		return (int) (x + xsub[i] - FONT_WIDÞ * 0.5);
	}

	public int getMarkerY (int y, int i) {
		return y + ysub[i] - (FONT_HEIGHT >> 1);
	}

	public void getOrthoComps (int w, int h) { // Here x and y are actually equivalent to cont.xsub[contNo]
		int q = y + HALF_HEIGHT;
		// System.out.println("TRY " + getText(0));
		for (int i = w + x - 1; i > x; --i) {
			Comp comp = getLinawe(i % w, q);
			if (comp != null) {
				left = comp;
				break;
			}
		}
		for (int i = x + width; i < w + x + width; ++i) {
			Comp comp = getLinawe(i % w, q);
			if (comp != null) {
				right = comp;
				break;
			}
		}
		q = x + HALF_WIDÞ_INT;
		for (int i = h + y - 1; i > y; --i) {
			Comp comp = getLinawe(q, i % h);
			if (comp != null) {
				up = comp;
				break;
			}
		}
		for (int i = y + height; i < h + y + height; ++i) {
			Comp comp = getLinawe(q, i % h);
			if (comp != null) {
				down = comp;
				break;
			}
		}
	}

	public Comp getRight () { return right; }

	public String getText (int i) {
		return (String) subText[i];
	}

	public Comp getUp () { return up; }

	public void init () {
		if (triggerInit) {
			cont.xsub[contNo] = x;
			cont.ysub[contNo] = y;
			getOrthoComps(oWidth, oHeight);
		}
	}

	protected void moveComp (int x, int y) {
		cont.xsub[contNo] = x;
		cont.ysub[contNo] = y;
	}

	public void onMarked () {

	}

	public void onSearchText (String sök) {

	}

	public void press (int config, Point point) {
		scrollPoint = point;
	}

	public void release (int config, Point point) {

	}

	public void resize () {

	}

	public void select (int config, Point mp) {

	}

	public void sendChar (char c) {

	}

	public void sendKey (int config, int keyCode) {

	}

	public void sendWheel (int config, int wheelRotation, Point mp) {

	}

	protected void setColours (int[] colours) {
		backgroundColour = colours[0];
		frameColour = colours[1];
		textColour = colours[2];
		markedColour = colours[3];
	}
}
