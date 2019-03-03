// CSE 241 - HW 1
// Gokhan Has - 161044067

#include <iostream>
#include <fstream>
#include "calShapes.h"

using namespace std;

int main(){

	double mainRwidth,mainRheight,mainRadius,mainEdge;
	double smallRwidth,smallRheight,smallRadius,smallEdge;
	char mainContainer,smallShape;
	Shapes mainCo,smallSh;
	
	cout << "Please enter the main container shape (R, C, T)" << endl;
	cin >> mainContainer;

	if(whichShape(mainCo,mainContainer) == 0)
		return 0;
	
	shapes(mainCo,mainRwidth,mainRheight,mainRadius,mainEdge);

	/* Determining the shape of main and small container. */
	
	cout << "Please enter the small shape (R, C, T)" << endl;
	cin >> smallShape;

	if(whichShape(smallSh,smallShape) == 0)
		return 0;
	
	shapes(smallSh,smallRwidth,smallRheight,smallRadius,smallEdge);

	ofstream file;
	file.open("output.svg"); /* Opening svg file. */
	file << "<svg version = \"1.1\"" << endl
		 << "\tbaseProfile=\"full\"" << endl
		 << "\twidth=\"100%\" height=\"100%\"" << endl
		 << "\txmlns=\"http://www.w3.org/2000/svg\">" << endl;

	if(mainCo == R && smallSh == R)
		rectangleInRectangle(file,mainRwidth,mainRheight,smallRwidth,smallRheight);
	

	else if(mainCo == Shapes::R && smallSh == Shapes::C)
		circleInRectangle(file,mainRwidth,mainRheight,smallRadius);


	else if(mainCo == Shapes::R && smallSh == Shapes::T)
		triangleInRectangle(file,mainRwidth,mainRheight,smallEdge);
	

	else if(mainCo == Shapes::C && smallSh == Shapes::R){
		// ..................
	}

	else if(mainCo == Shapes::C && smallSh == Shapes::C)
		circleInCircle(file,mainRadius,smallRadius);

	else if(mainCo == Shapes::C && smallSh == Shapes::T){
		// ..................
	}

	else if(mainCo == Shapes::T && smallSh == Shapes::R)
		rectangleInTriangle(file,mainEdge,smallRwidth,smallRheight);
	

	else if(mainCo == Shapes::T && smallSh == Shapes::C)
		circleInTriangle(file,mainEdge,smallRadius);

	else if(mainCo == Shapes::T && smallSh == Shapes::T)
		triangleInTriangle(file,mainEdge,smallEdge);
	

	file << "</svg>";
	file.close(); /* Closing svg file. */
	return 0;
}