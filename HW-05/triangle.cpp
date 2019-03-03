/*
 * Gokhan Has - 161044067
 */

#include "triangle.h"

namespace HasShapes{

	Triangle::Triangle() noexcept :Shapes(){ 
		shapeType = 't'; 
		loc_x = 0.0; 
		loc_y = 0.0; 
	}
	
	Triangle::Triangle(double e) throw() : Shapes(),edge(e) { 
		shapeType = 't'; 
		try{
			if(e < 0){
				throw Control_Exception();
			}
			else{
				loc_x = edge/2.0; 
				loc_y = 0; 
			}
		}
		catch(Control_Exception& errorMessage){
			cout << errorMessage.error() << endl;
			loc_x = 0; // this is the top of the coordinates Triangle
			loc_y = 0;
		}
	}
	
	Triangle::Triangle(double x,double y) throw() : Shapes() { 
		shapeType = 't'; 
		
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
	
	Triangle::Triangle(double e,double x,double y) throw() : Shapes(),edge(e) { 
		shapeType = 't'; 
		try{
			if(e < 0 || x < 0 || y < 0)
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
			edge = 0; 
		} 
	}
	
	Triangle::Triangle(double e,double x,double y,int color,int rotate) throw() : Shapes(),edge(e),controlTriangleColor(color),rotateControl(rotate) { 
		shapeType = 't'; 
		try{
			if(e < 0 || x < 0 || y < 0)
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
			edge = 0; 
		}
	}

	void Triangle::setEdge(double e) throw() { 
		edge = e; 
	}
	
	ostream& operator <<(ostream& outs,const Triangle& triangle) noexcept{

		double tx2,tx3,ty2,ty3;

		if(triangle.getRotateControl() == 0){ // Coordinates for drawing normal triangles
			tx2 = triangle.get_x() - triangle.getEdge()/2; 		ty2 = triangle.get_y() + triangle.getEdge()/2*sqrt(3);
			tx3 = triangle.get_x() + triangle.getEdge()/2;		ty3 = triangle.get_y()+ triangle.getEdge()/2*sqrt(3);
		}

		else{ // Coordinates for drawing inverse triangles
			tx2 = triangle.get_x() + triangle.getEdge(); 			ty2 = triangle.get_y();
			tx3 = triangle.get_x() + triangle.getEdge()/2;			ty3 = triangle.get_y() + triangle.getEdge()/2*sqrt(3);
		}

		if(triangle.controlTriangleColor == 0){ // Drawing big triangle
			outs << "\n\t<polygon points=\"" << triangle.get_x() << "," << triangle.get_y() << " " << tx2 
				 << "," << ty2 << " " << tx3 << "," << ty3 
				 << "\" style=\"fill:red\" />" << endl;
		}
		else{ // Drawing small triangle
			outs << "\n\t<polygon points=\"" << triangle.get_x() << "," << triangle.get_y() << " " << tx2 
				 << "," << ty2 << " " << tx3 << "," << ty3 
				 << "\" style=\"fill:green;stroke-width:0.5\" />" << endl;
		}
		return outs;
	}

	
	Triangle& Triangle::operator++(int ignoreMe) noexcept { // postfix version

		double tempX = loc_x;
		double tempY = loc_y;
		loc_x++;
		loc_y++;

		Triangle temp(edge,tempX,tempY,this->getControlTriangleColor(),this->getRotateControl());
		Triangle *returnTemp = &temp;
		return *returnTemp;
	}

	Triangle& Triangle::operator++() noexcept{ // prefix version
		
		loc_x++;
		loc_y++;

		return *this;
	}

	Triangle& Triangle::operator--(int ignoreMe) throw() { // postfix version

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

		Triangle temp(edge,tempX,tempY,this->getControlTriangleColor(),this->getRotateControl());
		Triangle *returnTemp = &temp;
		return *returnTemp;
	}

	Triangle& Triangle::operator--() throw() { // prefix version
		
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