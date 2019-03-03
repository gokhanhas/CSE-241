/*
 *	Gokhan Has - 161044067
*/

#include "rectangle.h"

Rectangle::Rectangle(){}
Rectangle::Rectangle(int w,int h):height(h),width(w) {}

void Rectangle::setWidth(int w) { width = w; }
void Rectangle::setHeight(int h) {height = h; }
void Rectangle::setCoordinate_X(double x) { rx = x; }
void Rectangle::setCoordinate_Y(double y) { ry = y; }

void Rectangle::draw(ofstream &filename){

	filename << "\n\t<rect x=\"" << rx << "\" y=\"" << ry  << "\" width=\""
			 << width << "\" height=\"" << height 
			 << "\" style=\"fill:red\" />" << endl;
}

void Rectangle::draw(ofstream &filename,int color){

	filename << "\n\t<rect x=\"" << rx << "\" y=\"" << ry  << "\" width=\""
			 << width << "\" height=\"" << height 
			 << "\" style=\"fill:green;stroke-width:1\" />" << endl;
}