import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int number[] = new int[N];
		int max, min;

		for (int i = 0; i < N; i++) {
			number[i] = sc.nextInt();
		}
		max = number[0];
		min = number[0];
		for (int i = 0; i < number.length; i++) {
			if (number[i] > max) {
				max = number[i];
			}
			if (number[i] < min) {
				min = number[i];
			}
		}
		System.out.printf(min + " " + max);

	}
}
