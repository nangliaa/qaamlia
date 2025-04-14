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