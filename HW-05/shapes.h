/*
 *	Gokhan Has - 161044067
*/

#ifndef _SHAPES_H
#define _SHAPES_H

#include <iostream>
#include <exception>

using std::ostream;
using std::exception;
using std::cout;
using std::endl;

namespace HasShapes{
	
	
	class Control_Exception: public exception{
		public:
			const char* errorCoordinate_X() const throw(){ 
				return "Error ! X Coordinate must be positive or zero !!!"; 
			}
			const char* errorCoordinate_Y() const throw(){ 
				return "Error ! Y Coordinate must be positive or zero !!!"; 
			}
			const char* errorCoordinate() const throw(){ 
				return "Error ! Coordinates must be positive or zero !!!"; 
			}
			const char* error() const throw(){ 
				return "Error ! You entered negative input  !!!"; 
			}
			const char* indexError() const throw(){ 
				return "Error ! Index must be positive  !!!"; 
			}
	};


	class Shapes{
		
		public:
			Shapes();
			
			// Pure-virtual Functions
			virtual double area() const = 0;
			virtual double perimeter() const = 0;
			virtual void printSVG(ostream& outs) = 0;
			
			// Virtual functions...
			virtual Shapes& operator++(){/* Body Initialize Empty */} 			  	 // Prefix Version
			virtual Shapes& operator++(int ignoreMe){/* Body Initialize Empty */}    // Postfix Version
			virtual Shapes& operator--(){/* Body Initialize Empty */} 			     // Prefix Version
			virtual Shapes& operator--(int ignoreMe){/* Body Initialize Empty */}    // Postfix Version
			
			friend bool operator ==(const Shapes& shape1,const Shapes& shape2);
			friend bool operator !=(const Shapes& shape1,const Shapes& shape2);

			virtual double get_x() const noexcept { return loc_x; }
			virtual double get_y() const noexcept { return loc_y; }

			virtual void set_x(double x_value) throw();
			virtual void set_y(double y_value) throw();

			virtual char getType() const { return shapeType; }
			virtual ~Shapes(); // Base-Class virtual destructor...			

		protected:
			double loc_x;
			double loc_y;
			char shapeType;	
	};
}

#endif // _SHAPES_H