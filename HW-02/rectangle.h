/*
 * Gokhan Has - 161044067
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Rectangle{

	public:
		Rectangle();
		Rectangle(int w,int h);
		double getWidth() const { return width; }
		double getHeight() const { return height; }
		double getRx() const { return rx; }
		double getRy() const { return ry; }
		void setWidth(int w);
		void setHeight(int h);
		void setCoordinate_X(double x);
		void setCoordinate_Y(double y);
		void draw(ofstream &filename);
		void draw(ofstream &filename,int color);
	
	private:
		double height;
		double width;
		double rx;
		double ry;
};

#endif