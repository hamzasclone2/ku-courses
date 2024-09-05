import java.util.Scanner;
public class NumberGuessingGame 
{
	public static void main (String [] args)
	{
		Scanner input=new Scanner(System.in);
		int userNum=0;
		int secret=73;
		System.out.println("Welcome to the number guessing game.");
		do
		{
			System.out.print("Guess a number: ");
			userNum=input.nextInt();
			if(userNum>73)
			{
				System.out.println("Sorry, your guess is too high.");
			}
			else if(userNum<73)
			{
				System.out.println("Sorry, your guess is too low.");
			}
		} while(userNum!=73);
		System.out.println("You win!");
	}
}
