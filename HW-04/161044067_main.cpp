/*
 * Gokhan Has - 161044067
*/

#include "composedShape.h"
#include "polyline.h"

using namespace shapes;
// user-defined "shapes" namespace

void writingSVG(ofstream &filename);

int main(){
	
	Rectangle mainR(300,100),innerR(80,40);
	Circle mainC(200),innerC(20);
	Triangle mainT(800),innerT(27);
	
	ofstream file1,file2,file3,file4,file5,file6,file7,file8,file9;
	ofstream file_test1,file_test2;

	file_test1.open("outputTestOperator+.svg"); 	writingSVG(file_test1);
	file_test2.open("outputTestConversionCon.svg"); writingSVG(file_test2);
	
	// ********** Testing **********

	cout << endl <<"******* Testing the ComposedShape's *******" << endl << endl;

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

 	// 	In composedShape class,I tested Polygon class'
 	// Triangle,Rectangle,Circle conversion constructors and << operator
 	// *******************************************************************
 	
 	cout << endl << "***** Testing Polygon Class Function *****" << endl;

 	// 1
 	cout << endl << "*** Testing Polygon == and != operator (Information : p1 = p2 != p3) ***" << endl;

 	Polygon testPolygon1(mainR);
 	Polygon testPolygon2(mainR);
 	Polygon testPolygon3(innerR);

 	if(testPolygon1 == testPolygon2)
 		cout << endl << "Testing Polygon1 and Polygon2 are equal" << endl;

 	if(testPolygon1 != testPolygon3)
 		cout << "Testing Polygon1 and Polygon3 are NOT equal" << endl;

	
	// 2
	cout << endl << "*** Testing Polygon + operator ***" << endl << endl;
	
	Polygon pAdd;
	pAdd = testPolygon1 + testPolygon3;

	cout << "testPolygon1 : ";
	cout << testPolygon1 << endl << endl;

	cout << "testPolygon2 : ";
	cout << testPolygon3 << endl << endl;
	
	cout << "pAdd = testPolygon1 + testPolygon3";
	cout << pAdd << endl << endl;
	
	file_test1 << pAdd;
	file_test1 << "\n</svg>";
	file_test1.close();
	
	// 3
	cout << "***** Testing [] operator *****" << endl;

	Triangle testT1(500,250,0);
	Triangle testT2(900,450,0);
	Circle testC1(100,100,100);
	Circle testC2(750,750,750);

	Polygon *arrayPolygon;
	arrayPolygon = new Polygon[4];
	arrayPolygon[0] = testT1;
	arrayPolygon[1] = testT2;
	arrayPolygon[2] = testC1;
	arrayPolygon[3] = testC2;

	cout << "Testing arrayPolygon[0] operator" << endl;
  	// arrayPolygon[0] is triangle,so it has 3 (x,y) coordinate
   	for(int i=0;i<arrayPolygon[0].getSize();++i)
   		cout << arrayPolygon[0][i];

   	
   	// 4
   	cout << endl <<"***** Testing conversion constructor for vector Point2D *****" << endl;

   	vector <Polygon::Point2D> vectorPoint2D;
   	vectorPoint2D.push_back(arrayPolygon[0][0]); cout << vectorPoint2D[0];
   	vectorPoint2D.push_back(arrayPolygon[1][2]); cout << vectorPoint2D[1];
   	vectorPoint2D.push_back(arrayPolygon[2][3]); cout << vectorPoint2D[2];
   	vectorPoint2D.push_back(arrayPolygon[3][1]); cout << vectorPoint2D[3];
   	// I assigned the values randomly...

   	Polygon temp(vectorPoint2D); // conversion constructor for vector Point2D
   	cout << temp << endl << endl;
   	file_test2 << temp << "\n</svg>";
   	file_test2.close();

   	// 5
   	cout << endl << "***** Testing conversion constructor for Point2D *****" << endl;

   	Polygon temp2(arrayPolygon[1][1]); // arrayPolygon[1][1] is a Point2D object
   	cout << temp2 << endl << endl; 
}

void writingSVG(ofstream &filename){

	filename<< "<svg version=\"1.1\"" << endl
 		 << "\tbaseProfile=\"full\"" << endl
 		 <<	"\twidth=\"100%\" height=\"100%\"" << endl
 		 <<	"\txmlns=\"http://www.w3.org/2000/svg\">";
}