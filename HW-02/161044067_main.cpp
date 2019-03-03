/*
 * Gokhan Has - 161044067
*/

#include <iostream>
#include <fstream>
#include "composedShape.h"

using namespace std;

int shapes(char mainShape,char innerShape,Rectangle & mainR,Rectangle & innerR,Circle & mainC,
			Circle & innerC,Triangle & mainT,Triangle & innerT);

int main(){
	
	Rectangle mainR(200,100),innerR(70,30);
	Circle mainC(100),innerC(10);
	Triangle mainT(900),innerT(30);
	char mainShape,innerShape;

	/*************************************************************************************
	 *	This block can be removed if you want to enter the information from the terminal.*
	 *************************************************************************************
	
	cout << "Please enter the main container.(R,C,T)" << endl;
	cin >> mainShape;


	cout << "Please enter the inner shape.(R,C,T)" << endl;
	cin >> innerShape; 

	shapes(mainShape,innerShape,mainR,innerR,mainC,innerC,mainT,innerT);
	
	// ********* Blocks end. ***********
	*/
	
	ofstream file1,file2,file3,file4,file5,file6,file7;
	

	file1.open("output1.svg");
	ComposedShape testRR(mainR,innerR);
 	testRR.optimalFit(1);
 	testRR.draw(file1,'R','R');
 	file1.close();

 	file2.open("output2.svg");
	ComposedShape testRC(mainR,innerC);
 	testRC.optimalFit(2);
 	testRC.draw(file2,'R','C');
 	file2.close();

 	file3.open("output3.svg");
	ComposedShape testRT(mainR,innerT);
 	testRT.optimalFit(3);
 	testRT.draw(file3,'R','T');
 	file3.close();

 	file4.open("output4.svg");
	ComposedShape testTR(mainT,innerR);
 	testTR.optimalFit(4);
 	testTR.draw(file4,'T','R');
 	file4.close();

 	file5.open("output5.svg");
	ComposedShape testTC(mainT,innerC);
 	testTC.optimalFit(5);
 	testTC.draw(file5,'T','C');
 	file5.close();

 	file6.open("output6.svg");
	ComposedShape testTT(mainT,innerT);
 	testTT.optimalFit(6);
 	testTT.draw(file6,'T','T');
 	file6.close();

 	file7.open("output7.svg");
	ComposedShape testCC(mainC,innerC);
 	testCC.optimalFit(7);
 	testCC.draw(file7,'C','C');
 	file7.close();
}


int shapes(char mainShape,char innerShape,Rectangle& mainR,Rectangle& innerR,Circle& mainC,
			Circle& innerC,Triangle& mainT,Triangle& innerT){

	
	double width,height,radius,edge;

	if( (mainShape == 'R' || mainShape == 'r') && (innerShape == 'R' || innerShape == 'r')){

		cout << "Enter main Rectangle width" << endl;
		cin >> width;
		cout << "Enter main Rectangle height" << endl;
		cin >> height;

		mainR.setWidth(width);            mainR.setHeight(height);

		cout << "Enter inner Rectangle width" << endl;
		cin >> width;
		cout << "Enter inner Rectangle height" << endl;
		cin >> height;

		innerR.setWidth(width);            innerR.setHeight(height);
	}

	else if( (mainShape == 'R' || mainShape == 'r') && (innerShape == 'C' || innerShape == 'c')){

		cout << "Enter main Rectangle width" << endl;
		cin >> width;
		cout << "Enter main Rectangle height" << endl;
		cin >> height;

		mainR.setWidth(width);            mainR.setHeight(height);

		cout << "Enter inner Circle radius" << endl;
		cin >> radius;

		innerC.setRadius(radius);
	}
	
	else if( (mainShape == 'R' || mainShape == 'r') && (innerShape == 'T' || innerShape == 't')){

		cout << "Enter main Rectangle width" << endl;
		cin >> width;
		cout << "Enter main Rectangle height" << endl;
		cin >> height;

		mainR.setWidth(width);            mainR.setHeight(height);

		cout << "Enter inner Triangle edge" << endl;
		cin >> edge;

		innerT.setEdge(edge);
	}
    else if( (mainShape == 'C' || mainShape == 'c') && (innerShape == 'R' || innerShape == 'r')){

    	cout << "Enter main Circle radius" << endl;
		cin >> radius;

		mainC.setRadius(radius);

		cout << "Enter inner Rectangle width" << endl;
		cin >> width;
		cout << "Enter inner Rectangle height" << endl;
		cin >> height;

		innerR.setWidth(width);            innerR.setHeight(height);
    }
    else if( (mainShape == 'C' || mainShape == 'c') && (innerShape == 'C' || innerShape == 'c')){

    	cout << "Enter main Circle radius" << endl;
		cin >> radius;

		mainC.setRadius(radius);

		cout << "Enter inner Circle radius" << endl;
		cin >> radius;

		innerC.setRadius(radius);
    }
    else if( (mainShape == 'C' || mainShape == 'c') && (innerShape == 'T' || innerShape == 't')){

    	cout << "Enter main Circle radius" << endl;
		cin >> radius;

		mainC.setRadius(radius);

		cout << "Enter inner Triangle edge" << endl;
		cin >> edge;

		innerT.setEdge(edge);
    }
    else if( (mainShape == 'T' || mainShape == 't') && (innerShape == 'R' || innerShape == 'r')){

    	cout << "Enter main Triangle edge" << endl;
		cin >> edge;


		mainT.setEdge(edge);
		
		cout << "Enter inner Rectangle width" << endl;
		cin >> width;
		cout << "Enter inner Rectangle height" << endl;
		cin >> height;

		innerR.setWidth(width);            innerR.setHeight(height);

    }
    else if( (mainShape == 'T' || mainShape == 't') && (innerShape == 'C' || innerShape == 'c')){

    	cout << "Enter main Triangle edge" << endl;
		cin >> edge;

		mainT.setEdge(edge);

		cout << "Enter inner Circle radius" << endl;
		cin >> radius;

		innerC.setRadius(radius);
	}
    else if( (mainShape == 'T' || mainShape == 't') && (innerShape == 'T' || innerShape == 't')){

    	cout << "Enter main Triangle edge" << endl;
		cin >> edge;

		mainT.setEdge(edge);

		cout << "Enter inner Triangle edge" << endl;
		cin >> edge;

		innerT.setEdge(edge);

    }


	/* This function gets the information of the shape that the user entered. */
}