/*
 * Gokhan Has - 161044067
*/

#include "composedShape.h"

ComposedShape::ComposedShape(){/* Default construction */}

ComposedShape::ComposedShape(Rectangle mainR,Rectangle smallR){

	mainRectangle = mainR;
	smallRectangle = smallR;

	smallRectangle.setCoordinate_X(0);      smallRectangle.setCoordinate_Y(0);
	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Rectangle mainR,Circle smallC){

	mainRectangle = mainR;
	smallCircle = smallC;
	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
	
	smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
}

ComposedShape::ComposedShape(Rectangle mainR,Triangle smallT){

	mainRectangle = mainR;
	smallTriangle = smallT;
	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Triangle mainT,Rectangle smallR){
	
	mainTriangle = mainT;
	smallRectangle = smallR;
	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Triangle mainT,Circle smallC){

	mainTriangle = mainT;
	smallCircle = smallC;

	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
	smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
}

ComposedShape::ComposedShape(Triangle mainT,Triangle smallT){

	mainTriangle = mainT;
	smallTriangle = smallT;

	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Circle mainC,Circle smallC){

	mainCircle = mainC;
	smallCircle = smallC;

	mainCircle.setCoordinate_X(mainCircle.getRadius());    mainCircle.setCoordinate_Y(mainCircle.getRadius());
	smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
}

