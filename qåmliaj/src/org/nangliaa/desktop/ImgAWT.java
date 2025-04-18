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

package org.nangliaa.desktop;

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

/**
 * An extension of java.awt.Image, for use when platform independent Img doesn't work.
 */
public class ImgAWT extends BufferedImage {
	public static double calculateArea (Polygon p) {
		double area = 0.0;

		for (int i = 0; i < p.npoints; i++) {
			int j = (i + 1) % p.npoints;
			area += p.xpoints[i] * p.ypoints[j];
			area -= p.xpoints[j] * p.ypoints[i];
		}

		area /= 2.0;
		return Math.abs(area);
	}

	public static Img drawString (String text, int colour, float size) {
		ImgAWT bufAwt = new ImgAWT(text.length() * FONT_WIDÞ, MAX_FONT_HEIGHT);
		Graphics2D g = bufAwt.createGraphics();
		g.setFont(size == 16f ? Graphix.FONT : Graphix.FONT2);
		g.setColor(new Color(colour));
		g.drawString(text, 0, 12); // TODO
		g.dispose();
		return toImg(bufAwt);
	}

	public static ImgAWT getBufferedImage (Img img) {
		int h = img.getHeight();
		int w = img.getWidth();
		ImgAWT awt = new ImgAWT(w, h);
		awt.setRGB(0, 0, w, h, img.getPixels(), 0, w);
		return awt;
	}

	public static BufferedImage getImageFromFile (String file) {
		try {
			return ImageIO.read(Special.resFileStream(file));
		} catch (IOException e) {
			System.err.println("Img.imgRead: File does not exist.");
		}
		return null;
	}

	public static ImgAWT imgRead (String url) {
		BufferedImage b = null;
		try {
			b = ImageIO.read(new File(url));
		} catch (IOException e) {
			System.err.println("Img.imgRead: File does not exist. " + url);
		}
		ImgAWT temp = new ImgAWT(b.getWidth(), b.getHeight(), TYPE_INT_ARGB);
		Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public static ImgAWT loadRes (String url) {
		BufferedImage b = getImageFromFile(url);
		ImgAWT temp = new ImgAWT(b.getWidth(), b.getHeight(), TYPE_INT_ARGB);
		Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public static ImgAWT sprite (String sheet, int x, int y, int size) throws IOException {
		ImgAWT image = imgRead(sheet);
		return image.getSubImage(x * 32, y * 32, size, size);
	}

	public static Img toImg (BufferedImage img) {
		int h = img.getHeight();
		int w = img.getWidth();
		int[] pixels = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				pixels[y * w + x] = img.getRGB(x, y);
		return new Img(pixels, w);
	}

	public Graphix g4;

	protected RescaleOp op;

	protected BufferedImage i;

	public int subx, suby;

	public ImgAWT (Img img) {
		super(img.getWidth(), img.getHeight(), TYPE_INT_ARGB);
		int w = img.getWidth();
		for (int i = 0; i < img.getLength(); i++)
			setRGB(i % w, i / w, img.getPixel(i));
	}

	public ImgAWT (int width, int height) {
		super(width, height, TYPE_INT_ARGB);
	}

	public ImgAWT (int width, int height, int imageType) {
		super(width, height, imageType);
	}

	/**
	 * Override this.
	 */
	protected void drawStuff () {

	}

	public Graphix getGraphix () { return new Graphix(getGraphics()); }

	public int getLength () { return getWidth() * getHeight(); }

	public int[] getPixels () {
		int h = getHeight();
		int w = getWidth();
		int[] pixels = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				pixels[y * w + x] = getRGB(x, y);
		return pixels;
	}

	public ImgAWT getSubImage (int x, int y, int w, int h) {
		BufferedImage b = getSubimage(x, y, w, h);
		ImgAWT temp = new ImgAWT(w, h, TYPE_INT_ARGB);
		Graphics g4 = temp.createGraphics();
		g4.drawImage(b, 0, 0, null);
		g4.dispose();
		return temp;
	}

	public void redraw () {
		g4 = new Graphix(createGraphics());
		drawStuff();
		g4.dispose();
	}

	public ImgAWT silhouette (int c) {
		g4 = new Graphix(createGraphics());
		op = new RescaleOp(0.0f, 0, null);
		i = op.filter(this, null);
		g4.drawImage(i, 0, 0);
		for (int a = 0; a < getWidth() * getHeight(); a++)
			if (getRGB(a / getWidth(), a % getHeight()) == 0xff000000) setRGB(a / getWidth(), a % getHeight(), c);
		g4.dispose();
		return this;
	}

	public void sub (int x, int y) {
		subx = x;
		suby = y;
	}

	public ImgAWT transform (int x, int y) {
		ImgAWT temp = new ImgAWT(this.getWidth() + x, this.getHeight() + y, TYPE_INT_ARGB);
		Graphics g4 = temp.createGraphics();
		g4.drawImage(this, x, y, null);
		g4.dispose();
		return temp;
	}
}
