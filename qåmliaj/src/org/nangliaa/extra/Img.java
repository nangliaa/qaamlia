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

package org.nangliaa.extra;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static org.nangliaa.extra.Colour.TRANS;
import static org.nangliaa.extra.Extra.clamp;
import static org.nangliaa.extra.Extra.inBounds;

import java.util.Arrays;

import org.nangliaa.desktop.ExtendedCanvas;

public class Img {
	public static final int OCTA61 = 1, RECT = 2;
	int[] pixels;
	int widþ;

	public Img (final int widþ, final int height) {
		pixels = new int[widþ * height];
		this.widþ = widþ;
	}

	public Img (final int widþ, final int height, final int šape, final int colour) {
		pixels = new int[widþ * height];
		this.widþ = widþ;
		switch (šape) {
			case OCTA61:
				final int beginY = height / 6 - 1;
				for (int y = 0; y < height; y++) {
					int begin = 0;
					if (y < beginY) begin = beginY - y;
					else if (y > height - beginY) begin = beginY - (height - y - 1);
					for (int x = begin; x < widþ - begin; x++)
						pixels[y * widþ + x] = colour;
				}
				break;
			case RECT:
				Arrays.fill(pixels, colour);
				break;
		}
	}

	public Img (final int[] pixels, final int widþ) {
		this.pixels = pixels;
		this.widþ = widþ;
	}

	public void add (final Img img, final int x, final int y) {
		for (int q = 0; q < img.getLeŋþ() / img.widþ; q++)
			for (int p = 0; p < img.widþ; p++)
				if (inBounds(p + x, q + y, 0, 0, widþ, pixels.length / widþ) && img.getPixel(p, q) != TRANS) setPixel(p + x, q + y, img.getPixel(p, q));
	}

	public void arc (final int x, final int y, final int i, final int j, final int angle, final int nan, final int colour) {

	}

	public void drawImage (final Img img, final int i, final int j) {
		if (!inBounds(i, j, 0, 0, widþ, getHeight()) || img == null) return;
		final int w = min(widþ - 1, i + img.getWidþ()) - i;
		final int h = min(getHeight() - 1, j + img.getHeight()) - j;
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				final int c = img.pixels[y * img.widþ + x];
				if (c != TRANS) pixels[(y + j) * widþ + x + i] = c;
			}
	}

	public void drawImage (final Img fatima, final int i, final int j, final int w, final int h) {

	}

	public void drawLine (final int x1, final int y1, final int x2, final int y2, final int colour) {
		// TODO DIAGONAL LINES
		final int p1 = min(clamp(x1, 0, widþ - 1), clamp(x2, 0, widþ - 1));
		final int p2 = max(clamp(x1, 0, widþ - 1), clamp(x2, 0, widþ - 1));
		final int q1 = min(clamp(y1, 0, getHeight() - 1), clamp(y2, 0, getHeight() - 1));
		final int q2 = max(clamp(y1, 0, getHeight() - 1), clamp(y2, 0, getHeight() - 1));
		if (p1 == p2) for (int i = q1; i < q2; i++)
			pixels[i * widþ + p1] = colour;
		else if (q1 == q2) for (int i = p1; i < p2; i++)
			pixels[q1 * widþ + i] = colour;
		else System.err.println("Can only draw orþogonal lines now!!");
	}

	public void drawRect (final int x, final int y, final int w, final int h, final int round, final int colour) {
		final int p1 = clamp(x, 0, widþ - 1);
		final int p2 = clamp(x + w - 1, 0, widþ - 1);
		final int q1 = clamp(y, 0, getHeight() - 1);
		final int q2 = clamp(y + h - 1, 0, getHeight() - 1);
		for (int p = p1; p < p2; p++) {
			pixels[q1 * widþ + p] = colour;
			pixels[q2 * widþ + p] = colour;
		}
		for (int q = q1; q < q2; q++) {
			pixels[q * widþ + p1] = colour;
			pixels[q * widþ + p2] = colour;
		}
	}

	public void drawSERect (final int x, final int y, final int w, final int h, final int round, final int colour) {
		drawLine(x + w, y, x + w, y + h, colour);
		drawLine(x, y + h, x + w, y + h, colour);
	}

	public void drawString (final String text, final int i, final int j, final int colour) {
		if (text.length() == 0) return;
		drawImage(ExtendedCanvas.drawString(text, colour, 16f), i, j - 4); // TODO
	}

	public void drawString (final String text, final int i, final int j, final int colour, final float size) {
		if (text.length() == 0) return;
		drawImage(ExtendedCanvas.drawString(text, colour, size), i, j - 4); // TODO
	}

	public void fill (final int colour) {
		Arrays.fill(pixels, colour);
	}

	public void frame (int x, int y, int w, int h, final int round, final int noOfFrames, final int frameColour, final boolean small) {
		// TODO ROUND
		for (int i = 0; i < noOfFrames; i++) {
			drawRect(x, y, w, h, round, frameColour);
			w -= 4;
			h -= 4;
			x += 2;
			y += 2;
		}
	}

	public void framedRect (final int x, final int y, final int w, final int h, final int round, final int frameNo, final int colour, final int frameColour) {
		// TODO
		rect(x, y, w, h, round, colour);
		frame(x, y, w, h, round, frameNo, frameColour, false);
	}

	public int getHeight () { return pixels.length / widþ; }

	public int getLeŋþ () { return pixels.length; }

	public int getPixel (final int i) {
		return pixels[i];
	}

	public int getPixel (final int x, final int y) {
		if (!inBounds(x, y, 0, 0, widþ, getHeight())) {
			System.err.println("Img.getPixel() not in bounds");
			return TRANS;
		}
		return pixels[y * widþ + x];
	}

	public int[] getPixels () { return pixels; }

	public int getRGB (final int x, final int y) {
		return getPixel(x, y);
	}

	public Img getSubImage (final int i, final int j, final int w, int h) {
		if (!inBounds(i, j, 0, 0, widþ, getHeight()) || w < 0 || h < 0) return null;
		final int nw = min(widþ - 1, i + w) - i;
		h = min(getHeight() - 1, j + h) - j;
		final int[] np = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < nw; x++)
				np[y * w + x] = pixels[(j + y) * widþ + i + x];
		return new Img(np, w);
	}

	public int getWidþ () { return widþ; }

	public void rect (final int x, final int y, int w, int h, final int round, final int backgroundColour) {
		// TODO ROUND
		if (!inBounds(x, y, 0, 0, widþ, getHeight())) return;
		w = min(widþ - 1, x + w) - x;
		h = min(getHeight() - 1, y + h) - y;
		for (int q = 0; q < h; q++)
			for (int p = 0; p < w; p++)
				pixels[(y + q) * widþ + x + p] = backgroundColour;
	}

	public void setPixel (final int i, final int value) {
		pixels[i] = value;
	}

	public void setPixel (final int x, final int y, final int value) {
		if (!inBounds(x, y, 0, 0, widþ, getHeight())) System.err.println("Img.setPixel() not in bounds");
		else pixels[y * widþ + x] = value;
	}
}
