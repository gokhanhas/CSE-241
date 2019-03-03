/*
 * Gokhan Has - 161044067
 */


import java.awt.Graphics;
import javax.swing.JPanel;


/**
 * Polygon is a abstract class extends JPanel and implements Shape.
 * @author Gokhan Has
 *
 */
public abstract class Polygon extends JPanel implements Shape {

	protected double areaPolygon;
	protected double perimeterPolygon;
	
	/**
	 * This is class Point2D.Keeps the coordinates.
	 * @author G�khan Has
	 *
	 */
	protected class Point2D {
		/**
		 * Keeps the x coordinate.
		 */
		private double pos_x;
		/**
		 * Keeps the y coordinate.
		 */
		private double pos_y;
		
		/**
		 * No parameter constructor for Point2D.
		 */
		public Point2D() throws Exception{
			this(0.0,0.0);
		}
		
		public Point2D(double x,double y)throws Exception {
			if(x <0 || y <0)
				throw new Exception();
		
			this.pos_x = x;
			this.pos_y = y;
		}
		/**
		 * 
		 * @return x point
		 */
		public double getPos_x() {
			return pos_x;
		}
		/**
		 * 
		 * @param x to x point.
		 * @throws Exception
		 */
		public void setPos_x(double x) throws Exception {
			if(x < 0)
				throw new Exception();

			this.pos_x = x;
		}
		/**
		 * 
		 * @return y point
		 */
		public double getPos_y() {
			return pos_y;
		}
		/**
		 * 
		 * @param y to y point
		 * @throws Exception
		 */
		public void setPos_y(double y) throws Exception{
			if(y < 0)
				throw new Exception();
			
			this.pos_y = y;
		}
	}
	
	public Polygon(){
		/* Body Initialize Empty */
	}
	
	@Override
	public double area() {
		return areaPolygon;
	}

	@Override
	public double perimeter() {
		return perimeterPolygon;
	}
}
