import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int total=0;
		int len = sc.nextInt();
		if(len>=1&&len<=10000) {
			for(int i=1; i<=len; i++) {
				total=i+total;
			}
			System.out.println(total);

		}
		else 
			System.exit(1);

			}

}
