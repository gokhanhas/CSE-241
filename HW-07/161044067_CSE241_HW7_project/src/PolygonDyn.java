/*
 * Gokhan Has - 161044067
 */


import java.awt.Color;
import java.awt.Graphics;

/**
 * This is the class PolygonDyn extends hw07.Polygon class.
 * Keeps the Java Array for coordinates(Point2D).
 * @author Gokhan Has
 *
 */
public class PolygonDyn extends Polygon {
	
	private Point2D[] arrayDyn;
	
	
	public PolygonDyn() {
		setArrayDyn(null);
	}
	/**
	 * Convert Rectangle to PolygonDyn.
	 * @param rectangle which converted PolygonDyn.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonDyn(Rectangle rectangle) throws Exception {
		
		areaPolygon = rectangle.area();
		perimeterPolygon = rectangle.perimeter();
		
		arrayDyn = new Point2D[4];
		for(int i=0;i<4;i++){
			arrayDyn[i] = new Point2D();
		}
		
		arrayDyn[0].setPos_x(rectangle.getPos_x());
		arrayDyn[0].setPos_y(rectangle.getPos_y());
		
		arrayDyn[1].setPos_x(rectangle.getPos_x() + rectangle.get_Width());    
		arrayDyn[1].setPos_y(rectangle.getPos_y());
		
		arrayDyn[2].setPos_x(rectangle.getPos_x() + rectangle.get_Width());   
		arrayDyn[2].setPos_y(rectangle.getPos_y() + rectangle.get_Height());
		
		arrayDyn[3].setPos_x(rectangle.getPos_x());    
		arrayDyn[3].setPos_y(rectangle.getPos_y() + rectangle.get_Height());
	}
	/**
	 * Convert Circle to PolygonDyn.
	 * @param circle which converted PolygonDyn.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonDyn(Circle circle) throws Exception {
		
		areaPolygon = circle.area();
		perimeterPolygon = circle.perimeter();
		
		arrayDyn = new Point2D[100];
		for(int i=0;i<100;i++){
			arrayDyn[i] = new Point2D();
		}
		
		double point_X = circle.getPos_x();
		double point_Y = circle.getPos_y() - circle.getRadius();
		
		arrayDyn[0].setPos_x(point_X);
		arrayDyn[0].setPos_y(point_Y);

   		for(int i=1; i<100; ++i){

	    	arrayDyn[i].setPos_x( circle.getPos_x() + (circle.getRadius()*Math.sin((i) * Math.PI/50.0)));
	    	arrayDyn[i].setPos_y( circle.getPos_y() + ((-1)*circle.getRadius()*Math.cos((i) * Math.PI/50.0)));
	    }
	}
	/**
	 * Convert Triangle to PolygonDyn.
	 * @param triangle which converted PolygonDyn.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonDyn(Triangle triangle) throws Exception {
		areaPolygon = triangle.area();
		perimeterPolygon = triangle.perimeter();
		
		arrayDyn = new Point2D[3];
		for(int i=0;i<3;i++){
			arrayDyn[i] = new Point2D();
		}
		
		if(triangle.getRotateControl() == 0){ // Normal triangle's coordinate 

			arrayDyn[0].setPos_x(triangle.getPos_x());
			arrayDyn[0].setPos_y(triangle.getPos_y());
			
			arrayDyn[1].setPos_x(triangle.getPos_x() - triangle.getEdge()/2);    
			arrayDyn[1].setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
			
			arrayDyn[2].setPos_x(triangle.getPos_x() + triangle.getEdge()/2);    
			arrayDyn[2].setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
		}

		else{ // Inverse triangle's coordinate

			arrayDyn[0].setPos_x(triangle.getPos_x());
			arrayDyn[0].setPos_y(triangle.getPos_y());
			
			arrayDyn[1].setPos_x(triangle.getPos_x() + triangle.getEdge());    
			arrayDyn[1].setPos_y(triangle.getPos_y());
			
			arrayDyn[2].setPos_x(triangle.getPos_x() + triangle.getEdge()/2);    
			arrayDyn[2].setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
		}
	}
	
	public Point2D[] getArrayDyn() {
		return arrayDyn;
	}


	public void setArrayDyn(Point2D[] arrayDyn) {
		this.arrayDyn = arrayDyn;
	}
	
	@Override
	public double area() {
		return areaPolygon;
	}

	@Override
	public double perimeter() {
		return perimeterPolygon;
	}

	@Override
	public void increment() throws Exception {
		for(int i=0;i<arrayDyn.length;++i ) {
			arrayDyn[i].setPos_x(arrayDyn[i].getPos_x()+1);
			arrayDyn[i].setPos_y(arrayDyn[i].getPos_y()+1);
		}
	}

	@Override
	public void decrement() throws Exception {
		for(int i=0;i<arrayDyn.length;++i ) {
			arrayDyn[i].setPos_x(arrayDyn[i].getPos_x()-1);
			arrayDyn[i].setPos_y(arrayDyn[i].getPos_y()-1);
		}
	}

	@Override
	public void draw(Graphics g) {
		paintComponent(g);
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		int [] xPoints = new int[arrayDyn.length];
		int [] yPoints = new int[arrayDyn.length];
		
		for(int i=0;i<arrayDyn.length;++i) {
			xPoints[i] = (int) arrayDyn[i].getPos_x();
			yPoints[i] = (int) arrayDyn[i].getPos_y();
		}
		g.setColor(Color.magenta);
		g.drawPolygon(xPoints, yPoints,arrayDyn.length);
	}

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 0;
		else if(this.area() > other.area())
			return 1;
		else
			return -1;
	}
}
