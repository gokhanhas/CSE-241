/*
 * Gokhan Has - 161044067
 */


import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * Rectangle class extends JPanel and implements Shape.
 * @author Gokhan Has
 *
 */
public class Rectangle extends JPanel implements Shape {

	private double width;
	private double height;
	private double pos_x;
	private double pos_y;
	private int sizeNumber;
	
	/**
	 * No parameter constructor.
	 */
	Rectangle() {
		width = 0.0;
		height = 0.0;
		pos_x = 0;
		pos_y = 0;
	}
	
	/**
	 *  Two parameters constructor.Pos_x and Pos_y assign to zero.
	 * @param w to initialize  width.
	 * @param h to initialize  height.
	 */
	Rectangle(double w,double h) {
		width = w;
		height = h;
		pos_x = 0;
		pos_y = 0;
	}
	
	/**
	 * Constructor that initialize data fields.
	 * @param w to initialize  width.
	 * @param h to initialize height.
	 * @param x to initialize  pos_x.
	 * @param y to initialize pos_y.
	 * @param num to initialize  0 is main Shape or 1 is small Shape.
	 * @throws Exception
	 */
	Rectangle(double w,double h,double x,double y,int num) throws Exception {
		this(w,h);
		if(x < 0 || y < 0)
			throw new Exception();
		setPos_x(x);
		setPos_y(y);
		setSizeNumber(num);
	}
	
	Rectangle(Rectangle other) throws Exception{
		this(other.width,other.height,other.pos_x,other.pos_y,other.sizeNumber);
	}
	
	@Override
	public double area() {
		return (width*height);
	}

	@Override
	public double perimeter() {
		return (2*(width+height));
	}

	@Override
	public void increment() {
		pos_x += 1;
		pos_y += 1;
	}

	@Override
	public void decrement() throws Exception {
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

        g.drawRect((int)pos_x, (int)pos_y, (int)width,(int) height);
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
	 * @throws Exception if the x or y is negative value.
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
	 * @throws Exception if the x or y is negative value.
	 */
	public void setPos_y(double y) throws Exception {
		if(y < 0)
			throw new Exception();
		
		this.pos_y = y;
	}
	
	public double get_Width() {
		return width;
	}
	
	public void setWidth(double w) {
		width = w;
	}
	
	public double get_Height() {
		return height;
	}
	
	public void setHeight(double h)  throws Exception {
		if(h < 0)
			throw new Exception();
		
		height = h;
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
