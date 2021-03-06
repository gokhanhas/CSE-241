/*
 * Gokhan Has - 161044067
*/

#include "composedShape.h"

	
namespace HasShapes{
	
	ComposedShape::ComposedShape() noexcept:Shapes(){ shapeType = 'k'; }

	ComposedShape::ComposedShape(Rectangle& mainR,Rectangle& smallR) noexcept:Shapes(){

		shapeType = 'k';
		mainRectangle = mainR;
		smallRectangle = smallR;

		smallRectangle.set_x(0);      smallRectangle.set_y(0);
		mainRectangle.set_x(0);       mainRectangle.set_y(0);

		Shapes * tempShape = &mainRectangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(1);
		smallRectangle.setRectangleColor(1);
	}

	ComposedShape::ComposedShape(Rectangle& mainR,Circle& smallC) noexcept:Shapes(){

		shapeType = 'k';
		mainRectangle = mainR;
		smallCircle = smallC;
		
		mainRectangle.set_x(0);       				   mainRectangle.set_y(0);
		smallCircle.set_x(smallCircle.getRadius());    smallCircle.set_y(smallCircle.getRadius());
		
		
		Shapes * tempShape = &mainRectangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(2);
		smallCircle.setCircleColor(1);
	}

	ComposedShape::ComposedShape(Rectangle& mainR,Triangle& smallT) noexcept:Shapes(){

		shapeType = 'k';
		mainRectangle = mainR;
		smallTriangle = smallT;
		
		mainRectangle.set_x(0);       mainRectangle.set_y(0);
		
		Shapes * tempShape = &mainRectangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(3);
		smallTriangle.setTriangleColor(1);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Rectangle& smallR) noexcept:Shapes(){
		
		shapeType = 'k';
		mainTriangle = mainT;
		smallRectangle = smallR;
		
		mainTriangle.set_x(mainTriangle.getEdge()/2);     mainTriangle.set_y(0);
		
		Shapes * tempShape = &mainTriangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(4);
		smallRectangle.setRectangleColor(1);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Circle& smallC) noexcept:Shapes(){

		shapeType = 'k';
		mainTriangle = mainT;
		smallCircle = smallC;

		mainTriangle.set_x(mainTriangle.getEdge()/2);     mainTriangle.set_y(0);
		smallCircle.set_x(smallCircle.getRadius());    smallCircle.set_y(smallCircle.getRadius());
		
		Shapes * tempShape = &mainTriangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(5);
		smallCircle.setCircleColor(1);
	}

	ComposedShape::ComposedShape(Triangle& mainT,Triangle& smallT) noexcept:Shapes(){

		shapeType = 'k';
		mainTriangle = mainT;
		smallTriangle = smallT;
		
		mainTriangle.set_x(mainTriangle.getEdge()/2);     mainTriangle.set_y(0);
		
		Shapes * tempShape = &mainTriangle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(6);
		smallTriangle.setTriangleColor(1);
	}

	ComposedShape::ComposedShape(Circle& mainC,Rectangle& smallR) noexcept:Shapes(){

		shapeType = 'k';
		mainCircle = mainC;
		smallRectangle = smallR;

		mainCircle.set_x(mainCircle.getRadius());    mainCircle.set_y(mainCircle.getRadius());

		Shapes * tempShape = &mainCircle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(7);
		smallRectangle.setRectangleColor(1);
	}

	ComposedShape::ComposedShape(Circle& mainC,Circle& smallC) noexcept:Shapes(){

		shapeType = 'k';
		mainCircle = mainC;
		smallCircle = smallC;

		mainCircle.set_x(mainCircle.getRadius());    mainCircle.set_y(mainCircle.getRadius());
		smallCircle.set_x(smallCircle.getRadius());    smallCircle.set_y(smallCircle.getRadius());
		
		Shapes * tempShape = &mainCircle;
		vectorShape.push_back(tempShape);
		
		setOptimalFitNumber(8);
		smallCircle.setCircleColor(1);
	}

