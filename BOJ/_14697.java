package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _14697 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int dp[] = new int[501];
		dp[0] = 1;	
		for (int i = 0; i < N; i++) {			
			if(dp[i] == 0) continue;
			dp[i+A] = dp[i+B] = dp[i+C] = 1;
		}
		System.out.println(dp[N]);
	}

}