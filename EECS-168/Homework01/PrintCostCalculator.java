/*
 * File Name: PrintCostCalculator.java
 * Author: Hamza Hameed
 * KUID: 2796053
 * Email Address: h002h741@ku.edu
 * Homework Assignment Number: 1
 * Description: This program takes various inputs from a user to
 * calculate the cost of a print job
 * Last Changed: 9/22/14
*/
import java.util.Scanner;
public class PrintCostCalculator 
{
	public static void main (String [] args)
	{
		Scanner input=new Scanner(System.in);
		int pages=0;
		int printColor=0;
		int dotsPerPage=0;
		double inkPrice=0;
		double costPerPage=0;
		double totalCost=0;
		double inkUsage=0;
		double sale=0;
		double salePrice=0;
		String tempString="blank";
		System.out.println("--- Price Estimator Program ---");
		System.out.print("Enter number of Pages (digits only): ");
		pages=input.nextInt();
		//blank line
		System.out.println();
		System.out.println("---- Select a Print Type ----");
		System.out.println("Enter T or t for Text");
		System.out.println("Enter I or i for Image");
		System.out.println("Enter C or c for Compressed Text");
		System.out.println("Enter S or s for statement");
		System.out.println("---------------------------");
		System.out.print("Enter Print Type: ");
		tempString=input.next();
		char printType=tempString.charAt(0);
		System.out.println();
		if (printType=='T' || printType== 't')
		{
			dotsPerPage=4300;
		}
		else if (printType=='I' || printType== 'i')
		{
			dotsPerPage=15000;
		}
		else if (printType=='C' || printType=='c')
		{
			dotsPerPage=25000;
		}
		else if (printType=='S' || printType=='s')
		{
			dotsPerPage=27000;
		}
		System.out.println("--- Select a Print Color ---");
		System.out.println("Enter 0 for Grayscale");
		System.out.println("Enter 1 for Color");
		System.out.println("-----------------------------");
		System.out.print("Enter Print Color : ");
		printColor=input.nextInt();
		System.out.print("Is there a sale (y/n): ");
		tempString=input.next();
		char saleAnswer=tempString.charAt(0);
		//lots of other ways to do the following
		if (saleAnswer=='y' && pages>100)
		{
			sale=.5;
		}
		if (printColor==0)
		{
			inkPrice=0.03;
		}
		else if (printColor==1)
		{
			inkPrice=0.11;
		}
		System.out.println("-----------------------------");
		System.out.println();
		System.out.println("--- Cost Estimate ---");
		System.out.println("Ink Usage Per Page: " + dotsPerPage);
		inkUsage=(dotsPerPage*pages);
		/*
		 * g is for exponential notation
		 * \n for new line
		 */
		System.out.printf("Total Ink Usage: " + "%.3g\n" , inkUsage);
		System.out.println();
		costPerPage=((dotsPerPage*inkPrice)/1000);
		System.out.printf("Estimated Cost Per Page: $" + "%.4f\n", costPerPage);
		totalCost=(costPerPage*pages);
		System.out.printf("Total Cost: $" + "%.2f\n", totalCost);
		if (sale==.5)
		{
			System.out.println();
			salePrice=(sale*totalCost);
			System.out.printf("SALE Price: " + "%.2f\n", salePrice);
		}
	}
}
