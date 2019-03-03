/*
 * Gokhan Has - 161044067 
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Circle{

	public:
		Circle();
		Circle(int r);
		int getRadius() const { return radius; }
		double getCx() const { return cx; }
		double getCy() const { return cy; }
		void setRadius(int r);
		void setCoordinate_X(double x);
		void setCoordinate_Y(double y);
		void draw(ofstream &filename);
		void draw(ofstream &filename,int color);

	private:
		int radius;
		double cx;
		double cy;
};

#endif