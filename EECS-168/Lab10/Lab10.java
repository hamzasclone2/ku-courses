import java.util.Random;
import java.util.Scanner; 
public class Lab10 
{
	public static void main(String[]args)
	{
		Scanner input=new Scanner(System.in);
		int userNum=0;
		int userChoice=0;
		long start=0;
		long stop=0;
		long elapsed=0;
		Random rand=new Random();
		BubbleSort bubbleSort=new BubbleSort();
		System.out.println("How many random numbers do you want to generate?");
		userNum=input.nextInt();
		int[]array=new int[userNum];
		System.out.print("Would you like to sort the array in ascending or descending order? (0 for ascending, 1 for descending): ");
		userChoice=input.nextInt();
		System.out.println();
		System.out.println("Unsorted Array:");
		for(int i=0; i<array.length; i++)
		{
			array[i]=rand.nextInt(256);
			System.out.print(array[i] + " ");
		}
		System.out.println();
		System.out.println();
		start=System.nanoTime();
		System.out.println("Starting sort at " + start);
		
		
		if(userChoice==0)
		{
			bubbleSort.ascending(array);
			stop=System.nanoTime();
			elapsed=stop-start;
			System.out.println("Stopping sort at " + stop);
			System.out.println();
			System.out.println("Sorted Array: ");
			for(int i=0; i<array.length; i++)
			{
				System.out.print(array[i] + " ");
			}
		}
		else
		{
			bubbleSort.descending(array);
			stop=System.nanoTime();
			elapsed=stop-start;
			System.out.println("Stopping sort at " + stop);
			System.out.println();
			System.out.println("Sorted Array: ");
			for(int i=0; i<array.length; i++)
			{
				System.out.print(array[i] + " ");
			}
		}
		System.out.println();
		System.out.println();
		System.out.println("This sort took a total of " + elapsed + " nano seconds, or " + elapsed/1000000000.0 + " seconds");
	}
}
