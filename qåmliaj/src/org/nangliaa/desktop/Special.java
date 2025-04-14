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

import java.awt.HeadlessException;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

import org.nangliaa.extra.Img;

public class Special {
	private static class ImageSelection implements Transferable {
		private final BufferedImage image;

		public ImageSelection (BufferedImage image) {
			this.image = image;
		}

		@Override
		public Object getTransferData (DataFlavor flavour) throws UnsupportedFlavorException {
			if (!isDataFlavorSupported(flavour)) throw new UnsupportedFlavorException(flavour);
			return image;
		}

		@Override
		public DataFlavor[] getTransferDataFlavors () {
			return new DataFlavor[] {
					DataFlavor.imageFlavor
			};
		}

		@Override
		public boolean isDataFlavorSupported (DataFlavor flavour) {
			return DataFlavor.imageFlavor.equals(flavour);
		}
	}

	public static Img getClipboardImg () {
		try {
			return ImgAWT.toImg((BufferedImage) Toolkit.getDefaultToolkit().getSystemClipboard().getData(DataFlavor.imageFlavor));
		} catch (HeadlessException | UnsupportedFlavorException | IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * Exits on failure.
	 *
	 * @return
	 */
	public static String getClipboardString () {
		try {
			return (String) Toolkit.getDefaultToolkit().getSystemClipboard().getData(DataFlavor.stringFlavor);
		} catch (HeadlessException | UnsupportedFlavorException | IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		return null;
	}

	public static boolean isClipboardImg () { return Toolkit.getDefaultToolkit().getSystemClipboard().isDataFlavorAvailable(DataFlavor.imageFlavor); }

	public static boolean isClipboardString () { return Toolkit.getDefaultToolkit().getSystemClipboard().isDataFlavorAvailable(DataFlavor.stringFlavor); }

	public static byte[] readRes (String file) {
		ClassLoader classLoader = Special.class.getClassLoader();
		InputStream inputStream = classLoader.getResourceAsStream(file);

		if (inputStream == null) throw new IllegalArgumentException("File " + file + " not found!");
		try {
			return inputStream.readAllBytes();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static InputStream resFileStream (String file) {
		ClassLoader classLoader = Special.class.getClassLoader();
		InputStream inputStream = classLoader.getResourceAsStream(file);

		if (inputStream == null) throw new IllegalArgumentException("File " + file + " not found!");
		return inputStream;
	}

	public static void setClipboard (Img img) {
		Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
		clipboard.setContents(new ImageSelection(ImgAWT.getBufferedImage(img)), null);
	}

	public static void setClipboard (String string) {
		Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
		clipboard.setContents(new StringSelection(string), null);
	}

	public static String[] split (String str, String delimiter, int limit) {
		return str.split(delimiter, limit);
	}

	/**
	 * Writes binary to the resources folder.
	 *
	 * @param file
	 * @param msg
	 */

	public static void writeRes (String file, byte[] msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream("resources\\" + file));) {
			outputStream.write(msg);
			outputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Writes to the resources folder.
	 *
	 * @param file
	 * @param msg
	 */

	public static void writeRes (String file, String msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream("resources\\" + file));) {
			outputStream.write(msg.getBytes(StandardCharsets.UTF_8));
			outputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
