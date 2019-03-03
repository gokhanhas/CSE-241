/*
 * Gokhan Has - 161044067
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>

using std::ostream;
using std::ofstream;
using std::cout;
using std::endl;

namespace shapes{

	class Rectangle{

		public:
			Rectangle();
			Rectangle(int w,int h);
			Rectangle(double x,double y);
			Rectangle(int w,int h,double x,double y);
			double getWidth() const { return width; }
			double getHeight() const { return height; }
			double getRx() const { return rx; }
			double getRy() const { return ry; }
			double getPerimeterLength() const { return (2*(height + width)); }
			double getArea() const { return (height * width); } 
			void setWidth(int w);
			void setHeight(int h);
			void setCoordinate_X(double x);
			void setCoordinate_Y(double y);
			void setRectangleColor(int control){controlRectangleColor=control;}
			friend ostream& operator <<(ostream& outs,const Rectangle& rectangle);
			Rectangle operator++(); // prefix version
			Rectangle operator++(int ignoreMe); // postfix version
			Rectangle operator--(); // prefix version
			Rectangle operator--(int ignoreMe); // postfix version
			friend Rectangle operator+(const Rectangle& rect,double add);
			friend Rectangle operator-(const Rectangle& rect,double subtract);
			friend bool operator ==(const Rectangle& rectangle1,const Rectangle& rectangle2);
			friend bool operator !=(const Rectangle& rectangle1,const Rectangle& rectangle2);
			friend bool operator >=(const Rectangle& rectangle1,const Rectangle& rectangle2);
			friend bool operator <=(const Rectangle& rectangle1,const Rectangle& rectangle2);
		
		private:
			double height;
			double width;
			double rx;
			double ry;
			int controlRectangleColor;
	};
}

#endif