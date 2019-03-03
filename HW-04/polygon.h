/*
 * Gokhan Has - 161044067
 */

#ifndef _POLYGON_H
#define _POLYGON_H

#include <cstdlib> // For error check. (exit() function)
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

using std::vector;

namespace shapes{

	class Polygon{

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
					friend ostream& operator <<(ostream& outs,const Point2D& point){
						outs << point.getCoordinate_X() << "," << point.getCoordinate_Y() << endl;
						return outs;
					}

				private:
					double coordinate_X;
					double coordinate_Y;
			};

			Polygon();
			Polygon(const Point2D& point);
			Polygon(const vector <Point2D> vectorPoint2D);
			Polygon(const Rectangle& otherRectangle);
			Polygon(const Triangle& otherTriangle);
			Polygon(const Circle& otherCircle);

			// ************** Big Three ***************
			Polygon(const Polygon& copy);
			Polygon& operator =(const Polygon& other);
			~Polygon();
			// ****************************************
			
			int getSize() const { return size; }
			void setControlShapeColor(int value);
			int getControlShapeColor() const { return controlShapeColor; }

			Point2D& operator [](int index);
			Point2D& operator [](int index) const;
			
			friend bool operator ==(const Polygon& p1,const Polygon& p2);
			friend bool operator !=(const Polygon& p1,const Polygon& p2);

			Polygon operator+(const Polygon& add);
			friend ostream& operator <<(ostream& outs,const Polygon& p);

		private:
			Point2D *arrPoints;
			int size;
			int controlShapeColor;
	};
}

#endif