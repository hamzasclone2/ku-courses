import java.util.Scanner;
public class Pyramid
{
	public static void main (String [] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.print("Enter the number of asterisks for the base of the triangle: ");
		int numOfRows=input.nextInt();
		for(int x=1; x<=numOfRows ; x++)
		{
			for(int y=1; y<=x; y++)
			{
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
