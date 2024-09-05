import java.util.Scanner;
public class Pokemon 
{
	private int hp;
	private int attackLevel;
	private int defenseLevel;
	private String name;
	private Dice d20=new Dice(20);
	private Dice d6=new Dice(6);
	public int get_hp()
	{
		return(hp);
	}
	public void set_hp(int newhp)
	{
		hp=newhp;
	}
	public int get_attackLevel()
	{
		return(attackLevel);
	}
	public void set_attackLevel(int newAttackLevel)
	{
		attackLevel=newAttackLevel;
	}
	public int get_defenseLevel()
	{
		return(defenseLevel);
	}
	public void set_defenseLevel(int newDefenseLevel)
	{
		defenseLevel=newDefenseLevel;
	}
	public String get_name()
	{
		return(name);
	}
	public void set_name(String newName)
	{
		name=newName;
	}
	public Pokemon()
	{
		hp=0;
		attackLevel=0;
		defenseLevel=0;
		name="";
	}
	public boolean attack(Pokemon opponent)
	{
		if(hp<=0)
		{
			return(true);
		}
		int attackBonus=d20.roll();
		int defenseBonus=d20.roll();
		int attack=attackLevel+attackBonus;
		int defense=opponent.defenseLevel+defenseBonus;
		System.out.println(name + " is attacking " + opponent.name);
		System.out.println(name + " rolls an attack bonus of " + attackBonus);
		System.out.println(opponent.name + " rolls a defense bonus of " + defenseBonus);
		if (attack>defense)
		{
			System.out.println("The attack hits dealing 3-D6 damage!");
			int damage1=d6.roll();
			int damage2=d6.roll();
			int damage3=d6.roll();
			int totalDamage=damage1+damage2+damage3;
			System.out.println("The rolls are " + damage1 + ", " + damage2 + ", " + damage3 + " totaling: " + totalDamage + " damage!");
			opponent.hp=opponent.hp-totalDamage;
			if(opponent.hp<=0)
			{
				System.out.println(opponent.name + " has been defeated!");
				return(true);
			}
			else
			{
				System.out.println(opponent.name + " has " + opponent.hp + " hitpoints left");
				return(false);
			}
		}
		else
		{
			System.out.println("The attack missed!");
		}
		return(false);
	}
	public void userBuild()
	{
		Scanner input=new Scanner(System.in);
		System.out.print("Please name your pokemon: ");
		name=input.next();
		System.out.println();
		System.out.print("How many hit points will it have? (1-50): ");
		hp=input.nextInt();
		while(hp>50 || hp<1)
		{
			System.out.print("Sorry. Hit points must be between 1 and 50: ");
			hp=input.nextInt();
		}
		System.out.println();
		System.out.println("Split fifty points between attack level and defense level");
		System.out.print("Enter your attack level (1-49): ");
		attackLevel=input.nextInt();
		while(attackLevel>49 || attackLevel<1)
		{
			System.out.print("Sorry. The attack level must be between 1 and 49: ");
			attackLevel=input.nextInt();
		}
		int topDefenseLevel=50-attackLevel;
		System.out.println();
		System.out.print("Enter your defense level (1-" + topDefenseLevel + "): ");
		defenseLevel=input.nextInt();
		while(defenseLevel>topDefenseLevel || defenseLevel<1)
		{
			System.out.println("Sorry. The defense level must be between 1 and " + topDefenseLevel + ": ");
			defenseLevel=input.nextInt();
		}
		System.out.println();
	}
}
