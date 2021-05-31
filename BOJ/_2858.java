package baekjoon;

import java.util.Scanner;

public class _2858 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int R = sc.nextInt();
		int B = sc.nextInt();
		int temp = 0;
		if (R >= B) {
			temp = R;
		} else {
			temp = B;
		}
		int sum = R + B;

		for (int i = 1; i <= temp; i++) {
			for (int j = 1; j <= temp; j++) {

				if (i * j == sum) {
					if (Math.abs(i - j) <= 1) {

						System.out.printf(j + " " + i);
						System.exit(0);
					}

				}
			}
		}

	}
}