	ComposedShape::ComposedShape(Circle& mainC,Triangle& smallT) noexcept:Shapes(){

		shapeType = 'k';
		mainCircle = mainC;
		smallTriangle = smallT;

		mainCircle.set_x(mainCircle.getRadius());    mainCircle.set_y(mainCircle.getRadius());

		Shapes * tempShape = &mainCircle;
		vectorShape.push_back(tempShape);

		setOptimalFitNumber(9);
		smallTriangle.setTriangleColor(1);
	}

	void ComposedShape::setOptimalFitNumber(int number) noexcept { 
		optimalFitNumber = number; 
	}	

	void ComposedShape::optimalFit() noexcept{

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
				while(smallRectangle.get_x()+smallRectangle.getWidth() <= mainRectangle.getWidth() && 
						smallRectangle.get_y()+smallRectangle.getHeight() <= mainRectangle.getHeight()){
					
					
					Rectangle * temp = new Rectangle(smallRectangle);
					Shapes * tempShape = temp;
					vectorShape.push_back(tempShape);
					
					counter++;
					smallRectangle.set_x(smallRectangle.get_x()+smallRectangle.getWidth());
					controlX=smallRectangle.get_x();
				}
				smallRectangle.set_x(0);
				smallRectangle.set_y(smallRectangle.get_y() + smallRectangle.getHeight());
				/* When the line is finished, it is passed to a bottom line.So, x can be 0. */

				if(smallRectangle.get_y() >= mainRectangle.getHeight())
					control = -1; /* If more rectangles cannot be printed, the loop is exited. */
			}

			controlX2 = controlX;
			remainder = mainRectangle.getWidth() - controlX; 
			/* The difference is retained in the remainder variable. Can the rectangle be printed vertically to the remaining length? */

