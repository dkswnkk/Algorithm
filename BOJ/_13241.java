package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _13241 {
	private static long GCD(long a,long b) {
		if (b==0) return a;
		else return(GCD(b,a%b));
	}
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		long a=Long.parseLong(st.nextToken());
		long b=Long.parseLong(st.nextToken());
		
		System.out.println(a*b/GCD(a,b));
	}
}
