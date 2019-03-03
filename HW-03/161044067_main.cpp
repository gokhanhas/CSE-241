/*
 * Gokhan Has - 161044067
*/

#include <iostream>
#include <fstream>
#include "composedShape.h"

using namespace std;

void writingSVG(ofstream &filename);

int main(){
	
	Rectangle mainR(300,100),innerR(80,40);
	Circle mainC(200),innerC(20);
	Triangle mainT(800),innerT(27);

	ofstream file1,file2,file3,file4,file5,file6,file7;
	
	/********** Testing **********/

	file1.open("output1.svg");
	writingSVG(file1);
	ComposedShape testRR(mainR,innerR);
 	testRR.optimalFit(1);
 	file1 << testRR;
 	file1 << "</svg>";
 	file1.close();
 	
 	file2.open("output2.svg");
	writingSVG(file2);
	ComposedShape testRC(mainR,innerC);
 	testRC.optimalFit(2);
 	file2 << testRC;
 	file2 << "</svg>";
 	file2.close();

 	file3.open("output3.svg");
	writingSVG(file3);
	ComposedShape testRT(mainR,innerT);
 	testRT.optimalFit(3);
 	file3 << testRT;
 	file3 << "</svg>";
 	file3.close();

 	file4.open("output4.svg");
	writingSVG(file4);
	ComposedShape testTR(mainT,innerR);
 	testTR.optimalFit(4);
 	file4 << testTR;
 	file4 << "</svg>";
 	file4.close();

 	file5.open("output5.svg");
	writingSVG(file5);
	ComposedShape testTC(mainT,innerC);
 	testTC.optimalFit(5);
 	file5 << testTC;
 	file5 << "</svg>";
 	file5.close();

 	file6.open("output6.svg");
	writingSVG(file6);
	ComposedShape testTT(mainT,innerT);
 	testTT.optimalFit(6);
 	file6 << testTT;
 	file6 << "</svg>";
 	file6.close();

 	file7.open("output7.svg");
	writingSVG(file7);
	ComposedShape testCC(mainC,innerC);
 	testCC.optimalFit(7);
 	file7 << testCC;
 	file7 << "</svg>";
 	file7.close();
	
}

void writingSVG(ofstream &filename){

	filename<< "<svg version=\"1.1\"" << endl
 		 << "\tbaseProfile=\"full\"" << endl
 		 <<	"\twidth=\"100%\" height=\"100%\"" << endl
 		 <<	"\txmlns=\"http://www.w3.org/2000/svg\">";
}