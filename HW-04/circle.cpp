/*
 * Gokhan Has - 161044067
*/

#include "circle.h"

namespace shapes{	

	Circle::Circle(){/* Default Constructor */}
	Circle::Circle(int r):radius(r),cx(r),cy(r){/* Body Initialize Empty */}
	Circle::Circle(double x,double y): cx(x), cy(y) {/* Body Initialize Empty */}
	Circle::Circle(int r,double x,double y): radius(r),cx(x),cy(y) {/* Body Initialize Empty */}

	void Circle::setRadius(int r){ radius = r; }

	void Circle::setCoordinate_X(double x){ cx = x; }
	void Circle::setCoordinate_Y(double y){ cy = y; }

	ostream& operator <<(ostream& outs,const Circle& circle){

		if(circle.controlCircleColor == 0){ // Drawing big circle
			outs << "\n\t<circle cx=\"" << circle.cx << "\" cy=\"" << circle.cy
			 	 << "\" r=\"" << circle.radius << "\" fill=\"red\" />";
		}
		else{ // Drawing small circle
			outs << "\n\t<circle cx=\"" << circle.cx << "\" cy=\"" << circle.cy
			 	 << "\" r=\"" << circle.radius << "\" fill=\"green\" />";
		}

		return outs;
	}

	Circle Circle::operator++(int ignoreMe){ // postfix version

		double tempX = cx;
		double tempY = cy;
		cx++;
		cy++;

		return Circle(tempX,tempY);
	}

	Circle Circle::operator++(){ // prefix vesion

		cx++;
		cy++;

		return Circle(cx,cy);
	}

	Circle Circle::operator--(int ignoreMe){ // postfix version

		double tempX = cx;
		double tempY = cy;
		cx--;
		cy--;

		if(cx < 0)
			cx = 0; // Coordinate must be positive or zero.
		if(cy < 0)
			cy = 0;

		return Circle(tempX,tempY);
	}

	Circle Circle::operator--(){ // prefix vesion

		cx--;
		cy--;

		if(cx < 0)
			cx = 0; // Coordinate must be positive or zero.
		if(cy < 0)
			cy = 0;

		return Circle(cx,cy);
	}

	Circle operator+(const Circle& circle1,double add){

		double newCircle = circle1.radius + add;
		double x = circle1.cx + add;
		double y = circle1.cy + add;
		
		return Circle(newCircle,x,y);
	}

	Circle operator-(const Circle& circle1,double subtract){

		double newCircle = circle1.radius - subtract;
		double x = circle1.cx - subtract;
		double y = circle1.cy - subtract;

		if(newCircle < 0){
			newCircle = circle1.radius; // Control the negative statement.
			x = circle1.cx;
			y = circle1.cy;
		}

		return Circle(newCircle,circle1.cx,circle1.cy);
	}

	bool operator ==(const Circle& circle1,const Circle& circle2){
		return (circle1.getArea() == circle2.getArea());
	}
	bool operator !=(const Circle& circle1,const Circle& circle2){
		return !(circle1.getArea() == circle2.getArea());
	}
	bool operator >=(const Circle& circle1,const Circle& circle2){
		return (circle1.getArea() >= circle2.getArea());
	}
	bool operator <=(const Circle& circle1,const Circle& circle2){
		return (circle1.getArea() <= circle2.getArea());
	}
}