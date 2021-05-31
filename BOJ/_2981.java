package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2981 {
	private static int mod(int n1,int n2) {
		if(n2==0) return n1;
		else return mod(n2,n1%n2);
	}
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		int N= Integer.parseInt(br.readLine());
		
//		for(int i=0; i<=N; i++) {
			int j=Integer.parseInt(br.readLine());
			int k=Integer.parseInt(br.readLine());
			System.out.println(mod(j,k));
			
//		}
		
	}
}
