/*
 * Gokhan Has - 161044067
 */

#ifndef _POLYLINE_H
#define _POLYLINE_H

#include <cstdlib> // For error check. (exit() function)
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

using std::vector;
using shapes::Rectangle;
using shapes::Circle;
using shapes::Triangle;

namespace {

	class Polyline{

		public:
			class Point2D{
				public:
					Point2D();
					Point2D(double x,double y);
					void setCoordinate_X(double x);
					void setCoordinate_Y(double y);
					double getCoordinate_X() const { return coordinate_X; }
					double getCoordinate_Y() const { return coordinate_Y; }
					bool operator !=(const Point2D& other) const;

				private:
					double coordinate_X;
					double coordinate_Y;
			};

			Polyline();
			Polyline(vector <Point2D> vectorPoint2D);
			Polyline(const Rectangle& otherRectangle);
			Polyline(const Triangle& otherTriangle);
			Polyline(const Circle& otherCircle);

			// ************** Big Three ***************
			Polyline(const Polyline& copy);
			Polyline& operator =(const Polyline& other);
			~Polyline();
			// ****************************************
			
			int getSize() const { return size; }
		
			Point2D& operator [](int index);
			Point2D& operator [](int index) const;
			
			friend bool operator ==(const Polyline& p1,const Polyline& p2);
			friend bool operator !=(const Polyline& p1,const Polyline& p2);

			Polyline operator+(const Polyline& add);
			friend ostream& operator <<(ostream& outs,const Polyline& p);

		private:
			Point2D *arrPoints;
			int size;
	};
}

#endif