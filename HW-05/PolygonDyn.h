/*
 * Gokhan Has - 161044067
*/

#ifndef _POLYGON_DYN_H
#define _POLYGON_DYN_H

#include "polygon.h"
#include "composedShape.h"

namespace HasShapes{
	
	class PolygonDyn: public Polygon{

		public:
			PolygonDyn() noexcept;
			PolygonDyn(const Rectangle& otherRectangle) noexcept;
			PolygonDyn(const Triangle& otherTriangle) noexcept;
			PolygonDyn(const Circle& otherCircle) noexcept;

			// ************** Big Three ***************
			PolygonDyn(const PolygonDyn& copy) noexcept;
			PolygonDyn& operator =(const PolygonDyn& other) noexcept;
			~PolygonDyn() noexcept;
			// ****************************************
			
			int getSize() const noexcept { return size; }
		
			void PrintSVG(ostream& outs) noexcept { this->newPrintSVG(outs);}
			void newPrintSVG(ostream& outs) noexcept;

		private:
			Polygon::Point2D *arrPoints;
			int size;
	};
}

#endif // _POLYGON_DYN_H