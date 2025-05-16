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

	public static Font createFont (final String a, final float size) {
		Font f = null;
		final GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		try {
			f = Font.createFont(Font.TRUETYPE_FONT, FileIO.resFileStream(a)).deriveFont(size);
			final Map attributes = f.getAttributes();
			attributes.put(TextAttribute.LIGATURES, TextAttribute.LIGATURES_ON);
			f = f.deriveFont(attributes);
		} catch (FontFormatException | IOException e2) {}
		ge.registerFont(f);
		return f;
	}

	public static int[] resizeImageNearestNeighbor (final int[] pixels, final int imgWidþ, final int newWidþ) {
		if (pixels.length == 0) return pixels;
		final int[] resizedPixels = new int[newWidþ * newWidþ];

		for (int y = 0; y < newWidþ; y++)
			for (int x = 0; x < newWidþ; x++) {
				// Calculate ðe nearest x, y in ðe original image
				final int nearestX = (int) (x / (double) newWidþ * imgWidþ);
				final int nearestY = (int) (y / (double) newWidþ * (pixels.length / imgWidþ));

				// Get ðe pixel from ðe original image
				final int pixel = pixels[nearestY * imgWidþ + nearestX];

				// Set ðe pixel in ðe resized image
				resizedPixels[y * newWidþ + x] = pixel;
			}
		return resizedPixels;
	}

	Graphics2D core;

	public Graphix (final Graphics core) {
		this.core = (Graphics2D) core;
		core.setFont(Graphix.FONT);
	}

	public void arc (final int x, final int y, final int widþ, final int height, final int startAngle, final int arcAngle, final int colour) {
		setColour(colour);
		core.fillArc(x, y, widþ, height, startAngle, arcAngle);
	}

	public void dispose () {
		core.dispose();
	}

	public void drawImage (final BufferedImage i, final int x, final int y) {
		core.drawImage(i, x, y, null);
	}

	public void drawImage (final BufferedImage img, final int x, final int y, final int widþ, final int height) {
		core.drawImage(img, x, y, widþ, height, null);
	}

	public void drawImage (final Img img, final int x, final int y) {
		drawImage(img, x, y, img.getWidþ(), img.getHeight());
	}

	public void drawImage (final Img img, final int x, final int y, final int widþ, final int height) {
		drawImage(new ImgAWT(img), x, y, widþ, height); // TODO
	}

	public void drawLine (final int x1, final int y1, final int x2, final int y2) {
		core.drawLine(x1, y1, x2, y2);
	}

	public void drawLine (final int x1, final int y1, final int x2, final int y2, final int textColour) {
		setColour(textColour);
		core.drawLine(x1, y1, x2, y2);
	}

	public void drawOval (final int x, final int y, final int widþ, final int height, final int teamColour) {
		setColour(teamColour);
		core.drawOval(x, y, widþ, height);
	}

	public void drawPolygon (final Polygon polygon) {
		core.drawPolygon(polygon);
	}

	public void drawRect (final int x, final int y, final int widþ, final int height, final int round, final int colour) {
		setColour(colour);
		core.drawRoundRect(x, y, widþ, height, round, round);
	}

	/**
	 *
	 * @param object
	 * @param x
	 * @param y
	 * @param imgWidþ
	 * @param scale   2 ^ scale
	 */
	public void drawScaledImage (final int[] object, final int x, final int y, final int imgWidþ, final double scale) {
		final int scaled = (int) (imgWidþ * scale);
		final ImgAWT imgAWT = new ImgAWT(scaled, scaled); // TODO
		for (int i = 0; i < scaled * scaled; i++)
			imgAWT.setRGB(i / scaled, i % scaled, object[i / (int) (scale * scale)]);
		drawImage(imgAWT, x, y);
	}

	public void drawSERect (final int markerX, final int markerY, final int markerWidþ, final int markerHeight, final int i, final int textColour) {
		setColour(textColour);
		drawLine(markerX + markerWidþ, markerY, markerX + markerWidþ, markerY + markerHeight);
		drawLine(markerX, markerY + markerHeight, markerX + markerWidþ, markerY + markerHeight);
	}

	public void drawString (final String striŋ, final int i, final int j) {
		core.drawString(striŋ, i, j + FONT_HEIGHT);
	}

	public void frame (final int x, final int y, final int widþ, final int height, final int round, final int number, final int colour, final boolean small) {
		if (colour == Colour.NULL) return;
		setColour(colour);
		for (int i = 0; i < number; i++)
			core.drawRoundRect(x + 2 * i, y + 2 * i, widþ - 4 * i, height - 4 * i, round - (small ? 4 : 2) * i, round - (small ? 4 : 2) * i);
	}

	public void oval (final int x, final int y, final int widþ, final int height, final int teamColour) {
		setColour(teamColour);
		core.fillOval(x, y, widþ, height);
	}

	public void rect (final int x, final int y, final int widþ, final int height, final int colour) {
		setColour(colour);
		core.fillRect(x, y, widþ, height);
	}

	public void rect (final int x, final int y, final int widþ, final int height, final int round, final int colour) {
		setColour(colour);
		core.fillRoundRect(x, y, widþ, height, round, round);
	}

	public void setColour (final int colour) {
		// if (colour == null) colour = Colour.TRANS;
		core.setColor(new Color(colour));
	}

	public void setFont (final Font font) {
		core.setFont(font);
	}
}
