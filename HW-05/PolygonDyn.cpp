/*
 * Gokhan Has - 161044067
*/

#include "PolygonDyn.h"

namespace HasShapes{

	PolygonDyn::PolygonDyn() noexcept : Polygon(),size(0),arrPoints(nullptr) { /* Body Initialize Empty */ }

	PolygonDyn::PolygonDyn(const Rectangle& otherRectangle) noexcept{
		
		areaPolygon = otherRectangle.area();
		perimeterPolygon = otherRectangle.perimeter();
		
		size = 4;
		arrPoints = new Polygon::Point2D[size];
		
		arrPoints[0].setCoordinate_X(otherRectangle.get_x());
		arrPoints[0].setCoordinate_Y(otherRectangle.get_y());
		
		arrPoints[1].setCoordinate_X(otherRectangle.get_x() + otherRectangle.getWidth());    
		arrPoints[1].setCoordinate_Y(otherRectangle.get_y());
		
		arrPoints[2].setCoordinate_X(otherRectangle.get_x() + otherRectangle.getWidth());   
		arrPoints[2].setCoordinate_Y(otherRectangle.get_y() + otherRectangle.getHeight());
		
		arrPoints[3].setCoordinate_X(otherRectangle.get_x());    
		arrPoints[3].setCoordinate_Y(otherRectangle.get_y() + otherRectangle.getHeight());
	}

	PolygonDyn::PolygonDyn(const Triangle& otherTriangle) noexcept{

		areaPolygon = otherTriangle.area();
		perimeterPolygon = otherTriangle.perimeter();
		
		size = 3;
		arrPoints = new Polygon::Point2D[size];

		if(otherTriangle.getRotateControl() == 0){ // Normal triangle's coordinate 

			arrPoints[0].setCoordinate_X(otherTriangle.get_x());
			arrPoints[0].setCoordinate_Y(otherTriangle.get_y());
			
			arrPoints[1].setCoordinate_X(otherTriangle.get_x() - otherTriangle.getEdge()/2);    
			arrPoints[1].setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
			
			arrPoints[2].setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge()/2);    
			arrPoints[2].setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
		}

		else{ // Inverse triangle's coordinate

			arrPoints[0].setCoordinate_X(otherTriangle.get_x());
			arrPoints[0].setCoordinate_Y(otherTriangle.get_y());
			
			arrPoints[1].setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge());    
			arrPoints[1].setCoordinate_Y(otherTriangle.get_y());
			
			arrPoints[2].setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge()/2);    
			arrPoints[2].setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
		}
	}

	PolygonDyn::PolygonDyn(const Circle& otherCircle) noexcept{

		areaPolygon = otherCircle.area();
		perimeterPolygon = otherCircle.perimeter();

		size = 100;
		arrPoints = new Polygon::Point2D[size];
		
		double point_X = otherCircle.get_x();
		double point_Y = otherCircle.get_y() - otherCircle.getRadius();
		
		arrPoints[0].setCoordinate_X(point_X);
		arrPoints[0].setCoordinate_Y(point_Y);

   		for(int i=1; i<size; ++i){

	    	arrPoints[i].setCoordinate_X( otherCircle.get_x() + (otherCircle.getRadius()*sin(static_cast<double>(i) * PI/50.0)));
	    	arrPoints[i].setCoordinate_Y( otherCircle.get_y() + ((-1)*otherCircle.getRadius()*cos(static_cast<double>(i) * PI/50.0)));
	    }
	}

	PolygonDyn::PolygonDyn(const PolygonDyn& copy) noexcept : size(copy.getSize()){

		arrPoints = new Polygon::Point2D[size];
		for(int i=0;i<size;++i)
			arrPoints[i] = copy.arrPoints[i];
		controlShapeColor = copy.controlShapeColor;
	}


	PolygonDyn& PolygonDyn::operator =(const PolygonDyn& other) noexcept{

		if(this != &other){
			// x = x
			delete [] arrPoints;
			arrPoints = new Polygon::Point2D[other.getSize()];
		}

		size = other.getSize();
		controlShapeColor = other.controlShapeColor;
		
		for(int i=0;i<size;++i)
			arrPoints[i] = other.arrPoints[i];

		return *this;
	}

	PolygonDyn::~PolygonDyn() noexcept { delete [] arrPoints; }


	void PolygonDyn::newPrintSVG(ostream& outs) noexcept{

		outs << "\n<polygon points = ";
		outs << "\"";
		
		for(int i=0;i<this->getSize();++i)
			outs << this->arrPoints[i].getX() << "," << this->arrPoints[i].getY() << " ";
		
		if(this->controlShapeColor == 0) // mainShape color
			outs << "\" style=\"fill:red;\"/>";
		else if(this->controlShapeColor == 1)
			outs << "\" style=\"fill:pink;\"/>"; // smallShape colors
		else
			outs << "\" style=\"fill:green;\"/>";
	}
}