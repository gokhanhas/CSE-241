/*
 * Gokhan Has - 161044067
*/

// This is the implemantation for Polygon abstract class...
#include "polygon.h"

namespace HasShapes{


	Polygon::Polygon() noexcept:Shapes(){ /* Body Initialize Empty */ }
	Polygon::Point2D::Point2D() noexcept { /* Body Initialize Empty */ }
	Polygon::Point2D::Point2D(double x,double y)throw(){

		try{
			if(x < 0 || y < 0)
				throw Control_Exception();
			else{
				coordinate_X = x;
				coordinate_Y = y;
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate() << endl;
			coordinate_X = 0;
			coordinate_Y = 0; 
		} 
	}

	void Polygon::Point2D::setCoordinate_X(int x) throw(){
		try{
			if(x < 0)
				throw Control_Exception();
			else
				coordinate_X = x;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate_X() << endl;
			coordinate_X = 0;
		} 
	}

	void Polygon::Point2D::setCoordinate_Y(int y) throw(){
		try{
			if(y < 0)
				throw Control_Exception();
			else
				coordinate_Y = y;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate_Y() << endl;
			coordinate_Y = 0;
		} 
	}

	Polygon::~Polygon() {/* Body Initialize Empty */}
} // HasShapes