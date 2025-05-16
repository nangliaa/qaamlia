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

import java.awt.HeadlessException;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import org.nangliaa.extra.Img;

public class Special {
	private static class ImageSelection implements Transferable {
		private final BufferedImage image;

		public ImageSelection (final BufferedImage image) {
			this.image = image;
		}

		@Override
		public Object getTransferData (final DataFlavor flavour) throws UnsupportedFlavorException {
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
		public boolean isDataFlavorSupported (final DataFlavor flavour) {
			return DataFlavor.imageFlavor.equals(flavour);
		}
	}

	public static char fileSeparator = File.separatorChar;

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
	public static String getClipboardStriŋ () {
		try {
			return (String) Toolkit.getDefaultToolkit().getSystemClipboard().getData(DataFlavor.stringFlavor);
		} catch (HeadlessException | UnsupportedFlavorException | IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		return null;
	}

	public static boolean isClipboardImg () { return Toolkit.getDefaultToolkit().getSystemClipboard().isDataFlavorAvailable(DataFlavor.imageFlavor); }

	public static boolean isClipboardStriŋ () { return Toolkit.getDefaultToolkit().getSystemClipboard().isDataFlavorAvailable(DataFlavor.stringFlavor); }

	public static void setClipboard (final Img img) {
		final Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
		clipboard.setContents(new ImageSelection(ImgAWT.getBufferedImage(img)), null);
	}

	public static void setClipboard (final String str) {
		final Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
		clipboard.setContents(new StringSelection(str), null);
	}

	public static String[] split (final String str, final String delimiter, final int limit) {
		return str.split(delimiter, limit);
	}
}
