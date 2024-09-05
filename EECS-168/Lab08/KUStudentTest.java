import java.util.Scanner;
public class KUStudentTest 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		KUStudent stu= new KUStudent();
		System.out.println("Please input the student's name (firstname lastname):");
		String fname=input.next();
		String lname=input.next();
		stu.set_name(fname, lname);
		System.out.println("Please input the student's KUID and department:");
		String kuid=input.next();
		String dpt=input.next();stu.set_kuinfo(kuid, dpt);
		writeOutput(stu);
	}
	public static void writeOutput(KUStudent stu)
	{
		System.out.println("Student: " + stu.get_fname() + stu.get_lname());
		System.out.println("KUID: " + stu.get_id());
		System.out.println("Department: " + stu.get_dept());
	}
}
