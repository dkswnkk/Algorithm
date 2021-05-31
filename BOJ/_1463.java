package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1463 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N= Integer.parseInt(br.readLine());
		long dp[]=new long[1000001];
		dp[0]=0;
		dp[1]=0;


		for(int i=2; i<=N; i++) {
			dp[i]=dp[i-1]+1;
			if(i%3==0) dp[i]=Math.min(dp[i],dp[i/3]+1); 
			else if(i%2==0) dp[i]=Math.min(dp[i],dp[i/2]+1);
	}

		System.out.println(dp[N]);

}
}