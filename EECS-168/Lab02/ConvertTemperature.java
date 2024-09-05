/* -----------------------------------------------------------------------------
 *
 * File Name:  ConvertTemperature.java
 * Author: Hamza Hameed h002h741@ku.edu
 * Assignment:   EECS-168 Lab2
 * Description:  This program will convert the input temperature from Fahrenheit to Celsius.
 * Date: 9/10/14
 *
 ---------------------------------------------------------------------------- */
//Start your program.
import java.util.Scanner;

public class ConvertTemperature 
{
	 public static void main(String[] args)
	 {
		 double fahrenheit;
		 double celsius;
		 
		 Scanner input = new Scanner(System.in);
		 System.out.println("Enter the temperature in Fahrenheit:");
		 fahrenheit= input.nextDouble();
		 
		 celsius=((fahrenheit-32.0)*(5.0/9.0));
				 
		 System.out.println("*Conversion");
		 System.out.println(fahrenheit + " degrees Fahrenheit = " + celsius + " degrees Celsius.");
	 }
	

}
