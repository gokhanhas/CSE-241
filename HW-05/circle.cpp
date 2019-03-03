/*
 * Gokhan Has - 161044067
*/

#include "circle.h"

namespace HasShapes{	

	Circle::Circle() noexcept : Shapes(){ 
		shapeType = 'c';
		loc_x = 0;
		loc_y = 0; 
	}
	
	Circle::Circle(double r) throw() : Shapes(),radius(r) { 
		shapeType = 'c'; 
		
		try{
			if(r < 0){
				throw Control_Exception();
			}
			else{
				loc_x = radius; 
				loc_y = radius; 
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0;
			loc_y = 0;
		} 
	}
	
	Circle::Circle(double x,double y) throw() : Shapes() { 
		shapeType = 'c';
		
		try{
			if(x < 0 || y < 0)
				throw Control_Exception();
			else{
				loc_x = x;
				loc_y = y; 
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate() << endl;
			loc_x = 0;
			loc_y = 0; 
		} 
	}
	
	Circle::Circle(double r,double x,double y) throw() : Shapes(),radius(r){ 
		shapeType = 'c'; 
		
		try{
			if(r < 0 || x < 0 || y < 0)
				throw Control_Exception();
			else{
				loc_x = x;
				loc_y = y;
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0;
			loc_y = 0;
			radius = 0; 
		} 
	}
	
	Circle::Circle(double r,double x,double y,int color) throw() : Shapes(),radius(r),controlCircleColor(color) { 
		shapeType = 'c'; 
		
		try{
			if(r < 0 || x < 0 || y < 0)
				throw Control_Exception();
			else{
				loc_x = x;
				loc_y = y;
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0;
			loc_y = 0;
			radius = 0; 
		} 
	}
	
	void Circle::setRadius(double r) throw(){ 
		try{
			if(r < 0){
				throw Control_Exception();
			}
			else{
				radius = r;
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			radius = 0;
		} 
	}
	
	ostream& operator <<(ostream& outs,const Circle& circle) noexcept {

		if(circle.getControlCircleColor() == 0){ // Drawing big circle
			outs << "\n\t<circle cx=\"" << circle.get_x() << "\" cy=\"" << circle.get_y()
			 	 << "\" r=\"" << circle.getRadius() << "\" fill=\"red\" />";
		}
		else if(circle.getControlCircleColor() == 1){ 
			outs << "\n\t<circle cx=\"" << circle.get_x() << "\" cy=\"" << circle.get_y()
			 	 << "\" r=\"" << circle.getRadius() << "\" fill=\"green\" />";
		}

		else if(circle.getControlCircleColor() == 2){
			outs << "\n\t<circle cx=\"" << circle.get_x() << "\" cy=\"" << circle.get_y()
			 	 << "\" r=\"" << circle.getRadius() << "\" fill=\"black\" />";
		}
		else{ // Drawing small circle
			outs << "\n\t<circle cx=\"" << circle.get_x() << "\" cy=\"" << circle.get_y()
			 	 << "\" r=\"" << circle.getRadius() << "\" fill=\"yellow\" />";
		}
		
		return outs;
	}
	
	Circle& Circle::operator++(int ignoreMe) noexcept { // postfix version

		double tempX = loc_x;
		double tempY = loc_y;
		loc_x++;
		loc_y++;

		Circle temp(radius,tempX,tempY,this->getControlCircleColor());
		Circle *returnTemp = &temp;
		return *returnTemp;
	}

	Circle& Circle::operator++() noexcept { // prefix vesion

		loc_x++;
		loc_y++;
		
		return *this;
	}
	
	Circle& Circle::operator--(int ignoreMe) throw(){ // postfix version

		double tempX = loc_x;
		double tempY = loc_y;
		loc_x--;
		loc_y--;

		try{
			if(loc_x < 0 || loc_y < 0)
				throw Control_Exception();
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate() << endl;
			loc_x = 0;
			loc_y = 0; 
		} 

		Circle temp(radius,tempX,tempY,this->getControlCircleColor());
		Circle *returnTemp = &temp;
		return *returnTemp;
	}

	Circle& Circle::operator--() throw() { // prefix vesion

		loc_x--;
		loc_y--;

		try{
			if(loc_x < 0 || loc_y < 0)
				throw Control_Exception();
	
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.errorCoordinate() << endl;
			loc_x = 0;
			loc_y = 0; 
		} 

		
		return *this;
	}
	
} // HasShapes