void ComposedShape::optimalFit(int number){

	if(number == 1){ // It means rectangle in rectangle for testing.
	
		int control=0,controlX,controlX2,i,counter=0;
		double temp,remainder,redArea,greenArea;
		
		if(smallRectangle.getHeight() > smallRectangle.getWidth()){
 			temp = smallRectangle.getWidth();
 			smallRectangle.setWidth(smallRectangle.getHeight());
 			smallRectangle.setHeight(temp);
 		}

		while(control != -1){
			/* First, prints the rectangles horizontally as far as it can be printed. */	
			while(smallRectangle.getRx()+smallRectangle.getWidth() <= mainRectangle.getWidth() && 
					smallRectangle.getRy()+smallRectangle.getHeight() <= mainRectangle.getHeight()){
				
				coordinate_X.push_back(smallRectangle.getRx());
				coordinate_Y.push_back(smallRectangle.getRy());
				counter++;
				smallRectangle.setCoordinate_X(smallRectangle.getRx()+smallRectangle.getWidth());
				controlX=smallRectangle.getRx();
			}
			smallRectangle.setCoordinate_X(0);
			smallRectangle.setCoordinate_Y(smallRectangle.getRy() + smallRectangle.getHeight());
			/* When the line is finished, it is passed to a bottom line.So, x can be 0. */

			if(smallRectangle.getRy() >= mainRectangle.getHeight())
				control = -1; /* If more rectangles cannot be printed, the loop is exited. */
		}

		controlX2 = controlX;
		remainder = mainRectangle.getWidth() - controlX; 
		/* The difference is retained in the remainder variable. Can the rectangle be printed vertically to the remaining length? */

		if(remainder >= smallRectangle.getHeight()){
			
			smallRectangle.setCoordinate_Y(0);
			temp = smallRectangle.getHeight();
			smallRectangle.setHeight(smallRectangle.getWidth());
			smallRectangle.setWidth(temp); /* The edges of the small rectangle are swap. */ 
			control=0;
			
			while(control != -1){
				
				while(controlX + smallRectangle.getWidth()<= mainRectangle.getWidth()){
					
					rotate_coordinate_X.push_back(controlX);
					rotate_coordinate_Y.push_back(smallRectangle.getRy());
					counter++;
					controlX += smallRectangle.getWidth(); /* This time it is printed vertically. */
				}
				controlX=controlX2;
				smallRectangle.setCoordinate_Y(smallRectangle.getRy() + smallRectangle.getHeight());

				if(smallRectangle.getRy() + smallRectangle.getHeight() >= mainRectangle.getHeight()) 
					control = -1;
			}

			temp = smallRectangle.getHeight();
			smallRectangle.setHeight(smallRectangle.getWidth());
			smallRectangle.setWidth(temp);

			redArea = mainRectangle.getWidth() * mainRectangle.getHeight();
			greenArea = counter * smallRectangle.getWidth() * smallRectangle.getHeight();

			cout << "Main : Rectangle || Inner : Rectangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 		<< (redArea-greenArea) << "." << endl;
				
		}
	}
		
	else if( number == 2){ // It means circle in rectangle for testing.

		int control=0,counter=0;
		double redArea,greenArea;
		
		if( (mainRectangle.getHeight() - mainRectangle.getWidth() > 0 && (2 * smallCircle.getRadius() > mainRectangle.getWidth())) || 
			( mainRectangle.getWidth()-mainRectangle.getHeight() > 0 && (2 * smallCircle.getRadius() > mainRectangle.getWidth()))){
			cout << "ERROR !" << endl;
		}

		else{
			while(control != -1){
				
				while(smallCircle.getCx()+smallCircle.getRadius() <= mainRectangle.getWidth() && 
						smallCircle.getCy()+smallCircle.getRadius() <= mainRectangle.getHeight()){

					coordinate_X.push_back(smallCircle.getCx());
					coordinate_Y.push_back(smallCircle.getCy());
					counter++;
					
					smallCircle.setCoordinate_X(smallCircle.getCx() + 2*smallCircle.getRadius());
				}
				smallCircle.setCoordinate_X(smallCircle.getRadius());
				smallCircle.setCoordinate_Y(smallCircle.getCy() + 2*smallCircle.getRadius());
				/* Circles are printed horizontally. When there is no space, a bottom line is checked and printed. */
				if(smallCircle.getCy() > mainRectangle.getHeight())
					control=-1;
			}
		}

		redArea = mainRectangle.getWidth() * mainRectangle.getHeight();
		greenArea = 3.14 * smallCircle.getRadius() * smallCircle.getRadius() * counter;
		
		cout << endl << "Main : Rectangle || Inner : Circle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}

	else if(number == 3){ // It means triangle in rectangle for testing.

		double x2,x3,y2,y3,redArea,greenArea;
		double base3 = sqrt(3);
		int control = 0,i,counter=0;

		if(mainRectangle.getHeight() <= smallTriangle.getEdge())
			cout << "ERROR! I can not fit shapes into the main container." << endl;

		else{
			
			smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2); smallTriangle.setCoordinate_Y(0);
			x2 = 0;              				y2 = (smallTriangle.getEdge()/2)*base3; 
			x3 = smallTriangle.getEdge();     	y3 = (smallTriangle.getEdge()/2)*base3;

			while(control != -1){	
				
				while(x3 <= mainRectangle.getWidth() && y2 <= mainRectangle.getHeight()){

					coordinate_X.push_back(smallTriangle.getTx());
					coordinate_Y.push_back(smallTriangle.getTy());
					counter++;

					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
					/* x coordinates increase by the edge of the triangle. */
					
					if(x3 > mainRectangle.getWidth() && y2+(smallTriangle.getEdge()/2)*base3 < mainRectangle.getHeight()){
						/* Condition for moving to a bottom line. */
						smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2);
						smallTriangle.setCoordinate_Y(smallTriangle.getTy()+(smallTriangle.getEdge()/2)*base3);
						x2 = 0;              			   y2 += (smallTriangle.getEdge()/2)*base3;
						x3 = smallTriangle.getEdge();      y3 += (smallTriangle.getEdge()/2)*base3;
						/* When going to the bottom line, y coordinates increase by the height of the triangle. */
					}

					else
						control=-1;
				}
			}
			
			control = 0;
			smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2);   smallTriangle.setCoordinate_Y(0); 
			x2 = (3*smallTriangle.getEdge())/2;    						y2 = 0;
			x3 = smallTriangle.getEdge();      						    y3 = (smallTriangle.getEdge()/2)*base3;

			
			while(control != -1){	
				
				while(x2 <= mainRectangle.getWidth() && y3 <= mainRectangle.getWidth()){
					/* Doing the same operation for opposite triangles. */
					rotate_coordinate_X.push_back(smallTriangle.getTx());
					rotate_coordinate_Y.push_back(smallTriangle.getTy());
					counter++;

					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());

					if(x2 > mainRectangle.getWidth() && (y3 + (smallTriangle.getEdge()/2)*base3) < mainRectangle.getHeight()){
						
						smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2);
						smallTriangle.setCoordinate_Y(smallTriangle.getTy()+(smallTriangle.getEdge()/2)*base3);
						x2 = (3*smallTriangle.getEdge())/2;  y2 += (smallTriangle.getEdge()/2)*base3;
						x3 = smallTriangle.getEdge();        y3 += (smallTriangle.getEdge()/2)*base3;
					}

					else
						control=-1;
				}
			}
		}

		redArea = mainRectangle.getWidth() * mainRectangle.getHeight();
		greenArea = counter * smallTriangle.getEdge() * smallTriangle.getEdge() * base3 / 4;

		cout << endl << "Main : Rectangle || Inner : Triangle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}

	else if(number == 4){ // It means rectangle in triangle for testing.

		int control=0,i=1,counter=0;
		double controlx,base3=sqrt(3),redArea,greenArea;
		
		controlx = ((smallRectangle.getHeight()*base3)/3); 
		smallRectangle.setCoordinate_X((smallRectangle.getHeight()*base3/3));
		smallRectangle.setCoordinate_Y(mainTriangle.getEdge()/2*base3-smallRectangle.getHeight());

		while(control != -1){	
			/* Drawing rectangles starting from left to right. */
		
			while(smallRectangle.getRx() + smallRectangle.getWidth() <= 
					mainTriangle.getEdge() - ((smallRectangle.getHeight()*base3)/3)*i){
	
				coordinate_X.push_back(smallRectangle.getRx());
				coordinate_Y.push_back(smallRectangle.getRy());
				counter++;
				
				smallRectangle.setCoordinate_X(smallRectangle.getRx() + smallRectangle.getWidth());
				/* Drawing starts from the bottom. */
			}
			i++;
			smallRectangle.setCoordinate_X(controlx*i);
			smallRectangle.setCoordinate_Y(smallRectangle.getRy() - smallRectangle.getHeight());
			/* When the upper line is passed, the triangle narrows and the x coordinate becomes narrower. */
			if(smallRectangle.getRx() > mainTriangle.getEdge() && 
				smallRectangle.getRy() > (mainTriangle.getEdge()/2*base3) - (i*smallRectangle.getHeight()))
					control = -1;
			/*There is no area to draw triangles. */
		}

		redArea = mainTriangle.getEdge() * mainTriangle.getEdge() * base3 / 4;
		greenArea = counter * smallRectangle.getHeight() * smallRectangle.getHeight();

		cout << endl << "Main : Triangle || Inner : Rectangle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}

	else if(number == 5){ // It means circle in triangle for testing.

		int counter=0,baseCount,i=1,count=0;
		double controlCx,base3=sqrt(3),redArea,greenArea;
		
		controlCx = smallCircle.getRadius() * base3;  
		smallCircle.setCoordinate_X(smallCircle.getRadius()*base3);
		smallCircle.setCoordinate_Y(mainTriangle.getEdge()/2*base3 - smallCircle.getRadius());
		
		while(smallCircle.getCx() + base3*smallCircle.getRadius() <= mainTriangle.getEdge()){  
			counter++;
			
			coordinate_X.push_back(smallCircle.getCx());
			coordinate_Y.push_back(smallCircle.getCy());
			count++;

			smallCircle.setCoordinate_X(smallCircle.getCx() + 2*smallCircle.getRadius());			
		}

		baseCount = counter;	
		/* Other columns have (bottom-1) circles. */ 
		while(baseCount != 1){ 
			smallCircle.setCoordinate_X(controlCx+smallCircle.getRadius()*i);
			smallCircle.setCoordinate_Y(smallCircle.getCy()-smallCircle.getRadius()*base3);
			i++;
			baseCount -= 1;

			for(int k=baseCount;k>0;k--){
				coordinate_X.push_back(smallCircle.getCx());
				coordinate_Y.push_back(smallCircle.getCy());
				count++;

				smallCircle.setCoordinate_X(smallCircle.getCx() + 2*smallCircle.getRadius());
			}
		}

		redArea = mainTriangle.getEdge() * mainTriangle.getEdge() * base3 / 4;
		greenArea = count * 3.14 * smallCircle.getRadius() * smallCircle.getRadius();

		cout << endl << "Main : Triangle || Inner : Circle" << endl;
		cout << "I can fit at most " << count << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;		
	}

	else if(number == 6){ // It means triangle in triangle for testing.
		
		double x2,x3,y2,y3,base3=sqrt(3),redArea,greenArea;
		int counter=0,baseCount,i=1,count=0;
		
		if(smallTriangle.getEdge() > mainTriangle.getEdge())
			cout << "I can not fit shapes into the main container." << endl;
	
		else{

			smallTriangle.setCoordinate_X(0);   smallTriangle.setCoordinate_Y((mainTriangle.getEdge()/2)*base3);
			x2=smallTriangle.getEdge();  	    y2=(mainTriangle.getEdge()/2*base3);
			x3=smallTriangle.getEdge()/2;       y3=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
			

			while(x2 <= mainTriangle.getEdge()){
				/* Most triangles are in the base column. */
			
				coordinate_X.push_back(smallTriangle.getTx()+smallTriangle.getEdge()/2);
				coordinate_Y.push_back(smallTriangle.getTy()-smallTriangle.getEdge()*base3/2);
				counter++;
				count++;
				
				x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
				smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
			}
			baseCount=counter;
			/* Other columns have (bottom-1) circles.Basecounter is the number which is base column's triangles. */
			while(baseCount != 1){

				smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2*i);
				smallTriangle.setCoordinate_Y(smallTriangle.getTy()-smallTriangle.getEdge()/2*base3);	
				x2=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y2 -= smallTriangle.getEdge()/2*base3;
				x3=smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2;		y3 -= smallTriangle.getEdge()/2*base3;
		
				i++;
				baseCount -= 1;
				
				for(int k=baseCount;k>0;k--){

					coordinate_X.push_back(smallTriangle.getTx()+smallTriangle.getEdge()/2);
					coordinate_Y.push_back(smallTriangle.getTy()-smallTriangle.getEdge()*base3/2);
					count++;
					counter++;
				
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
				}
			}

			baseCount=0; i=1;
			//x1=smallEdge/2;   	y1=base3*((mainEdge-smallEdge)/2);
			smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2);
			smallTriangle.setCoordinate_Y(base3*(mainTriangle.getEdge()-smallTriangle.getEdge())/2);
			x2=3*smallTriangle.getEdge()/2;  	y2=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
			x3=smallTriangle.getEdge(); 		y3=mainTriangle.getEdge()/2*base3; 
			/* The same operations are done in reserved triangles. */
			//      -------
			//		 \   /
			//        \ /
			//         -
			
			while(x2 <= mainTriangle.getEdge() - smallTriangle.getEdge()/2){
				counter++; baseCount++;
				rotate_coordinate_X.push_back(smallTriangle.getTx());
				rotate_coordinate_Y.push_back(smallTriangle.getTy());
				count++;
				
				x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
				smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
			}

			while(baseCount != 1){

				smallTriangle.setCoordinate_X(smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2);
				smallTriangle.setCoordinate_Y(smallTriangle.getTy() - smallTriangle.getEdge()/2*base3);
				
				x2=3*smallTriangle.getEdge()/2 + i*smallTriangle.getEdge()/2;	y2 -= smallTriangle.getEdge()/2*base3;
				x3=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y3 -= smallTriangle.getEdge()/2*base3;
				
				i++; baseCount -= 1;

				for(int c=baseCount;c>0;c--){
					
					rotate_coordinate_X.push_back(smallTriangle.getTx());
					rotate_coordinate_Y.push_back(smallTriangle.getTy());
					
					counter++;
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
				}
			}
		}

		redArea = mainTriangle.getEdge() * mainTriangle.getEdge() * base3 / 4;
		greenArea = counter * smallTriangle.getEdge() * smallTriangle.getEdge() * base3 / 4;

		cout << endl << "Main : Triangle || Inner : Triangle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}

	else if(number == 7){ // It means circle in circle for testing.

		int i=0,j=0,control=0,counter=0;
		double redArea,greenArea;
	
		if(smallCircle.getRadius() > mainCircle.getRadius())
			cout << "I can not fit shapes into the main container." << endl;
		
		while(i <= 2*mainCircle.getRadius()){   
			
			j=0; /* j is x axis, i is y axis. */  
			while(j <= 2*mainCircle.getRadius()){ 
				/* Circle writing on svg file is checked in line by line. */
				if( sqrt((mainCircle.getRadius()-i)*(mainCircle.getRadius()-i)+((mainCircle.getRadius()-j)*((mainCircle.getRadius()-j)))) 
						+ smallCircle.getRadius() <= mainCircle.getRadius()){
			
					coordinate_X.push_back(j);
					coordinate_Y.push_back(i);
					//filename << "\t\n<circle cx=\"" << j << "\" cy=\"" << i << "\" r=\"" << smallRadius << "\" fill=\"green\" />";
					j += 2*smallCircle.getRadius();
					control=-1;
					counter++;
				}
				else
					j += 1;
			}
			if(control == -1){
				i += 2 * smallCircle.getRadius();
				control=0;
				/* The condition of passing to a bottom line. */
			}
			
			else
				i += 1;
		}

		redArea = 3.14 * mainCircle.getRadius() * mainCircle.getRadius();
		greenArea = counter * 3.14 * smallCircle.getRadius() * smallCircle.getRadius();

		cout << endl << "Main : Circle || Inner : Circle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}
}


