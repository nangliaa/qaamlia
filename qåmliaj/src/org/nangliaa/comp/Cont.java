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

package org.nangliaa.comp;

import static org.nangliaa.extra.Extra.EMPTY_STRING;

import org.nangliaa.extra.Colour;
import org.nangliaa.extra.Img;

public class Cont extends Comp {
	protected static Comp[] getEmptyComps (int amount) {
		Comp[] comps = new Comp[amount];
		for (int i = 0; i < comps.length; i++)
			comps[i] = new Comp();
		return comps;
	}

	public Comp[] subs;
	int boxShift;

	public Cont (Comp sub) {
		super(EMPTY_STRING, sub.width, sub.height, 0, Colour.getDefaultColours());
		visible = false;
		subs = new Comp[] {
				sub
		};
		xsub = new int[] {
				0
		};
		ysub = new int[] {
				0
		};
		x = 0;
		y = 0;
		sub.cont = this;
		sub.contNo = 0;
	}

	public Cont (Comp[] subs, int[] xsub, int[] ysub, int x, int y, int width, int height, int round, int[] colours) {
		super(EMPTY_STRING, width, height, round, colours);
		visible = false;
		noOfFrames = 2;
		this.subs = subs;
		this.xsub = xsub;
		this.ysub = ysub;
		this.x = x;
		this.y = y;
		for (int i = 0; i < subs.length; i++) {
			subs[i].cont = this;
			subs[i].contNo = i;
		}
	}

	public void drawCont (Img g) {
		g.rect(x, y, width, height, round, backgroundColour);
		g.frame(x, y, width, height, round, noOfFrames, frameColour, false);
		for (int i = 0; i < subs.length; i++)
			if (subs[i].visible) subs[i].drawComp(g, x + xsub[i], y + ysub[i]);
	}

	@Override
	public void resize () {
		if (subs != null) for (Comp comp : subs)
			comp.resize();
	}

	protected void setComp (Comp comp, int i) {
		subs[i] = comp;
		comp.layout = layout;
		comp.contNo = i;
		comp.cont = this;
		comp.init();
	}
}
