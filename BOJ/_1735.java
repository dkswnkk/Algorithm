package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _1735 {
	private static int mod(int a,int b) {
		 if(b==0) return a;
		else return mod(b,a%b);
	}
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		

		StringTokenizer st = new StringTokenizer(br.readLine());		
		int A=Integer.parseInt(st.nextToken());
		int B=Integer.parseInt(st.nextToken());
		st=new StringTokenizer(br.readLine());
		int C=Integer.parseInt(st.nextToken());
		int D=Integer.parseInt(st.nextToken());
		int denominator=B*D; //분모
		int molecule=A*D+C*B; //분자
		
		
		;
		
		
		System.out.println(molecule/mod(molecule,denominator)+" "+ denominator/mod(molecule,denominator));
	
}
}
