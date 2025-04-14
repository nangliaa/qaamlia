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

package org.nangliaa.qaamlia;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

/**
 * Main class connectiŋ to native C/C++ code.m
 */
public class Qaamlia {
	private static final long serialVersionUID = 1L;
	private static View view;
	private static String os = System.getProperty("os.name").toLowerCase();

	static {
		System.loadLibrary("hookDLL");
		System.loadLibrary("libwinpthread-1");
		System.loadLibrary("SDL2");
		System.loadLibrary("libqåmliac");
	}

	private static String getAppDataPaþ () {
		if (os.contains("win")) {
			String appData = System.getenv("APPDATA");
			return appData + "\\Naŋliå\\qåmlia";
		}
		if (os.contains("mac")) return System.getProperty("user.home") + "/Library/Application Support/Naŋliå/qåmlia";
		return System.getProperty("user.home") + "/.local/share/Naŋliå/qåmlia";
	}

	private static String initFilesys () {
		File folder = new File(getAppDataPaþ());
		System.err.println(folder);
		if (!folder.exists()) folder.mkdirs();

		File qlia = new File(folder.getPath() + File.separatorChar + "qåmlia.qlia");
		System.err.println(qlia);
		if (!qlia.exists()) try (InputStream in = Qaamlia.class.getResourceAsStream("/qåmlia.qlia")) {
			Files.copy(in, qlia.toPath(), StandardCopyOption.REPLACE_EXISTING);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return folder.getPath() + File.separatorChar;
	}

	public static void main (String[] args) {
		Qaamlia main = new Qaamlia(); // Starts listening for keyboard input

		String paþ = initFilesys();

		view = new View();
		main.startHook(paþ);
	}

	public int auth (String code) {
		return Gen.generateTOTP(code);
	}

	public void calendar () {
		view.calendar();
	}

	public void lia (String text) {
		switch (text) {
			case "text":
				view.textEdit();
				break;
		}
	}

	public void robot (String command) {
		String[] cmds = command.split(" ");
		for (String string : cmds)
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

	public void window (String text) {
		view.window(text);
	}
}