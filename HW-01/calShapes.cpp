/********* Gokhan Has - 161044067 *********/

#include "calShapes.h"

int shapes(Shapes shape,double &width,double &height,double &radius, double &edge){

	if(shape == Shapes::R){
		cout << "Please enter the width" << endl;
		cin >> width;
		cout << "Please enter the height" << endl;
		cin >> height;
		return 1;
	}

	else if(shape == Shapes::C){
		cout << "Please enter the radius" << endl;
		cin >> radius;
		return 1;
	}

	else if(shape == Shapes::T){
		cout << "Please enter the edge" << endl;
		cin >> edge;
		return 1;
	}
	return 0;

	/* This function gets the information of the shape that the user entered. */
}


int whichShape(Shapes &shape,char sh){

	if(sh == 'R' || sh == 'r')
		shape = Shapes::R;
	else if(sh == 'C' || sh == 'c')
		shape = Shapes::C;
	else if(sh == 'T' || sh == 't')
		shape = Shapes::T;
	else{
		cout << "You entered an invalid input. Only R,C or T." << endl;
		return 0;
	}
	return 1;

	/* This function determines which shape the user enters. */
}

int rectangleInRectangle(ofstream &filename,double mainRwidth,double mainRheight,
							double smallRwidth,double smallRheight){

	int counter=0,x=0,y=0,redArea,greenArea,controlX,controlX2;
	int control=0;
	double temp,remainder;
	
	filename << "\n\t<rect width=\"" << mainRwidth << "\" height=\"" << mainRheight << "\" fill=\"red\" />" << endl;
	/* Writing main rectangle on svg file. */

	if(smallRheight > smallRwidth){
 		temp = smallRwidth;
 		smallRwidth = smallRheight;
 		smallRheight = temp;
 	}


	if(smallRheight > mainRheight || smallRwidth > mainRwidth){
		cout << "I can not fit small shapes into the main container." << endl;
		return 0;
	}

	else{
		
		while(control != -1){
			/* First, prints the rectangles horizontally as far as it can be printed. */	
			while(x+smallRwidth <= mainRwidth && y+smallRheight <= mainRheight){

				filename << "\n\t<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << smallRwidth << "\" height=\"" << smallRheight << "\" style=\"fill:green;;stroke-width:1\" />" << endl;
				counter++;
				x += smallRwidth;
				controlX=x;
			}
			x=0;
			y += smallRheight; 
			/* When the line is finished, it is passed to a bottom line.So, x can be 0. */

			if(y >= mainRheight)
				control = -1; /* If more rectangles cannot be printed, the loop is exited. */
		}

		controlX2 = controlX;
		remainder = mainRwidth-controlX; 
		/* The difference is retained in the remainder variable. Can the rectangle be printed vertically to the remaining length? */

		if(remainder >= smallRheight){
			y=0;
			temp = smallRheight,
			smallRheight = smallRwidth;
			smallRwidth = temp; /* The edges of the small rectangle are swap. */
			control=0;
			
			while(control != -1){
				
				while(controlX+smallRwidth <= mainRwidth){
					
					filename << "\n\t<rect x=\"" << controlX << "\" y=\"" << y  << "\" width=\"" << smallRwidth << "\" height=\"" << smallRheight << "\" style=\"fill:green;stroke-width:1\" />" << endl;
					counter++;
					controlX += smallRwidth; /* This time it is printed vertically. */
				}
				controlX=controlX2;
				y += smallRheight;

				if(y+smallRheight >= mainRheight)
					control = -1;
			}		
		}
	}
	redArea = mainRheight * mainRwidth;
	greenArea = counter * smallRheight * smallRwidth;
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;
	return 0;
}

