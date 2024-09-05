/*
 * File Name: AsciiArt.java
 * Author: Hamza Hameed
 * KUID: 2796053
 * Email Address: hh0718@yahoo.com
 * Homework Assignment Number: 2
 * Description: This program will make a certain shape based on the size that the user gives as an input
 * Last Changed: 10/1/14
 */
import java.util.Scanner;
public class AsciiArt
{
	public static void main (String [] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Choose one of the following patterns by typing the corresponding number:");
		System.out.println("1) Stripes");
		System.out.println("2) Checker Board");
		System.out.println("3) Double Diagonal (aka the X)");
		int answer=input.nextInt();
		if(answer!=1 && answer!=2 && answer!=3)
		{
			System.out.println();
			System.out.println("Error.");
		}
		else
		{
			System.out.println();
			System.out.println("Input a size (must be larger than 1):");
			int secondAnswer=input.nextInt();
			System.out.println();
			if(secondAnswer<2)
			{
				System.out.println("Error.");
			}
			else if(answer==1)
			{
				for(int x=0; x<secondAnswer; x++)
				{
					System.out.println(x + " *   *   *");
				}
			}
			else if(answer==2)
			{
				for(int x=0; x<secondAnswer; x++)
				{
					if(x%2==0)
					{
						System.out.println(x + " *   *   *");
					}
					else
					{
						System.out.println(x + "   *   *");
					}	
				}	
			}
			else
			{
				for(int x=0; x<secondAnswer; x++)
				{
					System.out.print(x);
					for(int y=0; y<secondAnswer; y++)
					{
						if(y%2==0)
						{
							System.out.print(" * ");
						}
						else
						{
							System.out.print("   ");
						}
					}
					System.out.print("\n");
				}
			}
		}
	}
}
