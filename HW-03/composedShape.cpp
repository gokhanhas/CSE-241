/*
 * Gokhan Has - 161044067
*/

#include "composedShape.h"

ComposedShape::ComposedShape(){/* Default construction */}

ComposedShape::ComposedShape(Rectangle mainR,Rectangle smallR){

	/* 0 means big shape,1 means small shape */
	mainR.setRectangleColor(0);
	smallR.setRectangleColor(1);

	mainRectangle = mainR;
	smallRectangle = smallR;

	mainShape = R;
	innerShape = R;

	smallRectangle.setCoordinate_X(0);      smallRectangle.setCoordinate_Y(0);
	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Rectangle mainR,Circle smallC){

	mainR.setRectangleColor(0);
	smallC.setCircleColor(1);

	mainRectangle = mainR;
	smallCircle = smallC;
	
	mainShape = R;
	innerShape = C;

	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
	smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
}

ComposedShape::ComposedShape(Rectangle mainR,Triangle smallT){

	mainR.setRectangleColor(0);
	smallT.setTriangleColor(1);

	mainRectangle = mainR;
	smallTriangle = smallT;
	
	mainShape = R;
	innerShape = T;

	mainRectangle.setCoordinate_X(0);       mainRectangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Triangle mainT,Rectangle smallR){
	
	mainT.setTriangleColor(0);
	smallR.setRectangleColor(1);

	mainTriangle = mainT;
	smallRectangle = smallR;
	
	mainShape = T;
	innerShape = R;

	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Triangle mainT,Circle smallC){

	mainT.setTriangleColor(0);
	smallC.setCircleColor(1);

	mainTriangle = mainT;
	smallCircle = smallC;

	mainShape = T;
	innerShape = C;

	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
	smallCircle.setCoordinate_X(smallCircle.getRadius());    smallCircle.setCoordinate_Y(smallCircle.getRadius());
}

ComposedShape::ComposedShape(Triangle mainT,Triangle smallT){

	mainT.setTriangleColor(0);
	smallT.setTriangleColor(1);

	mainTriangle = mainT;
	smallTriangle = smallT;

	mainShape = T;
	innerShape = T;

	mainTriangle.setCoordinate_X(mainTriangle.getEdge()/2);     mainTriangle.setCoordinate_Y(0);
}

ComposedShape::ComposedShape(Circle mainC,Circle smallC){

	mainC.setCircleColor(0);
	smallC.setCircleColor(1);

	mainCircle = mainC;
	smallCircle = smallC;

	mainShape = C;
	innerShape = C;

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
				
				ShapeElem tempElem(smallRectangle);
				vectorShapeElem.push_back(tempElem);
				
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
					ShapeElem tempElem(smallRectangle);
					vectorShapeElem.push_back(tempElem);
					
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

					ShapeElem tempElem(smallCircle);
					vectorShapeElem.push_back(tempElem);

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

					ShapeElem tempElem(smallTriangle);
					vectorShapeElem.push_back(tempElem);
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
					ShapeElem tempElem(smallTriangle);
					vectorShapeElem.push_back(tempElem);
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
	
				ShapeElem tempElem(smallRectangle);
				vectorShapeElem.push_back(tempElem);
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

	else if(number == 5){ // It means circle in triangle for testing.

		int counter=0,baseCount,i=1,count=0;
		double controlCx,base3=sqrt(3),redArea,greenArea;
		
		controlCx = smallCircle.getRadius() * base3;  
		smallCircle.setCoordinate_X(smallCircle.getRadius()*base3);
		smallCircle.setCoordinate_Y(mainTriangle.getEdge()/2*base3 - smallCircle.getRadius());
		
		while(smallCircle.getCx() + base3*smallCircle.getRadius() <= mainTriangle.getEdge()){  
			counter++;
			
			ShapeElem tempElem(smallCircle);
			vectorShapeElem.push_back(tempElem);
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
	
				ShapeElem tempElem(smallCircle);
				vectorShapeElem.push_back(tempElem);
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
	
	else if(number == 6){ // It means triangle in triangle for testing.
		
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
				ShapeElem tempElem(smallTriangle);
				vectorShapeElem.push_back(tempElem);
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

					ShapeElem tempElem(smallTriangle);
					vectorShapeElem.push_back(tempElem);
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
		
				ShapeElem tempElem(smallTriangle);
				vectorShapeElem.push_back(tempElem);
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
					
					ShapeElem tempElem(smallTriangle);
					vectorShapeElem.push_back(tempElem);
					
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
			
					smallCircle.setCoordinate_X(j);
					smallCircle.setCoordinate_Y(i);
					
					ShapeElem tempElem(smallCircle);
					vectorShapeElem.push_back(tempElem);
					
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

		cout << endl << "Number 7 : \nMain : Circle || Inner : Circle" << endl;
		cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 	<< (redArea-greenArea) << "." << endl;
	}
}


/**** Defining the ShapeElem constructors *******/

ComposedShape::ShapeElem::ShapeElem(Rectangle tempRectangle):shapeElem_rectangle(tempRectangle),shapeType(R),
		area(tempRectangle.getArea()),perimeterLength(tempRectangle.getPerimeterLength()){/* Body Initialize Empty */}

ComposedShape::ShapeElem::ShapeElem(Circle tempCircle):shapeElem_circle(tempCircle),shapeType(C),
		area(tempCircle.getArea()),perimeterLength(tempCircle.getPerimeterLength()){/* Body Initialize Empty */}

ComposedShape::ShapeElem::ShapeElem(Triangle tempTriangle):shapeElem_triangle(tempTriangle),shapeType(T),
		area(tempTriangle.getArea()),perimeterLength(tempTriangle.getPerimeterLength()){/* Body Initialize Empty */}



ostream& operator <<(ostream& outs,const ComposedShape::ShapeElem & shape){
	/* Overloading the ShapeElem's << operator */
	if(shape.shapeType == ComposedShape::Shapes::R)
		outs << shape.shapeElem_rectangle;
	else if(shape.shapeType == ComposedShape::Shapes::C)
		outs << shape.shapeElem_circle;
	else if(shape.shapeType == ComposedShape::Shapes::T)
		outs << shape.shapeElem_triangle;
}

ostream& operator <<(ostream& outs,const ComposedShape& composed_shape){
	/* Overloading the ComposedShape's << operator */
	if(composed_shape.mainShape == ComposedShape::Shapes::R)
		outs << composed_shape.mainRectangle;
	else if(composed_shape.mainShape == ComposedShape::Shapes::C)
		outs << composed_shape.mainCircle;
	else if(composed_shape.mainShape == ComposedShape::Shapes::T)
		outs << composed_shape.mainTriangle;

	int i;
	for(i=0;i<composed_shape.vectorShapeElem.size();i++){
		outs << composed_shape.vectorShapeElem[i];
	}
	return outs;
}