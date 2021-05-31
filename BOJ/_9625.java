package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _9625 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());

		int dpA[] = new int[46];
		int dpB[] = new int[46];

		dpA[0] = 0;
		dpA[1] = 1;
		dpB[0] = 1;
		dpB[1] = 1;

		for (int i = 2; i <= K; i++) {
			dpA[i] = dpA[i - 2] + dpA[i - 1];
			dpB[i] = dpB[i - 2] + dpB[i - 1];
		}
		System.out.println(dpA[K - 1] + " " + dpB[K - 1]);

	}
}
