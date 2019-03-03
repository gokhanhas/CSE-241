/*
 * Gokhan Has - 161044067
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Triangle{

	public:
		Triangle();
		Triangle(double e);
		double getEdge() const { return edge; }
		double getTx() const { return tx; }
		double getTy() const { return ty; }
		void setEdge(double e);
		void setCoordinate_X(double x);
		void setCoordinate_Y(double y);
		void draw(ofstream &filename);
		void draw(ofstream &filename,int color);
	
	private:
		double edge;
		double tx;
		double ty;
		double tx2;
		double ty2;
		double tx3;
		double ty3;
};

#endif