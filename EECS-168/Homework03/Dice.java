import java.util.Random;
public class Dice 
{
	private int numSides;
	public Dice(int sides)
	{
		numSides=sides;
	}
	public int roll()
	{
		Random myRand=new Random();
		int randomNum=myRand.nextInt(numSides)+1;
		return(randomNum);
	}
}
