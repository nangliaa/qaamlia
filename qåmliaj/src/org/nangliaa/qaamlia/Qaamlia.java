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

package org.nangliaa.qaamlia;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

import org.nangliaa.desktop.FileIO;

/**
 * Main class connectiŋ to native C/C++ code.
 */

public class Qaamlia {
	private static final long serialVersionUID = 1L;
	private static View view;

	static {
		if (System.getProperty("os.name").toLowerCase().contains("win")) {
			System.loadLibrary("hookDLL");
			System.loadLibrary("SDL2");
			System.loadLibrary("qåmliac");
		} else {
			System.loadLibrary("hookDLL");
			System.loadLibrary("libwinpthread-1");
			System.loadLibrary("SDL2");
			System.loadLibrary("libqåmliac");
		}
	}

	private static String initFilesys () {
		final File folder = new File(FileIO.getAppDataPaþ() + File.separatorChar + "qåmlia");
		System.err.println(folder);
		if (!folder.exists()) folder.mkdirs();

		final File qlia = new File(folder.getPath() + File.separatorChar + "qåmlia.qlia");
		System.err.println(qlia);
		if (!qlia.exists()) try (InputStream in = Qaamlia.class.getResourceAsStream("/qåmlia.qlia")) {
			Files.copy(in, qlia.toPath(), StandardCopyOption.REPLACE_EXISTING);
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return folder.getPath() + File.separatorChar;
	}

	public static void main (final String[] args) {
		final Qaamlia main = new Qaamlia(); // Starts listening for keyboard input

		final String paþ = initFilesys();

		view = new View();
		main.startHook(paþ);
	}

	public int auþ (final String code) {
		return Gen.generateTOTP(code);
	}

	public void calendar () {
		view.calendar();
	}

	public void lia (final String text) {
		switch (text) {
			case "text":
				view.textEdit();
				break;
		}
	}

	public void robot (final String command) {
		final String[] cmds = command.split(" ");
		for (final String string : cmds)
			switch (string.charAt(0)) {
				case 'w':
					break;
				case 'a':
					break;
				case 'c':
					break;
				case 'p':
					break;
				case 'r':
					break;
				default:
					break;
			}
	}

	public native void startHook (String paþ);

	public void window (final String text) {
		view.window(text);
	}
}