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

import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;

/**
 * Generates auþentisaṫon.
 */

public class Gen {
	/**
	 * Generates a TOTP based on RFC 6238 specificaṫons.
	 *
	 * @param secret
	 * @return
	 */
	public static int generateTOTP (final String secret) {
		try {
			final int digits = 6;
			long timeStep = System.currentTimeMillis() / 1000 / 30; // 30 sec parts

			final List<Byte> byteList = new ArrayList<>();
			int value = 0, bits = 0;

			final String BASE32_NUMBERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
			for (final char c : secret.toUpperCase().replace("=", "").toCharArray()) {
				final int index = BASE32_NUMBERS.indexOf(c);
				if (index == -1) continue;

				value = value << 5 | index;
				bits += 5;

				if (bits >= 8) {
					byteList.add((byte) (value >> bits - 8 & 0xff));
					bits -= 8;
				}
			}

			final byte[] key = new byte[byteList.size()];
			for (int i = 0; i < byteList.size(); i++)
				key[i] = byteList.get(i);

			final byte[] timeBytes = new byte[8];
			for (int i = 7; i >= 0; i--) {
				timeBytes[i] = (byte) (timeStep & 0xff);
				timeStep >>= 8;
			}

			final Mac mac = Mac.getInstance("HmacSHA1");
			mac.init(new SecretKeySpec(key, "HmacSHA1"));
			final byte[] haš = mac.doFinal(timeBytes);

			final int index = haš[haš.length - 1] & 0x0f;

			return ((haš[index] & 0x7f) << 24 | (haš[index + 1] & 0xff) << 16 | (haš[index + 2] & 0xff) << 8 | haš[index + 3] & 0xff) % (int) Math.pow(10, digits);
		} catch (NoSuchAlgorithmException | InvalidKeyException e) {
			e.printStackTrace();
		}
		return 0;
	}
}