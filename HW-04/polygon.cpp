/*
 * Gokhan Has - 161044067
*/

#include "polygon.h"

namespace shapes{

	// ************************* Defining Point2D class functions ********************************

	Polygon::Point2D::Point2D() : coordinate_X(0),coordinate_Y(0) {/* Body intentionally empty */}
	
	Polygon::Point2D::Point2D(double x,double y) : coordinate_X(x),coordinate_Y(y){
		
		if(x < 0 || y < 0){
			// Error check
			cout << "Error. x or y has invalid input." << endl;
			coordinate_X=0; coordinate_Y=0;
			exit(0);
		}
	}

	bool Polygon::Point2D::operator !=(const Point2D& other) const{
		return !((coordinate_X == other.getCoordinate_X()) && (coordinate_Y == other.getCoordinate_Y()));
	}

	void Polygon::Point2D::setCoordinate_X(double x){ 
		
		if(x < 0){
			cout << "Error.X coordinate do NOT be negative !" << endl;
			cout << "xx : " << x << endl;
			coordinate_X = 0;
			exit(0);
		}
		coordinate_X = x; 
	}
	
	void Polygon::Point2D::setCoordinate_Y(double y){ 
		
		if(y < 0){
			cout << "Error.Y coordinate do NOT be negative !" << endl;
			coordinate_Y = 0;
			exit(0);
		}
		coordinate_Y = y; 
	}


	// ************************** Ending Point2D class functions ********************************


	Polygon::Polygon() : size(0) { arrPoints = nullptr; }

	Polygon::Polygon(const Point2D& point){
		size = 1;
		arrPoints = new Point2D[size];
		arrPoints[0] = point;
	}

	Polygon::Polygon(const vector <Point2D> vectorPoint2D){

		size = vectorPoint2D.size();
		arrPoints = new Point2D[size];

		for(int i=0;i<size;++i)
			arrPoints[i] = vectorPoint2D[i];
	}

	Polygon::Polygon(const Rectangle& otherRectangle){

		size = 4;
		arrPoints = new Point2D[size];

		arrPoints[0].setCoordinate_X(otherRectangle.getRx());
		arrPoints[0].setCoordinate_Y(otherRectangle.getRy());
		
		arrPoints[1].setCoordinate_X(otherRectangle.getRx() + otherRectangle.getWidth());    
		arrPoints[1].setCoordinate_Y(otherRectangle.getRy());
		
		arrPoints[2].setCoordinate_X(otherRectangle.getRx() + otherRectangle.getWidth());   
		arrPoints[2].setCoordinate_Y(otherRectangle.getRy() + otherRectangle.getHeight());
		
		arrPoints[3].setCoordinate_X(otherRectangle.getRx());    
		arrPoints[3].setCoordinate_Y(otherRectangle.getRy() + otherRectangle.getHeight());
	}

	Polygon::Polygon(const Triangle& otherTriangle){

		size = 3;
		arrPoints = new Point2D[size];

		if(otherTriangle.getRotateControl() == 0){ // Normal triangle's coordinate 

			arrPoints[0].setCoordinate_X(otherTriangle.getTx());
			arrPoints[0].setCoordinate_Y(otherTriangle.getTy());
			
			arrPoints[1].setCoordinate_X(otherTriangle.getTx() - otherTriangle.getEdge()/2);    
			arrPoints[1].setCoordinate_Y(otherTriangle.getTy() + otherTriangle.getEdge()/2*sqrt(3));
			
			arrPoints[2].setCoordinate_X(otherTriangle.getTx() + otherTriangle.getEdge()/2);    
			arrPoints[2].setCoordinate_Y(otherTriangle.getTy() + otherTriangle.getEdge()/2*sqrt(3));
		}

		else{ // Inverse triangle's coordinate

			arrPoints[0].setCoordinate_X(otherTriangle.getTx());
			arrPoints[0].setCoordinate_Y(otherTriangle.getTy());
			
			arrPoints[1].setCoordinate_X(otherTriangle.getTx() + otherTriangle.getEdge());    
			arrPoints[1].setCoordinate_Y(otherTriangle.getTy());
			
			arrPoints[2].setCoordinate_X(otherTriangle.getTx() + otherTriangle.getEdge()/2);    
			arrPoints[2].setCoordinate_Y(otherTriangle.getTy() + otherTriangle.getEdge()/2*sqrt(3));
		}
	}

	Polygon::Polygon(const Circle& otherCircle){

		size = 100;
		arrPoints = new Point2D[size];
		
		double point_X = otherCircle.getCx();
		double point_Y = otherCircle.getCy() - otherCircle.getRadius();
		
		arrPoints[0].setCoordinate_X(point_X);
		arrPoints[0].setCoordinate_Y(point_Y);

   		for(int i=1; i<size; ++i){

	    	arrPoints[i].setCoordinate_X( otherCircle.getCx() + (otherCircle.getRadius()*sin(static_cast<double>(i) * PI/50.0)));
	    	arrPoints[i].setCoordinate_Y( otherCircle.getCy() + ((-1)*otherCircle.getRadius()*cos(static_cast<double>(i) * PI/50.0)));
	    }
	}

	// Big Three ...
	Polygon::Polygon(const Polygon& copy) : size(copy.getSize()){

		arrPoints = new Point2D[size];
		for(int i=0;i<size;++i)
			arrPoints[i] = copy.arrPoints[i];
		controlShapeColor = copy.getControlShapeColor();
	}

	Polygon& Polygon::operator =(const Polygon& other){

		if(size != other.getSize()){
			// x = x
			delete [] arrPoints;
			arrPoints = new Point2D[other.getSize()];
		}

		size = other.getSize();
		controlShapeColor = other.getControlShapeColor();
		
		for(int i=0;i<size;++i)
			arrPoints[i] = other.arrPoints[i];

		return *this;
	}

	Polygon::~Polygon() { delete [] arrPoints; }
	// Big Three Ends...

	void Polygon::setControlShapeColor(int value){
		controlShapeColor = value;
	}
	
	Polygon::Point2D& Polygon::operator [](int index){ 
		
		if(index >= this->getSize() || index < 0){
			cout << "Error.Index is invalid ! " << endl;
			exit(0);
		}

		return arrPoints[index]; 
	}

	bool operator !=(const Polygon& p1,const Polygon& p2){
		
		if(p1.getSize() != p2.getSize() )
			return true;

		for(int i=0;i<p1.getSize();++i){

			if(p1.arrPoints[i] != p2.arrPoints[i])
				return true;
		}
		return false;
	}

	bool operator ==(const Polygon& p1,const Polygon& p2){
		return !(p1 != p2);
	}

	Polygon Polygon::operator+(const Polygon& add){

		Polygon temp;
		temp.size = size + add.getSize();
		temp.arrPoints = new Point2D[temp.getSize()];
		int i;

		for(i=0;i<size;++i)
			temp.arrPoints[i] = arrPoints[i];

		int j=0;
		for(i=size;i<(size + add.getSize());++i){
			temp.arrPoints[i] = add.arrPoints[j];
			++j;
		}

		return temp;
	}

	ostream& operator <<(ostream& outs,const Polygon& p){

		outs << "\n<polygon points = ";
		outs << "\"";
		
		for(int i=0;i<p.size;++i)
			outs << p.arrPoints[i].getCoordinate_X() << "," << p.arrPoints[i].getCoordinate_Y() << " ";
		
		if(p.getControlShapeColor() == 0) // mainShape color
			outs << "\" style=\"fill:red;\"/>";
		else
			outs << "\" style=\"fill:green;\"/>"; // smallShape color

		return outs;
	}
}