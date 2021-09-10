import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		
		Scanner sc = new Scanner(System.in);
		int total=0;
		int bur;
		int drink;
		int A=10000;
		int B=10000;
//햄버거 가격		
			 for(int i=1; i<=3; i++) {
				 bur=sc.nextInt();
				  	if(bur<A) {
				  		A=bur;
			 }
			 }
//음료수 가격
			 for(int i=1; i<=2; i++) {
				 drink=sc.nextInt();
				 	if(drink<B) {
				 		B=drink;
				 	}
			 }
			 System.out.println((A+B-50));
			}
}
