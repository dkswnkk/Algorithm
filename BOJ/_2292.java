package baekjoon;

import java.util.Scanner;

public class _2292 {
	public static int bee(int n) {
		if (n == 1) {
			return 1;
		}
		int a = 2;
		int b = 1;
		while (a <= n) {
			a += 6 * b;
			b++;
		}
		return b;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		System.out.println(bee(n));

	}

}
