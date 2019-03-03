/*
 * Gokhan Has - 161044067
 */


import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

/**
 * Triangle class extends JPanel and implements Shape.
 * @author Gokhan Has
 *
 */
public class Triangle extends JPanel implements Shape {
	
	private double edge;
	private double pos_x;
	private double pos_y;
	private int rotateControl;
	private int sizeNumber;
	
	/**
	 * No parameter constructor.
	 */
	Triangle() {
		edge = 0.0;
		pos_x = 0;
		pos_y = 0;
	}
	
	/**
	 * One parameter constructor.Pos_x and Pos_y assign to zero.
	 * @param e to initialize edge.
	 */
	Triangle(double e) {
		edge = e;
		pos_x = 0;
		pos_y = 0;
	}
	/**
	 * Constructor that initialize data fields.
	 * @param e to initialize edge.
	 * @param x to initialize x coordinate.
	 * @param y to initialize y coordinate.
	 * @param rc to initialize rotate control number 1 is reverse Triangle and 0 is street Triangle.
	 * @param sizeNum toinitialize 0 main Shape or 1 small Shape.
	 * @throws Exception
	 */
	Triangle(double e,double x,double y,int rc,int sizeNum) throws Exception {
		this(e);
		
		if(x < 0 || y < 0)
			throw new Exception();
		
		setPos_x(x);
		setPos_y(y);
		setRotateControl(rc);
		setSizeNumber(sizeNum);
	}
	
	Triangle(Triangle other) throws Exception{
		this(other.edge,other.pos_x,other.pos_y,other.rotateControl,other.sizeNumber);
	}
	
	@Override
	public double area() {
		return (Math.pow(edge,2) * Math.sqrt(3) / 4.0 );
	}

	@Override
	public double perimeter() {
		return (3.0 * edge);
	}

	@Override
	public void increment() {
		pos_x = pos_x +1;
		pos_y = pos_y + 1;
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
		
		
		int [] xPoints = new int[3];
		int [] yPoints = new int[3];
		if(sizeNumber == 0)
			g.setColor(Color.RED); 
		else
			g.setColor(Color.GREEN);  
		
		if(this.getRotateControl() == 0) {
			xPoints[0] = (int) this.pos_x;  yPoints[0] = (int)this.pos_y;
			xPoints[1] = (int)(this.getPos_x() - this.getEdge()/2);  yPoints[1] = (int)(this.getPos_y() + this.getEdge()/2*Math.sqrt(3));  
			xPoints[2] = (int)(this.getPos_x() + this.getEdge()/2);  yPoints[2] =(int)(this.getPos_y() + this.getEdge()/2*Math.sqrt(3));
		}
		else {
			xPoints[0] = (int) this.pos_x;  yPoints[0] = (int)this.pos_y;
			xPoints[1] = (int)(this.getPos_x() + this.getEdge());  yPoints[1] = (int)(this.getPos_y());  
			xPoints[2] = (int)(this.getPos_x() + this.getEdge()/2);  yPoints[2] =(int)(this.getPos_y() + this.getEdge()/2*Math.sqrt(3));
		}
		
		g.drawPolygon(xPoints, yPoints, 3);
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
	
	public double getEdge() {
		return edge;
	}

	public void setEdge(double e) throws Exception {
		if(e < 0)
			throw new Exception();

		this.edge = e;
	}
	/**
	 * 
	 * @return x coordinate.
	 */
	public double getPos_x() {
		return pos_x;
	}
	/**
	 * 
	 * @param x is x coordinate.
	 * @throws Exception if the x or y is negative value.
	 */
	public void setPos_x(double x) throws Exception {
		if(x<0)
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
	 * @throws Exception if the x or y is negative value.
	 */
	public void setPos_y(double y) throws Exception {
		if(y < 0)
			throw new Exception();
		
		this.pos_y = y;
	}
	
	@Override
	public String toString(){
		return String.format("X : %.2f\tY: %.2f\n",this.getPos_x(),this.getPos_y());
	}
	
	public void setRotateControl(int a) {
		rotateControl = a;
	}
	
	public int getRotateControl() {
		return rotateControl;
	}

	public int getSizeNumber() {
		return sizeNumber;
	}

	public void setSizeNumber(int sizeNumber) {
		this.sizeNumber = sizeNumber;
	}
}
