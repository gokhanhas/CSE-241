/*
 * Gokhan Has - 161044067
*/

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "composedShape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"

using namespace std;
using namespace HasShapes;

// Global operator << printing the shapes to SVG files...
ostream& operator <<(ostream& outs,Shapes& shape);

void writingSVG(ofstream &filename);
void printAll(vector <Shapes *> vectorShape);
void printPoly(vector <Shapes *> vectorShape);
vector <Shapes *> convertAll(vector <Shapes *> vectorShape);
void sortShapes(vector <Shapes *> &vectorShape);
	
// This functions use convertAll Functions...
Polygon* convertCircle(Shapes * shapesPointer);
Polygon* convertRectangle(Shapes* shapesPointer);
Polygon* convertTriangle(Shapes* shapesPointer);
Polygon* convertComposedShape(Shapes* shapesPointer);


int main(){

	Rectangle mainR(300,100),innerR(80,40);
	Circle mainC(200),innerC(20);
	Triangle mainT(800),innerT(27);

	ofstream file1,file2,file3,file4,file5,file6,file7,file8,file9;
	ofstream test1,test2,test3;
	
	/********** Testing ComposedShape's **********/

	cout << endl << "****** Testing ComposedShape's Function ******" << endl <<endl;
	
	file1.open("output1.svg");
	writingSVG(file1);
	ComposedShape testRR(mainR,innerR);
 	testRR.optimalFit();
 	file1 << testRR;
 	file1 << "\n</svg>";
 	file1.close();
 	
 	file2.open("output2.svg");
	writingSVG(file2);
	ComposedShape testRC(mainR,innerC);
 	testRC.optimalFit();
 	file2 << testRC;
 	file2 << "\n</svg>";
 	file2.close();

 	file3.open("output3.svg");
	writingSVG(file3);
	ComposedShape testRT(mainR,innerT);
 	testRT.optimalFit();
 	file3 << testRT;
 	file3 << "\n</svg>";
 	file3.close();

 	file4.open("output4.svg");
	writingSVG(file4);
	ComposedShape testTR(mainT,innerR);
 	testTR.optimalFit();
 	file4 << testTR;
 	file4 << "\n</svg>";
 	file4.close();

 	file5.open("output5.svg");
	writingSVG(file5);
	ComposedShape testTC(mainT,innerC);
 	testTC.optimalFit();
 	file5 << testTC;
 	file5 << "\n</svg>";
 	file5.close();

 	file6.open("output6.svg");
	writingSVG(file6);
	ComposedShape testTT(mainT,innerT);
 	testTT.optimalFit();
 	file6 << testTT;
 	file6 << "\n</svg>";
 	file6.close();

 	
 	file7.open("output7.svg");
	writingSVG(file7);
	ComposedShape testCR(mainC,innerR);
 	testCR.optimalFit();
 	file7 << testCR;
 	file7 << "\n</svg>";
 	file7.close();

	
	file8.open("output8.svg");
	writingSVG(file8);
	ComposedShape testCC(mainC,innerC);
 	testCC.optimalFit();
 	file8 << testCC;
 	file8 << "\n</svg>";
 	file8.close();

 	file9.open("output9.svg");
	writingSVG(file9);
	ComposedShape testCT(mainC,innerT);
 	testCT.optimalFit();
 	file9 << testCT;
 	file9 << "\n</svg>";
 	file9.close();
	
 	/****************** Testing Global Functions *************************/

 	vector <Shapes *> vectorShape;

 	Rectangle testR(350,250,0,0);       testR.setRectangleColor(1);
 	Circle testC(50,100,100); 			testC.setCircleColor(3);
 	Triangle testT(100,220,0);				
 	PolygonDyn testPolyDyn(innerR);     testPolyDyn.setControlShapeColor(1);
 	PolygonVect testPolyVect(innerC);   

 	Circle testCSc(500);
 	ComposedShape testComposedShape(testCSc,innerC);
 	//  This ComposedSHape constructor only draw mainShape,so only draw
 	// testCsc (radius 500 circle).Because don't calling optimalFit function.
 	// Such a more comfortable understandable svg file was created.
 	
	vectorShape.push_back(&testR);
 	vectorShape.push_back(&testC);
 	vectorShape.push_back(&testT);
 	vectorShape.push_back(&testPolyDyn);
 	vectorShape.push_back(&testPolyVect);
 	vectorShape.push_back(&testComposedShape);

	/****************** Testing PrintAll *************************/

 	cout << endl << "***** Testing Global PrintAll Function *****" << endl;

	printAll(vectorShape);
 	cout << "Writing SVG...OK!" << endl << endl;

	/****************** Testing PrintPoly *************************/

	cout << endl << "***** Testing Global PrintPoly Function *****" << endl;
	printPoly(vectorShape);
	cout << "Writing SVG...OK!" << endl << endl;


	/****************** Testing ConvertAll *************************/
	
	cout << endl << "***** Testing Global ConvertAll Function *****" << endl;
	vector <Shapes *> testConvert = convertAll(vectorShape);

	ofstream fileConvertAll;
	fileConvertAll.open("testConvertAll.svg");
	writingSVG(fileConvertAll);
	
	for(int i=0;i<testConvert.size();++i)
		/*testConvert[i]->printSVG(cout);*/ fileConvertAll << *testConvert[i];
	fileConvertAll << "\n</svg>";
	fileConvertAll.close();
	
	cout << "Writing SVG...OK!" << endl << endl;


	/****************** Testing SortShapes *************************/

	cout << endl << "***** Testing Global SortShapes Function *****" << endl;
	sortShapes(vectorShape);

	for(int i=0;i<vectorShape.size();++i)
		cout << "Index : " << i << "\tArea : " << vectorShape[i]->area() << endl;


	/****************** Testing Shapes * Functions *************************/
 	
	cout << endl << "***** Testing Shape * Functions *****" << endl;


	Rectangle r1(200,100,1,1);
	Rectangle r2(400,50,5,5); // As we can see rectangle's area is equal...
	Circle c1(200,1,1);
	Triangle t1(600,35,12);

	Shapes *s1 = &r1;
	Shapes *s2 = &r2;
	Shapes *s3 = &c1;
	Shapes *s4 = &t1;

	cout << endl << "*** Testing == functions ***" << endl;
	
	if(*s1 == *s2)
		cout << "They are equal ! (*s1 == *s2)" << endl;

	if(*s3 != *s4)
		cout << "They are NOT equal ! (*s3 != *s4)" << endl;


	cout << endl << "*** Testing ++,-- Functions ***" << endl;


	cout << "Before (*s1)++ : " << "\tx: " << s1->get_x() << "  y: " << s1->get_y() << endl;
	(*s1)++;
	cout << "After  (*s1)++ : " << "\tx: " << s1->get_x() << "  y: " << s1->get_y() << endl;
	++(*s1);
	cout << "After  ++(*s1) : " << "\tx: " << s1->get_x() << "  y: " << s1->get_y() << endl;

	cout << endl << endl;

	cout << "Before (*s3)--: " << "\tx: " << s3->get_x() << "  y: " << s3->get_y() << endl;
	(*s3)--;
	cout << "After  (*s3)--: " << "\tx: " << s3->get_x() << "  y: " << s3->get_y() << endl;
	cout << "--(*s3)" << endl;
	--(*s3);
	cout << "After  --(*s3): " << "\tx: " << s3->get_x() << "  y: " << s3->get_y() << endl;

	/*************************** END *******************************/

	cout << endl << "END..." << endl << endl;
}



