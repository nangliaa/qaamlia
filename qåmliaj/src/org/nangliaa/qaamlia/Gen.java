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

import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;

/**
 * Generates auþentisation.
 */
public class Gen {
	/**
	 * Generates a TOTP based on RFC 6238 specifications.
	 * @param secret
	 * @return
	 */
	public static int generateTOTP (String secret) {
		try {
			int digits = 6;
			long timeStep = System.currentTimeMillis() / 1000 / 30; // 30 sec parts

			List<Byte> byteList = new ArrayList<>();
			int value = 0, bits = 0;

			final String BASE32_NUMBERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
			for (char c : secret.toUpperCase().replace("=", "").toCharArray()) {
				int index = BASE32_NUMBERS.indexOf(c);
				if (index == -1) continue;

				value = value << 5 | index;
				bits += 5;

				if (bits >= 8) {
					byteList.add((byte) (value >> bits - 8 & 0xff));
					bits -= 8;
				}
			}

			byte[] key = new byte[byteList.size()];
			for (int i = 0; i < byteList.size(); i++)
				key[i] = byteList.get(i);

			byte[] timeBytes = new byte[8];
			for (int i = 7; i >= 0; i--) {
				timeBytes[i] = (byte) (timeStep & 0xff);
				timeStep >>= 8;
			}

			Mac mac = Mac.getInstance("HmacSHA1");
			mac.init(new SecretKeySpec(key, "HmacSHA1"));
			byte[] hash = mac.doFinal(timeBytes);

			int index = hash[hash.length - 1] & 0x0f;

			return ((hash[index] & 0x7f) << 24 | (hash[index + 1] & 0xff) << 16 | (hash[index + 2] & 0xff) << 8 | hash[index + 3] & 0xff) % (int) Math.pow(10, digits);
		} catch (NoSuchAlgorithmException | InvalidKeyException e) {
			e.printStackTrace();
		}
		return 0;
	}
}