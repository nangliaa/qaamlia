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

	public static Img drawString (String s, int colour, float size) {
		return ImgAWT.drawString(s, colour, size);
	}

	public static void initFrame (JFrame j) {
		j.pack();
		j.setVisible(false);
		j.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}

	protected JFrame frame;

	protected Graphix g2;
	protected ImgAWT image2;
	public double katt = 1.4;
	public int width;
	public int height;
	public Map<Class<? extends Nangliaa>, List<? extends Nangliaa>> objects;

	@Override
	public void componentHidden (ComponentEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void componentMoved (ComponentEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void componentResized (ComponentEvent e) {
		resize();
	}

	@Override
	public void componentShown (ComponentEvent e) {
		// TODO Auto-generated method stub

	}

	public Img drawComps () {
		return null;
	}

	protected void frameInit () {
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

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

		int scrW = (int) screenSize.getWidth();
		int scrH = (int) screenSize.getHeight();
		width = scrW - frame.getInsets().left - frame.getInsets().right;
		height = scrH - frame.getInsets().top - frame.getInsets().bottom;
		onScreenChanged();
		requestFocus();
	}

	public boolean isPhone () { return false; }

	public void keyPressed (int vk, int mod) {}

	@Override
	public void keyPressed (KeyEvent e) {
		keyPressed(e.getExtendedKeyCode(), e.getModifiersEx());
		repaint();
	}

	public void keyReleased (int vk, int mod) {}

	@Override
	public void keyReleased (KeyEvent e) {
		keyReleased(e.getExtendedKeyCode(), e.getModifiersEx());
	}

	public void keyTyped (char c, int mod) {}

	@Override
	public void keyTyped (KeyEvent e) {
		keyTyped(e.getKeyChar(), e.getModifiersEx());
		repaint();
	}

	@Override
	public void mouseClicked (MouseEvent e) {
		mouseClicked(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mouseClicked (Point point, int mod) {}

	@Override
	public void mouseDragged (MouseEvent e) {
		mouseDragged(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mouseDragged (Point point, int mod) {}

	@Override
	public void mouseEntered (MouseEvent e) {}

	@Override
	public void mouseExited (MouseEvent e) {}

	@Override
	public void mouseMoved (MouseEvent e) {
		java.awt.Point pos = getMousePosition();
		if (pos == null) return;
		mouseMoved(new Point(pos.x, pos.y), e.getModifiersEx());
		repaint();
	}

	public void mouseMoved (Point point, int mod) {}

	@Override
	public void mousePressed (MouseEvent e) {
		mousePressed(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mousePressed (Point point, int mod) {}

	@Override
	public void mouseReleased (MouseEvent e) {
		mouseReleased(new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void mouseReleased (Point point, int mod) {}

	public void mouseWheelMoved (int rotations, Point point, int mod) {}

	@Override
	public void mouseWheelMoved (MouseWheelEvent e) {
		mouseWheelMoved(e.getWheelRotation(), new Point(getMousePosition().x, getMousePosition().y), e.getModifiersEx());
		repaint();
	}

	public void onScreenChanged () {
		image2 = new ImgAWT(width, height, BufferedImage.TYPE_INT_ARGB);
		g2 = new Graphix(image2.createGraphics());
	}

	@Override
	public void paint (Graphics g) {
		Img img = drawComps();
		if (img != null) {
			g2.drawImage(img, 0, 0);
			g.drawImage(image2, 0, 0, (int) (image2.getWidth() * katt), (int) (image2.getHeight() * katt), this);
		}
	}

	@Override
	public void repaint () {
		// TODO Auto-generated method stub
		super.repaint();
	}

	protected void resize () {

	}

	@Override
	public void update (Graphics g) {
		paint(g);
	}
}
