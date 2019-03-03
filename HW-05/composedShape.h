/*
 * Gokhan Has - 161044067
*/

#ifndef _COMPOSEDSHAPE_H
#define _COMPOSEDSHAPE_H

#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <string>

using std::vector;
using std::ostream;

namespace HasShapes{ 
	
	class ComposedShape : public Shapes{

		public:

			ComposedShape() noexcept ;
			ComposedShape(Rectangle& mainR,Rectangle& smallR) noexcept;
			ComposedShape(Rectangle& mainR,Circle& smallC) noexcept;
			ComposedShape(Rectangle& mainR,Triangle& smallT) noexcept;
			ComposedShape(Triangle& mainT,Rectangle& smallR) noexcept; 
			ComposedShape(Triangle& mainT,Circle& smallC) noexcept;
			ComposedShape(Triangle& mainT,Triangle& smallT) noexcept;
			ComposedShape(Circle& mainC,Rectangle& smallR) noexcept;
			ComposedShape(Circle& mainC,Circle& smallC) noexcept;
			ComposedShape(Circle& mainC,Triangle& smallT) noexcept;
			void optimalFit() noexcept;
			friend ostream& operator <<(ostream& outs,const ComposedShape& object) noexcept;
			
			int getVectorSize() const noexcept { return vectorShape.size(); }
			vector <Shapes *> getComposedShapeVector() const noexcept { return vectorShape; }
			
			double area() const noexcept;
			double perimeter() const noexcept;
			void printSVG(ostream& outs) noexcept {outs << (*this);}

		private:
			vector <Shapes *> vectorShape;
			Rectangle mainRectangle,smallRectangle;
			Triangle mainTriangle,smallTriangle;
			Circle mainCircle,smallCircle;
			int optimalFitNumber;
			void setOptimalFitNumber(int number) noexcept;
			/*
			 * Fx: optimalFitNumber 1 means 
			 * main:Rectangle inner:Rectangle...
			*/ 
	};
}

#endif // _COMPOSEDSHAPE_H