/*
 * Gokhan Has - 161044067
 */

#include "triangle.h"

Triangle::Triangle(){/* Default Constructor */}
Triangle::Triangle(double e):edge(e) {/* Body Initialize Empty */}

void Triangle::setEdge(double e){ edge = e; }

void Triangle::setCoordinate_X(double x) { tx = x;}
void Triangle::setCoordinate_Y(double y) { ty = y;}

void Triangle::draw(ofstream &filename){
	
	tx2 = 0;		ty2 = (edge/2)*sqrt(3);
	tx3 = edge;     ty3 = (edge/2)*sqrt(3);
	
	filename << "\n\t<polygon points=\"" << tx << "," << ty << " " << tx2 
			 << "," << ty2 << " " << tx3 << "," << ty3 
			 << "\" style=\"fill:red\" />" << endl;
	
}

void Triangle::draw(ofstream &filename,int color){

	if(color == 1){

		tx2 = tx - edge/2; 		ty2 = ty + edge/2*sqrt(3);
		tx3 = tx + edge/2;		ty3 = ty + edge/2*sqrt(3);
	}

	else{
		tx2 = tx + edge;       ty2=ty;
		tx3 = tx + edge/2;     ty3=ty+edge/2*sqrt(3);
	}

	filename << "\n\t<polygon points=\"" << tx << "," << ty << " " << tx2 
			 << "," << ty2 << " " << tx3 << "," << ty3 
			 << "\" style=\"fill:green;stroke-width:0.5\" />" << endl;
	
}