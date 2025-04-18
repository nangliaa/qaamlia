/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as published by ðe Free Software Foundation,
	eiðer version 3 of ðe License, or (at your option) any later version.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÞOUT ANY WARRANTY;
	wiþout even ðe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You should have received a copy of ðe GNU General Public License
	aloŋ wiþ ðis program. If not, see <https://www.gnu.org/licenses/>.
============================================================================================= */

package org.nangliaa.extra;

import static java.lang.Math.max;
import static java.lang.Math.min;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Extra {
	public static final int FONT_WIDÞ = 8;
	public static final int FONT_HEIGHT = 8;
	public static final int MAX_FONT_HEIGHT = 16;
	public static final int ROW_HEIGHT = 17;
	public static final double HALF_WIDÞ = 3.5;
	public static final int HALF_WIDÞ_INT = 3;
	public static final int HALF_HEIGHT = 4;
	public static final String DASH = "-";
	public static final String EMPTY_STRING = "", ERROR_STRING = "ERROR";
	public static final byte[] EMPTY_BYTE_ARRAY = {};
	public static StringBuilder sb = new StringBuilder();

	public static final String nagolima = "nagolima";

	public static final String sv = "sv";

	public static final String en = "en";

	public static final String[] EMPTY_STRING_ARRAY = {};

	public static boolean anyInt (int[] k, int com) {
		for (int a : k)
			if (a == com) return true;
		return false;
	}

	public static int anyIntInt (int[] k, int com) {
		for (int a = 0; a < k.length; a++)
			if (k[a] == com) return a;
		return -1;
	}

	public static int bati (byte[] bytes) {
		int wht = 0;
		if (bytes.length > 4) throw new NumberFormatException();
		for (byte element : bytes)
			wht = wht << 8 | btui(element);
		return wht;
	}

	public static int[] batia (byte[] bytes) {
		int[] ints = new int[bytes.length / 4];
		for (int i = 0; i < ints.length; i++) {
			ints[i] = bytes[i * 4] << 24 & 0xff000000;
			ints[i] |= bytes[i * 4 + 1] << 16 & 0xff0000;
			ints[i] |= bytes[i * 4 + 2] << 8 & 0xff00;
			ints[i] |= bytes[i * 4 + 3] & 0xff;
		}
		return ints;
	}

	public static long batl (byte[] bytes) {
		long wht = 0;
		if (bytes.length > 8) throw new NumberFormatException();
		for (byte element : bytes)
			wht = wht << 8 | btul(element);
		return wht;
	}

	public static long batl (byte[] bytes, int index, int numberOfChars) {
		long wht = 0;
		if (numberOfChars > 8) throw new NumberFormatException();
		for (int i = index; i < index + numberOfChars; i++)
			wht = wht << 8 | btul(bytes[i]);
		return wht;
	}

	public static int btui (byte b) {
		return b & 0xff;
	}

	public static long btul (byte b) {
		return b & 0xffL;
	}

	public static int circleAround (int initialValue, int listLength, boolean increase) {
		if (increase) return initialValue + 1 >= listLength ? 0 : initialValue + 1;
		return initialValue - 1 < 0 ? listLength - 1 : initialValue - 1;
	}

	public static int clamp (int x, int min, int max) {
		return min(max(min, x), max);
	}

	/**
	 * Gives a string representation of a double in hex.
	 *
	 * @param d
	 * @return
	 */
	public static String dtxs (double d) {
		long intPart = (long) d;
		double fracPart = d - intPart;
		String hexIntPart = Long.toString(intPart, 16);

		while (fracPart != 0 && sb.length() < 16) {
			fracPart *= 16;
			int digit = (int) fracPart;
			sb.append(Integer.toString(digit, 16));
			fracPart -= digit;
		}

		String res = sb.length() > 0 ? (hexIntPart + "." + sb).toUpperCase() : hexIntPart.toUpperCase();
		sb.setLength(0);
		return res;
	}

	public static int[] extend (int[] a, int b) {
		int[] neu = Arrays.copyOf(a, a.length + 1);
		neu[a.length] = b;
		return neu;
	}

	public static <T> T[] extend (T[] a, T b) {
		T[] neu = Arrays.copyOf(a, a.length + 1);
		neu[a.length] = b;
		return neu;
	}

	public static List<? extends Nangliaa> filterByName (List<? extends Nangliaa> list, String string, boolean caseSensitive) {
		List<Nangliaa> ne = new ArrayList<>();
		if (!caseSensitive) {
			string = string.toLowerCase();
			for (Nangliaa n : list)
				if (n.getName().toLowerCase().contains(string)) ne.add(n);
		} else for (Nangliaa n : list)
			if (n.getName().contains(string)) ne.add(n);
		return ne;
	}

	public static boolean hasModifier (int value, int down, int up) {
		return (value & (down | up)) == down;
	}

	public static byte[] iatba (int[] ints) {
		byte[] bytes = new byte[ints.length * 4];
		for (int i = 0; i < ints.length; i++) {
			bytes[i * 4] = (byte) (ints[i] >>> 24);
			bytes[i * 4 + 1] = (byte) (ints[i] >>> 16);
			bytes[i * 4 + 2] = (byte) (ints[i] >>> 8);
			bytes[i * 4 + 3] = (byte) ints[i];
		}
		return bytes;
	}

	/**
	 * 3-byte int to byte[3]
	 *
	 * @param i
	 * @return
	 */
	public static byte[] idtba (int i) {
		return new byte[] {
				(byte) (i >>> 16), (byte) (i >>> 8), (byte) i
		};
	}

	public static boolean inBounds (int x, int x0, int x1) {
		return x0 <= x && x < x1;
	}

	public static boolean inBounds (int x, int y, int x0, int y0, int x1, int y1) {
		return x0 <= x && x < x1 && y0 <= y && y < y1;
	}

	public static boolean inBoundsMsg (int x, int y, int x0, int y0, int x1, int y1) {
		System.out.println(x0 + "<=" + x + "<" + x1 + " " + y0 + "<=" + y + "<" + y1);
		return x0 <= x && x < x1 && y0 <= y && y < y1;
	}

	public static boolean inRect (Point p, int x, int y, int width, int height) {
		return x <= p.x && p.x <= x + width && y <= p.y && p.y <= y + height;
	}

	public static boolean inRect (Point p, int x, int y, int width, int height, boolean printValues) {
		if (printValues) System.out.println(x + " <= " + p.x + " <= " + (x + width) + " & " + y + " <= " + p.y + " <= " + (y + height));
		return x <= p.x && p.x <= x + width && y <= p.y && p.y <= y + height;
	}

	public static int[] insert (int[] a, int where, int value) {
		if (where < 0 || where > a.length) throw new IllegalArgumentException("Index out of bounds");
		int[] na = new int[a.length + 1];

		for (int i = 0; i < where; i++)
			na[i] = a[i];

		na[where] = value;
		for (int i = where; i < a.length; i++)
			na[i + 1] = a[i];

		return na;
	}

	public static <T> T[] insert (T[] a, int where, T value) {
		if (where < 0 || where > a.length) throw new IllegalArgumentException("Index out of bounds");
		@SuppressWarnings ("unchecked")
		T[] na = (T[]) new Object[a.length + 1];

		System.arraycopy(a, 0, na, 0, where);
		na[where] = value;
		System.arraycopy(a, where, na, where + 1, a.length - where);
		return na;
	}

	public static boolean isNumeric (String string, int radix) {
		int len = string.length();
		if (len == 1 && string.charAt(0) == '-' || len == 0 || string.charAt(0) != '-' && Character.digit(string.charAt(0), radix) == -1) return false;
		for (int i = 1; i < len; i++)
			if (Character.digit(string.charAt(i), radix) == -1) return false;
		return true;
	}

	/**
	 * 4-byte int to byte[4]
	 *
	 * @param i
	 * @return
	 */
	public static byte[] itba (int i) {
		return new byte[] {
				(byte) (i >>> 24), (byte) (i >>> 16), (byte) (i >>> 8), (byte) i
		};
	}

	public static String itbs (int value, int length) {
		return setLength(Integer.toBinaryString(value), '0', length);
	}

	public static String its (int value, int length, int radix) {
		return setLength(Integer.toString(value, radix), '0', length);
	}

	public static long itul (int i) {
		return i & 0xffffffffL;
	}

	public static String itxs (int value, int length) {
		return setLength(Integer.toString(value, 16), '0', length);
	}

	public static String lts (long cellType, int length, int radix) {
		return setLength(Long.toString(cellType, radix), '0', length);
	}

	public static String ltxs (long cellType, int length) {
		return setLength(Long.toString(cellType, 16), '0', length);
	}

	public static String pop (String s) {
		if (s.length() > 0) return s.substring(0, s.length() - 1);
		return EMPTY_STRING;
	}

	public static int[] popFirst (int[] a, int b) {
		int[] neu = new int[a.length - b];
		for (int i = 0; i < neu.length; i++)
			neu[i] = a[i + b];
		return neu;
	}

	public static String popFirst (String s) {
		if (s.length() > 0) return s.substring(1);
		return EMPTY_STRING;
	}

	public static <T> void printArray (T[] text) {
		sb.append('{');
		for (int i = 0; i < text.length; i++) {
			if (i != 0) sb.append(", ");
			sb.append(text[i]);
		}
		sb.append('}');
		System.out.println(sb.toString());
		sb.setLength(0);
	}

	public static void printBytes (byte[] text) {
		sb.append('{');
		for (int i = 0; i < text.length; i++) {
			if (i != 0) sb.append(", ");
			sb.append(ltxs(btul(text[i]), 2));
		}
		sb.append('}');
		System.out.println(sb.toString());
		sb.setLength(0);
	}

	public static void printInt (int i) {
		sb.append('{');
		sb.append(uits(i, 2, 16));
		sb.append('}');
		System.out.println(sb.toString());
		sb.setLength(0);
	}

	public static void printInts (int[] text) {
		sb.append('{');
		for (int i = 0; i < text.length; i++) {
			if (i != 0) sb.append(", ");
			sb.append(uits(text[i], 2, 16));
		}
		sb.append('}');
		System.out.println(sb.toString());
		sb.setLength(0);
	}

	public static <T> T[] pushFront (T[] a, T b) {
		T[] neu = Arrays.copyOf(a, a.length + 1);
		for (int i = 0; i < a.length; i++)
			neu[i + 1] = a[i];
		neu[0] = b;
		return neu;
	}

	public static String rightAlign (String a, int leŋþ) {
		while (a.length() < leŋþ)
			a = " " + a;
		return a;
	}

	public static String setLength (String string, char addToStart, int leŋþ) {
		if (leŋþ == 0) return string;
		for (int i = 0; i < leŋþ - string.length(); i++)
			sb.append(addToStart);
		sb.append(string);
		String result = sb.toString();
		sb.setLength(0);
		return result;
	}

	/**
	 * Negative amount takes from end, positive from start
	 *
	 * @param <T>
	 * @param a
	 * @param amount
	 * @return
	 */
	public static <T> T[] shorten (T[] a, int amount) {
		return Arrays.copyOfRange(a, max(amount, 0), min(a.length + amount, a.length - 1));
	}

	public static int sti (String string, int radix) {
		if (string.length() == 0) return 0;
		return Integer.parseInt(string, radix);
	}

	/**
	 * String to long.
	 * @param string
	 * @param radix
	 * @return
	 */
	public static long stl (String string, int radix) {
		if (string.length() == 0) return 0;
		return Long.parseLong(string, radix);
	}

	/**
	 * String to unsigned int. (CN1-compliant implementation of Integer.toUnsignedInt(String))
	 * @param string
	 * @param radix
	 * @return
	 */
	public static int stui (String string, int radix) {
		if (string.length() == 0) return 0;
		return (int) Long.parseLong(string, radix);
	}

	public static String uits (int value, int length, int radix) {
		return setLength(Long.toString(value & 0xffffffffL, radix), '0', length);
	}
}
