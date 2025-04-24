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

package org.nangliaa.extra;

import static org.nangliaa.extra.Colour.TRANS;
import static org.nangliaa.extra.Extra.clamp;
import static org.nangliaa.extra.Extra.inBounds;

import java.util.Arrays;

import org.nangliaa.desktop.ExtendedCanvas;

public class Img {
	public static final int OCTA61 = 1, RECT = 2;
	int[] pixels;
	int width;

	public Img (int width, int height) {
		pixels = new int[width * height];
		this.width = width;
	}

	public Img (int width, int height, int shape, int colour) {
		pixels = new int[width * height];
		this.width = width;
		switch (shape) {
			case OCTA61:
				int beginY = height / 6 - 1;
				for (int y = 0; y < height; y++) {
					int begin = 0;
					if (y < beginY) begin = beginY - y;
					else if (y > height - beginY) begin = beginY - (height - y - 1);
					for (int x = begin; x < width - begin; x++)
						pixels[y * width + x] = colour;
				}
				break;
			case RECT:
				Arrays.fill(pixels, colour);
				break;
		}
	}

	public Img (int[] pixels, int width) {
		this.pixels = pixels;
		this.width = width;
	}

	public void add (Img img, int x, int y) {
		for (int q = 0; q < img.getLength() / img.width; q++)
			for (int p = 0; p < img.width; p++)
				if (inBounds(p + x, q + y, 0, 0, width, pixels.length / width) && img.getPixel(p, q) != TRANS) setPixel(p + x, q + y, img.getPixel(p, q));
	}

	public void arc (int x, int y, int i, int j, int angle, int nan, int colour) {
		// TODO Auto-generated method stub

	}

	public void drawImage (Img img, int i, int j) {
		if (!inBounds(i, j, 0, 0, width, getHeight()) || img == null) return;
		int w = Math.min(width - 1, i + img.getWidth()) - i;
		int h = Math.min(getHeight() - 1, j + img.getHeight()) - j;
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				int c = img.pixels[y * img.width + x];
				if (c != TRANS) pixels[(y + j) * width + x + i] = c;
			}
	}

	public void drawImage (Img fatima, int i, int j, int w, int h) {
		// TODO Auto-generated method stub

	}

	public void drawLine (int x1, int y1, int x2, int y2, int colour) {
		// TODO DIAGONAL LINES
		int p1 = Math.min(clamp(x1, 0, width - 1), clamp(x2, 0, width - 1));
		int p2 = Math.max(clamp(x1, 0, width - 1), clamp(x2, 0, width - 1));
		int q1 = Math.min(clamp(y1, 0, getHeight() - 1), clamp(y2, 0, getHeight() - 1));
		int q2 = Math.max(clamp(y1, 0, getHeight() - 1), clamp(y2, 0, getHeight() - 1));
		if (p1 == p2) for (int i = q1; i < q2; i++)
			pixels[i * width + p1] = colour;
		else if (q1 == q2) for (int i = p1; i < p2; i++)
			pixels[q1 * width + i] = colour;
		else System.err.println("Can only draw orthogonal lines now!!");
	}

	public void drawRect (int x, int y, int w, int h, int round, int colour) {
		int p1 = clamp(x, 0, width - 1);
		int p2 = clamp(x + w - 1, 0, width - 1);
		int q1 = clamp(y, 0, getHeight() - 1);
		int q2 = clamp(y + h - 1, 0, getHeight() - 1);
		for (int p = p1; p < p2; p++) {
			pixels[q1 * width + p] = colour;
			pixels[q2 * width + p] = colour;
		}
		for (int q = q1; q < q2; q++) {
			pixels[q * width + p1] = colour;
			pixels[q * width + p2] = colour;
		}
	}

	public void drawSERect (int x, int y, int w, int h, int round, int colour) {
		drawLine(x + w, y, x + w, y + h, colour);
		drawLine(x, y + h, x + w, y + h, colour);
	}

	public void drawString (String text, int i, int j, int colour) {
		if (text.length() == 0) return;
		drawImage(ExtendedCanvas.drawString(text, colour, 16f), i, j - 4); // TODO
	}

	public void drawString (String text, int i, int j, int colour, float size) {
		if (text.length() == 0) return;
		drawImage(ExtendedCanvas.drawString(text, colour, size), i, j - 4); // TODO
	}

	public void fill (int colour) {
		Arrays.fill(pixels, colour);
	}

	public void frame (int x, int y, int w, int h, int round, int noOfFrames, int frameColour, boolean small) {
		// TODO ROUND
		for (int i = 0; i < noOfFrames; i++) {
			drawRect(x, y, w, h, round, frameColour);
			w -= 4;
			h -= 4;
			x += 2;
			y += 2;
		}
	}

	public void framedRect (int x, int y, int w, int h, int round, int frameNo, int colour, int frameColour) {
		// TODO
		rect(x, y, w, h, round, colour);
		frame(x, y, w, h, round, frameNo, frameColour, false);
	}

	public int getHeight () { return pixels.length / width; }

	public int getLength () { return pixels.length; }

	public int getPixel (int i) {
		return pixels[i];
	}

	public int getPixel (int x, int y) {
		if (!inBounds(x, y, 0, 0, width, getHeight())) {
			System.err.println("Img.getPixel() not in bounds");
			return TRANS;
		}
		return pixels[y * width + x];
	}

	public int[] getPixels () { return pixels; }

	public int getRGB (int x, int y) {
		return getPixel(x, y);
	}

	public Img getSubImage (int i, int j, int w, int h) {
		if (!inBounds(i, j, 0, 0, width, getHeight()) || w < 0 || h < 0) return null;
		int nw = Math.min(width - 1, i + w) - i;
		h = Math.min(getHeight() - 1, j + h) - j;
		int[] np = new int[w * h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < nw; x++)
				np[y * w + x] = pixels[(j + y) * width + i + x];
		return new Img(np, w);
//		return this;
	}

	public int getWidth () { return width; }

	public void rect (int x, int y, int w, int h, int round, int backgroundColour) {
		// TODO ROUND
		if (!inBounds(x, y, 0, 0, width, getHeight())) return;
		w = Math.min(width - 1, x + w) - x;
		h = Math.min(getHeight() - 1, y + h) - y;
		for (int q = 0; q < h; q++)
			for (int p = 0; p < w; p++)
				pixels[(y + q) * width + x + p] = backgroundColour;
	}

	public void setPixel (int i, int value) {
		pixels[i] = value;
	}

	public void setPixel (int x, int y, int value) {
		if (!inBounds(x, y, 0, 0, width, getHeight())) System.err.println("Img.setPixel() not in bounds");
		else pixels[y * width + x] = value;
	}
}