void writingSVG(ofstream &filename){

	filename<< "<svg version=\"1.1\"" << endl
 		 << "\tbaseProfile=\"full\"" << endl
 		 <<	"\twidth=\"100%\" height=\"100%\"" << endl
 		 <<	"\txmlns=\"http://www.w3.org/2000/svg\">";
}

ostream& operator <<(ostream& outs,Shapes& shape){
	shape.printSVG(outs);
	return outs;
}

void printAll(vector <Shapes *> vectorShape){

	int i;
	ofstream file;
	file.open("testPrintAll.svg");
	writingSVG(file);

	for(i=0;i<vectorShape.size();++i)
		vectorShape[i]->printSVG(file);

	file << "\n</svg>";
	file.close();
}

void printPoly(vector <Shapes *> vectorShape){

	int i;
	ofstream file;
	file.open("testPrintPoly.svg");
	writingSVG(file);

	for(i=0;i<vectorShape.size();++i){

		if(dynamic_cast <Polygon *>(vectorShape[i]) != nullptr)
			vectorShape[i]->printSVG(file);
	}

	file << "\n</svg>";
	file.close();
}


vector <Shapes *> convertAll(vector <Shapes *> vectorShape){

	// Downcasting...

	vector <Shapes *> vectorPolygon;
	int i;
	for(i=0;i<vectorShape.size();++i){
		if(dynamic_cast <Polygon *>(vectorShape[i]) == nullptr){ // It means object is Circle,Rectangle,Triangle or ComposedShape ...
			
			if(dynamic_cast <Circle *>(vectorShape[i]) != nullptr){
				Polygon* temp = convertCircle(vectorShape[i]); 
				vectorPolygon.push_back(temp);
			}
			else if(dynamic_cast <Rectangle *>(vectorShape[i]) != nullptr){
				Polygon* temp = convertRectangle(vectorShape[i]); 
				vectorPolygon.push_back(temp);
			}

			else if(dynamic_cast <Triangle *>(vectorShape[i]) != nullptr){// It means Triangle...
				Polygon* temp = convertTriangle(vectorShape[i]); 
				vectorPolygon.push_back(temp);
			}

			else if(dynamic_cast <ComposedShape *>(vectorShape[i]) != nullptr){

				ComposedShape * tempComposedShape =(ComposedShape *) (vectorShape[i]); 
				vector <Shapes *> newVector = tempComposedShape->getComposedShapeVector();

				for(int i=0;i<tempComposedShape->getVectorSize();++i){
					Polygon * temp = convertComposedShape(newVector[i]);
					vectorPolygon.push_back(temp);
				}
				
			}
		}
		else
			vectorPolygon.push_back((vectorShape[i]));
	}
	return vectorPolygon;
}

