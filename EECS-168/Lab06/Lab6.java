import java.util.Scanner;
public class Lab6 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int arraySize=0;
		do
		{
			System.out.print("Input an array size: ");
			arraySize=input.nextInt();
		}while(arraySize<1);
		int[] userNums=new int[arraySize];
		for(int i=0; i<arraySize; i++)
		{
			System.out.print("Input a number into your array: ");
			userNums[i]=input.nextInt();
		}
		System.out.println("Here are all the numbers in your array: ");
		for(int i=0; i<arraySize; i++)
		{
			System.out.println(userNums[i]);
		}
		int sum=0;
		int x=0;
		for(int i=0; i<arraySize; i++)
		{
			x=userNums[i];
			sum=sum+x;
		}
		System.out.println("The sum of all the values is: " + sum);
		int avg=0;
		avg=sum/arraySize;
		System.out.println("The average of all the values is: " + avg);
		int max=0;
		int min=0;
		min=userNums[0];
		for(int i=0; i<arraySize; i++)
		{
			if(userNums[i]>max)
			{
				max=userNums[i];
			}
			if(userNums[i]<min)
			{
				min=userNums[i];
			}
		}
		System.out.println("The largest value is: " + max);
		System.out.println("The smallest value is: " + min);
	}
}
