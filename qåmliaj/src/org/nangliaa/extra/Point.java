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
