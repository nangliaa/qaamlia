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

public class Point {
	public static final Point DEF_POINT = new Point();

	public int x, y;

	public Point () {
		this(0, 0);
	}

	public Point (final double d, final double e) {
		x = (int) d;
		y = (int) e;
	}

	public Point (final int x, final int y) {
		this.x = x;
		this.y = y;
	}

	public Point (final Point p) {
		this(p.x, p.y);
	}

	public Point getNew (final int dx, final int dy) {
		return new Point(x + dx, y + dy);
	}

	public void move (final int x, final int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString () {
		return "(" + x + ", " + y + ')';
	}

	public void translate (final int dx, final int dy) {
		x += dx;
		y += dy;
	}
}
