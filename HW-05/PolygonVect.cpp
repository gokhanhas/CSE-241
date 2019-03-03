/*
 * Gokhan Has - 161044067
*/

#include "PolygonVect.h"

namespace HasShapes{

	PolygonVect::PolygonVect() noexcept {/* Body Initialize Empty */}
	
	PolygonVect::PolygonVect(const Rectangle& otherRectangle)noexcept{

		areaPolygon = otherRectangle.area();
		perimeterPolygon = otherRectangle.perimeter();
		
		Polygon::Point2D temp;
		
		temp.setCoordinate_X(otherRectangle.get_x());
		temp.setCoordinate_Y(otherRectangle.get_y());
		vectorPoint2D.push_back(temp);

		temp.setCoordinate_X(otherRectangle.get_x() + otherRectangle.getWidth());
		temp.setCoordinate_Y(otherRectangle.get_y());
		vectorPoint2D.push_back(temp);

		temp.setCoordinate_X(otherRectangle.get_x() + otherRectangle.getWidth());
		temp.setCoordinate_Y(otherRectangle.get_x() + otherRectangle.getHeight());
		vectorPoint2D.push_back(temp);

		temp.setCoordinate_X(otherRectangle.get_x());
		temp.setCoordinate_Y(otherRectangle.get_y() + otherRectangle.getHeight());
		vectorPoint2D.push_back(temp);
	}
	
	PolygonVect::PolygonVect(const Triangle& otherTriangle)noexcept{

		areaPolygon = otherTriangle.area();
		perimeterPolygon = otherTriangle.perimeter();

		Polygon::Point2D temp;

		if(otherTriangle.getRotateControl() == 0){ // Normal triangle's coordinate 
			
			temp.setCoordinate_X(otherTriangle.get_x());
			temp.setCoordinate_Y(otherTriangle.get_y());
			vectorPoint2D.push_back(temp);

			temp.setCoordinate_X(otherTriangle.get_x() - otherTriangle.getEdge()/2);
			temp.setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
			vectorPoint2D.push_back(temp);

			temp.setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge()/2);
			temp.setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
			vectorPoint2D.push_back(temp);
		}

		else{ // Inverse triangle's coordinate

			temp.setCoordinate_X(otherTriangle.get_x());
			temp.setCoordinate_Y(otherTriangle.get_y());
			vectorPoint2D.push_back(temp);

			temp.setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge());
			temp.setCoordinate_Y(otherTriangle.get_y());
			vectorPoint2D.push_back(temp);

			temp.setCoordinate_X(otherTriangle.get_x() + otherTriangle.getEdge()/2);
			temp.setCoordinate_Y(otherTriangle.get_y() + otherTriangle.getEdge()/2*sqrt(3));
			vectorPoint2D.push_back(temp);			
		}
	}
	
	PolygonVect::PolygonVect(const Circle& otherCircle)noexcept{

		areaPolygon = otherCircle.area();
		perimeterPolygon = otherCircle.perimeter();

		Polygon::Point2D temp;
		int size = 100;
		
		double point_X = otherCircle.get_x();
		double point_Y = otherCircle.get_y() - otherCircle.getRadius();
		
		temp.setCoordinate_X(point_X);
		temp.setCoordinate_Y(point_Y);
		vectorPoint2D.push_back(temp);	

   		for(int i=1; i<size; ++i){

	    	temp.setCoordinate_X( otherCircle.get_x() + (otherCircle.getRadius()*sin(static_cast<double>(i) * PI/50.0)));
	    	temp.setCoordinate_Y( otherCircle.get_y() + ((-1)*otherCircle.getRadius()*cos(static_cast<double>(i) * PI/50.0)));
	    	vectorPoint2D.push_back(temp);
	    }
	}
	
	PolygonVect::PolygonVect(const PolygonVect& copy)noexcept{

		for(int i=0;i<copy.vectorPoint2D.size();++i)
			vectorPoint2D[i] = copy.vectorPoint2D[i];
		controlShapeColor = copy.controlShapeColor;
	}
	
	PolygonVect& PolygonVect::operator =(const PolygonVect& other)noexcept{

		if(this != &other){

			vectorPoint2D.clear();
			
			for(int i=0;i<other.vectorPoint2D.size();++i)
				vectorPoint2D[i] = other.vectorPoint2D[i];
			controlShapeColor = other.controlShapeColor;
		}
		return *this;
	}
	
	PolygonVect::~PolygonVect() noexcept {/* Body Initialize Empty */}
	
	void PolygonVect::newPrintSVG(ostream& outs) noexcept{

		outs << "\n<polygon points = ";
		outs << "\"";
		
		for(int i=0;i<this->vectorPoint2D.size();++i)
			outs << this->vectorPoint2D[i].getX() << "," << this->vectorPoint2D[i].getY() << " ";
		
		if(this->controlShapeColor == 0) // mainShape color
			outs << "\" style=\"fill:red;\"/>";
		else if(this->controlShapeColor == 1)
			outs << "\" style=\"fill:purple;\"/>"; // smallShape color
		else
			outs << "\" style=\"fill:green;\"/>";
	}
}