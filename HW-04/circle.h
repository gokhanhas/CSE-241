/*
 * Gokhan Has - 161044067 
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#define PI 3.14159265

using std::ostream;
using std::cout;
using std::endl;

namespace shapes{
	
	class Circle{

		public:
			Circle();
			Circle(int r);
			Circle(double x,double y);
			Circle(int r,double x,double y);
			int getRadius() const { return radius; }
			double getCx() const { return cx; }
			double getCy() const { return cy; }
			double getPerimeterLength() const { return (2 * PI * radius);}
			double getArea() const { return (PI * radius * radius);}
			void setRadius(int r);
			void setCoordinate_X(double x);
			void setCoordinate_Y(double y);
			void setCircleColor(int control){controlCircleColor=control;}
			friend ostream& operator <<(ostream& outs,const Circle& circle);
			Circle operator++(); // Prefix Version
			Circle operator++(int ignoreMe); // Postfix Version
			Circle operator--(); // Prefix Version
			Circle operator--(int ignoreMe); // Postfix Version
			friend Circle operator +(const Circle& circle1,double add);
			friend Circle operator -(const Circle& circle1,double subtract);
			friend bool operator ==(const Circle& circle1,const Circle& circle2);
			friend bool operator !=(const Circle& circle1,const Circle& circle2);
			friend bool operator <=(const Circle& circle1,const Circle& circle2);
			friend bool operator >=(const Circle& circle1,const Circle& circle2);

		private:
			int radius;
			double cx;
			double cy;
			int controlCircleColor;
	};
}

#endif