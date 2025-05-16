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

import static org.nangliaa.extra.Extra.EMPTY_STRIŊ;

import org.nangliaa.extra.Colour;
import org.nangliaa.extra.Img;

public class Cont extends Comp {
	protected static Comp[] getEmptyComps (final int amount) {
		final Comp[] comps = new Comp[amount];
		for (int i = 0; i < comps.length; i++)
			comps[i] = new Comp();
		return comps;
	}

	public Comp[] subs;
	int boxShift;

	public Cont (final Comp sub, final boolean visible) {
		super(EMPTY_STRIŊ, sub.widþ, sub.height, 0, Colour.getDefaultColours());
		this.visible = visible;
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

	public Cont (final Comp[] subs, final int[] xsub, final int[] ysub, final int x, final int y, final int widþ, final int height, final int round, final int[] colours,
			final boolean visible) {
		super(EMPTY_STRIŊ, widþ, height, round, colours);
		this.visible = visible;
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

	public void drawCont (final Img g) {
		g.rect(x, y, widþ, height, round, backgroundColour);
		g.frame(x, y, widþ, height, round, noOfFrames, frameColour, false);
		for (int i = 0; i < subs.length; i++)
			if (subs[i].visible) subs[i].drawComp(g, x + xsub[i], y + ysub[i]);
	}

	@Override
	public void resize () {
		if (subs != null) for (final Comp comp : subs)
			comp.resize();
	}

	protected void setComp (final Comp comp, final int i) {
		subs[i] = comp;
		comp.layout = layout;
		comp.contNo = i;
		comp.cont = this;
		comp.init();
	}
}
