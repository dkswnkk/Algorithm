import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		int score;

		Scanner sc= new Scanner(System.in);
		score= sc.nextInt();
	
if(!((0<=score)&&(score<=100))){
	System.exit(0);
}

	
 if((score>=90)&&(100>=score)) {
	System.out.println("A");
}
else if((score>=80&&89>=score)) {
	System.out.println("B");
}
else if((score>=70&&79>=score)) {
	System.out.println("C");
}
else if((score>=60&&69>=score)) {
	System.out.println("D");
}
else {
	System.out.println("F");
}
}
}
