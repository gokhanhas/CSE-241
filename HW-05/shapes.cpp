/*
 *	Gokhan Has - 161044067
*/

// This is the implementatition for the abstract class Shapes.

#include "shapes.h"

namespace HasShapes{

	Shapes::Shapes() {/* Default Constructor */}

	bool operator ==(const Shapes& shape1,const Shapes& shape2){
		return (shape1.area() == shape2.area());
	}

	bool operator !=(const Shapes& shape1,const Shapes& shape2){
		return !(shape1 == shape2);
	}

	void Shapes::set_x(double x_value) throw() { 
		
		try{
			if(x_value < 0)
				throw Control_Exception();
			else
				loc_x = x_value;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate_X() << endl;
			loc_x = 0;
		} 
	}
	
	void Shapes::set_y(double y_value) throw() { 
		try{
			if(y_value < 0)
				throw Control_Exception();
			else
				loc_y = y_value;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate_Y() << endl;
			loc_y = 0;
		} 
	}

	Shapes::~Shapes() {/* Body Initialize Empty */}

} // HasShapes