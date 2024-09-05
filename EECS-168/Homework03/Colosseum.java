public class Colosseum 
{
	public static void main(String[]args)
	{
		int x=1;
		Pokemon pokemon1=new Pokemon();
		Pokemon pokemon2=new Pokemon();
		System.out.println("Player 1, build your Pokemon!");
		System.out.println("=====================");
		pokemon1.userBuild();
		System.out.println("Player 2, build your Pokemon!");
		System.out.println("=====================");
		pokemon2.userBuild();
		Dice d2=new Dice(2);
		System.out.println("Player 1 will roll a D2 to decide who goes first.");
		int coinFlip=d2.roll();
		System.out.print("Player 1 rolls a " + coinFlip + " and will go ");
		if (coinFlip==1)
		{
			System.out.println("first.");
			while(pokemon1.get_hp()>0 && pokemon2.get_hp()>0 && x<11)
			{
					System.out.println();
					System.out.println("Round " + x + "!");
					System.out.println();
					pokemon1.attack(pokemon2);
					pokemon2.attack(pokemon1);
					x++;
			}
			if(x>10)
			{
				System.out.println("Both fighters are still standing! It's a draw!");
			}
		}
		else
		{
			System.out.println("second.");
			while(pokemon1.get_hp()>0 && pokemon2.get_hp()>0 && x<11)
			{
					System.out.println();
					System.out.println("Round " + x + "!");
					System.out.println();
					pokemon2.attack(pokemon1);
					pokemon1.attack(pokemon2);
					x++;
			}
			if(x>10)
			{
				System.out.println("Both fighters are still standing! It's a draw!");
			}
		}
	}
}