int circleInRectangle(ofstream &filename,double mainRwidth,double mainRheight,double radius){

	int counter=0,cx=radius,cy=radius,control=0;
	double redArea,greenArea;

	filename << "\n\t<rect width=\"" << mainRwidth << "\" height=\"" << mainRheight << "\" fill=\"red\" />" << endl;
	/* Writing main rectangle on svg file. */

	if( (mainRheight-mainRwidth > 0 && (2*radius > mainRwidth)) || ( mainRwidth-mainRheight > 0 && (2*radius > mainRheight))){
		cout << "I can not fit shapes into the main container." << endl;
		return 0;
	}

	else{

		while(control != -1){

			while(cx+radius <= mainRwidth && cy+radius <= mainRheight){

				filename << "\t<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << radius << "\" fill=\"green\" />" << endl;
				counter++;
				cx += 2*radius;
			}
			cx=radius;
			cy += 2*radius;
			/* Circles are printed horizontally. When there is no space, a bottom line is checked and printed. */
			if(cy > mainRheight)
				control=-1;
		}
	}

	redArea = mainRwidth * mainRheight;
	greenArea = (PI * radius * radius) * counter; /* PI defining in "calShapes.h" */
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}

int triangleInRectangle(ofstream &filename,double mainRwidth,double mainRheight,double smallEdge){

	double x1,x2,x3,y1,y2,y3;
	double redArea,greenArea,base3;
	int control=0,counter=0,counter2=1;
	base3 = sqrt(3);

	if(mainRheight <= smallEdge){
		cout << "I can not fit shapes into the main container." << endl;
		return 0;
	}

	else{

		filename << "\n\t<rect width=\"" << mainRwidth << "\" height=\"" << mainRheight << "\" fill=\"red\" />" << endl;
		/* Writing main rectangle on svg file. */
		
		x1 = smallEdge/2;    y1 = 0;
		x2 = 0;              y2 = (smallEdge/2)*base3; /* Determining the coordinates of the triangle. */
		x3 = smallEdge;      y3 = (smallEdge/2)*base3;

		while(control != -1){	
			
			while(x3 <= mainRwidth && y2 <= mainRheight){

				filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke::0.1\" />" << endl;
				counter++;
				x1 += smallEdge; x2 += smallEdge; x3 += smallEdge;
				/* x coordinates increase by the edge of the triangle. */
				
				if(x3 > mainRwidth && y2+(smallEdge/2)*base3 < mainRheight){
					/* Condition for moving to a bottom line. */
					x1 = smallEdge/2;    y1 += (smallEdge/2)*base3;
					x2 = 0;              y2 += (smallEdge/2)*base3;
					x3 = smallEdge;      y3 += (smallEdge/2)*base3;
					/* When going to the bottom line, y coordinates increase by the height of the triangle. */
				}

				else
					control=-1;
			}
		}

		control = 0;
		x1 = smallEdge/2;        y1 = 0;
		x2 = (3*smallEdge)/2;    y2 = 0;
		x3 = smallEdge;      y3 = (smallEdge/2)*base3;

		while(control != -1){	
			
			while(x2 <= mainRwidth && y3 <= mainRheight){
				/* Doing the same operation for opposite triangles. */
				filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke-width::0.1\" />" << endl;
				counter++;
				x1 += smallEdge; x2 += smallEdge; x3 += smallEdge;

				if(x2 > mainRwidth && y3+(smallEdge/2)*base3 < mainRheight){
					
					x1 = smallEdge/2;      y1 += (smallEdge/2)*base3;
					x2 = (3*smallEdge)/2;  y2 += (smallEdge/2)*base3;
					x3 = smallEdge;        y3 += (smallEdge/2)*base3;
				}

				else
					control=-1;
			}
		}
	}

	redArea = mainRheight * mainRwidth;
	greenArea = counter * (smallEdge*((smallEdge/2)*base3) / 2);
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}


