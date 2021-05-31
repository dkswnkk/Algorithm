package baekjoon;

import java.util.Scanner;

public class _13417 {
	static char[] c;
	static String s;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();

			c = new char[N];

			for (int j = 0; j < N; j++) {
				c[j] = sc.next().charAt(0);
			}
			s = String.valueOf(c[0]);

			for (int k = 1; k < N; k++) {
				if (c[k] > s.charAt(0)) {
					s = s + c[k];
				} else
					s = c[k] + s;
			}
			System.out.println(s);

		}

	}

}
