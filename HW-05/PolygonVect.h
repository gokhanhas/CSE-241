/*
 * Gokhan Has - 161044067
*/

#ifndef _POLYGON_VECT_H
#define _POLYGON_VECT_H

#include "polygon.h"

namespace HasShapes{	

	class PolygonVect: public Polygon{

		public:
			PolygonVect() noexcept;
			PolygonVect(const Rectangle& otherRectangle) noexcept;
			PolygonVect(const Triangle& otherTriangle) noexcept;
			PolygonVect(const Circle& otherCircle) noexcept;

			// ************** Big Three ***************
			PolygonVect(const PolygonVect& copy) noexcept;
			PolygonVect& operator =(const PolygonVect& other) noexcept;
			~PolygonVect() noexcept;
			// ****************************************
			
			void PrintSVG(ostream& outs)noexcept{ this->newPrintSVG(outs);}
			void newPrintSVG(ostream& outs) noexcept;

		private:
			vector <Polygon::Point2D> vectorPoint2D;
	};
}


#endif