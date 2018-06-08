// Sean Michalec
// bounce.cpp
#include <iostream>
#include "pegs.h"
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <vector>
using namespace std;

int collision(vector<vector<Pegs> >a, int, int);

int main()
{
	const int xsize = 750, ysize = 1000;
	double ddy = 0;
	int v = 3;
	int myrand;
	//	int collide = 0;
	int oCounter = 0;
	int pointCounter = 0;
	int ballCounter = 15;
	// Open a new window drawing.
	gfx_open(xsize, ysize, "bounce");
	gfx_color(255, 255, 255); // white

	vector<vector<Pegs> > peggles(10, vector<Pegs>(10));
	for (int i = 0, x = 100; i < 10; i++, x += 60) {
		for (int j = 0, y = 200; j < 10; j++, y += 60) {
			peggles.at(i).at(j) = Pegs(x, y);
			myrand = rand() % 100;
			if (myrand >= 25)
			{
				peggles.at(i).at(j).setColor(0);
			}
			else
			{
				peggles.at(i).at(j).setColor(1);
			}
			if (((peggles.at(i).at(j)).getColor()== 1) && (oCounter < 20)) {
				oCounter += 1;
				// cout << "oCounter" << " = " << oCounter << endl;
			}
			if (oCounter == 20) {
				(peggles.at(i).at(j)).setColor(0);
				// cout << "set to blue" << endl;
			}
			(peggles.at(i).at(j)).print();
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			(peggles.at(i).at(j)).print();
		}
	}
	
	int q = 1;
	while (q == 1) { // need an infinite loop for animation
		if (gfx_event_waiting()) {
			if (gfx_wait() == 1)
			{
				
				// to make possible to display score
				string points;
				stringstream ss;
				ss << pointCounter;
				points = ss.str();

				// display score
				gfx_clear(); // reset board clear
				gfx_text(xsize - 60, 20, "Points:");
				gfx_text(xsize - 60, 30, points.c_str());

				// to make possible to display balls
				string balls;
				stringstream bb;
				bb << ballCounter;
				balls = bb.str();

				// ball counter
				gfx_text(xsize - 60, 45, "Balls:");
				gfx_text(xsize - 60, 60, balls.c_str());
				//gfx_flush();

				ballCounter--; // decrease balls

				
				// start point
				double cx = xsize / 2;
				double cy = 50;

				// find mouse cursor click
				double xcursor = gfx_xpos();
				double ycursor = gfx_ypos();

				// initialize the dx and dy as the run and rise of the slope between the start and mouse click point
				double dx = (xcursor - cx);
				double dy = (ycursor - cy);
				

				double length = sqrt((dx*dx) + (dy*dy));

				// out velocity of ball (magnitue AND direction)
				dx = (5.5*dx) / (length);
				dy = (5.5*dy) / (length);

				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						(peggles.at(i).at(j)).print();
					}
				}
				int detect = 1;
				while (detect == 1) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {

							// detect collisions
							int x = (peggles.at(i).at(j)).getX();
							int y = (peggles.at(i).at(j)).getY();
							int delx = (x)-(cx); // change in x
							int dely = (y)-(cy); // change in y
							double dist = sqrt((delx*delx) + (dely*dely)); // find distance between points of ball and peg

							if (dist <= 17 && (peggles.at(i).at(j)).getState() == false) { // if the distance between center points is less than the sum of the radii, they have collided

								// cout << "HIT"; // for testing purposes

								gfx_color(0, 0, 0); // remove peg
								gfx_fill_circle(peggles.at(i).at(j).getX(), peggles.at(i).at(j).getY(), 7); // remove peg
								 // activate circle (redraw it as an empty circle)

								if (((peggles.at(i).at(j)).getColor() == 0) && (peggles.at(i).at(j)).getState() == false) {// if blue and touched
									(peggles.at(i).at(j)).touch();
									pointCounter += 10;
								}
								if (((peggles.at(i).at(j)).getColor() == 1) && (peggles.at(i).at(j)).getState() == false) { // if orange and touched
									(peggles.at(i).at(j)).touch();
									pointCounter += 100;
									oCounter--;
								}
								// flip for bounce
								dx = -dx;
								
								
							}
						}
					} 
					// ball interation
					gfx_color(0, 0, 0); // delete ball behind it
					gfx_fill_circle(cx, cy, 10); // make black circle to cover up old circle position


					
					if (cx <= 10) { // left boundary bounce
						dx = -dx;
					}
					if (cx >= xsize - 10) { // right bounce
						dx = -dx;
					}

					if (cy >= ysize - 10) { // bottom detect
						
						for (int i = 0; i < 10; i++) {
							for (int j = 0; j < 10; j++) {
								if ((peggles.at(i).at(j)).getState() == true)
								{
									(peggles.at(i).at(j)).remove(); // remove hit pegs by banishing to death muahahaha >:D
								}
							}
						}
						detect = 0;
					}

					// increment circle
					cx += dx;
					cy += dy;

					gfx_color(255, 255, 255);
					gfx_fill_circle(cx, cy, 10);
					gfx_flush();
					usleep(10000);
				}

			}
			// win/lose conditions (end game!)
			if (ballCounter == 0) {
				gfx_clear();
				gfx_text(xsize / 2 - 30, 70, "You Lose :( Press q to quit.");
			}
			if (oCounter == 0) {
				gfx_clear();
				gfx_text(xsize / 2 - 30, 70, "You Win! :D Press q to quit.");
			}
			if (gfx_wait() == 'q') {
				q = 0;
				return 0;
			}
		}
	}
	return 0;
}

