package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1003 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		int[][] dp = new int[41][2];

		while (T-- > 0) {
			int N = Integer.parseInt(br.readLine());

			if (N == 0) {
				System.out.println("1 0");
				continue;
			} else if (N == 1) {
				System.out.println("0 1");
				continue;
			}
			dp[0][0] = 1; // N=0 일때 0호출 횟수
			dp[1][1] = 1; // N=1 일때 1 호출 횟수

			for (int i = 2; i <= N; i++) {
				dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
				dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
			}

			System.out.println(dp[N][0] + " " + dp[N][1]);
		}

	}
}