int rectangleInTriangle(ofstream &filename,double mainEdge,double smallRwidth,double smallRheight){

	int control=0,counter=0,i=1;
	double x,y,x1,x2,x3,y1,y2,y3,base3,controlx,redArea,greenArea;
	base3 = sqrt(3);
	
	x1=mainEdge/2;    y1=0;
	x2=0;             y2=(mainEdge/2)*base3;
	x3=mainEdge;      y3=(mainEdge/2)*base3;

	filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:red\" />" << endl;
	/* Writing the svg file according to the coordinates of the triangle. */
	
	controlx = (smallRheight*base3)/3;
	x = (smallRheight*base3)/3; y=((mainEdge/2)*base3)-smallRheight;

	while(control != -1){	
		/* Drawing rectangles starting from left to right. */
		while(x+smallRwidth <= mainEdge - (smallRheight*base3/3)*i){
			filename << "\n\t<rect x=\"" << x <<  "\" y=\"" << y << "\" width=\"" << smallRwidth << "\" height=\"" << smallRheight << "\" fill=\"green\" />";
			counter++;
			x += smallRwidth;
			/* Drawing starts from the bottom. */
		}
		i++;
		x = controlx*i;  y -= smallRheight;
		/* When the upper line is passed, the triangle narrows and the x coordinate becomes narrower. */
		if(x > mainEdge && y > (mainEdge/2*base3) - (i*smallRheight))
			control = -1;
		/*There is no area to draw triangles. */
	}
	
	redArea = (mainEdge) * ((mainEdge/2)*base3) / 2;
	greenArea = counter * smallRheight * smallRwidth;
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}

int circleInTriangle(ofstream &filename,double mainEdge,double smallRadius){

	int control=0,counter=0,i=1,baseCount;
	double x,y,x1,x2,x3,y1,y2,y3,base3,controlCx,redArea,greenArea,cx,cy;
	base3 = sqrt(3);
	
	x1=mainEdge/2;    y1=0;
	x2=0;             y2=(mainEdge/2)*base3;
	x3=mainEdge;      y3=(mainEdge/2)*base3;
	/* Writing the svg file according to the coordinates of the triangle. */
	filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:red\" />" << endl;
	
	controlCx = smallRadius * base3;
	cx = smallRadius * base3;
	cy = (mainEdge/2*base3)-smallRadius;
	
	while(cx+base3*smallRadius <= mainEdge){
		/* In the triangle, the column with the most circles is the closest to the base. */
		filename << "\t\n<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << smallRadius << "\" fill=\"green\" />";
		counter++;
		cx += 2*smallRadius; 			
	}

	baseCount = counter;	
	/* Other columns have (bottom-1) circles. */ 
	while(baseCount != 1){
		cx = controlCx+smallRadius*i;
		cy = cy-(smallRadius*base3);
		i++;
		baseCount -= 1;

		for(int k=baseCount;k>0;k--){
			filename << "\t\n<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << smallRadius << "\" fill=\"green\" />";
			counter++;
			cx += 2*smallRadius;
		}
	}
		
	redArea = (mainEdge) * ((mainEdge/2)*base3) / 2;
	greenArea = counter * PI * smallRadius * smallRadius;
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}

