/*
 * Gokhan Has - 161044067
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>

using std::ostream;
using std::ofstream;
using std::cout;
using std::endl;

namespace shapes{
	
	class Triangle{

		public:
			Triangle();
			Triangle(double e);
			Triangle(double x,double y);
			Triangle(double e,double x,double y);
			double getEdge() const { return edge; }
			double getTx() const { return tx; }
			double getTy() const { return ty; }
			double getPerimeterLength() const { return (3*edge);}
			double getArea() const { return ((edge * edge * sqrt(3)) / 4);}
			void setRotateControl(int rotate) { rotateControl = rotate; }
			int getRotateControl() const { return rotateControl; }
			void setEdge(double e);
			void setCoordinate_X(double x);
			void setCoordinate_Y(double y);
			void setTriangleColor(int control){controlTriangleColor=control;}
			friend ostream& operator <<(ostream& outs,const Triangle& triangle);
			Triangle operator++(); // prefix version
			Triangle operator++(int ignoreMe); // postfix version
			Triangle operator--(); // prefix version
			Triangle operator--(int ignoreMe); // postfix version
			friend Triangle operator+(const Triangle& triangle1,double add);
			friend Triangle operator-(const Triangle& triangle1,double subtract);
			friend bool operator ==(const Triangle& triangle1,const Triangle& triangle2);
			friend bool operator !=(const Triangle& triangle1,const Triangle& triangle2);
			friend bool operator <=(const Triangle& triangle1,const Triangle& triangle2);
			friend bool operator >=(const Triangle& triangle1,const Triangle& triangle2);
		
		private:
			int rotateControl;
			double edge;
			double tx;
			double ty;
			int controlTriangleColor;
	};
}

#endif