package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class _1083 {

	public static void newSort(int A[], int N, int S) {
		for (int i = 0; i < N; i++) {
			int max = A[i];
			int l = i;
			for (int j = i + 1; j <= i + S; j++) {
				if (j == N)
					break;
				if (max < A[j]) {
					max = A[j];
					l = j;
				}
			}
			if (l != i) {
				for (int k = l; k > i; k--) {
					A[k] = A[k - 1];
				}
				A[i] = max;
				S -= (l - i);
			}
			if (S == 0)
				break;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}

		int S = Integer.parseInt(br.readLine());

		newSort(A, N, S);
		for (int z : A) {
			System.out.print(z + " ");
		}
	}
}