import java.util.Scanner;
public class Tornado 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the wind speed:");
		double windspeed=input.nextDouble();
	    if (windspeed>=40 && windspeed<=72)
		{
			System.out.println("The tornado is a F-0 torndado");
		}
		else if (windspeed>72 && windspeed<=112)
		{
			System.out.println("The tornado is a F-1 torndado");
		}
		else if (windspeed>112 && windspeed<=157)
		{
			System.out.println("The tornado is a F-2 torndado");
		}
		else if (windspeed>157 && windspeed<=205)
		{
			System.out.println("The tornado is a F-3 torndado");
		}
		else if (windspeed>205 && windspeed<=260)
		{
			System.out.println("The tornado is a F-4 torndado");
		}
		else if (windspeed>260 && windspeed<=318)
		{
			System.out.println("The tornado is a F-2 torndado");
		}
		else
		{
			System.out.println("This is not a tornado");
		}
	}
}
