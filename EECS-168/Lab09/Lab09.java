import java.util.Scanner;
public class Lab09 
{
	public static void main(String[]args)
	{
		Scanner input=new Scanner(System.in);
		System.out.print("How many rows?: ");
		int rows=input.nextInt();
		System.out.print("How many columns?: ");
		int columns=input.nextInt();
		int[][] array2d=new int[rows][columns];
		for (int i=0; i<rows; i++)
		{
			for(int j=0; j<columns; j++)
			{
				System.out.print("Enter a value for position (" + i + "," + j + "): ");
				array2d[i][j]=input.nextInt();
			}
		}
		System.out.println("Here is your array");
		ArrayHelper arrayHelper=new ArrayHelper();
		arrayHelper.print2DArray(array2d);
		int[] array1d=new int[columns];
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<columns; j++)
			{
				array1d[j]=array2d[i][j];
			}
			int[]sum=new int[rows];
			sum[i]=arrayHelper.arraySum(array1d);
			double[]avg=new double[rows];
			avg[i]=arrayHelper.arrayAvg(array1d);
			System.out.print("Row " + i + " sum= " + sum[i] + " avg = " + avg[i]);
			System.out.println();
		}
		System.out.println("The sum for the entire array is = " + arrayHelper.arraySum2D(array2d));
		System.out.println("The average for the entire array is = " + arrayHelper.arrayAvg2D(array2d));
	}
}
