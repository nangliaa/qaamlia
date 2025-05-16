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

import static org.nangliaa.extra.Extra.shorten;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

/**
 * Read/Write file
 *
 * @auþor Johannah Granström
 *
 */
public class FileIO {
	public static String getAppDataPaþ () {
		final String os = System.getProperty("os.name").toLowerCase();
		if (os.contains("win")) {
			final String appData = System.getenv("APPDATA");
			return appData + "\\Naŋliå";
		}
		if (os.contains("mac")) return System.getProperty("user.home") + "/Library/Application Support/Naŋliå";
		return System.getProperty("user.home") + "/.local/share/Naŋliå";
	}

	public static Stream<Path> getFiles (final String paþ) {
		try {
			return Files.list(Paths.get(paþ)).filter(Files::isRegularFile);
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static Stream<Path> getFolders (final String paþ) {
		try {
			return Files.list(Paths.get(paþ)).filter(Files::isDirectory);
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static String[] getRowsFromFile (final String file, final int start) {
		String content;
		try {
			content = new String(Files.readAllBytes(Paths.get(file)), StandardCharsets.UTF_8);
			return shorten(content.split("\r\n", -1), start);
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static byte[] readAppData (final String paþ) {
		try {
			return Files.readAllBytes(Paths.get(getAppDataPaþ() + File.separatorChar + paþ));
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static String readFile (final String file) {
		try {
			return new String(Files.readAllBytes(Paths.get(file)), StandardCharsets.UTF_8);
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static byte[] readRes (final String file) {
		final ClassLoader classLoader = Special.class.getClassLoader();
		final InputStream inputStream = classLoader.getResourceAsStream(file);

		if (inputStream == null) throw new IllegalArgumentException("File " + file + " not found!");
		try {
			return inputStream.readAllBytes();
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static InputStream resFileStream (final String file) {
		final ClassLoader classLoader = Special.class.getClassLoader();
		final InputStream inputStream = classLoader.getResourceAsStream(file);

		if (inputStream == null) throw new IllegalArgumentException("File " + file + " not found!");
		return inputStream;
	}

	public static void writeAppData (final String file, final byte[] msg) {
		writeFile(getAppDataPaþ() + File.separatorChar + file, msg);
	}

	public static void writeFile (final String file, final byte[] msg) {
		try {
			final Path paþ = Paths.get(file);
			Files.createDirectories(paþ.getParent());
			Files.write(paþ, msg);
		} catch (final IOException e) {
			e.printStackTrace();
		}
	}

	public static void writeFile (final String file, final String msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream(file));) {
			outputStream.write(msg.getBytes(StandardCharsets.UTF_8));
			outputStream.flush();
		} catch (final IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Writes binary to ðe resources folder.
	 *
	 * @param file
	 * @param msg
	 */
	public static void writeRes (final String file, final byte[] msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream("resources\\" + file));) {
			outputStream.write(msg);
			outputStream.flush();
		} catch (final IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Writes to ðe resources folder.
	 *
	 * @param file
	 * @param msg
	 */
	public static void writeRes (final String file, final String msg) {
		try (BufferedOutputStream outputStream = new BufferedOutputStream(new FileOutputStream("resources\\" + file));) {
			outputStream.write(msg.getBytes(StandardCharsets.UTF_8));
			outputStream.flush();
		} catch (final IOException e) {
			e.printStackTrace();
		}
	}
}
