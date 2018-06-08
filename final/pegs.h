// Sean Michalec and Georges Alsankary
// pegs.h

#include <iostream>
#include <stdlib.h>
#include "gfx.h"
#include <vector>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#define PI 3.14
using namespace std;

class Pegs {
public:
	// construct deconstruct
	Pegs();
	Pegs(int, int);
	~Pegs();

	//methods
	void touch();
	int getX();
	int getY();
	int getColor();
	bool getState();
	bool getClear();
	void clear();
	void remove();

	//utility methods
	void print();
	void setColor(int);
	void setX(int);
	void setY(int);	

private:
	bool state;
	bool isclear;
	int color;
	int x;
	int y;
	int rad;
};
