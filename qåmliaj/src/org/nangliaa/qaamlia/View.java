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

package org.nangliaa.qaamlia;

import static org.nangliaa.extra.Codes.CTRL_MASK;
import static org.nangliaa.extra.Codes.V_ESC;
import static org.nangliaa.extra.Codes.V_MINUS;
import static org.nangliaa.extra.Codes.V_PLUS;
import static org.nangliaa.extra.Colour.getDefaultBackgroundColours;
import static org.nangliaa.extra.Colour.getDefaultColours;
import static org.nangliaa.extra.Extra.EMPTY_STRING_ARRAY;

import java.awt.Insets;

import javax.swing.JFrame;

import org.nangliaa.comp.Comp;
import org.nangliaa.comp.CompLayout;
import org.nangliaa.comp.Cont;
import org.nangliaa.comp.Txt;

public class View extends CompLayout {
	private static final long serialVersionUID = 1L;
	Insets insets;

	public View () {
		super();
		frame.setBounds(500, 200, 800, 600);
		katt = 2;
		insets = frame.getInsets();
		setBoxes(new Cont[] {
				new Cont(new Comp[] {
						new Comp(new Object[] {
								"Ko"
						}, new int[] {
								0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
						}, new int[] {
								0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208
						}, 300, 100, getDefaultBackgroundColours()) {
							@Override
							public void resize () {
								width = cont.width - cont.subs[1].width - 32;
								height = cont.height - 20;
							}
						}, new Txt(28, 260, 0, 2, getDefaultColours()) {
							@Override
							public void resize () {
								// width =
								height = cont.height - 20;
							}
						}
				}, new int[] {
						200, 10
				}, new int[] {
						10, 10
				}, 0, 0, 444, 284, 0, getDefaultBackgroundColours()) {
					@Override
					public void resize () {
						width = View.this.width;
						height = View.this.height;
						super.resize();
					}
				}
		});
		resize();
		onScreenChanged();
	}

	protected void calendar () {

	}

	@Override
	protected void frameInit () {
		addKeyListener(this);
		addMouseListener(this);
		addMouseMotionListener(this);
		addMouseWheelListener(this);
		addComponentListener(this);

		frame = new JFrame();
		frame.add(this);
		frame.pack();
	}

	@Override
	public void keyPressed (int vk, int mod) {
		super.keyPressed(vk, mod);
		switch (mod) {
			case CTRL_MASK:
				switch (vk) {
					case V_PLUS:
						katt += 0.01;
						break;
					case V_MINUS:
						katt -= 0.01;
						break;
				}
				System.out.println("Katt: " + katt);
			case 0:
				if (vk == V_ESC) setVisible(false);
			default:

		}
		repaint();
	}

	@Override
	protected void resize () {
		width = (int) ((frame.getWidth() - insets.left - insets.right) / katt);
		height = (int) ((frame.getHeight() - insets.top - insets.bottom) / katt);
		super.resize();
	}

	@Override
	public void setVisible (boolean b) {
		frame.setVisible(b);
		repaint();
		// if (b) frame.requestFocus();
	}

	protected void textEdit () {
		boxes[0].subs[0].subText = EMPTY_STRING_ARRAY;
		boxes[0].xsub[0] = boxes[0].subs[1].width + 10;
		boxes[0].subs[1].visible = true;
		frame.setAlwaysOnTop(false);
		setVisible(true);
	}

	protected void window (String text) {
		boxes[0].subs[0].subText = text.split("\n");
		boxes[0].xsub[0] = 10;
		boxes[0].subs[1].visible = false;
		frame.setAlwaysOnTop(true);
		setVisible(true);
	}
}
