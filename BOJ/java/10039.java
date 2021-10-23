import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		
		Scanner sc = new Scanner(System.in);
		int total=0;
		for(int i = 1; i<=5 ; i++) {
			int N=sc.nextInt();
			
				if(N<40) {
					N=40;
				}
			total=total+N;
		}
		System.out.println(total/5);
	}
}
