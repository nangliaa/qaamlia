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

import static org.nangliaa.extra.Colour.NULL;
import static org.nangliaa.extra.Colour.getFrom;
import static org.nangliaa.extra.Extra.EMPTY_STRIŊ;
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
	public int x, y, widþ, height, round, contNo, markerWidþ, markerHeight, xMod, yMod, marked;
	public int backgroundColour, frameColour, textColour, markedColour;
	public boolean drawItself;
	public CompLayout layout;
	protected int noOfFrames;
	public Point scrollPoint;
	private boolean triggerInit;
	protected boolean fillWidþ;
	public boolean visible = true;
	private int oWidþ, oHeight;

	public Comp () {}

	public Comp (final Object nul) {
		widþ = 1;
		height = 1;
		subText = new Object[0];
		xsub = new int[0];
		ysub = new int[0];
		setColours(getFrom(NULL));
	}

	public Comp (final Object[] subs, final int[] xsub, final int[] ysub, final int width, final int height) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		widþ = width;
		this.height = height;
		setColours(getFrom(NULL));
	}

	public Comp (final Object[] subs, final int[] xsub, final int[] ysub, final int width, final int height, final int round, final int frames, final int[] colours) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		widþ = width;
		this.height = height;
		this.round = round;
		noOfFrames = frames;
		setColours(colours);
	}

	public Comp (final Object[] subs, final int[] xsub, final int[] ysub, final int width, final int height, final int[] colours) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		widþ = width;
		this.height = height;
		setColours(colours);
	}

	public Comp (final Object[] subs, final int[] xsub, final int[] ysub, final int width, final int height, final int[] colours, final int x, final int y, final int oWidth, final int oHeight) {
		subText = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		widþ = width;
		this.height = height;
		setColours(colours);
		this.x = x * 7 + 12;
		this.y = y * 8 + 8;
		triggerInit = true;
		this.oHeight = oHeight;
		oWidþ = oWidth;
	}

	public Comp (final String string, final int width, final int height, final int round, final int[] colours) {
		subText = new String[] {
				string
		};
		xsub = new int[] {
				0
		};
		ysub = new int[] {
				0
		};
		widþ = width;
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

	public void drag (final int config, final Point point) {

	}

	public void drawComp (final Img g, final int i, final int j) {
		drawComp(g, i, j, true, true);
	}

	public void drawComp (final Img g, final int x, final int y, final boolean drawSubText, final boolean drawMarker) {
		g.rect(x, y, widþ, height, round, backgroundColour);
		g.frame(x, y, widþ, height, round, noOfFrames, frameColour, false);
		if (drawSubText) for (int i = 0; i < subText.length; i++)
			if (subText[i] == null) subText[i] = EMPTY_STRIŊ;
			else g.drawString(getText(i), x + xsub[i], y + ysub[i], textColour);
		if (drawMarker && layout.activeComp == this) {
			final int mh = getMarkerHeight(layout.markedBox);
			g.frame(x, y, widþ, height, round, 2, markedColour, false);
			if (inBounds(getMarkerX(x, layout.markedBox), getMarkerY(y, layout.markedBox), x, y + 2 * mh + 2, x + widþ, y + height - mh))
				g.drawRect(getMarkerX(x, layout.markedBox), getMarkerY(y, layout.markedBox), getMarkerWidþ(layout.markedBox), getMarkerHeight(layout.markedBox), 4, markedColour);
		}
	}

	public Comp getDown () { return down; }

	public Comp getLeft () { return left; }

	private Comp getLinawe (final int x, final int y) {
		for (final Comp comp : cont.subs) // System.out.println(x + " " + y + " " + comp.getText(0) + " x " + comp.x + " y " + comp.y + " " + (comp.x+comp.width) + " " + (comp.y+comp.height));
			if (inBounds(x, y, comp.x, comp.y, comp.x + comp.widþ, comp.y + comp.height)) return comp;
		return null;
	}

	public int getMarkerHeight (final int i) {
		return FONT_HEIGHT << 1;
	}

	public int getMarkerWidþ (final int i) {
		return widþ - FONT_WIDÞ;
	}

	public int getMarkerX (final int x, final int i) {
		return (int) (x + xsub[i] - FONT_WIDÞ * 0.5);
	}

	public int getMarkerY (final int y, final int i) {
		return y + ysub[i] - (FONT_HEIGHT >> 1);
	}

	public void getOrthoComps (final int w, final int h) { // Here x and y are actually equivalent to cont.xsub[contNo]
		int q = y + HALF_HEIGHT;
		// System.out.println("TRY " + getText(0));
		for (int i = w + x - 1; i > x; --i) {
			final Comp comp = getLinawe(i % w, q);
			if (comp != null) {
				left = comp;
				break;
			}
		}
		for (int i = x + widþ; i < w + x + widþ; ++i) {
			final Comp comp = getLinawe(i % w, q);
			if (comp != null) {
				right = comp;
				break;
			}
		}
		q = x + HALF_WIDÞ_INT;
		for (int i = h + y - 1; i > y; --i) {
			final Comp comp = getLinawe(q, i % h);
			if (comp != null) {
				up = comp;
				break;
			}
		}
		for (int i = y + height; i < h + y + height; ++i) {
			final Comp comp = getLinawe(q, i % h);
			if (comp != null) {
				down = comp;
				break;
			}
		}
	}

	public Comp getRight () { return right; }

	public String getText (final int i) {
		if (subText[i] instanceof String) return (String) subText[i];
		if (subText[i] instanceof Character) return "" + subText[i];
		return (String) subText[i];
	}

	public Comp getUp () { return up; }

	public void init () {
		if (triggerInit) {
			cont.xsub[contNo] = x;
			cont.ysub[contNo] = y;
			getOrthoComps(oWidþ, oHeight);
		}
	}

	protected void moveComp (final int x, final int y) {
		cont.xsub[contNo] = x;
		cont.ysub[contNo] = y;
	}

	public void onMarked () {

	}

	public void onSearchText (final String sök) {

	}

	public void press (final int config, final Point point) {
		scrollPoint = point;
	}

	public void release (final int config, final Point point) {

	}

	public void resize () {

	}

	public void select (final int config, final Point mp, final int clicks) {

	}

	public void sendChar (final char c) {

	}

	public void sendKey (final int config, final int keyCode) {

	}

	public void sendWheel (final int config, final int wheelRotation, final Point mp) {

	}

	protected void setColours (final int[] colours) {
		backgroundColour = colours[0];
		frameColour = colours[1];
		textColour = colours[2];
		markedColour = colours[3];
	}
}
