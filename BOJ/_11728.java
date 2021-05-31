package baekjoon;

import java.util.Arrays;
import java.util.Scanner;

public class _11728 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int A = sc.nextInt();
		int B = sc.nextInt();

		int Aarr[] = new int[A];
		int Barr[] = new int[B];
		int carr[] = new int[A + B];

		for (int i = 0; i < A; i++) {
			Aarr[i] = sc.nextInt();
		}
		for (int i = 0; i < B; i++) {
			Barr[i] = sc.nextInt();
		}
		for (int i = 0; i < A; i++) {
			carr[i] = Aarr[i];
		}
		for (int i = A, j = 0; i < A + B; i++, j++) {

			carr[i] = Barr[j];

		}
		Arrays.sort(carr);

		for (int i : carr) {
			sb.append(i).append(" ");
		}
		System.out.println(sb);
	}
}
