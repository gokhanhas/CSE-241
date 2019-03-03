/*
 * Gokhan Has - 161044067
*/

#include "composedShape.h"

	
namespace shapes{
	
	ComposedShape::ComposedShape(){/* Default construction */}

	ComposedShape::ComposedShape(Rectangle& mainR,Rectangle& smallR){

		mainRectangle = mainR;
		smallRectangle = smallR;

		smallRectangle.setCoordinate_X(0);      smallRectangle.setCoordinate_Y(0);
		mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);

		Polygon tempPolygon(mainRectangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);
		
		setOptimalFitNumber(1);
	}

	ComposedShape::ComposedShape(Rectangle& mainR,Circle& smallC){

		mainRectangle = mainR;
		smallCircle = smallC;
		
		mainRectangle.setCoordinate_X(0);       				 mainRectangle.setCoordinate_Y(0);
		smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
		
		Polygon tempPolygon(mainRectangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);
		
		setOptimalFitNumber(2);
	}

	ComposedShape::ComposedShape(Rectangle& mainR,Triangle& smallT){

		mainRectangle = mainR;
		smallTriangle = smallT;
		
		mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
		
		Polygon tempPolygon(mainRectangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);
		
		setOptimalFitNumber(3);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Rectangle& smallR){
		

		mainTriangle = mainT;
		smallRectangle = smallR;
		
		mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
		

		Polygon tempPolygon(mainTriangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);

		setOptimalFitNumber(4);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Circle& smallC){

		mainTriangle = mainT;
		smallCircle = smallC;

		mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
		smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
		
		Polygon tempPolygon(mainTriangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);

		setOptimalFitNumber(5);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Triangle& smallT){

		mainTriangle = mainT;
		smallTriangle = smallT;
		
		mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
		
		Polygon tempPolygon(mainTriangle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);

		setOptimalFitNumber(6);
	}

	ComposedShape::ComposedShape(Circle& mainC,Rectangle& smallR){

		mainCircle = mainC;
		smallRectangle = smallR;

		mainCircle.setCoordinate_X(mainCircle.getRadius());    mainCircle.setCoordinate_Y(mainCircle.getRadius());

		Polygon tempPolygon(mainCircle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);

		setOptimalFitNumber(7);
	}

	ComposedShape::ComposedShape(Circle& mainC,Circle& smallC){

		mainCircle = mainC;
		smallCircle = smallC;

		mainCircle.setCoordinate_X(mainCircle.getRadius());    mainCircle.setCoordinate_Y(mainCircle.getRadius());
		smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
		
		Polygon tempPolygon(mainCircle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);
		
		setOptimalFitNumber(8);
	}

	ComposedShape::ComposedShape(Circle& mainC,Triangle& smallT){

		mainCircle = mainC;
		smallTriangle = smallT;

		mainCircle.setCoordinate_X(mainCircle.getRadius());    mainCircle.setCoordinate_Y(mainCircle.getRadius());

		Polygon tempPolygon(mainCircle);
		tempPolygon.setControlShapeColor(0);
		vectorPolygon.push_back(tempPolygon);

		setOptimalFitNumber(9);
	}

	void ComposedShape::setOptimalFitNumber(int number) { 
		optimalFitNumber = number; 
	}	

	void ComposedShape::optimalFit(){

		if(optimalFitNumber == 1){ // It means rectangle in rectangle for testing.
			
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
					
					Polygon tempPolygon(smallRectangle);
					tempPolygon.setControlShapeColor(1);
					vectorPolygon.push_back(tempPolygon);
					
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
						
						
						smallRectangle.setCoordinate_X(controlX);
						Polygon tempPolygon(smallRectangle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);
						
						counter++;
						controlX += smallRectangle.getWidth(); /* This time it is printed vertically. */
					}
					controlX=controlX2;
					smallRectangle.setCoordinate_Y(smallRectangle.getRy() + smallRectangle.getHeight());

					if(smallRectangle.getRy() + smallRectangle.getHeight() >= mainRectangle.getHeight()) 
						control = -1;
				}

				redArea = mainRectangle.getArea();
				greenArea = counter * smallRectangle.getArea();

				cout << "Number 1 : \nMain : Rectangle || Inner : Rectangle" << endl;
				cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 		<< (redArea-greenArea) << "." << endl;
					
			}
		}
			
		else if( optimalFitNumber == 2){ // It means circle in rectangle for testing.

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

						Polygon tempPolygon(smallCircle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);

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

			redArea = mainRectangle.getArea();
			greenArea = smallCircle.getArea() * counter;
			
			cout << endl << "Number 2 : \nMain : Rectangle || Inner : Circle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 3){ // It means triangle in rectangle for testing.

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

						Polygon tempPolygon(smallTriangle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);
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

				smallTriangle.setRotateControl(1);
				
				while(control != -1){	
					
					while(x2 <= mainRectangle.getWidth() && y3 <= mainRectangle.getWidth()){
						/* Doing the same operation for opposite triangles. */
						Polygon tempPolygon(smallTriangle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);
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

			redArea = mainRectangle.getArea();
			greenArea = counter * smallTriangle.getArea();

			cout << endl << "Number 3 : \nMain : Rectangle || Inner : Triangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 4){ // It means rectangle in triangle for testing.

			int control=0,i=1,counter=0;
			double controlx,base3=sqrt(3),redArea,greenArea;
			
			controlx = ((smallRectangle.getHeight()*base3)/3); 
			smallRectangle.setCoordinate_X((smallRectangle.getHeight()*base3/3));
			smallRectangle.setCoordinate_Y(mainTriangle.getEdge()/2*base3-smallRectangle.getHeight());

			while(control != -1){	
				/* Drawing rectangles starting from left to right. */
			
				while(smallRectangle.getRx() + smallRectangle.getWidth() <= 
						mainTriangle.getEdge() - ((smallRectangle.getHeight()*base3)/3)*i){
		
					Polygon tempPolygon(smallRectangle);
					tempPolygon.setControlShapeColor(1);
					vectorPolygon.push_back(tempPolygon);
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

			redArea = mainTriangle.getArea();
			greenArea = counter * smallRectangle.getArea();

			cout << endl << "Number 4 : \nMain : Triangle || Inner : Rectangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 5){ // It means circle in triangle for testing.

			int counter=0,baseCount,i=1,count=0;
			double controlCx,base3=sqrt(3),redArea,greenArea;
			
			controlCx = smallCircle.getRadius() * base3;  
			smallCircle.setCoordinate_X(smallCircle.getRadius()*base3);
			smallCircle.setCoordinate_Y(mainTriangle.getEdge()/2*base3 - smallCircle.getRadius());
			
			while(smallCircle.getCx() + base3*smallCircle.getRadius() <= mainTriangle.getEdge()){  
				counter++;
				
				Polygon tempPolygon(smallCircle);
				tempPolygon.setControlShapeColor(1);
				vectorPolygon.push_back(tempPolygon);
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
		
					Polygon tempPolygon(smallCircle);
					tempPolygon.setControlShapeColor(1);
					vectorPolygon.push_back(tempPolygon);
					count++;
					smallCircle.setCoordinate_X(smallCircle.getCx() + 2*smallCircle.getRadius());
				}
			}

			redArea = mainTriangle.getArea();
			greenArea = count * smallCircle.getArea();

			cout << endl << "Number 5 : \nMain : Triangle || Inner : Circle" << endl;
			cout << "I can fit at most " << count << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;		
		}
		
		else if(optimalFitNumber == 6){ // It means triangle in triangle for testing.
			
			double x2,x3,y2,y3,base3=sqrt(3),redArea,greenArea;
			int counter=0,baseCount,i=2,count=0;
			
			if(smallTriangle.getEdge() > mainTriangle.getEdge())
				cout << "I can not fit shapes into the main container." << endl;
		
			else{

				smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2);   smallTriangle.setCoordinate_Y((mainTriangle.getEdge()/2)*base3-(smallTriangle.getEdge()/2)*base3);
				x2=smallTriangle.getEdge();  	    						y2=(mainTriangle.getEdge()/2*base3);
				x3=smallTriangle.getEdge()/2;       						y3=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				

				while(x2 <= mainTriangle.getEdge()){
					/* Most triangles are in the base column. */
					Polygon tempPolygon(smallTriangle);
					tempPolygon.setControlShapeColor(1);
					vectorPolygon.push_back(tempPolygon);
					counter++;
					count++;
					
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
				}
				baseCount=counter;
				/* Other columns have (bottom-1) circles.Basecounter is the number which is base column's triangles.*/
				while(baseCount != 1){

					smallTriangle.setCoordinate_X(smallTriangle.getEdge()/2*i);
					smallTriangle.setCoordinate_Y(smallTriangle.getTy()-smallTriangle.getEdge()/2*base3);	

					x2=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y2 -= smallTriangle.getEdge()/2*base3;
					x3=smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2;		y3 -= smallTriangle.getEdge()/2*base3;
			
					i++;
					baseCount -= 1;
					
					for(int k=baseCount;k>0;k--){

						Polygon tempPolygon(smallTriangle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);
						count++;
						counter++;
					
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
					}
				}

				smallTriangle.setRotateControl(1);

				baseCount=0; i=1;

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
			
					Polygon tempPolygon(smallTriangle);
					tempPolygon.setControlShapeColor(1);
					vectorPolygon.push_back(tempPolygon);
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
						
						Polygon tempPolygon(smallTriangle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);
						
						counter++;
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setCoordinate_X(smallTriangle.getTx() + smallTriangle.getEdge());
					}
				}
			}

			redArea = mainTriangle.getArea();
			greenArea = counter * smallTriangle.getArea();

			cout << endl << "Number 6 : \nMain : Triangle || Inner : Triangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
			
		}

		else if(optimalFitNumber == 7){

			int counter=0,i=0,j=0;
			double redArea,greenArea,x,y,result;
			// i is x axis, j is y axis
			
			while(j<2*mainCircle.getRadius()){

				i=0;		
				while(i<2*mainCircle.getRadius()){

					x = pow(i-mainCircle.getCx(),2);
					y = pow(j-mainCircle.getCy(),2);
					result = sqrt(x+y);
					// Given the circle equation (x-a)^2 + (y-b)^2 = r*r (M(a,b)) 				
					if((result <= mainCircle.getRadius())){
						// The 4 coordinates of the rectangle are checked to see if they are in the circle.
						x = pow(i-mainCircle.getCx(),2);
						y = pow(j+smallRectangle.getHeight()-mainCircle.getCy(),2);
						result = sqrt(x+y);
						
						if((result <= mainCircle.getRadius())){
							x = pow(i+smallRectangle.getWidth()-mainCircle.getCx(),2);
							y = pow(j+smallRectangle.getHeight()-mainCircle.getCy(),2);
							result = sqrt(x+y);

							if((result <= mainCircle.getRadius())){
								
								x = pow(i+smallRectangle.getHeight()-mainCircle.getCx(),2);
								y = pow(j-mainCircle.getCy(),2);
								result = sqrt(x+y);

								if((result <= mainCircle.getRadius())){

									smallRectangle.setCoordinate_X(i);
									smallRectangle.setCoordinate_Y(j);
									
									Polygon tempPolygon(smallRectangle);
									tempPolygon.setControlShapeColor(1);
									vectorPolygon.push_back(tempPolygon);
									i += smallRectangle.getWidth();
									counter++;
								}
								else
									++i;
							}
							else
								++i;
						}
						else
							++i;
					}
					else
						++i;
				}
				j += smallRectangle.getHeight();
			}

			redArea = mainCircle.getArea();
			greenArea = counter * smallRectangle.getArea();

			cout << endl << "Number 7 : \nMain : Circle || Inner : Rectangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 8){ // It means circle in circle for testing.

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
				
						smallCircle.setCoordinate_X(j);
						smallCircle.setCoordinate_Y(i);
						
						Polygon tempPolygon(smallCircle);
						tempPolygon.setControlShapeColor(1);
						vectorPolygon.push_back(tempPolygon);;
						
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

			redArea = mainCircle.getArea();
			greenArea = counter * smallCircle.getArea();

			cout << endl << "Number 8 : \nMain : Circle || Inner : Circle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 9){

			int i=0,j=0,counter=0;
			double x,y,result,redArea,greenArea;
			
			while(j <= 2*mainCircle.getRadius()){
				i=0;
				while(i <= 2*mainCircle.getRadius()){
					x = pow(i-mainCircle.getCx(),2);
					y = pow(j-mainCircle.getCy(),2);
					result = sqrt(x+y);

					if(result <= mainCircle.getRadius()){

						x = pow((i-smallTriangle.getEdge()/2)-mainCircle.getCx(),2);
						y = pow((j+smallTriangle.getEdge()*sqrt(3)/2)-mainCircle.getCy(),2);
						result = sqrt(x+y);

						if(result <= mainCircle.getRadius()){

							x = pow((i+smallTriangle.getEdge()/2)-mainCircle.getCx(),2);
							y = pow((j+smallTriangle.getEdge()*sqrt(3)/2)-mainCircle.getCy(),2);
							result = sqrt(x+y);

							if(result <= mainCircle.getRadius()){
								smallTriangle.setCoordinate_X(i);
								smallTriangle.setCoordinate_Y(j);
								smallTriangle.setRotateControl(0);
								
								Polygon tempPolygon(smallTriangle);
								tempPolygon.setControlShapeColor(1);
								vectorPolygon.push_back(tempPolygon);
								counter++;

								if( sqrt(pow(i+smallTriangle.getEdge()-mainCircle.getCx(),2) + pow(j-mainCircle.getCy(),2)) < mainCircle.getRadius()){
									// Control the inversi triangle's coordinate
									smallTriangle.setRotateControl(1);
									Polygon tempPolygon2(smallTriangle);
									tempPolygon2.setControlShapeColor(1);
									vectorPolygon.push_back(tempPolygon2);
									counter++;
								}
								i += smallTriangle.getEdge();	
							}
							else
								++i;
						}
						else
							++i;
					}
					else
						++i;
				}
				j += smallTriangle.getEdge();
			}

			redArea = mainCircle.getArea();
			greenArea = counter * smallTriangle.getArea();

			cout << endl << "Number 9 : \nMain : Circle || Inner : Triangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}
	}

	ostream& operator <<(ostream& outs,const ComposedShape& object){

		for(int i=0;i<object.vectorPolygon.size();++i)
			outs << object.vectorPolygon[i];

		return outs;
	}
}