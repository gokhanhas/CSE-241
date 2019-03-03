/*
 * Gokhan Has - 161044067
*/

#include "circle.h"

Circle::Circle(){/* Default Constructor */}
Circle::Circle(int r):radius(r){}

void Circle::setRadius(int r){ radius = r; }

void Circle::setCoordinate_X(double x){ cx = x; }
void Circle::setCoordinate_Y(double y){ cy = y; }

void Circle::draw(ofstream &filename){

	filename << "\n\t<circle cx=\"" << cx << "\" cy=\"" << cy 
			 << "\" r=\"" << radius << "\" fill=\"red\" />";
}
void Circle::draw(ofstream &filename,int color){

	filename << "\n\t<circle cx=\"" << cx << "\" cy=\"" << cy 
	 		 << "\" r=\"" << radius << "\" fill=\"green\" />";
}