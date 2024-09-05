import java.util.Scanner;
public class Multiples 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("What number do you wish to see multiples of?");
		int number=input.nextInt();
		System.out.println("How many multiples?");
		int multiples=input.nextInt();
		if (multiples<=0)
		{
			System.out.println("Error: The amount of multiples to display must be greater than zero");
		}
		else
		{
			System.out.println("Here are the first "+ multiples + " multiples of the number "+ number +":");
			for (int x=number;multiples>0; multiples=multiples-1)
			{
				System.out.println(x);
				x=x+number;
			}
				
		}
		
	}
}
