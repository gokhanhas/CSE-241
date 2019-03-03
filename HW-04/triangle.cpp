/*
 * Gokhan Has - 161044067
 */

#include "triangle.h"

namespace shapes{

	Triangle::Triangle(){/* Default Constructor */}
	Triangle::Triangle(double e):edge(e) {/* Body Initialize Empty */}
	Triangle::Triangle(double x,double y):tx(x),ty(y) {/* Body Initialize Empty */}
	Triangle::Triangle(double e,double x,double y):edge(e),tx(x),ty(y) {/* Body Initialize Empty */}

	void Triangle::setEdge(double e){ edge = e; }

	void Triangle::setCoordinate_X(double x) { tx = x;}
	void Triangle::setCoordinate_Y(double y) { ty = y;}


	ostream& operator <<(ostream& outs,const Triangle& triangle){

		double tx2,tx3,ty2,ty3;

		if(triangle.rotateControl == 0){ // Coordinates for drawing normal triangles
			tx2 = triangle.tx - triangle.edge/2; 		ty2 = triangle.ty + triangle.edge/2*sqrt(3);
			tx3 = triangle.tx + triangle.edge/2;		ty3 = triangle.ty + triangle.edge/2*sqrt(3);
		}

		else{ // Coordinates for drawing inverse triangles
			tx2 = triangle.tx + triangle.edge; 			ty2 = triangle.ty;
			tx3 = triangle.tx + triangle.edge/2;		ty3 = triangle.ty + triangle.edge/2*sqrt(3);
		}

		if(triangle.controlTriangleColor == 0){ // Drawing big triangle
			outs << "\n\t<polygon points=\"" << triangle.tx << "," << triangle.ty << " " << tx2 
				 << "," << ty2 << " " << tx3 << "," << ty3 
				 << "\" style=\"fill:red\" />" << endl;
		}
		else{ // Drawing small triangle
			outs << "\n\t<polygon points=\"" << triangle.tx << "," << triangle.ty << " " << tx2 
				 << "," << ty2 << " " << tx3 << "," << ty3 
				 << "\" style=\"fill:green;stroke-width:0.5\" />" << endl;
		}
		return outs;
	}

	Triangle Triangle::operator++(int ignoreMe){ // postfix version

		double tempX = tx;
		double tempY = ty;
		tx++;
		ty++;

		return Triangle(tempX,tempY);
	}

	Triangle Triangle::operator++(){ // prefix version
		
		tx++;
		ty++;

		return Triangle(tx,ty);
	}

	Triangle Triangle::operator--(int ignoreMe){ // postfix version

		double tempX = tx;
		double tempY = ty;
		tx--;
		ty--;

		if(tx < 0)
			tx = 0; // Coordinate must be positive or zero.
		if(ty < 0)
			ty = 0;

		return Triangle(tempX,tempY);
	}

	Triangle Triangle::operator--(){ // prefix version
		
		tx--;
		ty--;
		
		if(tx < 0)
			tx = 0; // Coordinate must be positive or zero.
		if(ty < 0)
			ty = 0;
		
		return Triangle(tx,ty);
	}

	Triangle operator+(const Triangle& triangle1,double add){

		double tempEdge = triangle1.edge + add;
		double x = tempEdge / 2;
		double y = 0;

		return Triangle(tempEdge,x,y);
	}

	Triangle operator-(const Triangle& triangle1,double subtract){

		double tempEdge = triangle1.edge - subtract;
		double x = tempEdge / 2;

		if(tempEdge < 0)
			tempEdge = 0; // Control the negative statement. 

		return Triangle(tempEdge,x,triangle1.ty);
	}

	bool operator ==(const Triangle& triangle1,const Triangle& triangle2){
		return (triangle1.getArea() == triangle2.getArea());
	}
	bool operator !=(const Triangle& triangle1,const Triangle& triangle2){
		return !(triangle1.getArea() == triangle2.getArea());
	}
	bool operator >=(const Triangle& triangle1,const Triangle& triangle2){
		return (triangle1.getArea() >= triangle2.getArea());
	}
	bool operator <=(const Triangle& triangle1,const Triangle& triangle2){
		return (triangle1.getArea() <= triangle2.getArea());
	}
}