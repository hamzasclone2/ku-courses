/*
File Name: Hangman..java
Author: Hamza Hameed 
KUID: 2796053
Email Address: h002h741@ku.edu 
Homework Assignment Number: 4 
Description: Initializes all variables and runs logic of game 
Last Changed: 12/6/14 
*/
public class Hangman 
{
	private final String secretWord="trilogy";
	private char[] disguisedWord=new char[secretWord.length()];
	private int guessCount;
	private int missesCount;
	private int maxMissesAllowed=7;
	private char[] missedMarkers=new char[maxMissesAllowed];
	private static int gamesPlayed;
	public Hangman()
	{
		char c;
		for(int i=0; i<secretWord.length(); i++)
		{
			c=secretWord.charAt(i);
			if(c==' ')
			{
				disguisedWord[i]=' ';
			}
			else
			{
			disguisedWord[i]='?';
			}
		}
		for(int i=0; i<7; i++)
		{
			missedMarkers[i]='O';
		}
		guessCount=0;
		missesCount=0;
		gamesPlayed++;
		maxMissesAllowed=7;
	}
	//pre: character is valid
	//post: updates diguised word/ missed marker depending on if guess was correct
	public boolean guessCharacter(char c)
	{
		guessCount++;
		boolean b=true;
		for(int i=0; i<secretWord.length(); i++)
		{
			if(secretWord.charAt(i)==c)
			{
				disguisedWord[i]=c;
				b=false;
			}
		}
		if(b==false)
		{
			return(true);
		}
		missesCount++;
		return(false);
	}
	//pre: a character is guessed
	//post: ends or continues game based on # of incorrect guesses
	public boolean isGameOver()
	{
		if(missesCount>=maxMissesAllowed || isFound()==true)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	//pre: a character is guessed
	//post: informs gamedriver if a character was found
	public boolean isFound()
	{
		for(int i=0; i<disguisedWord.length; i++)
		{
			if(disguisedWord[i]=='?')
			{
				return(false);
			}
		}
		return(true);
	}
	//pre: disguised word is a char[]
	//post: returns string of char[]
	public String getDisguisedWord()
	{
		String s=new String(disguisedWord);
		return(s);
	}
	public int getGuessCount()
	{
		return(guessCount);
	}
	public int getMissesCount()
	{
		return(missesCount);
	}
	//pre: missed marker= OOOOOOO
	//post: missed marker updated based on incorrect guesses
	public String getMissedMarker()
	{
		for(int i=0; i<missesCount; i++)
		{
			missedMarkers[i]='X';
		}
		String s=new String(missedMarkers);
		return(s);
	}
	public int getGamesPlayed()
	{
		return(gamesPlayed);
	}
}
