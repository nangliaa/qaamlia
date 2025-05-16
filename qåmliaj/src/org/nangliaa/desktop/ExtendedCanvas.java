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

package org.nangliaa.desktop;

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.image.BufferedImage;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.swing.JFrame;
import javax.swing.WindowConstants;

import org.nangliaa.extra.Img;
import org.nangliaa.extra.Nangliaa;
import org.nangliaa.extra.Point;

/**
 * Base class of {@code CompLayout}
 */
public class ExtendedCanvas extends Canvas implements MouseListener, KeyListener, MouseMotionListener, MouseWheelListener, ComponentListener {
	private static final long serialVersionUID = 1L;

	public static Img drawString (final String s, final int colour, final float size) {
		return ImgAWT.drawString(s, colour, size);
	}

	public static void initFrame (final JFrame j) {
		j.pack();
		j.setVisible(false);
		j.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}

	public int queuedRepaints = 0;

	protected JFrame frame;

	protected Graphix g2;
	protected ImgAWT image2;
	public double katt = 1.4;
	public int widþ;
	public int height;
	public Map<Class<? extends Nangliaa>, List<? extends Nangliaa>> objects;

	@Override
	public void componentHidden (final ComponentEvent e) {}

	@Override
	public void componentMoved (final ComponentEvent e) {}

	@Override
	public void componentResized (final ComponentEvent e) {
		resize();
	}

	@Override
	public void componentShown (final ComponentEvent e) {}

	public Img drawComps () {
		return null;
	}

	protected void frameInit () {
		final Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

		addKeyListener(this);
		addMouseListener(this);
		addMouseMotionListener(this);
		addMouseWheelListener(this);
		addComponentListener(this);

		frame = new JFrame();
		frame.setExtendedState(Frame.MAXIMIZED_BOTH);
		frame.add(this);
		frame.pack();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		objects = new HashMap<>();

		final int scrW = (int) screenSize.getWidth();
		final int scrH = (int) screenSize.getHeight();
		widþ = scrW - frame.getInsets().left - frame.getInsets().right;
		height = scrH - frame.getInsets().top - frame.getInsets().bottom;
		onScreenChanged();
		requestFocus();
	}

	public boolean isPhone () { return false; }

	public void keyPressed (final int vk, final int mod) {}

	@Override
	public void keyPressed (final KeyEvent e) {
		keyPressed(e.getExtendedKeyCode(), e.getModifiersEx());
		repaint();
	}

	public void keyReleased (final int vk, final int mod) {}

	@Override
	public void keyReleased (final KeyEvent e) {
		keyReleased(e.getExtendedKeyCode(), e.getModifiersEx());
	}

	public void keyTyped (final char c, final int mod) {}

	@Override
	public void keyTyped (final KeyEvent e) {
		keyTyped(e.getKeyChar(), e.getModifiersEx());
		repaint();
	}

	@Override
	public void mouseClicked (final MouseEvent e) {
		mouseClicked(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx() + (1 << (e.getButton() > 3 ? e.getButton() + 10 : e.getButton() + 9)), e.getClickCount());
		repaint();
	}

	public void mouseClicked (final Point point, final int mod, final int clicks) {}

	@Override
	public void mouseDragged (final MouseEvent e) {
		mouseDragged(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mouseDragged (final Point point, final int mod) {}

	@Override
	public void mouseEntered (final MouseEvent e) {}

	@Override
	public void mouseExited (final MouseEvent e) {}

	@Override
	public void mouseMoved (final MouseEvent e) {
		final java.awt.Point pos = getMousePosition();
		if (pos == null) return;
		mouseMoved(new Point(pos.x, pos.y), e.getModifiersEx());
		repaint();
	}

	public void mouseMoved (final Point point, final int mod) {}

	@Override
	public void mousePressed (final MouseEvent e) {
		mousePressed(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mousePressed (final Point point, final int mod) {}

	@Override
	public void mouseReleased (final MouseEvent e) {
		mouseReleased(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mouseReleased (final Point point, final int mod) {}

	public void mouseWheelMoved (final int rotations, final Point point, final int mod) {}

	@Override
	public void mouseWheelMoved (final MouseWheelEvent e) {
		mouseWheelMoved(e.getWheelRotation(), new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void onScreenChanged () {
		image2 = new ImgAWT(widþ, height, BufferedImage.TYPE_INT_ARGB);
		g2 = new Graphix(image2.createGraphics());
	}

	@Override
	public void paint (final Graphics g) {
		final Img img = drawComps();
		if (g2 != null && img != null) {
			g2.drawImage(img, 0, 0);
			g.drawImage(image2, 0, 0, (int) (image2.getWidth() * katt), (int) (image2.getHeight() * katt), this);
		}
		queuedRepaints--;
	}

	@Override
	public void repaint () {
		queuedRepaints++;
		super.repaint();
	}

	protected void resize () {

	}

	@Override
	public void update (final Graphics g) {
		paint(g);
	}
}
