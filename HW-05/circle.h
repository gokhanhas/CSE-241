/*
 * Gokhan Has - 161044067 
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapes.h"
#include <string>
#define PI 3.14159265

namespace HasShapes{
	
	class Circle: public Shapes{

		public:
			Circle() noexcept;
			Circle(double r) throw();
			Circle(double x,double y) throw();
			Circle(double r,double x,double y) throw();
			Circle(double r,double x,double y,int color) throw();
			
			void setRadius(double r) throw();
			double getRadius() const noexcept { return radius; }
			
			void setCircleColor(int control) noexcept { controlCircleColor=control; }
			int getControlCircleColor() const noexcept { return controlCircleColor; } 
			
			double area() const noexcept { return (PI * radius * radius); }
			double perimeter() const noexcept { return (2 * PI * radius); }

			Circle& operator++() noexcept; 			    // Prefix Version
			Circle& operator++(int ignoreMe) noexcept;  // Postfix Version
			Circle& operator--() throw(); 			    // Prefix Version
			Circle& operator--(int ignoreMe) throw();   // Postfix Version

			friend ostream& operator <<(ostream& outs,const Circle& circle) noexcept;

			void printSVG(ostream& outs) noexcept {outs << (*this);}

		private:
			double radius;
			int controlCircleColor;
	};
}

#endif