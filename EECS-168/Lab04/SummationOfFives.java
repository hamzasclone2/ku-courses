import java.util.Scanner;
public class SummationOfFives 
{
	public static void main (String [] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.print("Please input a positive integer as the end value: ");
		int x=input.nextInt();
		int y=x/5;
		int n=x;
		if(x%5==0)
		{
			while(x>=5 && y>0)
			{
				y--;
				x=x-5;
				n=n+x;
			}
		}
		else
		{
			while(x%5!=0)
			{
				x--;
			}
			n=x;
		}
		while(y>0)
		{
			y--;
			x=x-5;
			n=n+x;
		}
		System.out.println("The summation is: " + n);
	}
}
