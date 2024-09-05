
public class ArrayHelper 
{
	public void print2DArray(int[][] array)
	{
		for(int i=0; i<array.length; i++)
		{
			for (int j=0; j<array[i].length; j++)
			{
				System.out.print(array[i][j] + "  ");
			}
			System.out.println();
		}
	}
	public int arraySum(int[] array)
	{
		int sum=0;
		for(int j=0; j<array.length; j++)
		{
			sum=array[j]+sum;
		}
		return(sum);
	}
	public double arrayAvg(int[] array)
	{
		double avg=0;
		double sum=0;
		for(int j=0; j<array.length; j++)
		{
			sum=array[j]+ sum;
		}
		avg=sum/array.length;
		return(avg);
	}
	public int arraySum2D(int[][] array)
	{
		int sum=0;
		for(int i=0; i<array.length; i++)
		{
			for(int j=0; j<array[i].length; j++)
			{
				sum=array[i][j]+sum;
			}
		}
		return(sum);
	}
	public double arrayAvg2D(int[][] array)
	{
		double sum=0;
		double avg=0;
		for(int i=0; i<array.length; i++)
		{
			for(int j=0; j<array[i].length; j++)
			{
				sum=array[i][j]+sum;
			}
		}
		avg=sum/(array.length*array[0].length);
		return(avg);
	}

}
