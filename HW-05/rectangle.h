/*
 * Gokhan Has - 161044067
*/

#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shapes.h"

using std::endl;
using std::cout;

namespace HasShapes{

	class Rectangle: public Shapes{

		public:
			Rectangle() noexcept;
			Rectangle(int w,int h) throw();
			Rectangle(double x,double y) throw();
			Rectangle(int w,int h,double x,double y)throw();
			Rectangle(int w,int h,double x,double y,int color) throw();
			
			void setWidth(int w) throw();
			void setHeight(int h) throw();
			double getWidth() const noexcept { return width; }
			double getHeight() const noexcept { return height; }
			
			double area() const noexcept { return (height * width); } 
			double perimeter() const noexcept { return (2*(height + width)); }
			
			void setRectangleColor(int control) noexcept {controlRectangleColor=control;}
			int getControlRectangleColor() const noexcept { return controlRectangleColor; }

			Rectangle& operator++() noexcept; 			   // Prefix Version
			Rectangle& operator++(int ignoreMe) noexcept;  // Postfix Version
			Rectangle& operator--() throw(); 			   // Prefix Version
			Rectangle& operator--(int ignoreMe) throw();   // Postfix Version
		
			friend ostream& operator <<(ostream& outs,const Rectangle& rectangle) noexcept;
			
			void printSVG(ostream& outs) noexcept {outs << (*this);}
			
		private:
			double height;
			double width;
			int controlRectangleColor;
	};
} // HasShapes

#endif // _RECTANGLE_H