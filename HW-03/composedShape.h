/*
 * Gokhan Has - 161044067
*/

#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

class ComposedShape{

	public:
		enum Shapes{R,C,T};
		class ShapeElem{

			public:
				ShapeElem();
				ShapeElem(Rectangle tempRectangle);
				ShapeElem(Circle tempCircle);
				ShapeElem(Triangle tempTriangle);
				Rectangle getRectangle() const {return shapeElem_rectangle;}
				Circle getCircle() const {return shapeElem_circle;}
				Triangle getTriangle() const {return shapeElem_triangle;}
				Shapes getShapeType() const {return shapeType;}
				friend ostream& operator <<(ostream& outs,const ComposedShape::ShapeElem& shape);
				double getArea() const { return area;}
				double getPerimeterLength() const {return perimeterLength;}

			private:
				Shapes shapeType;
				Rectangle shapeElem_rectangle;
				Circle shapeElem_circle;
				Triangle shapeElem_triangle;
				double area,perimeterLength;
		};
		
		ComposedShape();
		ComposedShape(Rectangle mainR,Rectangle smallR);
		ComposedShape(Rectangle mainR,Circle smallC);
		ComposedShape(Rectangle mainR,Triangle smallT);
		ComposedShape(Triangle mainT,Rectangle smallR); 
		ComposedShape(Triangle mainT,Circle smallC);
		ComposedShape(Triangle mainT,Triangle smallT);
		//ComposedShape(Circle mainC,Rectangle smallR); It is empty.
		ComposedShape(Circle mainC,Circle smallC);
		//ComposedShape(Circle mainC,Triangle smallT);	It is empty.
		void optimalFit(int number);
		friend ostream& operator <<(ostream& outs,const ComposedShape& composed_shape);
		ShapeElem operator[](int i){return this->vectorShapeElem[i];}			 

	private:
		Shapes mainShape,innerShape;
		vector<ShapeElem> vectorShapeElem;
		Rectangle mainRectangle,smallRectangle;
		Triangle mainTriangle,smallTriangle;
		Circle mainCircle,smallCircle;
};

#endif