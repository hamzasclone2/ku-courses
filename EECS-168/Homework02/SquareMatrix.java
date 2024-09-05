/*
 * File Name: SquareMatrix.java
 * Author: Hamza Hameed
 * KUID: 2796053
 * Email Address: hh0718@yahoo.com
 * Homework Assignment Number: 2
 * Description: Creats a square matrix with the dimensions that the user gives
 * Last Changed: 10/1/14
 */

import java.util.Scanner;
public class SquareMatrix
{
	public static void main(String [] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the Size of the Square Matrix:");
		int size=input.nextInt();
		System.out.println("Square Matrix:");
		for(int x=1; x<size+1; x++)
		{
			for(int y=1; y<size+1; y++)
			{
				System.out.print(y+ " ");
			}
			System.out.print("\n");
		}
		System.out.println("Transpose:");
		for(int x=1; x<size+1; x++)
		{
			for(int y=1; y<size+1; y++)
			{
				System.out.print(y+ " ");
			}
			System.out.print("\n");
		}
	}
}
