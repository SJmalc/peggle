// Sean Michalec and Georges Alsankary
// pegs.cpp

#include <iostream>
#include "pegs.h"
#include "gfx.h"

Pegs::Pegs()
{}

Pegs::Pegs (int a, int b) {
	x = a;
	y = b;
	rad = 7;
	// try to make whole board random, leans heavily toward the front end
	color = 0; // 0 is blue, 1 is orange
	state = false;
	isclear = false;
}

Pegs::~Pegs()
{}

int Pegs::getX() {
	return x;
}

int Pegs::getY() {
	return y;
}

int Pegs::getColor() {
	return color;
}

bool Pegs::getState() {
	return state;
}

bool Pegs::getClear() {
	return isclear;
}

void Pegs::setColor(int a) {
	color = a;
}

void Pegs::setX(int a) {
	x = a;
}

void Pegs::setY(int a) {
	y = a;
}

void Pegs::touch() {
	state = true;
	print();
}

void Pegs::remove() {
	x = 0;
	y = 0;
}

void Pegs::clear() {
	isclear = true;
}

void Pegs::print() {
	if (isclear == false) {
		if (state == true && color == 1) {
			gfx_color(255, 149, 0);
			gfx_circle(x, y, rad);
		}
		if (state == false && color == 1) {
			gfx_color(255, 149, 0);
			gfx_fill_circle(x, y, rad);
		}
		if (state == true && color == 0) {
			gfx_color(0, 0, 255);
			gfx_circle(x, y, rad);
		}
		if (state == false && color == 0) {
			gfx_color(0, 0, 255);
			gfx_fill_circle(x, y, rad);
		}
	}
}
