/*
 * Gokhan Has - 161044067
 */

#ifndef _POLYGON_H
#define _POLYGON_H

#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

using std::vector;

namespace HasShapes{

	class Polygon: public Shapes{

		public:
			class Point2D {
				
				public:
					Point2D () noexcept;
					Point2D (double x,double y) throw();
					
					void setCoordinate_X(int x) throw();
					void setCoordinate_Y(int y) throw();

					double getX() const noexcept {return coordinate_X;}
					double getY() const noexcept {return coordinate_Y;}
				
				private:
					double coordinate_X;
					double coordinate_Y;
			};

			Polygon() noexcept; // default constructor
			void setControlShapeColor(int value) noexcept { controlShapeColor = value; }
			
			// Shapes pure-virtual functions implemantation...
			double area() const noexcept { return areaPolygon; } 
			double perimeter() const noexcept { return perimeterPolygon; } 
			void printSVG(ostream& outs) noexcept { this->newPrintSVG(outs); }
			
			// Polygon's pure-virtual function...
			virtual void newPrintSVG(ostream& outs) = 0;

			virtual ~Polygon(); // Base class Polygon destructor...
		
		protected:
			int controlShapeColor;
			double areaPolygon; 
			double perimeterPolygon;
			// They will be use in PolygonVect and PolygonDyn...
	};
}

#endif // _POLYGON_H