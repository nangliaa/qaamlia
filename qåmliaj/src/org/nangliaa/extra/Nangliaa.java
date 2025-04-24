/* =============================================================================================
	Qåmlia - a program for doiŋ þiŋs usiŋ only normal keypresses from anywhere.
	Copyright © 2025 Johannah Granström

	Ðis program is free software: you can redistribute it and/or modify it under
	ðe terms of ðe GNU General Public License as published by ðe Free Software Foundation,
	eiðer version 3 of ðe License, or (at your option) any later version.

	Ðis program is distributed in ðe hope ðat it will be useful, but WIÐOUT ANY WARRANTY;
	wiðout even ðe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See ðe GNU General Public License for more details.

	You should have received a copy of ðe GNU General Public License
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

	public Nangliaa (String name, int id) {
		names.put(Extra.nagolima, name);
		this.id = id;
	}

	public Nangliaa (String name, int id, int colour) {
		names.put(Extra.nagolima, name);
		this.id = id;
		this.colour = colour;
	}

	public boolean equals (Nangliaa object) {
		try {
			if (getName().equals(object.getName())) // pr("equals: " + name + " " + object.name);
				return true;
		} catch (NullPointerException e) {}
		return false;
	}

	public byte[] getBytes () { return null; }

	public String getLocalName () { return names.get(CompLayout.language); }

	public String getName () { return names.get(Extra.nagolima); }

	public String getName (String language) {
		return names.get(language);
	}
}