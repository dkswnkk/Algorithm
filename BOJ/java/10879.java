import java.util.Scanner;
public class Main {
	public static int Fibonacci(int n) {
		if (n == 0) {
			return 0;
		} else if (n == 1) {
			return 1;
		} else if (n == 2) {
			return 1;
		} else
			return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(Fibonacci(n));
	}
}
