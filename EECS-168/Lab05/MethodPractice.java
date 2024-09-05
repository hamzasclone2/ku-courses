import java.util.Scanner;
public class MethodPractice 
{
	public static void main (String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Input two numbers:");
		int a=input.nextInt();
		int b=input.nextInt();
		chooseGreater(a,b);
		System.out.println();
		System.out.print("Input a radius: ");
		double radius=input.nextDouble();circumference(radius);
		System.out.println();
		System.out.println("Input a string:");
		String word=input.next();
		System.out.print("How many times do you want to print it?: ");
		int timesToPrint=input.nextInt();
		printWord(word, timesToPrint);
	}
	public static int chooseGreater(int a, int b)
	{
		if(a>b)
		{
			System.out.println("The larger number is " + a);
			return(a);
		}
		else
		{
			System.out.println("The larger number is " + b);
			return(b);
		}
		
	}
	public static double circumference(double radius)
	{
		double answer=radius*2*3.14159;
		System.out.println("The circumference is: " + answer);
		return(answer);
	}
	public static void printWord(String word, int timesToPrint)
	{
		for(int x=0; x<timesToPrint; x++)
		{
			System.out.println(word);
		}
	}
}
