/*
 * Gokhan Has - 161044067
 */


import java.awt.Graphics;


/**
 * An interface that Shape.
 * @author Gokhan Has
 *
 */
public interface Shape extends Comparable<Shape> {
	/**
	 * Calculate the shape area.
	 * @return the shape area.
	 */
	double area();
	
	/**
	 * Calculate the shape perimeter.
	 * @return the shape perimeter.
	 */
	double perimeter();
	
/**
 * Increment 1 to shape coordinates.
 * @throws Exception if the x or y is negative value.
 */
	void increment() throws Exception;
	
	/**
	 * Decrement 1 to shape coordinates.
	 * @throws Exception if the user entered negative number.
	 */
	void decrement() throws Exception;
	
	/**
	 * Draw 
	 * @param g is a Graphics referance.
	 */
	void draw(Graphics g);
	
	/**
	 * Compare to Shape object with their areas.
	 * @return 0,1,-1 is equal areas.
	 */
	int compareTo(Shape other);
}
