/********* Gokhan Has - 161044067 *********/

#include <iostream>
#include <fstream>
#include <cmath>


#ifndef calShapes_h
#define calShapes_h
#define PI 3.14159
using namespace std;
	
	enum Shapes{
		R,C,T
	};
	
	int shapes(Shapes,double &,double &,double &, double &);
	int whichShape(Shapes &,char);
	int rectangleInRectangle(ofstream &,double ,double,double ,double );
	int circleInRectangle(ofstream &,double ,double ,double );
	int triangleInRectangle(ofstream &,double ,double ,double );
	int rectangleInTriangle(ofstream &,double ,double ,double );
	int circleInTriangle(ofstream &,double ,double );
	int triangleInTriangle(ofstream &,double ,double );
	int circleInCircle(ofstream &,double ,double );

#endif