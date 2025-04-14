/* =============================================================================================
	Qåmlia - a program for doing stuff usiŋ only normal keypresses from anywhere.
	Copyright (C) 2025 Johannah Granström

	This program is free software: you can redistribute it and/or modify it under
	the terms of the GNU General Public License as published by the Free Software Foundation,
	either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

package org.nangliaa.desktop;

import static org.nangliaa.extra.Extra.FONT_HEIGHT;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontFormatException;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.Polygon;
import java.awt.font.TextAttribute;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Map;

import org.nangliaa.extra.Colour;
import org.nangliaa.extra.Img;

public class Graphix {
	public static final Font FONT2 = createFont("židlia.ttf", 32f);
	public static final Font FONT = createFont("židlia.ttf", 16f);

	public static Font createFont (String a, float size) {
		Font f = null;
		GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		try {
			f = Font.createFont(Font.TRUETYPE_FONT, Special.resFileStream(a)).deriveFont(size);
			Map attributes = f.getAttributes();
			attributes.put(TextAttribute.LIGATURES, TextAttribute.LIGATURES_ON);
			f = f.deriveFont(attributes);
		} catch (FontFormatException | IOException e2) {}
		ge.registerFont(f);
		return f;
	}

	public static int[] resizeImageNearestNeighbor (int[] pixels, int imgWidth, int newWidth) {
		if (pixels.length == 0) return pixels;
		int[] resizedPixels = new int[newWidth * newWidth];

		for (int y = 0; y < newWidth; y++)
			for (int x = 0; x < newWidth; x++) {
				// Calculate the nearest x, y in the original image
				int nearestX = (int) (x / (double) newWidth * imgWidth);
				int nearestY = (int) (y / (double) newWidth * (pixels.length / imgWidth));

				// Get the pixel from the original image
				int pixel = pixels[nearestY * imgWidth + nearestX];

				// Set the pixel in the resized image
				resizedPixels[y * newWidth + x] = pixel;
			}
		return resizedPixels;
	}

	Graphics2D core;

	public Graphix (Graphics core) {
		this.core = (Graphics2D) core;
		core.setFont(Graphix.FONT);
	}

	public void arc (int x, int y, int width, int height, int startAngle, int arcAngle, int colour) {
		setColour(colour);
		core.fillArc(x, y, width, height, startAngle, arcAngle);
	}

	public void dispose () {
		core.dispose();
	}

	public void drawImage (BufferedImage i, int x, int y) {
		core.drawImage(i, x, y, null);
	}

	public void drawImage (BufferedImage img, int x, int y, int width, int height) {
		core.drawImage(img, x, y, width, height, null);
	}

	public void drawImage (Img img, int x, int y) {
		drawImage(img, x, y, img.getWidth(), img.getHeight());
	}

	public void drawImage (Img img, int x, int y, int width, int height) {
		drawImage(new ImgAWT(img), x, y, width, height); // TODO
	}

	public void drawLine (int x1, int y1, int x2, int y2) {
		core.drawLine(x1, y1, x2, y2);
	}

	public void drawLine (int x1, int y1, int x2, int y2, int textColour) {
		setColour(textColour);
		core.drawLine(x1, y1, x2, y2);
	}

	public void drawOval (int x, int y, int width, int height, int teamColour) {
		setColour(teamColour);
		core.drawOval(x, y, width, height);
	}

	public void drawPolygon (Polygon polygon) {
		core.drawPolygon(polygon);
	}

	public void drawRect (int x, int y, int width, int height, int round, int colour) {
		setColour(colour);
		core.drawRoundRect(x, y, width, height, round, round);
	}

	/**
	 *
	 * @param object
	 * @param x
	 * @param y
	 * @param imgWidth
	 * @param scale    2 ^ scale
	 */

	public void drawScaledImage (int[] object, int x, int y, int imgWidth, double scale) {
		int scaled = (int) (imgWidth * scale);
		ImgAWT imgAWT = new ImgAWT(scaled, scaled); // TODO
		for (int i = 0; i < scaled * scaled; i++)
			imgAWT.setRGB(i / scaled, i % scaled, object[i / (int) (scale * scale)]);
		drawImage(imgAWT, x, y);
	}

	public void drawSERect (int markerX, int markerY, int markerWidth, int markerHeight, int i, int textColour) {
		setColour(textColour);
		drawLine(markerX + markerWidth, markerY, markerX + markerWidth, markerY + markerHeight);
		drawLine(markerX, markerY + markerHeight, markerX + markerWidth, markerY + markerHeight);
	}

	public void drawString (String string, int i, int j) {
		core.drawString(string, i, j + FONT_HEIGHT);
	}

	public void frame (int x, int y, int width, int height, int round, int number, int colour, boolean small) {
		if (colour == Colour.NULL) return;
		setColour(colour);
		for (int i = 0; i < number; i++)
			core.drawRoundRect(x + 2 * i, y + 2 * i, width - 4 * i, height - 4 * i, round - (small ? 4 : 2) * i, round - (small ? 4 : 2) * i);
	}

	public void oval (int x, int y, int width, int height, int teamColour) {
		setColour(teamColour);
		core.fillOval(x, y, width, height);
	}

	public void rect (int x, int y, int width, int height, int colour) {
		setColour(colour);
		core.fillRect(x, y, width, height);
	}

	public void rect (int x, int y, int width, int height, int round, int colour) {
		setColour(colour);
		core.fillRoundRect(x, y, width, height, round, round);
	}

	public void setColour (int colour) {
		// if (colour == null) colour = Colour.TRANS;
		core.setColor(new Color(colour));
	}

	public void setFont (Font font) {
		core.setFont(font);
	}
}
