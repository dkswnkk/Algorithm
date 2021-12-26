import java.util.Scanner;
public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B=  sc.nextInt();
		
		if((A>=-1000&&A<=1000)&&(B>=-1000&&B<=1000)){
			
		}
		if(A>0&&B>0) {
			System.out.println("1");
		}
		else if (A<0&&B>0) {
			System.out.println("2");
		}
		else if(A<0&&B<0) {
			System.out.println("3");
		}
		else
			System.out.println("4");

		}
	}
