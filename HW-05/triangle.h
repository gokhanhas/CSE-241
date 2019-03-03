/*
 * Gokhan Has - 161044067
*/

#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "shapes.h"
#include <fstream>
#include <cmath>

using std::ostream;
using std::ofstream;
using std::cout;
using std::endl;

namespace HasShapes{
	
	class Triangle: public Shapes{

		public:
			Triangle() noexcept ;
			Triangle(double e) throw();
			Triangle(double x,double y) throw();
			Triangle(double e,double x,double y) throw();
			Triangle(double e,double x,double y,int color,int rotate) throw();
			
			void setEdge(double e) throw();
			double getEdge() const noexcept { return edge; }
			
			double area() const noexcept { return ((edge * edge * sqrt(3)) / 4);}
			double perimeter() const noexcept { return (3*edge);}
			
			void setRotateControl(int rotate) noexcept { rotateControl = rotate; }
			int getRotateControl() const noexcept { return rotateControl; }
			
			void setTriangleColor(int control) noexcept { controlTriangleColor=control; }
			int getControlTriangleColor() const noexcept { return controlTriangleColor; }
			
			Triangle& operator++() noexcept; 			   // Prefix Version
			Triangle& operator++(int ignoreMe) noexcept;   // Postfix Version
			Triangle& operator--() throw(); 			   // Prefix Version
			Triangle& operator--(int ignoreMe) throw();    // Postfix Version

			friend ostream& operator <<(ostream& outs,const Triangle& triangle) noexcept;

			void printSVG(ostream& outs) noexcept {outs << (*this);}
			
		private:
			int rotateControl;
			double edge;
			int controlTriangleColor;
	};
}

#endif // _TRIANGLE_H