package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _9095 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		int dp[]= new int[12];
		dp[1]=1; // 1
		dp[2]=2; // 1+1, 2
		dp[3]=4; // 1+1+1, 1+2, 2+1, 3
//		dp[4]=7; // 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1
//		dp[5]=13;   
//  	dp[6]=24;
//		dp[7]=44;
		while(T-->0) {
			int n= Integer.parseInt(br.readLine());
			for(int i=4; i<=n; i++) {
				dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
			}
			System.out.println(dp[n]);
	        }
	 }
}
	
		
