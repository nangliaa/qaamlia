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

package org.nangliaa.extra;

import java.util.HashMap;
import java.util.Map;

import org.nangliaa.comp.CompLayout;

public class Nangliaa {
	public static final Nangliaa NONE = new Nangliaa();
	public int id, colour;
	public Map<String, String> names = new HashMap<>();

	public Nangliaa () {}

	public Nangliaa (final String name, final int id) {
		names.put(Extra.nagolima, name);
		this.id = id;
	}

	public Nangliaa (final String name, final int id, final int colour) {
		names.put(Extra.nagolima, name);
		this.id = id;
		this.colour = colour;
	}

	public boolean equals (final Nangliaa object) {
		try {
			if (getName().equals(object.getName())) // pr("equals: " + name + " " + object.name);
				return true;
		} catch (final NullPointerException e) {}
		return false;
	}

	public byte[] getBytes () { return null; }

	public String getLocalName () { return names.get(CompLayout.language); }

	public String getName () { return names.get(Extra.nagolima); }

	public String getName (final String language) {
		return names.get(language);
	}
}