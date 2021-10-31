import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		
			int A,B,C; 
		
			Scanner sc = new Scanner(System.in);
			A=sc.nextInt();
			B=sc.nextInt();
			C=sc.nextInt();
			sc.close();
			System.out.println((A+B)%C);
			System.out.println(((A%C) + (B%C))%C);
			System.out.println((A*B)%C);
			System.out.println(((A%C) * (B%C))%C);

	}
}
