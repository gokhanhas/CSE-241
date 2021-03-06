
import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.JMenuBar;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.JCheckBox;

public class Main_161044067 {

	private JFrame frame;
	private JTextField txtNumber;
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	private JTextField textField_5;
	private JTextField textField_6;
	private JTextField textField_7;
	private JTextField textField_8;

/**
 * Launch the application
 * @param args for main function
 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Main_161044067 window = new Main_161044067();
					window.frame.setTitle("Gokhan Has - 161044067");
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Main_161044067() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		
		int choose;
		
		frame = new JFrame();
		frame.setBounds(100, 100, 1030, 815);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		final JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		panel.setBounds(187, 11, 800, 743);
		frame.getContentPane().add(panel);
		
		JButton btnRectRect = new JButton("1-) Rect - Rect");
		btnRectRect.setBounds(10, 36, 167, 23);
		frame.getContentPane().add(btnRectRect);
		
		JButton btnNewButton = new JButton("2-) Rect - Circle");
		btnNewButton.setBounds(10, 70, 167, 23);
		frame.getContentPane().add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("3-) Rect - Triangle");
		btnNewButton_1.setBounds(10, 104, 167, 23);
		frame.getContentPane().add(btnNewButton_1);
			
		JButton btnNewButton_3 = new JButton("4-) Circle - Rect");
		btnNewButton_3.setBounds(10, 138, 167, 23);
		frame.getContentPane().add(btnNewButton_3);
		
		JButton btnNewButton_2 = new JButton("5-) Circle - Circle");
		btnNewButton_2.setBounds(10, 172, 167, 23);
		frame.getContentPane().add(btnNewButton_2);
		
		JButton btnNewButton_4 = new JButton("6-) Circle - Triangle");
		btnNewButton_4.setBounds(10, 206, 167, 23);
		frame.getContentPane().add(btnNewButton_4);
		
		JButton btnNewButton_5 = new JButton("7-) Triangle - Rect");
		btnNewButton_5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnNewButton_5.setBounds(10, 240, 167, 23);
		frame.getContentPane().add(btnNewButton_5);
		
		JButton btnNewButton_6 = new JButton("8-) Triangle - Circle");
		btnNewButton_6.setBounds(10, 274, 167, 23);
		frame.getContentPane().add(btnNewButton_6);
		
		JButton btnNewButton_7 = new JButton("9-) Triangle - Triangle");
		btnNewButton_7.setBounds(10, 308, 167, 23);
		frame.getContentPane().add(btnNewButton_7);
		
		JButton btnNewButton_8 = new JButton("Draw");
		btnNewButton_8.setBounds(9, 603, 168, 21);
		frame.getContentPane().add(btnNewButton_8);
		
		JLabel lblMainShape = new JLabel("Main Shape");
		lblMainShape.setHorizontalAlignment(SwingConstants.CENTER);
		lblMainShape.setBounds(10, 372, 167, 14);
		frame.getContentPane().add(lblMainShape);
		
		textField = new JTextField();
		textField.setBounds(105, 397, 30, 20);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		textField.setText("300");
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(145, 397, 30, 20);
		frame.getContentPane().add(textField_1);
		textField_1.setText("200");
		
		textField_2 = new JTextField();
		textField_2.setColumns(10);
		textField_2.setBounds(105, 422, 72, 20);
		frame.getContentPane().add(textField_2);
		textField_2.setText("200");
		
		textField_3 = new JTextField();
		textField_3.setColumns(10);
		textField_3.setBounds(105, 447, 72, 20);
		frame.getContentPane().add(textField_3);
		textField_3.setText("500");
		
		JLabel lblSmallShape = new JLabel("Small Shape");
		lblSmallShape.setHorizontalAlignment(SwingConstants.CENTER);
		lblSmallShape.setBounds(10, 475, 167, 14);
		frame.getContentPane().add(lblSmallShape);
		
		textField_4 = new JTextField();
		textField_4.setColumns(10);
		textField_4.setBounds(105, 500, 30, 20);
		frame.getContentPane().add(textField_4);
		textField_4.setText("80");
		
		textField_5 = new JTextField();
		textField_5.setColumns(10);
		textField_5.setBounds(147, 500, 30, 20);
		frame.getContentPane().add(textField_5);
		textField_5.setText("50");
		
		textField_6 = new JTextField();
		textField_6.setColumns(10);
		textField_6.setBounds(105, 525, 72, 20);
		frame.getContentPane().add(textField_6);
		textField_6.setText("40");
		
		textField_7 = new JTextField();
		textField_7.setColumns(10);
		textField_7.setBounds(105, 550, 72, 20);
		frame.getContentPane().add(textField_7);
		textField_7.setText("27");
		
		JLabel lblYourChoose = new JLabel("Your Choose : ");
		lblYourChoose.setBounds(10, 578, 89, 14);
		frame.getContentPane().add(lblYourChoose);
		
		textField_8 = new JTextField();
		textField_8.setBounds(105, 575, 72, 20);
		frame.getContentPane().add(textField_8);
		textField_8.setColumns(10);
		textField_8.setText("1");
		
		JLabel lblRectangle = new JLabel("Rectangle");
		lblRectangle.setBounds(10, 400, 64, 14);
		frame.getContentPane().add(lblRectangle);
		
		JLabel lblCircle = new JLabel("Circle");
		lblCircle.setBounds(10, 425, 46, 14);
		frame.getContentPane().add(lblCircle);
		
		JLabel lblTriangle = new JLabel("Triangle");
		lblTriangle.setBounds(10, 450, 46, 14);
		frame.getContentPane().add(lblTriangle);
		
		JLabel lblRectangle_1 = new JLabel("Rectangle");
		lblRectangle_1.setBounds(10, 503, 64, 14);
		frame.getContentPane().add(lblRectangle_1);
		
		JLabel lblCircle_1 = new JLabel("Circle");
		lblCircle_1.setBounds(10, 528, 46, 14);
		frame.getContentPane().add(lblCircle_1);
		
		JLabel lblTriangle_1 = new JLabel("Triangle");
		lblTriangle_1.setBounds(10, 553, 46, 14);
		frame.getContentPane().add(lblTriangle_1);
		
		JLabel lblDefaultOptions = new JLabel("Default Options");
		lblDefaultOptions.setHorizontalAlignment(SwingConstants.CENTER);
		lblDefaultOptions.setBounds(10, 11, 167, 14);
		frame.getContentPane().add(lblDefaultOptions);
		
		JLabel lblUsersChoose = new JLabel("User's Choose");
		lblUsersChoose.setHorizontalAlignment(SwingConstants.CENTER);
		lblUsersChoose.setBounds(10, 347, 167, 14);
		frame.getContentPane().add(lblUsersChoose);
		
		JButton btnDrawall = new JButton("drawAll");
		btnDrawall.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});
		btnDrawall.setBounds(10, 656, 167, 23);
		frame.getContentPane().add(btnDrawall);
		
		JButton btnNewButton_9 = new JButton("convertAll");
		btnNewButton_9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnNewButton_9.setBounds(10, 690, 167, 23);
		frame.getContentPane().add(btnNewButton_9);
		
		JButton btnNewButton_10 = new JButton("sortShapes");
		btnNewButton_10.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnNewButton_10.setBounds(10, 724, 167, 23);
		frame.getContentPane().add(btnNewButton_10);
		
		JLabel lblStaticsMethods = new JLabel("Statics Method's");
		lblStaticsMethods.setHorizontalAlignment(SwingConstants.CENTER);
		lblStaticsMethods.setBounds(10, 631, 167, 14);
		frame.getContentPane().add(lblStaticsMethods);
				
		btnRectRect.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				try {
				Rectangle rect = new Rectangle(300,200);
				Rectangle recttest = new Rectangle(80,40);
				ComposedShape testRR = new ComposedShape(rect,recttest);
				testRR.optimalFit();
				//Graphics g = panel.getGraphics();
				testRR.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
	
		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				try {
				Rectangle rect = new Rectangle(300,100);
				Circle circtest = new Circle(20);
				ComposedShape testRC = new ComposedShape(rect,circtest);
				testRC.optimalFit();
				//Graphics g = panel.getGraphics();
				testRC.draw(g);
				}catch(Exception e) {
					
				}
			}
		});

		btnNewButton_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				
				try {
				Rectangle rect = new Rectangle(300,100);
				Triangle tritest = new Triangle(27);
				ComposedShape testRT = new ComposedShape(rect,tritest);
				testRT.optimalFit();
				//Graphics g = panel.getGraphics();
				testRT.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_3.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				try {
				Circle circ = new Circle(200);
				Rectangle recttest = new Rectangle(80,40);
				ComposedShape testCR = new ComposedShape(circ,recttest);
				testCR.optimalFit();
				//Graphics g = panel.getGraphics();
				testCR.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				try {
				Circle circ = new Circle(200);
				Circle circtest = new Circle(20);
				ComposedShape testCC = new ComposedShape(circ,circtest);
				testCC.optimalFit();
				//Graphics g = panel.getGraphics();
				testCC.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_4.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				try {
				Circle circ = new Circle(200);
				Triangle tritest = new Triangle(27);
				ComposedShape testCT = new ComposedShape(circ,tritest);
				testCT.optimalFit();
				//Graphics g = panel.getGraphics();
				testCT.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_5.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				try {
				Triangle tri = new Triangle(800,400,0,0,0);
				Rectangle recttest = new Rectangle(80,40);
				ComposedShape testTR = new ComposedShape(tri,recttest);
				testTR.optimalFit();
				//Graphics g = panel.getGraphics();
				testTR.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_6.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				try {
				Triangle tri = new Triangle(800,400,0,0,0);
				Circle circtest = new Circle(20);
				ComposedShape testTC = new ComposedShape(tri,circtest);
				testTC.optimalFit();
				//Graphics g = panel.getGraphics();
				testTC.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_7.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				try {
				Triangle tri = new Triangle(800,400,0,0,0);
				Triangle tritest = new Triangle(27);
				ComposedShape testTT = new ComposedShape(tri,tritest);
				testTT.optimalFit();
				//Graphics g = panel.getGraphics();
				testTT.draw(g);
				}catch(Exception e) {
					
				}
			}
		});
		
		btnNewButton_8.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				String selection = textField_8.getText();
				int intSelection = Integer.parseInt(selection);
				
				String string_mainHeight = textField.getText();
				double mainHeight = Double.parseDouble(string_mainHeight);
				
				String string_mainWidth =  textField_1.getText();
				double mainWidth = Double.parseDouble(string_mainWidth);
				
				String string_mainRadius = textField_2.getText();
				double mainRadius = Double.parseDouble(string_mainRadius);
				
				String string_mainEdge = textField_3.getText();
				double mainEdge = Double.parseDouble(string_mainEdge);
				
				
				String string_smallHeight = textField_4.getText();
				double smallHeight = Double.parseDouble(string_smallHeight);
						
				String string_smallWidth = textField_5.getText();
				double smallWidth = Double.parseDouble(string_smallWidth);
						
				String string_smallRadius = textField_6.getText();
				double smallRadius = Double.parseDouble(string_smallRadius);
						
				String string_smallEdge = textField_7.getText();
				double smallEdge = Double.parseDouble(string_smallEdge);
				
				try {
					switch(intSelection) {
					case 1:
						System.out.println("Rect - Rect");
						Rectangle rect = new Rectangle(mainHeight,mainWidth);
						Rectangle recttest = new Rectangle(smallHeight,smallWidth);
						ComposedShape testRR = new ComposedShape(rect,recttest);
						testRR.optimalFit();
						testRR.draw(g);
						break;
					
					case 2:
						System.out.println("Rect - Circ");
						Rectangle rect2 = new Rectangle(mainHeight,mainWidth);
						Circle circtest = new Circle(smallRadius);
						ComposedShape testRC = new ComposedShape(rect2,circtest);
						testRC.optimalFit();
						testRC.draw(g);					
						break;
						
					case 3:
						System.out.println("Rect - Tri");
						Rectangle rect3 = new Rectangle(mainHeight,mainWidth);
						Triangle tritest = new Triangle(27);
						ComposedShape testRT = new ComposedShape(rect3,tritest);
						testRT.optimalFit();
						//Graphics g = panel.getGraphics();
						testRT.draw(g);
						break;
					
					case 4:
						System.out.println("Circ - Rect");
						Circle circ = new Circle(mainRadius);;
						Rectangle recttest2 = new Rectangle(smallHeight,smallWidth);
						ComposedShape testCR = new ComposedShape(circ,recttest2);
						testCR.optimalFit();
						testCR.draw(g);
						break;
					
					case 5:
						System.out.println("Circ - Circ");
						Circle circ2 = new Circle(mainRadius);
						Circle circtest2 = new Circle(smallRadius);
						ComposedShape testCC = new ComposedShape(circ2,circtest2);
						testCC.optimalFit();
						testCC.draw(g);
						break;
						
					case 6:
						System.out.println("Circ - Tri");
						Circle circ3 = new Circle(mainRadius);
						Triangle tritest2 = new Triangle(smallEdge);
						ComposedShape testCT = new ComposedShape(circ3,tritest2);
						testCT.optimalFit();
						testCT.draw(g);
						break;
						
					case 7:
						System.out.println("Tri - Rect");
						Triangle tri = new Triangle(mainEdge,mainEdge/2,0,0,0);
						Rectangle recttest3 = new Rectangle(80,40);
						ComposedShape testTR = new ComposedShape(tri,recttest3);
						testTR.optimalFit();
						testTR.draw(g);
						break;
						
					case 8:
						System.out.println("Tri - Circ");
						Triangle tri2 = new Triangle(mainEdge,mainEdge/2,0,0,0);
						Circle circtest3 = new Circle(smallRadius);
						ComposedShape testTC = new ComposedShape(tri2,circtest3);
						testTC.optimalFit();
						testTC.draw(g);
						break;
						
					case 9:
						System.out.println("Tri - Tri");
						Triangle tri3 = new Triangle(mainEdge,mainEdge/2,0,0,0);
						Triangle tritest3 = new Triangle(smallEdge);
						ComposedShape testTT = new ComposedShape(tri3,tritest3);
						testTT.optimalFit();
						testTT.draw(g);
						break;
						
					default:
					}
				}catch(Exception e) {
					System.out.println("You entered negative value !");	
				}
			}
		}); 
		
		btnDrawall.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				Shape [] arrayShapes = new Shape[6];
				
				try {
					
					
				Rectangle vectRect = new Rectangle(60,30,0,0,0);
				Circle dynCirc = new Circle(300);
				Triangle vectTri = new Triangle(300,300,150,0,1);
				
				Rectangle r1 = new Rectangle(500,300,0,0,1);
				Circle c1 = new Circle(50);
				Triangle t1 = new Triangle(210,400,200,0,0);
				PolygonVect pvect = new PolygonVect(vectRect);
				PolygonDyn parr = new PolygonDyn(dynCirc);
				PolygonVect ptri = new PolygonVect(vectTri);
				
				arrayShapes[0] = r1;
				arrayShapes[1] = c1;
				arrayShapes[2] = t1;
				arrayShapes[3] = pvect;
				arrayShapes[4] = parr;
				arrayShapes[5] = ptri;
				
				StaticMethods.drawAll(arrayShapes,g);
				
				}catch(Exception e) {
					System.out.println("You entered negative value !");	
				}

			}
		});
		
		btnNewButton_9.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				Shape [] arrayShapes = new Shape[3];
				try {
				Rectangle r1 = new Rectangle(500,300,0,0,1);
				Circle c1 = new Circle(50);
				Triangle t1 = new Triangle(210,400,200,0,0);
				System.out.println(r1.getClass().getName());
				arrayShapes[0] = r1;
				arrayShapes[1] = c1;
				arrayShapes[2] = t1;
				
				
				Polygon[] arrayPolygon = new Polygon[3];
				arrayPolygon = StaticMethods.convertAll(arrayShapes);
				
				for(int i=0;i<arrayPolygon.length;++i)
					arrayPolygon[i].draw(g);
				
				}catch(Exception e) {
					/* Body Initialize Empty */
				}
			}
		});
		
		btnNewButton_10.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g);
				
				Shape [] arrayShapes = new Shape[6];
				try {
				Rectangle r1 = new Rectangle(500,300,0,0,1);
				Circle c1 = new Circle(50);
				Triangle t1 = new Triangle(210,400,200,0,0);
				
				Rectangle vectRect = new Rectangle(60,30,0,0,0);
				Circle dynCirc = new Circle(300);
				Triangle vectTri = new Triangle(300,300,150,0,1);
				
				PolygonVect pvect = new PolygonVect(vectRect);
				PolygonDyn parr = new PolygonDyn(dynCirc);
				PolygonVect ptri = new PolygonVect(vectTri);
				
				arrayShapes[0] = r1;
				arrayShapes[1] = c1;
				arrayShapes[2] = t1;
				arrayShapes[3] = pvect;
				arrayShapes[4] = parr;
				arrayShapes[5] = ptri;
				
				}catch(Exception e) {
					//System.out.println("You entered negative value !");	
				}
				
				StaticMethods.sortShapes(arrayShapes);
				System.out.print("\n********* Calling sortShape *********\n");
				for(int k=0;k<arrayShapes.length;++k) {
					arrayShapes[k].draw(g);
					System.out.printf("%s's area is : %.2f\n",arrayShapes[k].getClass().getName(),arrayShapes[k].area());
				}
			}
		});
	}
	
}
