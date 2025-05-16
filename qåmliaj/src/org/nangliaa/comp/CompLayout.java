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

import static org.nangliaa.extra.Codes.ALTGR_MASK;
import static org.nangliaa.extra.Codes.ALT_MASK;
import static org.nangliaa.extra.Codes.CTRL_MASK;
import static org.nangliaa.extra.Codes.SHIFT_MASK;
import static org.nangliaa.extra.Codes.V_TAB;
import static org.nangliaa.extra.Colour.BACKGROUND_COLOUR;
import static org.nangliaa.extra.Colour.NULL;
import static org.nangliaa.extra.Extra.inRect;

import org.nangliaa.desktop.ExtendedCanvas;
import org.nangliaa.extra.Extra;
import org.nangliaa.extra.Img;
import org.nangliaa.extra.Nangliaa;
import org.nangliaa.extra.Point;

public class CompLayout extends ExtendedCanvas {
	public static final int ONE_CLICK = 1;

	private static final long serialVersionUID = 1L;
	public static String language = Extra.nagolima;

	public static Comp getCompAtPoint (final Cont c, final Point mp) {
		if (inRect(mp, c.x, c.y, c.widþ, c.height)) for (int j = 0; j < c.subs.length; j++) {
			final Comp s = c.subs[j];
			if (inRect(mp, c.x + c.xsub[j], c.y + c.ysub[j], s.widþ, s.height)) return s;
		}
		return null;
	}

	public int markedBox, numberSystem = 16;
	protected int prevMarkedBox, boxShift;
	public Cont activeBox;
	public Comp activeComp;
	public Cont[] boxes;

	protected boolean rctrl, rshift, ralt;

	public int currentTable;

	public CompLayout () {
		super();
		frameInit();
	}

	@Override
	public Img drawComps () {
		final Img img = new Img(widþ, height);
		img.fill(BACKGROUND_COLOUR);
		if (boxes != null) for (final Cont c : boxes)
			if (c.visible) c.drawCont(img);
		return img;
	}

	public Comp getCompAtPoint (final Point mp) {
		for (int i = boxes.length; i > 0;) {
			i--;
			final Cont c = boxes[i];
			if (inRect(mp, c.x, c.y, c.widþ, c.height)) for (int j = 0; j < c.subs.length; j++) {
				final Comp s = c.subs[j];
				if (inRect(mp, c.x + c.xsub[j], c.y + c.ysub[j], s.widþ, s.height)) return s;
			}
		}
		return null;
	}

	@Override
	public void keyPressed (final int vk, final int mod) {
		if (activeComp != null) if (vk == V_TAB) scrollComponent(mod, true);
		else if (vk == V_TAB && mod == SHIFT_MASK) scrollComponent(mod, false);
		else activeComp.sendKey(mod, vk);
	}

	@Override
	public void keyReleased (final int vk, final int mod) {}

	@Override
	public void keyTyped (final char c, final int mod) {
		if ((mod & (CTRL_MASK | ALT_MASK)) != 0 && (mod & ALTGR_MASK) == 0) return; // Ban all ctrl or alt chars if not altGR
		if (activeComp != null) activeComp.sendChar(c);
	}

	@Override
	public void mouseClicked (final Point point, final int mod, final int clicks) {
		final Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		final Comp a = getCompAtPoint(mp);
		if (activeComp != null && activeComp != a) activeComp.deselect();
		if (a != null) {
			a.select(mod, mp, clicks);
			a.actionA();
		}
	}

	@Override
	public void mouseDragged (final Point point, final int mod) {
		final Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		final Comp a = getCompAtPoint(mp);
		if (a != null) a.drag(mod, mp);
	}

	@Override
	public void mouseMoved (final Point point, final int mod) {

	}

	/*
	 * @Override public void mouseEntered (MouseEvent e) { }
	 *
	 * @Override public void mouseExited (MouseEvent e) { }
	 */

	@Override
	public void mousePressed (final Point point, final int mod) {
		final Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		final Comp a = getCompAtPoint(mp);
		if (a != null) a.press(mod, mp);
	}

	@Override
	public void mouseReleased (final Point point, final int mod) {
		final Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		final Comp a = getCompAtPoint(mp);
		if (a != null) a.release(mod, mp);
	}

	@Override
	public void mouseWheelMoved (final int rotations, final Point point, final int mod) {
		if (activeComp != null) activeComp.sendWheel(mod, rotations, new Point(point.x / katt, point.y / katt));
	}

	@Override
	protected void resize () {
		if (boxes != null) for (final Cont c : boxes)
			c.resize();
	}

	/**
	 * Override ðis to choose what ðe returned object should do.
	 *
	 * @param n ðe object from a list
	 */
	public void returnedA (final Comp comp, final Nangliaa n) {

	}

	public void scrollComponent (final int config, final boolean forwardOrDown) {
		final Comp[] aComps = activeComp.cont.subs;
		for (int i = 0; i < aComps.length; i++)
			if (aComps[i] == activeComp) {
				final int compNo = forwardOrDown ? (i + 1) % aComps.length : i > 0 ? i - 1 : aComps.length - 1;
				activeComp.deselect();
				aComps[compNo].select(config, null, CompLayout.ONE_CLICK);
				aComps[compNo].actionA();
				break;
			}
	}

	public void setBoxes (final Cont[] boxes) {
		this.boxes = boxes;
		for (final Cont a : boxes) {
			a.layout = this;
			for (final Comp b : a.subs) {
				b.layout = this;
				if (b.backgroundColour == NULL) b.backgroundColour = a.backgroundColour;
				if (b.frameColour == NULL) b.frameColour = a.frameColour;
				if (b.textColour == NULL) b.textColour = a.textColour;
				if (b.markedColour == NULL) b.markedColour = a.markedColour;
				b.init();
			}
			a.init();
		}
		repaint();
	}

	public void setMarkedBox (final int mark, final int shift) {
		markedBox = mark;
		boxShift = shift;
	}

	public void setVisible (final Cont prim, final boolean visible) {
		if (visible) activeBox = prim;
		else activeBox = null;
		if (prim != null) prim.visible = visible;
	}

	public void setVisible (final Cont prim, final Cont second, final Cont þird, final boolean visible) {
		setVisible(new Cont[] {
				prim, second, þird
		}, visible, false);
	}

	public void setVisible (final Cont[] list, final boolean visible, final boolean resetMarker) {
		if (resetMarker) {
			markedBox = 0;
			boxShift = 0;
		}
		if (visible) activeBox = list[0];
		else activeBox = null;
		for (final Cont box : list)
			if (box != null) box.visible = visible;
	}

	public void switchBoxes (final Cont from, final Cont to) {
		if (from != null) from.visible = false;
		if (to != null) {
			to.visible = true;
			activeBox = to;
		}
	}
}
