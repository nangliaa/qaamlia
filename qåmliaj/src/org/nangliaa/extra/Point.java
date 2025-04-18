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

public class Point {
	public static final Point DEF_POINT = new Point();

	public int x, y;

	public Point () {
		this(0, 0);
	}

	public Point (double d, double e) {
		x = (int) d;
		y = (int) e;
	}

	public Point (int x, int y) {
		this.x = x;
		this.y = y;
	}

	public Point (Point p) {
		this(p.x, p.y);
	}

	public Point getNew (int dx, int dy) {
		return new Point(x + dx, y + dy);
	}

	public void move (int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString () {
		return "(" + x + ", " + y + ')';
	}

	public void translate (int dx, int dy) {
		x += dx;
		y += dy;
	}
}
