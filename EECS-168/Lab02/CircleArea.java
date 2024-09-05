/*--------------------------------------
 * 
 * File Name: CircleArea.java
 * Author: Hamza Hameed h002h741@ku.edu
 * Assignment: EECS-168 Lab 2
 * Description: this program will compute the area of a circle with a hard-coded radius.
 * Date: 9/10/14
 * 
 -------------------------------------*/

public class CircleArea 
{
		public static void main(String[] args)
		{
			//Declare the variables and constatns.
			final double PI=3.141592;
			double radius;
			double area;
			
			//Assign a radius and calculate the area of the circle.
			radius=20.0;
			area=(PI*(radius*radius));
			System.out.println("The area for the circle of radius "+radius+" is "+area);
			
		}
}
