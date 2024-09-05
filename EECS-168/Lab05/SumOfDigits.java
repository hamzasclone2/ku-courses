import java.util.Scanner;
public class SumOfDigits 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int x=0;
		do
		{
			System.out.println("Please enter a No:");
			int num=input.nextInt();
			addDigits(num);
			System.out.println();
			System.out.println("Want to try again?(y=1/n=0) :");
			x=input.nextInt();
		}while(x==1);
	}
	public static int addDigits(int x)
	{
		while(x>10)
		{
			int a=x%10;
			int b=x/10;
			int c=b%10;
			int d=b/10;
			int e=d%10;
			int f=d/10;
			int g=f%10;
			int h=f/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			x=k;
			System.out.println("The sum of the digits is: " + (a+c+e+g+i+k));
		}
		return(x);
	}
}
