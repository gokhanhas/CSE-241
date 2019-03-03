/*
 * Gokhan Has - 161044067
*/

#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

class ComposedShape{

	public:
		ComposedShape();
		ComposedShape(Rectangle mainR,Rectangle smallR);
		ComposedShape(Rectangle mainR,Circle smallC);
		ComposedShape(Rectangle mainR,Triangle smallT);
		ComposedShape(Triangle mainT,Rectangle smallR); 
		ComposedShape(Triangle mainT,Circle smallC);
		ComposedShape(Triangle mainT,Triangle smallT);
		//ComposedShape(Circle mainC,Rectangle smallR); It is empty.
		ComposedShape(Circle mainC,Circle smallC);
		//ComposedShape(Circle mainC,Triangle smallT);	It is empty.
		void optimalFit(int number);
		void draw(ofstream& filename,char mainShape,char innerShape);

	private:
		vector<double> coordinate_X;
		vector<double> coordinate_Y;
		vector<double> rotate_coordinate_X;
		vector<double> rotate_coordinate_Y;
		Rectangle mainRectangle,smallRectangle;
		Triangle mainTriangle,smallTriangle;
		Circle mainCircle,smallCircle;
};

#endif