int triangleInTriangle(ofstream &filename,double mainEdge,double smallEdge){

	int counter=0,baseCount,i=1;
	double x,y,x1,x2,x3,y1,y2,y3,base3,redArea,greenArea;
	base3 = sqrt(3);
	
	x1=mainEdge/2;    y1=0;
	x2=0;             y2=(mainEdge/2)*base3;
	x3=mainEdge;      y3=(mainEdge/2)*base3;
	/* Writing the svg file according to the coordinates of the triangle. */
	filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:red\" />" << endl;

	if(smallEdge > mainEdge){
		cout << "I can not fit shapes into the main container." << endl;
		return 0;
	}

	else{

		x1=0;   		y1=(mainEdge/2*base3);
		x2=smallEdge;  	y2=(mainEdge/2*base3);
		x3=smallEdge/2; y3=base3*((mainEdge-smallEdge)/2);

		while(x2 <= mainEdge){
			/* Most triangles are in the base column. */
			filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke-width::0.2\" />" << endl;
			counter++;
			x2 += smallEdge;
			x1 += smallEdge;
			x3 += smallEdge;
		}
		baseCount=counter;
		/* Other columns have (bottom-1) circles.Basecounter is the number which is base column's triangles. */ 
		while(baseCount != 1){

			x1=smallEdge/2 * i;					y1 -= smallEdge/2*base3;	
			x2=smallEdge/2*i+smallEdge;			y2 -= smallEdge/2*base3;
			x3=smallEdge*i/2 + smallEdge/2;		y3 -= smallEdge/2*base3;
	
			i++;
			baseCount -= 1;
			
			for(int k=baseCount;k>0;k--){

				filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke-width::0.2\" />" << endl;
				counter++;
				x2 += smallEdge;
				x1 += smallEdge;
				x3 += smallEdge;
			}
		}

		baseCount=0; i=1;
		x1=smallEdge/2;   	y1=base3*((mainEdge-smallEdge)/2);
		x2=3*smallEdge/2;  	y2=base3*((mainEdge-smallEdge)/2);
		x3=smallEdge; 		y3=mainEdge/2*base3; 
		/* The same operations are done in reserved triangles. */
		//      -------
		//		 \   /
		//        \ /
		//         -
		
		while(x2 <= mainEdge - smallEdge/2){
			filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke-width::0.2\" />" << endl;
			counter++; baseCount++;
			x2 += smallEdge;
			x1 += smallEdge;
			x3 += smallEdge;
		}

		while(baseCount != 1){

			x1=smallEdge*i/2 + smallEdge/2;     y1 -= smallEdge/2*base3;
			x2=3*smallEdge/2 + i*smallEdge/2;	y2 -= smallEdge/2*base3;
			x3=smallEdge/2*i+smallEdge;			y3 -= smallEdge/2*base3;
			i++; baseCount -= 1;

			for(int c=baseCount;c>0;c--){
				filename << "\t<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" style=\"fill:green;stroke-width::0.5\" />" << endl;
				counter++;
				x2 += smallEdge;
				x1 += smallEdge;
				x3 += smallEdge;
			}
		}
	}

	redArea = (mainEdge) * ((mainEdge/2*base3) / 2);
	greenArea = counter * ((smallEdge) * (smallEdge/2*base3) / 2);
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}

int circleInCircle(ofstream &filename,double mainRadius,double smallRadius){
	
	int i=0,j=0,control=0,counter=0;
	double redArea,greenArea;
	
	filename << "\t\n<circle cx=\"" << mainRadius << "\" cy=\"" << mainRadius << "\" r=\"" << mainRadius << "\" fill=\"red\" />";
	/* Writing main circle on svg file. */

	if(smallRadius > mainRadius){
		cout << "I can not fit shapes into the main container." << endl;
		return 0;
	}
	
	while(i<=2*mainRadius){
		
		j=0; /* j is x axis, i is y axis. */
		while(j<=2*mainRadius){
			/* Circle writing on svg file is checked in line by line. */
			if( sqrt( (mainRadius-i)*(mainRadius-i) + (mainRadius-j)*(mainRadius-j) )+smallRadius <= mainRadius ){
				
				filename << "\t\n<circle cx=\"" << j << "\" cy=\"" << i << "\" r=\"" << smallRadius << "\" fill=\"green\" />";
				j += 2*smallRadius;
				control=-1;
				counter++;
			}
			else
				j += 1;
		}
		if(control == -1){
			i += 2*smallRadius;
			control=0;
			/* The condition of passing to a bottom line. */
		}
		
		else
			i += 1;
	}
	
	redArea = PI * mainRadius * mainRadius;
	greenArea = counter * PI * smallRadius * smallRadius;
	/* Calculating areas and printing result on screen. */
	cout << "I can fit at most " << counter << " small shapes into the main container.The empty area (red) in container is "
		 << (redArea-greenArea) << "." << endl;

	return 0;
}