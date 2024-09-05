import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
public class Letter_Counter 
{
	public static void main(String[]args)
	{
	Scanner input=new Scanner(System.in);
	FileReader myFileReader=null;
	BufferedReader myBufferedReader=null;
	FileReader myFileReader2=null;
	BufferedReader myBufferedReader2=null;
	int[]upperCase=new int[26];
	int x=65;
	for(int i=0; i<upperCase.length; i++)
	{
		upperCase[i]=x;
		x++;
	}
	int[]lowerCase=new int[26];
	int y=97;
	for(int i=0; i<lowerCase.length; i++)
	{
		lowerCase[i]=y;
		y++;
	}
	try
	{
		System.out.print("Input a file name: ");
		String filename=input.next();
		myFileReader=new FileReader(filename);
		myBufferedReader=new BufferedReader(myFileReader);
		System.out.println();
		System.out.print("Input an out file name: ");
		String outFileName=input.next();
		System.out.println();
		System.out.println("Reading from input.txt");
		System.out.println();
		String line;
		String line2;
		int sum=0;
		while((line=myBufferedReader.readLine())!=null)
		{
			System.out.println(line);
			sum+=line.length();
		}
		System.out.println("Results stored in " + outFileName);
		myBufferedReader.close();
		//doing it again because i can't figure this out
		myFileReader2=new FileReader(filename);
		myBufferedReader2=new BufferedReader(myFileReader2);
		int[]array=new int[sum];
		while((line2=myBufferedReader2.readLine())!=null)
		{
			for(int i=0; i<line2.length(); i++)
			{
				array[i]=line2.charAt(i);
			}
		}
		FileWriter myFileWriter=new FileWriter(outFileName);
		BufferedWriter out=new BufferedWriter(myFileWriter);
		int counter=0;
		for(int i=0; i<upperCase.length; i++)
		{
			for(int j=0; j<array.length; j++)
			{
				if(upperCase[i]==array[j])
				{
					counter++;
				}
			}
			out.write((char)upperCase[i]+ "=" + counter);
			out.newLine();
			counter=0;
		}
		for(int i=0; i<lowerCase.length; i++)
		{
			for(int j=0; j<array.length; j++)
			{
				if(lowerCase[i]==array[j])
				{
					counter++;
				}
			}
			out.write((char)lowerCase[i]+ "=" + counter);
			out.newLine();
			counter=0;
		}
		out.close();
	}
	catch(Exception e)
	{
		System.out.println("Error: " + e.getMessage());
	}
	}
}
