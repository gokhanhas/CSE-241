/*
 *	Gokhan Has - 161044067
*/

#include "rectangle.h"

Rectangle::Rectangle(){/* Default Constructor */}
Rectangle::Rectangle(int w,int h):height(h),width(w) {/* Body Initialize Empty */}
Rectangle::Rectangle(double x,double y):rx(x),ry(y) {/* Body Initialize Empty */}
Rectangle::Rectangle(int w,int h,double x,double y) :height(h),width(w),rx(x),ry(y) {/* Body Initialize Empty */}

void Rectangle::setWidth(int w) { width = w; }
void Rectangle::setHeight(int h) {height = h; }
void Rectangle::setCoordinate_X(double x) { rx = x; }
void Rectangle::setCoordinate_Y(double y) { ry = y; }

ostream& operator <<(ostream& outs,const Rectangle& rectangle){

	if(rectangle.controlRectangleColor == 0){ // Drawing big rectangle
		outs << "\n\t<rect x=\"" << rectangle.rx << "\" y=\"" << rectangle.ry  << "\" width=\""
			 << rectangle.width << "\" height=\"" << rectangle.height 
			 << "\" style=\"fill:red\" />" << endl;
	}
		
	else{ // Drawing small rectangle
		outs << "\n\t<rect x=\"" << rectangle.rx << "\" y=\"" << rectangle.ry  << "\" width=\""
			 << rectangle.width << "\" height=\"" << rectangle.height 
			 << "\" style=\"fill:green;stroke-width:1\" />" << endl;
	}

	return outs;
}

Rectangle Rectangle::operator++(int ignoreMe){ // postfix version

	double tempX = rx;
	double tempY = ry;
	rx++;
	ry++;

	return Rectangle(tempX,tempY);
}

Rectangle Rectangle::operator++(){ // prefix version

	rx++;
	ry++;

	return Rectangle(rx,ry);
}

Rectangle Rectangle::operator--(int ignoreMe){ // postfix version

	double tempX = rx;
	double tempY = ry;
	rx--;
	ry--;
	
	if(rx < 0)
		rx = 0; // Coordinate must be positive or zero.
	if(ry < 0)
		ry = 0;
	
	return Rectangle(tempX,tempY);
}

Rectangle Rectangle::operator--(){ // prefix version

	rx--;
	ry--;

	if(rx < 0)
		rx = 0; // Coordinate must be positive or zero.
	if(ry < 0)
		ry = 0;
	
	return Rectangle(rx,ry);
}

Rectangle operator+(const Rectangle& rect,double add){

	double tempWidth = rect.width + add;
	double tempHeight = rect.height + add;

	return Rectangle(tempWidth,tempHeight,rect.rx,rect.ry);
}
		
Rectangle operator-(const Rectangle& rect,double subtract){

	double tempWidth = rect.width - subtract;
	double tempHeight = rect.height - subtract;

	if(tempWidth < 0)
		tempWidth = rect.width;
	if(tempHeight < 0)  // Control the negative statement.
		tempHeight = rect.height;

	return Rectangle(tempWidth,tempHeight,rect.rx,rect.ry);
}

bool operator ==(const Rectangle& rectangle1,const Rectangle& rectangle2){
	return (rectangle1.getArea() == rectangle2.getArea());
}
bool operator !=(const Rectangle& rectangle1,const Rectangle& rectangle2){
	return !(rectangle1.getArea() == rectangle2.getArea());
}
bool operator <=(const Rectangle& rectangle1,const Rectangle& rectangle2){
	return (rectangle1.getArea() <= rectangle2.getArea());
}
bool operator >=(const Rectangle& rectangle1,const Rectangle& rectangle2){
	return (rectangle1.getArea() >= rectangle2.getArea());
}