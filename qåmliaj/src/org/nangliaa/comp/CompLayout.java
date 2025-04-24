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

import static org.nangliaa.extra.Codes.ALTGR_MASK;
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
	private static final long serialVersionUID = 1L;
	public static String language = Extra.nagolima;
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
		Img img = new Img(width, height);
		img.fill(BACKGROUND_COLOUR);
		if (boxes != null) for (Cont c : boxes)
			c.drawCont(img);
		return img;
	}

	public Comp getCompAtPoint (Cont c, Point mp) {
		if (inRect(mp, c.x, c.y, c.width, c.height)) for (int j = 0; j < c.subs.length; j++) {
			Comp s = c.subs[j];
			if (inRect(mp, c.x + c.xsub[j], c.y + c.ysub[j], s.width, s.height)) return s;
		}
		return null;
	}

	public Comp getCompAtPoint (Point mp) {
		for (int i = boxes.length; i > 0;) {
			i--;
			Cont c = boxes[i];
			if (inRect(mp, c.x, c.y, c.width, c.height)) for (int j = 0; j < c.subs.length; j++) {
				Comp s = c.subs[j];
				if (inRect(mp, c.x + c.xsub[j], c.y + c.ysub[j], s.width, s.height)) return s;
			}
		}
		return null;
	}

	@Override
	public void keyPressed (int vk, int mod) {
		if (activeComp != null) if (vk == V_TAB) scrollComponent(mod, true);
		else if (vk == V_TAB && mod == SHIFT_MASK) scrollComponent(mod, false);
		else activeComp.sendKey(mod, vk);
	}

	@Override
	public void keyReleased (int vk, int mod) {}

	@Override
	public void keyTyped (char c, int mod) {
		if ((mod & CTRL_MASK) == CTRL_MASK && (mod & ALTGR_MASK) == 0) return;
		if (activeComp != null) activeComp.sendChar(c);
	}

	@Override
	public void mouseClicked (Point point, int mod) {
		Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		Comp a = getCompAtPoint(mp);
		if (activeComp != null && activeComp != a) activeComp.deselect();
		if (a != null) {
			a.select(mod, mp);
			a.actionA();
		}
	}

	@Override
	public void mouseDragged (Point point, int mod) {
		Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		Comp a = getCompAtPoint(mp);
		if (a != null) a.drag(mod, mp);
	}

	@Override
	public void mouseMoved (Point point, int mod) {

	}

	/*
	 * @Override public void mouseEntered (MouseEvent e) { }
	 *
	 * @Override public void mouseExited (MouseEvent e) { }
	 */

	@Override
	public void mousePressed (Point point, int mod) {
		Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		Comp a = getCompAtPoint(mp);
		if (a != null) a.press(mod, mp);
	}

	@Override
	public void mouseReleased (Point point, int mod) {
		Point mp = new Point((int) (point.x / katt), (int) (point.y / katt));
		Comp a = getCompAtPoint(mp);
		if (a != null) a.release(mod, mp);
	}

	@Override
	public void mouseWheelMoved (int rotations, Point point, int mod) {
		if (activeComp != null) activeComp.sendWheel(mod, rotations, new Point(point.x / katt, point.y / katt));
	}

	@Override
	protected void resize () {
		if (boxes != null) for (Cont c : boxes)
			c.resize();
	}

	/**
	 * Override this to choose what the returned object should do.
	 *
	 * @param n The object from a list
	 */

	public void returnedA (Comp comp, Nangliaa n) {

	}

	public void scrollComponent (int config, boolean forwardOrDown) {
		Comp[] aComps = activeComp.cont.subs;
		for (int i = 0; i < aComps.length; i++)
			if (aComps[i] == activeComp) {
				int compNo = forwardOrDown ? (i + 1) % aComps.length : i > 0 ? i - 1 : aComps.length - 1;
				activeComp.deselect();
				aComps[compNo].select(config, null);
				aComps[compNo].actionA();
				break;
			}
	}

	public void setBoxes (Cont[] boxes) {
		this.boxes = boxes;
		for (Cont a : boxes) {
			a.layout = this;
			for (Comp b : a.subs) {
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

	public void setMarkedBox (int mark, int shift) {
		markedBox = mark;
		boxShift = shift;
	}

	public void setVisible (Cont prim, Cont second, Cont third, boolean visible) {
		setVisible(new Cont[] {
				prim, second, third
		}, visible, false);
	}

	public void setVisible (Cont[] list, boolean visible, boolean resetMarker) {
		if (resetMarker) {
			markedBox = 0;
			boxShift = 0;
		}
		if (visible) activeBox = list[0];
		else activeBox = null;
		for (Cont box : list)
			if (box != null) box.visible = visible;
	}

	public void switchBoxes (Cont from, Cont to) {
		if (from != null) from.visible = false;
		if (to != null) {
			to.visible = true;
			activeBox = to;
		}
	}
}
