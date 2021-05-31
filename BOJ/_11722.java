package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _11722 {
	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int A= Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int arr[]=new int[1001];
		for(int i=0; i<A; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		int dp[]=new int[1001];
		for(int i=0; i<A; i++) {
			int min=1001;
			for(int j=0; j<i; j++) {
				if(arr[i]<arr[j]) {
					if(dp[j]<=min) {
						min=dp[j];
					}
				}
			}
		}
	}
}