void ComposedShape::draw(ofstream& filename,char mainShape,char innerShape){

	filename << "<svg version=\"1.1\"" << endl
 		 << "\tbaseProfile=\"full\"" << endl
 		 <<	"\twidth=\"100%\" height=\"100%\"" << endl
 		 <<	"\txmlns=\"http://www.w3.org/2000/svg\">";

	if( mainShape == 'R' || mainShape == 'r'){
		
		mainRectangle.draw(filename);
		
		if(innerShape == 'R' || innerShape == 'r'){

			
			for(int i=0;i<coordinate_X.size();i++){
				smallRectangle.setCoordinate_X(coordinate_X[i]);
				smallRectangle.setCoordinate_Y(coordinate_Y[i]);
				smallRectangle.draw(filename,1);
			}

			double temp = smallRectangle.getHeight();
			smallRectangle.setHeight(smallRectangle.getWidth());
			smallRectangle.setWidth(temp);
			
			for(int i=0;i<rotate_coordinate_X.size();i++){
				smallRectangle.setCoordinate_X(rotate_coordinate_X[i]);
				smallRectangle.setCoordinate_Y(rotate_coordinate_Y[i]);
				smallRectangle.draw(filename,1);
			}
		}

		else if (innerShape == 'C' || innerShape == 'c'){

			for(int i=0;i<coordinate_X.size();i++){
				smallCircle.setCoordinate_X(coordinate_X[i]);
				smallCircle.setCoordinate_Y(coordinate_Y[i]);
				smallCircle.draw(filename,1);
			}
		}

		else if(innerShape == 'T' || innerShape == 't'){

			for(int i=0;i<coordinate_X.size();i++){
				smallTriangle.setCoordinate_X(coordinate_X[i]);
				smallTriangle.setCoordinate_Y(coordinate_Y[i]);
				smallTriangle.draw(filename,1);
		    }

		    for(int i=0;i<rotate_coordinate_X.size();i++){
				smallTriangle.setCoordinate_X(rotate_coordinate_X[i]);
				smallTriangle.setCoordinate_Y(rotate_coordinate_Y[i]);
				smallTriangle.draw(filename,2);
		    }
		}
	}

	else if( mainShape == 'T' || mainShape == 't'){

		mainTriangle.draw(filename);

		if(innerShape == 'R' || innerShape == 'r'){

			for(int i=0;i<coordinate_X.size();i++){

				smallRectangle.setCoordinate_X(coordinate_X[i]);
				smallRectangle.setCoordinate_Y(coordinate_Y[i]);
				smallRectangle.draw(filename,1);
			}
		}

		else if(innerShape == 'C' || innerShape == 'c'){

			for(int i=0;i<coordinate_X.size();i++){
				smallCircle.setCoordinate_X(coordinate_X[i]);
				smallCircle.setCoordinate_Y(coordinate_Y[i]);
				smallCircle.draw(filename,1);
			}
		}

		else if(innerShape == 'T' || innerShape == 't'){
			
			for(int i=0;i<coordinate_X.size();i++){
				smallTriangle.setCoordinate_X(coordinate_X[i]);
				smallTriangle.setCoordinate_Y(coordinate_Y[i]);
				smallTriangle.draw(filename,1);
		    }
		    
		    for(int i=0;i<rotate_coordinate_X.size();i++){
				smallTriangle.setCoordinate_X(rotate_coordinate_X[i]);
				smallTriangle.setCoordinate_Y(rotate_coordinate_Y[i]);
				smallTriangle.draw(filename,2);
		    }
		}
	}

	else if(mainShape == 'C' || mainShape == 'c'){

		mainCircle.draw(filename);

		if(innerShape == 'C' || innerShape == 'c'){
			
			for(int i=0;i<coordinate_X.size();i++){
				smallCircle.setCoordinate_X(coordinate_X[i]);
				smallCircle.setCoordinate_Y(coordinate_Y[i]);
				smallCircle.draw(filename,1);
			}		
		}
	}

	filename << "\n</svg>";
}