package baekjoon;

import java.util.Arrays;
import java.util.Scanner;

public class _2309 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h[] = new int[9];
		int sum = 0;

		for (int i = 0; i < h.length; i++) {
			h[i] = sc.nextInt();
		}

		for (int a = 0; a < h.length - 6; a++) {
			for (int b = a + 1; b < h.length - 5; b++) {
				for (int c = b + 1; c < h.length - 4; c++) {
					for (int d = c + 1; d < h.length - 3; d++) {
						for (int e = d + 1; e < h.length - 2; e++) {
							for (int f = e + 1; f < h.length - 1; f++) {
								for (int g = f + 1; g < h.length; g++) {
									sum = h[a] + h[b] + h[c] + h[d] + h[e] + h[f] + h[g];
									if (sum == 100) {
										int check[] = { h[a], h[b], h[c], h[d], h[e], h[f], h[g] };
										Arrays.sort(check);
										System.out.printf(check[0] + "\n" + check[1] + "\n" + check[2] + "\n" + check[3]
												+ "\n" + check[4] + "\n" + check[5] + "\n" + check[6]);
										System.exit(0);
									}
									
								}

							}

						}

					}

				}


			}

		}

	}
}
