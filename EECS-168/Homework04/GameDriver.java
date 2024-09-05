/*
File Name: GameDriver.java
Author: Hamza Hameed 
KUID: 2796053
Email Address: h002h741@ku.edu 
Homework Assignment Number: 4 
Description: Front end and user input of game 
Last Changed: 12/6/14 
*/	
import java.util.Scanner; 
public class GameDriver 
{
	public static void main(String[]args)
	{
		Scanner input=new Scanner(System.in);
		String s;
		char c;
		Hangman hangman=new Hangman();
		System.out.println("Welcome to the Hangman Game!");
		System.out.println("----------------------------");
		while(hangman.isGameOver()==false)
		{
			System.out.println();
			System.out.println("Guess This: " + hangman.getDisguisedWord()); 
			System.out.println("Guesses so far: " + hangman.getGuessCount());
			System.out.println("Misses: " + hangman.getMissedMarker());
			System.out.print("Enter your guess character: ");
			s=input.next();
			c=s.toLowerCase().charAt(0);
			if(hangman.guessCharacter(c)==true)
			{
				System.out.println(c + " is in the secret word! Good job!");
			}
			else
			{
				System.out.println(c + " is not in the secret word. Be careful!");
				if(hangman.getMissesCount()==1)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println("           |");
					System.out.println("           |");
					System.out.println("           |");
					System.out.println("         ____");
				}
				else if(hangman.getMissesCount()==2)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println(" | |       |");
					System.out.println("           |");
					System.out.println("           |");
					System.out.println("         ____");
				}
				else if(hangman.getMissesCount()==3)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println(" | |       |");
					System.out.println(" | |       |");
					System.out.println("           |");
					System.out.println("         ____");
				}
				else if(hangman.getMissesCount()==4)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println("\\| |       |");
					System.out.println(" | |       |");
					System.out.println("           |");
					System.out.println("         ____");
				}
				else if(hangman.getMissesCount()==5)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println("\\| |/      |");
					System.out.println(" | |       |");
					System.out.println("           |");
					System.out.println("         ____");
				}
				else if(hangman.getMissesCount()==6)
				{
					System.out.println("  __________");
					System.out.println("  |        |");
					System.out.println("(x_x)      |");
					System.out.println("\\| |/      |");
					System.out.println(" | |       |");
					System.out.println("/          |");
					System.out.println("         ____");
				}
			}
		}
		if(hangman.isGameOver()==true && hangman.isFound()==false)
		{
			System.out.println();
			System.out.println("  __________");
			System.out.println("  |        |");
			System.out.println("(x_x)      |");
			System.out.println("\\| |/      |");
			System.out.println(" | |       |");
			System.out.println("/   \\      |");
			System.out.println("         ____");
			System.out.println("Game Over, Man. Game Over!");
			System.out.println("You missed too many letters and lost.");
		}
		else if(hangman.isGameOver()==true && hangman.isFound()==true)
		{
			System.out.println();
			System.out.println("You Won!!!");
			System.out.println("You guessed the secret word \"" + hangman.getDisguisedWord() + "\" in " + hangman.getGuessCount() + " guesses.");
		}
		System.out.println("Do you want to play again? (yes/no):");
		s=input.next();
		if(s.toLowerCase().equals("yes"))
		{
			System.out.println("Input a new secret word: ");
			s=input.next();
			for(int i=0; i<100; i++)
			{
				System.out.println();
			}
			//figure out how to reset it!!!
		}
		else
		{
			System.out.println();
			System.out.println("Thanks for playing " + hangman.getGamesPlayed() + " game(s) of Hangman!");
		}
	}
}
