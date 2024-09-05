import java.util.Scanner;
import java.util.Arrays;
public class Lab07 
{
	public static void main(String[] args)
	{
		Scanner input= new Scanner(System.in);
		int arraySize=0;
		do
		{
			System.out.print("Input an array size: ");
			arraySize=input.nextInt();
		}while(arraySize<=0);
		System.out.println("");
		System.out.println("Now please enter " + arraySize + " numbers");
		double[] oldArray=new double[arraySize];
		for(int i=0; i<arraySize; i++)
		{
			System.out.print("Input a number into your array: ");
			oldArray[i]=input.nextDouble();
		}
		System.out.println("Here are all the numbers in your array: ");
		printArray(oldArray);
		System.out.println("");
	    int newArraySize=0;
		do
		{
			System.out.print("Input a new size: ");
			newArraySize=input.nextInt();
		}while(newArraySize<=arraySize);
		int x=newArraySize-arraySize;
		System.out.println("You need to add " + x + " values");
		double[] newArray=arrayResize(oldArray, newArraySize);
		for(int i=oldArray.length; i<newArraySize; i++)
		{
			System.out.print("Input a number to add to your array: ");
			newArray[i]=input.nextDouble();
		}
		System.out.println("Here are all the numbers in your new array: ");
		printArray(newArray);
	}
	public static void printArray(double[] arr)
	{
		System.out.println(Arrays.toString(arr));
	}
	public static double[] arrayResize(double[] oldArray, int newArraySize)
	{
		double[] newArray=new double[newArraySize];
		for(int i=0; i<oldArray.length; i++)
		{
			newArray[i]=oldArray[i];
		}
		return(newArray);
	}
}
