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

import static java.lang.Math.abs;
import static org.nangliaa.extra.Extra.FONT_WIDÞ;
import static org.nangliaa.extra.Extra.MAX_FONT_HEIGHT;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import org.nangliaa.extra.Img;

public class ImgAWT extends BufferedImage {
	public static double calculateArea (final Polygon p) {
		double area = 0.0;

		for (int i = 0; i < p.npoints; i++) {
			final int j = (i + 1) % p.npoints;
			area += p.xpoints[i] * p.ypoints[j];
			area -= p.xpoints[j] * p.ypoints[i];
		}

		area /= 2.0;
		return abs(area);
	}

	public static Img drawString (final String text, final int colour, final float size) {
		final ImgAWT bufAwt = new ImgAWT(text.length() * FONT_WIDÞ, MAX_FONT_HEIGHT);
		final Graphics2D g = bufAwt.createGraphics();
		g.setFont(size == 16f ? Graphix.FONT : Graphix.FONT2);
		g.setColor(new Color(colour));
		g.drawString(text, 0, 12); // TODO
		g.dispose();
		return toImg(bufAwt);
	}

	public static ImgAWT getBufferedImage (final Img img) {
		final int h = img.getHeight();
		final int w = img.getWidþ();
		final ImgAWT awt = new ImgAWT(w, h);
		awt.setRGB(0, 0, w, h, img.getPixels(), 0, w);
		return awt;
	}

	public static BufferedImage getImageFromFile (final String file) {
		try {
			return ImageIO.read(FileIO.resFileStream(file));
		} catch (final IOException e) {
			System.err.println("Img.imgRead: File does not exist.");
		}
		return null;
	}

	public static ImgAWT imgRead (final String url) {
		BufferedImage b = null;
		try {
			b = ImageIO.read(new File(url));
		} catch (final IOException e) {
			System.err.println("Img.imgRead: File does not exist. " + url);
		}
		final ImgAWT temp = new ImgAWT(b.getWidth(), b.getHeight(), TYPE_INT_ARGB);
		final Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public static ImgAWT loadRes (final String url) {
		final BufferedImage b = getImageFromFile(url);
		final ImgAWT temp = new ImgAWT(b.getWidth(), b.getHeight(), TYPE_INT_ARGB);
		final Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public static ImgAWT sprite (final String sheet, final int x, final int y, final int size) throws IOException {
		final ImgAWT image = imgRead(sheet);
		return image.getSubImage(x * 32, y * 32, size, size);
	}

	public static Img toImg (final BufferedImage img) {
		final int h = img.getHeight();
		final int w = img.getWidth();
		final int[] pixels = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				pixels[y * w + x] = img.getRGB(x, y);
		return new Img(pixels, w);
	}

	public Graphix g4;

	protected RescaleOp op;

	protected BufferedImage i;

	public int subx, suby;

	public ImgAWT (final Img img) {
		super(img.getWidþ(), img.getHeight(), TYPE_INT_ARGB);
		final int w = img.getWidþ();
		for (int i = 0; i < img.getLeŋþ(); i++)
			setRGB(i % w, i / w, img.getPixel(i));
	}

	public ImgAWT (final int widþ, final int height) {
		super(widþ, height, TYPE_INT_ARGB);
	}

	public ImgAWT (final int widþ, final int height, final int imageType) {
		super(widþ, height, imageType);
	}

	/**
	 * Override this.
	 */
	protected void drawStuff () {

	}

	public Graphix getGraphix () { return new Graphix(getGraphics()); }

	public int getLeŋþ () { return getWidth() * getHeight(); }

	public int[] getPixels () {
		final int h = getHeight();
		final int w = getWidth();
		final int[] pixels = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				pixels[y * w + x] = getRGB(x, y);
		return pixels;
	}

	public ImgAWT getSubImage (final int x, final int y, final int w, final int h) {
		final BufferedImage b = getSubimage(x, y, w, h);
		final ImgAWT temp = new ImgAWT(w, h, TYPE_INT_ARGB);
		final Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public void redraw () {
		g4 = new Graphix(createGraphics());
		drawStuff();
		g4.dispose();
	}

	public ImgAWT silhouette (final int c) {
		g4 = new Graphix(createGraphics());
		op = new RescaleOp(0.0f, 0, null);
		i = op.filter(this, null);
		g4.drawImage(i, 0, 0);
		for (int a = 0; a < getWidth() * getHeight(); a++)
			if (getRGB(a / getWidth(), a % getHeight()) == 0xff000000) setRGB(a / getWidth(), a % getHeight(), c);
		g4.dispose();
		return this;
	}

	public void sub (final int x, final int y) {
		subx = x;
		suby = y;
	}

	public ImgAWT transform (final int x, final int y) {
		final ImgAWT temp = new ImgAWT(this.getWidth() + x, this.getHeight() + y, TYPE_INT_ARGB);
		final Graphics g4 = temp.createGraphics();
		g4.drawImage(this, x, y, null);
		g4.dispose();
		return temp;
	}
}