Polygon* convertCircle(Shapes * shapesPointer){
	Circle *tempCircle = (Circle *)(shapesPointer);
	Polygon *temp = new PolygonDyn(Circle(tempCircle->getRadius(),shapesPointer->get_x(),shapesPointer->get_y()));
	temp->setControlShapeColor(1);
	return temp;
}

Polygon* convertRectangle(Shapes* shapesPointer){

	Rectangle *tempRectangle = (Rectangle *)(shapesPointer);
	Polygon *temp = new PolygonDyn(Rectangle(tempRectangle->getWidth(),tempRectangle->getHeight(),shapesPointer->get_x(),shapesPointer->get_y()));
	temp->setControlShapeColor(3);
	return temp;
}

Polygon* convertTriangle(Shapes* shapesPointer){
	Triangle *tempTriangle = (Triangle *)(shapesPointer);
	Polygon *temp = new PolygonDyn(Triangle(tempTriangle->getEdge(),shapesPointer->get_x(),shapesPointer->get_y(),tempTriangle->getControlTriangleColor(),tempTriangle->getRotateControl()));
	return temp;
}

Polygon* convertComposedShape(Shapes* shapesPointer){

	Polygon* temp;
	if(shapesPointer->getType() == 'r')
		temp = convertRectangle(shapesPointer);
	else if(shapesPointer->getType() == 'c')
		temp = convertCircle(shapesPointer);
	else if(shapesPointer->getType() == 't')
		temp = convertTriangle(shapesPointer);

	return temp;
}

void sortShapes(vector <Shapes *> &vectorShape){

	int i,j;
	Shapes * temp;
	
	for(i=0;i<vectorShape.size()-1;++i){
		for(j=i+1;j<vectorShape.size();++j){

			if(vectorShape[i]->area() > vectorShape[j]->area()){
				// Bubble Sort Algorithm
				temp = vectorShape[i];
				vectorShape[i] = vectorShape[j];
				vectorShape[j] = temp;
			}
		}
	}
}