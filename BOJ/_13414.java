package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class _13414 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st  = new StringTokenizer(br.readLine());
		
		int K= Integer.parseInt(st.nextToken());
		int L= Integer.parseInt(st.nextToken());
		
		HashSet<String> hs = new HashSet<>();
		
		for(int i=0; i<L; i++) {
			hs.add(br.readLine());
		}
		
		for(int i=0; i<K; i++) {
			System.out.println(hs);
		}
		
		
		
		
		
	}
}
