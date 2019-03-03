/*
 * Gokhan Has - 161044067
 */


import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * ComposedShape class extends JPanel implements Shape.
 * @author Gokhan Has
 *
 */
public class ComposedShape extends JPanel  implements Shape {

	public Shape[] arrayShape;
	private Rectangle mainRectangle,smallRectangle;
	private Circle mainCircle,smallCircle;
	private Triangle mainTriangle,smallTriangle;
	private int optimalFitNumber;
	
	ComposedShape() {
		arrayShape = null;
	}
	/**
	 *  ComposedShape two parameters constructor.
	 * @param mainR to initialize main Rectangle.
	 * @param smallR to initialize small Rectangle.
	 */
	ComposedShape(Rectangle mainR,Rectangle smallR) {
		mainRectangle = mainR;
		mainRectangle.setSizeNumber(0);
		smallRectangle = smallR;
		smallRectangle.setSizeNumber(1);
		set_optimalFitNumber(1);
		
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainR to initialize main Rectangle.
	 * @param smallC to initialize small Circle.
	 */
	ComposedShape(Rectangle mainR,Circle smallC) {
		mainRectangle = mainR;
		mainRectangle.setSizeNumber(0);
		smallCircle = smallC;
		smallCircle.setSizeNumber(1);
		set_optimalFitNumber(2);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainR to initialize main Rectangle.
	 * @param smallT to initialize small Triangle.
	 */
	ComposedShape(Rectangle mainR,Triangle smallT) {
		mainRectangle = mainR;
		mainRectangle.setSizeNumber(0);
		smallTriangle = smallT;
		smallTriangle.setSizeNumber(1);
		set_optimalFitNumber(3);
		
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainC to initialize main Circle.
	 * @param smallR to initialize small Rectangle.
	 */
	ComposedShape(Circle mainC,Rectangle smallR) {
		mainCircle = mainC;
		mainCircle.setSizeNumber(0);
		smallRectangle = smallR;
		smallRectangle.setSizeNumber(1);
		set_optimalFitNumber(4);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainC to initialize main Circle.
	 * @param smallC to initialize small Circle.
	 */
	ComposedShape(Circle mainC,Circle smallC) {
		mainCircle = mainC;
		mainCircle.setSizeNumber(0);
		smallCircle = smallC;
		smallCircle.setSizeNumber(1);
		set_optimalFitNumber(5);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainC to initialize main Circle.
	 * @param smallT to initialize small Triangle.
	 */
	ComposedShape(Circle mainC,Triangle smallT) {
		mainCircle = mainC;
		mainCircle.setSizeNumber(0);
		smallTriangle = smallT;
		smallTriangle.setSizeNumber(1);
		set_optimalFitNumber(6);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainT to initialize main Triangle.
	 * @param smallR to initialize small Rectangle.
	 */
	ComposedShape(Triangle mainT,Rectangle smallR) {
		mainTriangle = mainT;
		mainTriangle.setSizeNumber(0);
		mainTriangle.setRotateControl(0);
		smallRectangle = smallR;
		smallRectangle.setSizeNumber(1);
		set_optimalFitNumber(7);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainT to initialize main Triangle.
	 * @param smallC to initialize small Circle.
	 */
	ComposedShape(Triangle mainT,Circle smallC) {
		mainTriangle = mainT;
		mainTriangle.setSizeNumber(0);
		smallCircle = smallC;
		smallCircle.setSizeNumber(1);
		set_optimalFitNumber(8);
	}
	/**
	 * ComposedShape two parameters constructor.
	 * @param mainT to initialize mainTriangle.
	 * @param smallT to initialize small Triangle.
	 */
	ComposedShape(Triangle mainT,Triangle smallT) {
		mainTriangle = mainT;
		mainTriangle.setSizeNumber(0);
		smallTriangle = smallT;
		smallTriangle.setSizeNumber(1);
		set_optimalFitNumber(9);
	}
	/**
	 * optimalFit function calculate the small shapes.
	 * @throws Exception if the x or y is negative value.
	 */
	public void optimalFit() throws Exception{
		Shape[] tempArray = new Shape[1000];
		
		if(optimalFitNumber == 1) {
			
			tempArray[0] = mainRectangle;
			
			int control=0,counter=0,index=1;
			double controlX=0,controlX2=0;
			double temp,remainder;
			
			if(smallRectangle.get_Height() > smallRectangle.get_Width()){
	 			temp = smallRectangle.get_Width();
	 			smallRectangle.setWidth(smallRectangle.get_Height());
	 			smallRectangle.setHeight(temp);
	 		}
			
			while(control != -1){
				/* First, prints the rectangles horizontally as far as it can be printed. */	
				while(smallRectangle.getPos_x()+smallRectangle.get_Width() <= mainRectangle.get_Width() && 
						smallRectangle.getPos_y()+smallRectangle.get_Height() <= mainRectangle.get_Height()){
					
					
					Rectangle tempRect = new Rectangle(smallRectangle);
					tempArray[index] = tempRect;
					index++;

					counter++;
					smallRectangle.setPos_x(smallRectangle.getPos_x()+smallRectangle.get_Width());
					controlX = smallRectangle.getPos_x();
				}
				smallRectangle.setPos_x(0);
				smallRectangle.setPos_y(smallRectangle.getPos_y() + smallRectangle.get_Height());
				/* When the line is finished, it is passed to a bottom line.So, x can be 0. */

				if(smallRectangle.getPos_y() >= mainRectangle.get_Height())
					control = -1; /* If more rectangles cannot be printed, the loop is exited. */
			}
			
			
			controlX2 = controlX;
			remainder = mainRectangle.get_Width() - controlX; 
			/* The difference is retained in the remainder variable. Can the rectangle be printed vertically to the remaining length? */

			if(remainder >= smallRectangle.get_Height()){

				smallRectangle.setPos_y(0);
				temp = smallRectangle.get_Height();
				smallRectangle.setHeight(smallRectangle.get_Width());
				smallRectangle.setWidth(temp); /* The edges of the small rectangle are swap. */ 
				control=0;
				
				while(control != -1){
					
					while(controlX + smallRectangle.get_Width()<= mainRectangle.get_Width()){
						
						
						smallRectangle.setPos_x(controlX);
						
						Rectangle tempRect = new Rectangle(smallRectangle);
						tempArray[index] = tempRect;
						index++;

						counter++;
						controlX += smallRectangle.get_Width(); /* This time it is printed vertically. */
					}
					controlX=controlX2;
					smallRectangle.setPos_y(smallRectangle.getPos_y() + smallRectangle.get_Height());
					
					if(smallRectangle.getPos_y() + smallRectangle.get_Height() >= mainRectangle.get_Height()) 
						control = -1;
				}
			}
			
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);

			double redArea = mainRectangle.area();
			double greenArea = counter * smallRectangle.area();
			
			System.out.printf("\nNumber 1 : \nMain : Rectangle || Inner : Rectangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
			 
		}
		
		else if(optimalFitNumber == 2){
				
			tempArray[0] = mainRectangle;
				
			int control=0,counter=0,index=1;
				
			if( (mainRectangle.get_Height() - mainRectangle.get_Width() > 0 && (2 * smallCircle.getRadius() > mainRectangle.get_Width())) || 
				( mainRectangle.get_Width()-mainRectangle.get_Height() > 0 && (2 * smallCircle.getRadius() > mainRectangle.get_Width()))){
				throw new Exception();
			}
				

			else{
				while(control != -1){
												
					while(smallCircle.getPos_x()+smallCircle.getRadius() <= mainRectangle.get_Width() && 
							smallCircle.getPos_y()+smallCircle.getRadius() <= mainRectangle.get_Height()){

							//System.out.printf("X : %.2f \tY : %.2f\n",smallCircle.getPos_x(),smallCircle.getPos_y());
							
						Circle temp = new Circle(smallCircle);
						tempArray[index] = temp;
						index++;

						counter++;
							
						smallCircle.setPos_x(smallCircle.getPos_x() + 2*smallCircle.getRadius());
					}
					smallCircle.setPos_x(smallCircle.getRadius());
					smallCircle.setPos_y(smallCircle.getPos_y() + 2*smallCircle.getRadius());
					/* Circles are printed horizontally. When there is no space, a bottom line is checked and printed. */
					if(smallCircle.getPos_y() > mainRectangle.get_Height())
						control = -1;
				}
			}
				
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
				
			double redArea = mainRectangle.area();
			double greenArea = counter * smallCircle.area();
			
			System.out.printf("\nNumber 2 : \nMain : Rectangle || Inner : Circle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
		}
		
		else if(optimalFitNumber == 3){
			
			tempArray[0] = mainRectangle;
			
			double x2,x3,y2,y3;
			double base3 = Math.sqrt(3.0);
			int control = 0,i,counter=0,index=1;
			
			if(mainRectangle.get_Height() <= smallTriangle.getEdge())
				throw new Exception();

			else{
				
				smallTriangle.setPos_x(smallTriangle.getEdge()/2); smallTriangle.setPos_y(0);
				x2 = 0;              				y2 = (smallTriangle.getEdge()/2)*base3; 
				x3 = smallTriangle.getEdge();     	y3 = (smallTriangle.getEdge()/2)*base3;

				smallTriangle.setRotateControl(0);
				while(control != -1){	
					
					while(x3 <= mainRectangle.get_Width() && y2 <= mainRectangle.get_Height()){
						
						Triangle tempTri = new Triangle(smallTriangle);
						tempArray[index] = tempTri;
						index++;

						counter++;

						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());
						/* x coordinates increase by the edge of the triangle. */
						
						if(x3 > mainRectangle.get_Width() && y2+(smallTriangle.getEdge()/2)*base3 < mainRectangle.get_Height()){
							/* Condition for moving to a bottom line. */
						
							smallTriangle.setPos_x(smallTriangle.getEdge()/2);
							smallTriangle.setPos_y(smallTriangle.getPos_y()+(smallTriangle.getEdge()/2)*base3);
							x2 = 0;              			   y2 += (smallTriangle.getEdge()/2)*base3;
							x3 = smallTriangle.getEdge();      y3 += (smallTriangle.getEdge()/2)*base3;
							/* When going to the bottom line, y coordinates increase by the height of the triangle. */
						}

						else
							control=-1;
					}
				}

				control = 0;
				smallTriangle.setPos_x(smallTriangle.getEdge()/2);   smallTriangle.setPos_y(0); 
				x2 = (3*smallTriangle.getEdge())/2;    						y2 = 0;
				x3 = smallTriangle.getEdge();      						    y3 = (smallTriangle.getEdge()/2)*base3;

				smallTriangle.setRotateControl(1);
				
				while(control != -1){	
					
					while(x2 <= mainRectangle.get_Width() && y3 <= mainRectangle.get_Width()){
						/* Doing the same operation for opposite triangles. */
						
						Triangle tempTri = new Triangle(smallTriangle);
						tempArray[index] = tempTri;
						index++;

						counter++;

						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());

						if(x2 > mainRectangle.get_Width() && (y3 + (smallTriangle.getEdge()/2)*base3) < mainRectangle.get_Height()){
							
							smallTriangle.setPos_x(smallTriangle.getEdge()/2);
							smallTriangle.setPos_y(smallTriangle.getPos_y()+(smallTriangle.getEdge()/2)*base3);
							x2 = (3*smallTriangle.getEdge())/2;  y2 += (smallTriangle.getEdge()/2)*base3;
							x3 = smallTriangle.getEdge();        y3 += (smallTriangle.getEdge()/2)*base3;
						}

						else
							control=-1;
					}
				}
			}
	
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainRectangle.area();
			double greenArea = counter * smallTriangle.area();
			
			System.out.printf("\nNumber 3 : \nMain : Rectangle || Inner : Triangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
			
		}
		
		else if(optimalFitNumber == 4){
			
			tempArray[0] = mainCircle;
			
			int counter=0,i=0,j=0,index=1;
			double x,y,result;
			// i is x axis, j is y axis
			
			while(j<2*mainCircle.getRadius()){

				i=0;		
				while(i<2*mainCircle.getRadius()){

					x = Math.pow(i-mainCircle.getPos_x(),2);
					y = Math.pow(j-mainCircle.getPos_y(),2);
					result = Math.sqrt(x+y);
					// Given the circle equation (x-a)^2 + (y-b)^2 = r*r (M(a,b)) 				
					if((result <= mainCircle.getRadius())){
						// The 4 coordinates of the rectangle are checked to see if they are in the circle.
						x = Math.pow(i-mainCircle.getPos_x(),2);
						y = Math.pow(j+smallRectangle.get_Height()-mainCircle.getPos_y(),2);
						result = Math.sqrt(x+y);
						
						if((result <= mainCircle.getRadius())){
							x = Math.pow(i+smallRectangle.get_Width()-mainCircle.getPos_x(),2);
							y = Math.pow(j+smallRectangle.get_Height()-mainCircle.getPos_y(),2);
							result = Math.sqrt(x+y);

							if((result <= mainCircle.getRadius())){
								
								x = Math.pow(i+smallRectangle.get_Height()-mainCircle.getPos_x(),2);
								y = Math.pow(j-mainCircle.getPos_y(),2);
								result = Math.sqrt(x+y);

								if((result <= mainCircle.getRadius())){

									smallRectangle.setPos_x(i);
									smallRectangle.setPos_y(j);
									
									Rectangle tempRect = new Rectangle(smallRectangle);
									tempArray[index] = tempRect;
									index++;

									i += smallRectangle.get_Width();
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
				j += smallRectangle.get_Height();
			}

			
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainCircle.area();
			double greenArea = counter * smallRectangle.area();
			
			System.out.printf("\nNumber 4 : \nMain : Circle || Inner : Rectangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
			
		}
		
		else if(optimalFitNumber == 5) {
			
			tempArray[0] = mainCircle;
			
			int i=0,j=0,control=0,counter=0,index=1;
					
			while(i <= 2*mainCircle.getRadius()){   
				
				j=0; /* j is x axis, i is y axis. */  
				while(j <= 2*mainCircle.getRadius()){ 
					/* Circle writing on svg file is checked in line by line. */
					if( Math.sqrt((mainCircle.getRadius()-i)*(mainCircle.getRadius()-i)+((mainCircle.getRadius()-j)*((mainCircle.getRadius()-j)))) 
							+ smallCircle.getRadius() <= mainCircle.getRadius()){
				
						smallCircle.setPos_x(j);
						smallCircle.setPos_y(i);
						
						Circle tempCirc = new Circle(smallCircle);
						tempArray[index] = tempCirc;
						index++;

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
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainCircle.area();
			double greenArea = counter * smallCircle.area();
			
			System.out.printf("\nNumber 5 : \nMain : Circle || Inner : Circle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));

		}
		
		else if(optimalFitNumber == 6) {
			
			tempArray[0] = mainCircle;
			
			int i=0,j=0,counter=0,index=1;
			double x,y,result;
			
			while(j <= 2*mainCircle.getRadius()){
				i=0;
				while(i <= 2*mainCircle.getRadius()){
					x = Math.pow(i-mainCircle.getPos_x(),2);
					y = Math.pow(j-mainCircle.getPos_y(),2);
					result = Math.sqrt(x+y);

					if(result <= mainCircle.getRadius()){

						x = Math.pow((i-smallTriangle.getEdge()/2)-mainCircle.getPos_x(),2);
						y = Math.pow((j+smallTriangle.getEdge()*Math.sqrt(3)/2)-mainCircle.getPos_y(),2);
						result = Math.sqrt(x+y);

						if(result <= mainCircle.getRadius()){

							x = Math.pow((i+smallTriangle.getEdge()/2)-mainCircle.getPos_x(),2);
							y = Math.pow((j+smallTriangle.getEdge()*Math.sqrt(3)/2)-mainCircle.getPos_y(),2);
							result = Math.sqrt(x+y);

							if(result <= mainCircle.getRadius()){
								smallTriangle.setPos_x(i);
								smallTriangle.setPos_y(j);
								smallTriangle.setRotateControl(0);
								
								Triangle tempTri = new Triangle(smallTriangle);
								tempArray[index] = tempTri;
								index++;

								counter++;

								if( Math.sqrt(Math.pow(i+smallTriangle.getEdge()-mainCircle.getPos_x(),2) + Math.pow(j-mainCircle.getPos_y(),2)) < mainCircle.getRadius()){
									// Control the inversi triangle's coordinate
									smallTriangle.setRotateControl(1);
									
									Triangle tempTri2 = new Triangle(smallTriangle);
									tempArray[index] = tempTri2;
									index++;

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
			
			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainCircle.area();
			double greenArea = counter * smallTriangle.area();
			
			System.out.printf("\nNumber 6 : \nMain : Circle || Inner : Triangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
		}
		
		else if(optimalFitNumber == 7) {
			
			tempArray[0] = mainTriangle;
			
			int control=0,i=1,counter=0,index=1;
			double controlx,base3=Math.sqrt(3);
		
			controlx = ((smallRectangle.get_Height()*base3)/3); 
			smallRectangle.setPos_x((smallRectangle.get_Height()*base3/3));
			smallRectangle.setPos_y(mainTriangle.getEdge()/2*base3-smallRectangle.get_Height());

			while(control != -1){	
				/* Drawing rectangles starting from left to right. */
			
				while(smallRectangle.getPos_x() + smallRectangle.get_Width() <= 
						mainTriangle.getEdge() - ((smallRectangle.get_Height()*base3)/3)*i){
			
					Rectangle tempRect = new Rectangle(smallRectangle);
					tempArray[index] = tempRect;
					index++;

					counter++;
					
					smallRectangle.setPos_x(smallRectangle.getPos_x() + smallRectangle.get_Width());
					/* Drawing starts from the bottom. */
				}
				i++;
				smallRectangle.setPos_x(controlx*i);
				smallRectangle.setPos_y(smallRectangle.getPos_y() - smallRectangle.get_Height());
				/* When the upper line is passed, the triangle narrows and the x coordinate becomes narrower. */
				
				if(smallRectangle.getPos_y() - smallRectangle.get_Height() < 0)
					control = -1;

				if(smallRectangle.getPos_x() > mainTriangle.getEdge() && 
					smallRectangle.getPos_y() > (mainTriangle.getEdge()/2*base3) - (i*smallRectangle.get_Height()))
						control = -1;
				/*There is no area to draw triangles. */
			}

			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainTriangle.area();
			double greenArea = counter * smallRectangle.area();
			
			System.out.printf("\nNumber 7 : \nMain : Triangle || Inner : Rectangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
		}
		
		else if(optimalFitNumber == 8) {
			
			tempArray[0] = mainTriangle;
			
			int counter=0,baseCount,i=1,count=0,index=1;
			double controlCx,base3=Math.sqrt(3);
			
			controlCx = smallCircle.getRadius() * base3;  
			smallCircle.setPos_x(smallCircle.getRadius()*base3);
			smallCircle.setPos_y(mainTriangle.getEdge()/2*base3 - smallCircle.getRadius());
			
			while(smallCircle.getPos_x() + base3*smallCircle.getRadius() <= mainTriangle.getEdge()){  
				counter++;
				
				Circle tempCirc = new Circle(smallCircle);
				tempArray[index] = tempCirc;
				index++;

				count++;

				smallCircle.setPos_x(smallCircle.getPos_x() + 2*smallCircle.getRadius());			
			}

			baseCount = counter;	
			/* Other columns have (bottom-1) circles. */ 
			while(baseCount != 1){ 
				
				smallCircle.setPos_x(controlCx+smallCircle.getRadius()*i);
				smallCircle.setPos_y(smallCircle.getPos_y()-smallCircle.getRadius()*base3);
				i++;
				baseCount -= 1;

				for(int k=baseCount;k>0;k--){
					
					Circle tempCirc = new Circle(smallCircle);
					tempArray[index] = tempCirc;
					index++;

					count++;
					smallCircle.setPos_x(smallCircle.getPos_x() + 2*smallCircle.getRadius());
				}
			}

			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainTriangle.area();
			double greenArea = counter * smallCircle.area();
			
			System.out.printf("\nNumber 8 : \nMain : Triangle || Inner : Circle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
		}
		
		else if(optimalFitNumber == 9) {
			
			tempArray[0] = mainTriangle;
			
			double x2,x3,y2,y3,base3=Math.sqrt(3);
			int counter=0,baseCount,i=2,count=0,index=1;
			
			if(smallTriangle.getEdge() > mainTriangle.getEdge()){
				//cout << "I can not fit shapes into the main container." << endl;
			}
		
			else{

				smallTriangle.setPos_x(smallTriangle.getEdge()/2);   smallTriangle.setPos_y((mainTriangle.getEdge()/2)*base3-(smallTriangle.getEdge()/2)*base3);
				x2=smallTriangle.getEdge();  	    						y2=(mainTriangle.getEdge()/2*base3);
				x3=smallTriangle.getEdge()/2;       						y3=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				

				while(x2 <= mainTriangle.getEdge()){
					/* Most triangles are in the base column. */
					
					Triangle tempTri = new Triangle(smallTriangle);
					tempArray[index] = tempTri;
					index++;
					
					counter++;
					count++;
					
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());
				}
				baseCount=counter;
				/* Other columns have (bottom-1) circles.Basecounter is the number which is base column's triangles.*/
				

				while(baseCount != 1){

					smallTriangle.setPos_x(smallTriangle.getEdge()/2*i);
					if(smallTriangle.getPos_y()-smallTriangle.getEdge()/2*base3 < 0)
						smallTriangle.setPos_y(0);
					else
						smallTriangle.setPos_y(smallTriangle.getPos_y()-smallTriangle.getEdge()/2*base3);	
					
					x2=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y2 -= smallTriangle.getEdge()/2*base3;
					x3=smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2;		y3 -= smallTriangle.getEdge()/2*base3;
			
					i++;
					baseCount -= 1;
					
					for(int k=baseCount;k>0;k--){

						Triangle tempTri = new Triangle(smallTriangle);
						tempArray[index] = tempTri;
						index++;
						
						count++;
						counter++;
					
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());
					}
				}

				smallTriangle.setRotateControl(1);

				baseCount=0; i=1;

				smallTriangle.setPos_x(smallTriangle.getEdge()/2);
				smallTriangle.setPos_y(base3*(mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				x2=3*smallTriangle.getEdge()/2;  	y2=base3*((mainTriangle.getEdge()-smallTriangle.getEdge())/2);
				x3=smallTriangle.getEdge(); 		y3=mainTriangle.getEdge()/2*base3; 
				/* The same operations are done in reserved triangles. */
				//      -------
				//		 \   /
				//        \ /
				//         -
				
				while(x2 <= mainTriangle.getEdge() - smallTriangle.getEdge()/2){
					counter++; baseCount++;
			
					Triangle tempTri = new Triangle(smallTriangle);
					tempArray[index] = tempTri;
					index++;

					count++;
					
					x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
					smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());
				}

				while(baseCount != 1){

					smallTriangle.setPos_x(smallTriangle.getEdge()*i/2 + smallTriangle.getEdge()/2);
					smallTriangle.setPos_y(smallTriangle.getPos_y() - smallTriangle.getEdge()/2*base3);
					
					x2=3*smallTriangle.getEdge()/2 + i*smallTriangle.getEdge()/2;	y2 -= smallTriangle.getEdge()/2*base3;
					x3=smallTriangle.getEdge()/2*i+smallTriangle.getEdge();			y3 -= smallTriangle.getEdge()/2*base3;
					
					i++; baseCount -= 1;

					for(int c=baseCount;c>0;c--){
						
						Triangle tempTri = new Triangle(smallTriangle);
						tempArray[index] = tempTri;
						index++;
						
						counter++;
						x2 += smallTriangle.getEdge(); x3 += smallTriangle.getEdge();
						smallTriangle.setPos_x(smallTriangle.getPos_x() + smallTriangle.getEdge());
					}
				}
			}

			arrayShape = new Shape[index];
			System.arraycopy(tempArray, 0, arrayShape, 0, index);
			
			double redArea = mainTriangle.area();
			double greenArea = counter * smallTriangle.area();
			
			System.out.printf("\nNumber 9 : \nMain : Triangle || Inner : Triangle");
			System.out.printf("\nI can fit at most %d  small shapes into the main container.The empty area (red) in container is %.2f\n", counter,(redArea-greenArea));
		}
	}
	
	@Override
	public double area() {
		double totalArea=0.0;
		for(int i=0;i<arrayShape.length;++i){
			totalArea += arrayShape[i].area();
		}
		return totalArea;
	}

	@Override
	public double perimeter() {
		double totalPerimeter=0.0;
		for(int i=0;i<arrayShape.length;++i){
			totalPerimeter += arrayShape[i].perimeter();
		}
		return totalPerimeter;
	}

	@Override
	public void increment() throws Exception {
		for(int i=0;i<arrayShape.length;++i) {
			arrayShape[i].increment();
		}
	}

	@Override
	public void decrement() throws Exception {
		for(int i=0;i<arrayShape.length;++i) {
			arrayShape[i].decrement();
		}
	}

	@Override
	public void draw(Graphics g) {
		paintComponent(g);
	}
	
	@Override
	public void paintComponent(Graphics g) {		
		
		super.paintComponent(g);
        for(int i=0;i<arrayShape.length;++i) {
        	arrayShape[i].draw(g);
        }
	}
	
	@Override
	public int compareTo(Shape other){
		if(this.area() == other.area())
			return 0;
		else if(this.area() > other.area())
			return 1;
		else
			return -1;
	}
	
	private void set_optimalFitNumber(int num) {
		optimalFitNumber = num;
	}
	/**
	 * 
	 * @return ComposedShape's array size.
	 */
	public int size_array() {
		return arrayShape.length;
	}
}
