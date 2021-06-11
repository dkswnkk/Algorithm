package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _2609 {
	private static int GCD(int n1,int n2) {
		if(n2==0) return n1;
		else return GCD(n2,n1%n2);
	}
	
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n1 = Integer.parseInt(st.nextToken());
		int n2 = Integer.parseInt(st.nextToken());
		
		System.out.println(GCD(n1,n2));
		System.out.println(n1*n2/GCD(n1,n2));
		//최소공베수(LCM) = 두 수의 곱/최대공약수
	}
}
