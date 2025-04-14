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

import static org.nangliaa.extra.Extra.shorten;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Read/Write any file (Full path required)
 *
 * @author Johannah Granström
 *
 */

public class ComIO {

	public static String[] getRowsFromFile (String file, int start) {
		String content;
		try {
			content = new String(Files.readAllBytes(Paths.get(file)), StandardCharsets.UTF_8);
			return shorten(content.split("\r\n", -1), start);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * Returns a String[x][y] for csv or similar
	 *
	 * @param file
	 * @param split
	 * @param start
	 * @return
	 */

	public static String[][] getStringsXYFromFile (String file, String split) {
		String content;
		try {
			content = new String(Files.readAllBytes(Paths.get(file)), StandardCharsets.UTF_8);
			String[] rows = content.split("\r\n", -1);
			String[][] all = new String[rows.length][];
			for (int i = 0; i < rows.length; i++)
				all[i] = rows[i].split(split, -1);
			String[][] xy = new String[all[0].length][all.length];
			for (int x = 0; x < all[0].length; x++)
				for (int y = 0; y < all.length; y++)
					xy[x][y] = all[y][x];
			return xy;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static String readFile (String file) {
		try {
			return new String(Files.readAllBytes(Paths.get(file)), StandardCharsets.UTF_8);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static void writeFile (String file, byte[] msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream(file));) {
			outputStream.write(msg);
			outputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void writeFile (String file, String msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream(file));) {
			outputStream.write(msg.getBytes(StandardCharsets.UTF_8));
			outputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
