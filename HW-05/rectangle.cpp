/*
 *	Gokhan Has - 161044067
*/

#include "rectangle.h"

namespace HasShapes{
	
	Rectangle::Rectangle() noexcept : Shapes(){ 
		shapeType = 'r'; 
		loc_x = 0; 
		loc_y = 0;  
	}
	
	Rectangle::Rectangle(int w,int h) throw(): Shapes(),height(h),width(w) { 
		shapeType = 'r'; 
		
		try{
			if(w < 0 || h < 0){
				throw Control_Exception();
			}
			loc_x = 0;
			loc_y = 0;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			width = 0;
			height = 0;
		}
	}
	
	Rectangle::Rectangle(double x,double y) throw() : Shapes() { 
		shapeType = 'r'; 
		
		try{
			if(x < 0 || y < 0){
				throw Control_Exception();
			}
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
	
	Rectangle::Rectangle(int w,int h,double x,double y) throw(): Shapes(),height(h),width(w) { 
		shapeType = 'r'; 
		
		try{
			if(x < 0 || y < 0 || w < 0 || h < 0){
				throw Control_Exception();
			}
			else{
				loc_x = x; 
				loc_y = y; 
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0;
			loc_y = 0;
			height = 0;
			width = 0;
		} 
	}
	
	Rectangle::Rectangle(int w,int h,double x,double y,int color) throw(): Shapes(),height(h),width(w),controlRectangleColor(color) { 
		shapeType = 'r'; 
		
		try{
			if(x < 0 || y < 0 || w < 0 || h < 0){
				throw Control_Exception();
			}
			else{
				loc_x = x; 
				loc_y = y; 
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0;
			loc_y = 0;
			height = 0;
			width = 0;
		} 
	}

	void Rectangle::setWidth(int w) throw(){ 
		try{
			if(w < 0){
				throw Control_Exception();
			}
			else
				width = w;
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			width = 0;
			height = 0;
		}
	}
	
	void Rectangle::setHeight(int h) throw() {
		height = h; 
	}
	
	ostream& operator <<(ostream& outs,const Rectangle& rectangle) noexcept {

		if(rectangle.getControlRectangleColor() == 0){ // Drawing big rectangle
			outs << "\n\t<rect x=\"" << rectangle.get_x() << "\" y=\"" << rectangle.get_y()  << "\" width=\""
				 << rectangle.getWidth() << "\" height=\"" << rectangle.getHeight() 
				 << "\" style=\"fill:red\" />" << endl;
		}
			
		else if(rectangle.getControlRectangleColor() == 1){ // Drawing small rectangle
			outs << "\n\t<rect x=\"" << rectangle.get_x() << "\" y=\"" << rectangle.get_y()  << "\" width=\""
				 << rectangle.getWidth() << "\" height=\"" << rectangle.getHeight() 
				 << "\" style=\"fill:green;stroke-width:1\" />" << endl;
		}

		else if(rectangle.getControlRectangleColor() == 2){ // Drawing small rectangle
			outs << "\n\t<rect x=\"" << rectangle.get_x() << "\" y=\"" << rectangle.get_y()  << "\" width=\""
				 << rectangle.getWidth() << "\" height=\"" << rectangle.getHeight() 
				 << "\" style=\"fill:pink;stroke-width:1\" />" << endl;
		}

		return outs;
	}
	
	
	Rectangle& Rectangle::operator++(int ignoreMe) noexcept { // postfix version

		double tempX = loc_x;
		double tempY = loc_y;
		loc_x++;
		loc_y++;

		Rectangle temp(width,height,tempX,tempY,this->getControlRectangleColor());
		Rectangle *returnTemp = &temp;
		return *returnTemp;
	}

	Rectangle& Rectangle::operator++() noexcept { // prefix version

		loc_x++;
		loc_y++;

		return *this;
	}

	Rectangle& Rectangle::operator--(int ignoreMe) throw() { // postfix version

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
		
		Rectangle temp(width,height,tempX,tempY,this->getControlRectangleColor());
		Rectangle *returnTemp = &temp;
		return *returnTemp;
	}

	Rectangle& Rectangle::operator--() throw() { // prefix version

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