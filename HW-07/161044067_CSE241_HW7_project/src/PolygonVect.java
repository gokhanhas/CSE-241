/*
 * Gokhan Has - 161044067
 */


import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

/**
 * This is the class PolygonVect extends hw07.Polygon class.
 * Keeps the ArrayList for coordinates(Point2D).
 * @author Gokhan Has
 *
 */
public class PolygonVect extends Polygon {

	private ArrayList<Point2D> arrayList = new ArrayList<Point2D> ();
	
	public PolygonVect() {
		arrayList = null;
	}
	/**
	 * Convert Rectangle to PolygonVect.
	 * @param rectangle which converted PolygonVect.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonVect(Rectangle rectangle) throws Exception {
		
		areaPolygon = rectangle.area();
		perimeterPolygon = rectangle.perimeter();
		
		Point2D temp = new Point2D();
		
		temp.setPos_x(rectangle.getPos_x());
		temp.setPos_y(rectangle.getPos_y());
		arrayList.add(temp);
		
		temp = new Point2D();
		temp.setPos_x(rectangle.getPos_x() + rectangle.get_Width());
		temp.setPos_y(rectangle.getPos_y());
		arrayList.add(temp);
	
		temp = new Point2D();
		temp.setPos_x(rectangle.getPos_x() + rectangle.get_Width());
		temp.setPos_y(rectangle.getPos_x() + rectangle.get_Height());
		arrayList.add(temp);

		temp = new Point2D();
		temp.setPos_x(rectangle.getPos_x());
		temp.setPos_y(rectangle.getPos_y() + rectangle.get_Height());
		arrayList.add(temp);
		
	}
	
	/**
	 * Convert Circle to PolygonVect.
	 * @param circle which converted PolygonVect.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonVect(Circle circle) throws Exception {
		
		areaPolygon = circle.area();
		perimeterPolygon = circle.perimeter();
		
		int size = 100;
		
		double point_X = circle.getPos_x();
		double point_Y = circle.getPos_y() - circle.getRadius();
		
		Point2D temp = new Point2D();
		temp.setPos_x(point_X);
		temp.setPos_y(point_Y);
		arrayList.add(temp);

   		for(int i=1; i<size; ++i){
   			
   			temp = new Point2D();
	    	temp.setPos_x( circle.getPos_x() + (circle.getRadius()*Math.sin((i) * Math.PI/50.0)));
	    	temp.setPos_y( circle.getPos_y() + ((-1)*circle.getRadius()*Math.cos((i) * Math.PI/50.0)));
	    	arrayList.add(temp);
	    }
	}
	/**
	 * Convert Triangle to PolygonVect.
	 * @param triangle which converted PolygonVect.
	 * @throws Exception if the x or y is negative value.
	 */
	public PolygonVect(Triangle triangle) throws Exception {
		
		areaPolygon = triangle.area();
		perimeterPolygon = triangle.perimeter();
		
		Point2D temp = new Point2D();
		
		if(triangle.getRotateControl() == 0){ // Normal triangle's coordinate 
			
			temp.setPos_x(triangle.getPos_x());
			temp.setPos_y(triangle.getPos_y());
			arrayList.add(temp);

			temp = new Point2D();
			temp.setPos_x(triangle.getPos_x() - triangle.getEdge()/2);
			temp.setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
			arrayList.add(temp);
			
			temp = new Point2D();
			temp.setPos_x(triangle.getPos_x() + triangle.getEdge()/2);
			temp.setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
			arrayList.add(temp);
		}

		else{ // Inverse triangle's coordinate

			temp.setPos_x(triangle.getPos_x());
			temp.setPos_y(triangle.getPos_y());
			arrayList.add(temp);

			temp = new Point2D();
			temp.setPos_x(triangle.getPos_x() + triangle.getEdge());
			temp.setPos_y(triangle.getPos_y());
			arrayList.add(temp);

			temp = new Point2D();
			temp.setPos_x(triangle.getPos_x() + triangle.getEdge()/2);
			temp.setPos_y(triangle.getPos_y() + triangle.getEdge()/2*Math.sqrt(3));
			arrayList.add(temp);			
		}	
	}

	public ArrayList<Point2D> getArrayList() {
		return arrayList;
	}

	public void setArrayList(ArrayList<Point2D> arrayList) {
		this.arrayList = arrayList;
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
		for(int i=0;i<arrayList.size();++i) {
			arrayList.get(i).setPos_x(arrayList.get(i).getPos_x()+1);
			arrayList.get(i).setPos_y(arrayList.get(i).getPos_y()+1);
		}
	}

	@Override
	public void decrement() throws Exception {
		for(int i=0;i<arrayList.size();++i) {
			arrayList.get(i).setPos_x(arrayList.get(i).getPos_x()-1);
			arrayList.get(i).setPos_y(arrayList.get(i).getPos_y()-1);
		}
	}

	@Override
	public void draw(Graphics g) {
		paintComponent(g);
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		int [] xPoints = new int[arrayList.size()];
		int [] yPoints = new int[arrayList.size()];
		
		for(int i=0;i<arrayList.size();++i) {
			xPoints[i] = (int) arrayList.get(i).getPos_x();
			yPoints[i] = (int) arrayList.get(i).getPos_y();
		}
		g.setColor(Color.BLUE);
		g.drawPolygon(xPoints, yPoints,arrayList.size());
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
