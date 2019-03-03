/*
 * Gokhan Has - 161044067
*/

#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include "polygon.h"

using std::vector;
using std::ostream;

namespace shapes{ 
	
	class ComposedShape{

		public:

			ComposedShape();
			ComposedShape(Rectangle& mainR,Rectangle& smallR);
			ComposedShape(Rectangle& mainR,Circle& smallC);
			ComposedShape(Rectangle& mainR,Triangle& smallT);
			ComposedShape(Triangle& mainT,Rectangle& smallR); 
			ComposedShape(Triangle& mainT,Circle& smallC);
			ComposedShape(Triangle& mainT,Triangle& smallT);
			ComposedShape(Circle& mainC,Rectangle& smallR);
			ComposedShape(Circle& mainC,Circle& smallC);
			ComposedShape(Circle& mainC,Triangle& smallT);
			void optimalFit();
			friend ostream& operator <<(ostream& outs,const ComposedShape& object);
		
		private:
			vector <Polygon> vectorPolygon;
			Rectangle mainRectangle,smallRectangle;
			Triangle mainTriangle,smallTriangle;
			Circle mainCircle,smallCircle;
			int optimalFitNumber;
			void setOptimalFitNumber(int number);
			/*
			 * Fx: optimalFitNumber 1 means 
			 * main:Rectangle inner:Rectangle...
			*/ 
	};
}

#endif