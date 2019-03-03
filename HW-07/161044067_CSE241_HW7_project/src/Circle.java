/*
 * Gokhan Has - 161044067
 */


import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

/**
 * Circle class extends JPanel and implements Shape.
 * @author Gokhan Has
 *
 */
public class Circle extends JPanel implements Shape {

	private double radius;
	private double pos_x;
	private double pos_y;
	private int sizeNumber;
	
	/**
	 * No parameter constructor.
	 */
	Circle() {
		radius = 0.0;
		pos_x = 0.0;
		pos_y = 0.0;
	}
	
	/**
	 * One parameter constructor.
	 * @param radius to initialize radius.
	 * @throws Exception
	 */
	Circle(double radius) throws Exception {
		if(radius < 0)
			throw new Exception();
		
		this.radius = radius;
		pos_x = radius;
		pos_y = radius;
	}
	
	/**
	 * Constructors that initialize data fields.
	 * @param r to initialize radius.
	 * @param x to initialize x coordinate.
	 * @param y to initialize y coordinate.
	 * @param sizeNum to initialize 0 is main Shape or 1 is small Shape.
	 * @throws Exception
	 */
	Circle(double r,double x,double y,int sizeNum) throws Exception {
		this(r);
		setPos_x(x);
		setPos_y(y);
		setSizeNumber(sizeNum);
	}
	
	Circle(Circle other) throws Exception{
		this(other.radius,other.pos_x,other.pos_y,other.sizeNumber);
	}
	
	@Override
	public double area() {
		return (Math.PI * Math.pow(radius, 2));
	}

	@Override
	public double perimeter() {
		return (2.0 * Math.PI * radius);
	}

	@Override
	public void increment() {
		pos_x += 1;
		pos_y += 1;
	}

	@Override
	public void decrement() throws Exception{
		
		if(getPos_x()-1 < 0 || getPos_y()-1 < 0)
			throw new Exception();
		
		setPos_x(getPos_x() - 1);
		setPos_y(getPos_y() - 1);
	}

	@Override
	public void draw(Graphics g) {
		paintComponent(g);
	}
	
	@Override
	public void paintComponent(Graphics g) {		
		super.paintComponent(g);
       
		if(sizeNumber == 0)
        	g.setColor(Color.RED); 
        else
        	g.setColor(Color.GREEN); 
        
        g.drawOval((int)this.getPos_x()-(int)this.getRadius(), (int)this.getPos_y()-(int)this.getRadius(), (int)this.getRadius()*2,(int)this.getRadius()*2);
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
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	/**
	 * 
	 * @return x coordinate.
	 */
	public double getPos_x() {
		return pos_x;
	}
	/**
	 * Set x to pos_x.
	 * @param x is x coordinate.
	 * @throws Exception if the x  is negative value.
	 */
	public void setPos_x(double x) throws Exception{
		if(x < 0)
			throw new Exception();
		
		this.pos_x = x;
	}
	/**
	 * 
	 * @return y coordinate.
	 */
	public double getPos_y() {
		return pos_y;
	}
	/**
	 * Set y to pos_y.
	 * @param y is y coordinate.
	 * @throws Exception if the y is negative value.
	 */
	public void setPos_y(double y) throws Exception {
		if(y < 0)
			throw new Exception();
		
		this.pos_y =y;
	}
	
	@Override
	public String toString(){
		return String.format("X : %.2f\tY: %.2f\n",this.getPos_x(),this.getPos_y());
	}

	public int getSizeNumber() {
		return sizeNumber;
	}

	public void setSizeNumber(int sizeNumber) {
		this.sizeNumber = sizeNumber;
	}

}