			if(remainder >= smallRectangle.getHeight()){
				
				smallRectangle.set_y(0);
				temp = smallRectangle.getHeight();
				smallRectangle.setHeight(smallRectangle.getWidth());
				smallRectangle.setWidth(temp); /* The edges of the small rectangle are swap. */ 
				control=0;
				
				while(control != -1){
					
					while(controlX + smallRectangle.getWidth()<= mainRectangle.getWidth()){
						
						
						smallRectangle.set_x(controlX);
						
						Rectangle * temp = new Rectangle(smallRectangle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);
						
						counter++;
						controlX += smallRectangle.getWidth(); /* This time it is printed vertically. */
					}
					controlX=controlX2;
					smallRectangle.set_y(smallRectangle.get_y() + smallRectangle.getHeight());

					if(smallRectangle.get_y() + smallRectangle.getHeight() >= mainRectangle.getHeight()) 
						control = -1;
				}

				redArea = mainRectangle.area();
				greenArea = counter * smallRectangle.area();

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
					
					while(smallCircle.get_x()+smallCircle.getRadius() <= mainRectangle.getWidth() && 
							smallCircle.get_y()+smallCircle.getRadius() <= mainRectangle.getHeight()){

						Shapes * temp = new Circle(smallCircle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);

						counter++;
						
						smallCircle.set_x(smallCircle.get_x() + 2*smallCircle.getRadius());
					}
					smallCircle.set_x(smallCircle.getRadius());
					smallCircle.set_y(smallCircle.get_y() + 2*smallCircle.getRadius());
					/* Circles are printed horizontally. When there is no space, a bottom line is checked and printed. */
					if(smallCircle.get_y() > mainRectangle.getHeight())
						control=-1;
				}
			}

			redArea = mainRectangle.area();
			greenArea = smallCircle.area() * counter;
			
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
				
				smallTriangle.set_x(smallTriangle.getEdge()/2); smallTriangle.set_y(0);
				x2 = 0;              				y2 = (smallTriangle.getEdge()/2)*base3; 
				x3 = smallTriangle.getEdge();     	y3 = (smallTriangle.getEdge()/2)*base3;

				while(control != -1){	
					
					while(x3 <= mainRectangle.getWidth() && y2 <= mainRectangle.getHeight()){

						Shapes * temp = new Triangle(smallTriangle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);
						
						counter++;

						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());
						/* x coordinates increase by the edge of the triangle. */
						
						if(x3 > mainRectangle.getWidth() && y2+(smallTriangle.getEdge()/2)*base3 < mainRectangle.getHeight()){
							/* Condition for moving to a bottom line. */
						
							smallTriangle.set_x(smallTriangle.getEdge()/2);
							smallTriangle.set_y(smallTriangle.get_y()+(smallTriangle.getEdge()/2)*base3);
							x2 = 0;              			   y2 += (smallTriangle.getEdge()/2)*base3;
							x3 = smallTriangle.getEdge();      y3 += (smallTriangle.getEdge()/2)*base3;
							/* When going to the bottom line, y coordinates increase by the height of the triangle. */
						}

						else
							control=-1;
					}
				}

				control = 0;
				smallTriangle.set_x(smallTriangle.getEdge()/2);   smallTriangle.set_y(0); 
				x2 = (3*smallTriangle.getEdge())/2;    						y2 = 0;
				x3 = smallTriangle.getEdge();      						    y3 = (smallTriangle.getEdge()/2)*base3;

				smallTriangle.setRotateControl(1);
				
				while(control != -1){	
					
					while(x2 <= mainRectangle.getWidth() && y3 <= mainRectangle.getWidth()){
						/* Doing the same operation for opposite triangles. */
						
						Shapes * temp = new Triangle(smallTriangle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);
						
						counter++;

						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());

						if(x2 > mainRectangle.getWidth() && (y3 + (smallTriangle.getEdge()/2)*base3) < mainRectangle.getHeight()){
							
							smallTriangle.set_x(smallTriangle.getEdge()/2);
							smallTriangle.set_y(smallTriangle.get_y()+(smallTriangle.getEdge()/2)*base3);
							x2 = (3*smallTriangle.getEdge())/2;  y2 += (smallTriangle.getEdge()/2)*base3;
							x3 = smallTriangle.getEdge();        y3 += (smallTriangle.getEdge()/2)*base3;
						}

						else
							control=-1;
					}
				}
			}

			redArea = mainRectangle.area();
			greenArea = counter * smallTriangle.area();

			cout << endl << "Number 3 : \nMain : Rectangle || Inner : Triangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 4){ // It means rectangle in triangle for testing.

			int control=0,i=1,counter=0;
			double controlx,base3=sqrt(3),redArea,greenArea;
		
			controlx = ((smallRectangle.getHeight()*base3)/3); 
			smallRectangle.set_x((smallRectangle.getHeight()*base3/3));
			smallRectangle.set_y(mainTriangle.getEdge()/2*base3-smallRectangle.getHeight());

			while(control != -1){	
				/* Drawing rectangles starting from left to right. */
			
				while(smallRectangle.get_x() + smallRectangle.getWidth() <= 
						mainTriangle.getEdge() - ((smallRectangle.getHeight()*base3)/3)*i){
			
					Shapes * temp = new Rectangle(smallRectangle);		
					Shapes * tempShape = temp;
					vectorShape.push_back(tempShape);

					counter++;
					
					smallRectangle.set_x(smallRectangle.get_x() + smallRectangle.getWidth());
					/* Drawing starts from the bottom. */
				}
				i++;
				smallRectangle.set_x(controlx*i);
				smallRectangle.set_y(smallRectangle.get_y() - smallRectangle.getHeight());
				/* When the upper line is passed, the triangle narrows and the x coordinate becomes narrower. */
				
				if(smallRectangle.get_y() - smallRectangle.getHeight() < 0)
					control = -1;

				if(smallRectangle.get_x() > mainTriangle.getEdge() && 
					smallRectangle.get_y() > (mainTriangle.getEdge()/2*base3) - (i*smallRectangle.getHeight()))
						control = -1;
				/*There is no area to draw triangles. */
			}

			redArea = mainTriangle.area();
			greenArea = counter * smallRectangle.area();

			cout << endl << "Number 4 : \nMain : Triangle || Inner : Rectangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}

		else if(optimalFitNumber == 5){ // It means circle in triangle for testing.

			int counter=0,baseCount,i=1,count=0;
			double controlCx,base3=sqrt(3),redArea,greenArea;
			
			controlCx = smallCircle.getRadius() * base3;  
			smallCircle.set_x(smallCircle.getRadius()*base3);
			smallCircle.set_y(mainTriangle.getEdge()/2*base3 - smallCircle.getRadius());
			
			while(smallCircle.get_x() + base3*smallCircle.getRadius() <= mainTriangle.getEdge()){  
				counter++;
				
				Shapes * temp = new Circle(smallCircle);
				Shapes * tempShape = temp;
				vectorShape.push_back(tempShape);

				count++;

				smallCircle.set_x(smallCircle.get_x() + 2*smallCircle.getRadius());			
			}

			baseCount = counter;	
			/* Other columns have (bottom-1) circles. */ 
			while(baseCount != 1){ 
				smallCircle.set_x(controlCx+smallCircle.getRadius()*i);
				smallCircle.set_y(smallCircle.get_y()-smallCircle.getRadius()*base3);
				i++;
				baseCount -= 1;

				for(int k=baseCount;k>0;k--){
		
					Shapes * temp = new Circle(smallCircle);
					Shapes * tempShape = temp;
					vectorShape.push_back(tempShape);

					count++;
					smallCircle.set_x(smallCircle.get_x() + 2*smallCircle.getRadius());
				}
			}

			redArea = mainTriangle.area();
			greenArea = count * smallCircle.area();

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

				smallTriangle.set_x(smallTriangle.getEdge()/2);   smallTriangle.set_y((mainTriangle.getEdge()/2)*base3-(smallTriangle.getEdge()/2)*base3);
				x2=smallTriangle.getEdge();  	    						y2=(mainTriangle.getEdge()/2*base3);
				x3=smallTriangle.getEdge()/2;       						y3=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				

				while(x2 <= mainTriangle.getEdge()){
					/* Most triangles are in the base column. */
					
					Shapes * temp = new Triangle(smallTriangle);
					Shapes * tempShape = temp;
					vectorShape.push_back(tempShape);

					counter++;
					count++;
					
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());
				}
				baseCount=counter;
				/* Other columns have (bottom-1) circles.Basecounter is the number which is base column's triangles.*/
				

				while(baseCount != 1){

					smallTriangle.set_x(smallTriangle.getEdge()/2*i);
					if(smallTriangle.get_y()-smallTriangle.getEdge()/2*base3 < 0)
						smallTriangle.set_y(0);
					else
						smallTriangle.set_y(smallTriangle.get_y()-smallTriangle.getEdge()/2*base3);	
					
					x2=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y2 -= smallTriangle.getEdge()/2*base3;
					x3=smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2;		y3 -= smallTriangle.getEdge()/2*base3;
			
					i++;
					baseCount -= 1;
					
					for(int k=baseCount;k>0;k--){

						Shapes * temp = new Triangle(smallTriangle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);	
						
						count++;
						counter++;
					
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());
					}
				}

				smallTriangle.setRotateControl(1);

				baseCount=0; i=1;

				smallTriangle.set_x(smallTriangle.getEdge()/2);
				smallTriangle.set_y(base3*(mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				x2=3*smallTriangle.getEdge()/2;  	y2=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				x3=smallTriangle.getEdge(); 		y3=mainTriangle.getEdge()/2*base3; 
				/* The same operations are done in reserved triangles. */
				//      -------
				//		 \   /
				//        \ /
				//         -
				
				while(x2 <= mainTriangle.getEdge() - smallTriangle.getEdge()/2){
					counter++; baseCount++;
			
					Shapes * temp = new Triangle(smallTriangle);
					Shapes * tempShape = temp;
					vectorShape.push_back(tempShape);

					count++;
					
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());
				}

				while(baseCount != 1){

					smallTriangle.set_x(smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2);
					smallTriangle.set_y(smallTriangle.get_y() - smallTriangle.getEdge()/2*base3);
					
					x2=3*smallTriangle.getEdge()/2 + i*smallTriangle.getEdge()/2;	y2 -= smallTriangle.getEdge()/2*base3;
					x3=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y3 -= smallTriangle.getEdge()/2*base3;
					
					i++; baseCount -= 1;

					for(int c=baseCount;c>0;c--){
						
						Shapes * temp = new Triangle(smallTriangle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);
						
						counter++;
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.set_x(smallTriangle.get_x() + smallTriangle.getEdge());
					}
				}
			}

			redArea = mainTriangle.area();
			greenArea = counter * smallTriangle.area();

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

					x = pow(i-mainCircle.get_x(),2);
					y = pow(j-mainCircle.get_y(),2);
					result = sqrt(x+y);
					// Given the circle equation (x-a)^2 + (y-b)^2 = r*r (M(a,b)) 				
					if((result <= mainCircle.getRadius())){
						// The 4 coordinates of the rectangle are checked to see if they are in the circle.
						x = pow(i-mainCircle.get_x(),2);
						y = pow(j+smallRectangle.getHeight()-mainCircle.get_y(),2);
						result = sqrt(x+y);
						
						if((result <= mainCircle.getRadius())){
							x = pow(i+smallRectangle.getWidth()-mainCircle.get_x(),2);
							y = pow(j+smallRectangle.getHeight()-mainCircle.get_y(),2);
							result = sqrt(x+y);

							if((result <= mainCircle.getRadius())){
								
								x = pow(i+smallRectangle.getHeight()-mainCircle.get_x(),2);
								y = pow(j-mainCircle.get_y(),2);
								result = sqrt(x+y);

								if((result <= mainCircle.getRadius())){

									smallRectangle.set_x(i);
									smallRectangle.set_y(j);
									
									Shapes * temp = new Rectangle(smallRectangle);
									Shapes * tempShape = temp;
									vectorShape.push_back(tempShape);

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

			redArea = mainCircle.area();
			greenArea = counter * smallRectangle.area();

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
				
						smallCircle.set_x(j);
						smallCircle.set_y(i);
						
						Shapes * temp = new Circle(smallCircle);
						Shapes * tempShape = temp;
						vectorShape.push_back(tempShape);
						
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

			redArea = mainCircle.area();
			greenArea = counter * smallCircle.area();

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
					x = pow(i-mainCircle.get_x(),2);
					y = pow(j-mainCircle.get_y(),2);
					result = sqrt(x+y);

					if(result <= mainCircle.getRadius()){

						x = pow((i-smallTriangle.getEdge()/2)-mainCircle.get_x(),2);
						y = pow((j+smallTriangle.getEdge()*sqrt(3)/2)-mainCircle.get_y(),2);
						result = sqrt(x+y);

						if(result <= mainCircle.getRadius()){

							x = pow((i+smallTriangle.getEdge()/2)-mainCircle.get_x(),2);
							y = pow((j+smallTriangle.getEdge()*sqrt(3)/2)-mainCircle.get_y(),2);
							result = sqrt(x+y);

							if(result <= mainCircle.getRadius()){
								smallTriangle.set_x(i);
								smallTriangle.set_y(j);
								smallTriangle.setRotateControl(0);
								
								Shapes * temp = new Triangle(smallTriangle);
								Shapes * tempShape = temp;
								vectorShape.push_back(tempShape);

								counter++;

								if( sqrt(pow(i+smallTriangle.getEdge()-mainCircle.get_x(),2) + pow(j-mainCircle.get_y(),2)) < mainCircle.getRadius()){
									// Control the inversi triangle's coordinate
									smallTriangle.setRotateControl(1);
									
									Shapes * temp = new Triangle(smallTriangle);
									Shapes * tempShape = temp;
									vectorShape.push_back(tempShape);

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

			redArea = mainCircle.area();
			greenArea = counter * smallTriangle.area();

			cout << endl << "Number 9 : \nMain : Circle || Inner : Triangle" << endl;
			cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
			 	<< (redArea-greenArea) << "." << endl;
		}
	}
	
	ostream& operator <<(ostream& outs,const ComposedShape& object) noexcept{

		for(int i=0;i<object.vectorShape.size();++i)
			object.vectorShape[i]->printSVG(outs);

		return outs;
	}

	double ComposedShape::area()const noexcept{
		int i;
		double totalArea=0.0;
		for(i=0;i<vectorShape.size();++i)
			totalArea += (vectorShape[i])->area();
		return totalArea;
	}

	double ComposedShape::perimeter()const noexcept{
		int i;
		double totalPerimeter=0.0;
		for(i=0;i<vectorShape.size();++i)
			totalPerimeter += (vectorShape[i])->perimeter();
		return totalPerimeter;
	}
}