/*
 * Gokhan Has - 161044067
 */


import java.awt.Graphics;
/**
 * 
 * @author Gokhan Has
 *
 */


public class StaticMethods {

	/**
	 * Draws all shapes to an JPanel.
	 * @param arrayShapes keeps Shape referance array.
	 * @param g is a Graphics referance.
	 */
	public static void drawAll(Shape[] arrayShapes,Graphics g) {
		for(int i=0;i<arrayShapes.length;++i)
			arrayShapes[i].draw(g);
	}
	
	/**
	 * Convert all Shapes to Polygons
	 * @param arrayShapes keeps Shape referance array.
	 * @return Polygon array referance
	 * @throws Exception if the x or y is negative value.
	 */
	public static Polygon[] convertAll(Shape[] arrayShapes) throws Exception {
		
		int i;
		Polygon[] tempArr = new Polygon[arrayShapes.length];
		for(i=0;i<arrayShapes.length;++i){
			
			//System.out.println(arrayShapes[i].getClass().getName());
			if(arrayShapes[i].getClass().getName() == "Rectangle") {
				Rectangle tempRectangle = new Rectangle((Rectangle)(arrayShapes[i]));
				Polygon tempPolygon = new PolygonDyn(tempRectangle);
				tempArr[i] = tempPolygon;
			}
			else if(arrayShapes[i].getClass().getName() == "Circle") {
				Circle tempCircle = (Circle) (arrayShapes[i]);
				Polygon tempPolygon2 = new PolygonDyn(tempCircle);
				tempArr[i] = tempPolygon2;
			}
			else if(arrayShapes[i].getClass().getName() == "Triangle") {
				Triangle tempTriangle = (Triangle) (arrayShapes[i]);
				Polygon tempPolygon3 = new PolygonDyn(tempTriangle);
				tempArr[i] = tempPolygon3;
			}
			else{
				tempArr[i] = (Polygon) arrayShapes[i];
			}
		}		
		
		return tempArr;
	}
	
	/**
	 * Sorting shapes and increasingly sorts.
	 * @param arrayShapes keeps Shape referance array.
	 */
	public static void sortShapes(Shape[] arrayShapes) {
		
		int i,j;
		Shape temp;
		
		for(i=0;i<arrayShapes.length-1;++i){
			for(j=i+1;j<arrayShapes.length;++j){

				if(arrayShapes[i].area() > arrayShapes[j].area()){
					// Bubble Sort Algorithm
					temp = arrayShapes[i];
					arrayShapes[i] = arrayShapes[j];
					arrayShapes[j] = temp;
				}
			}
		}
	}
}
