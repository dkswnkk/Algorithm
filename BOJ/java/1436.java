package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1436 {
	public static void main(String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		

		int n = Integer.parseInt(br.readLine());
		int cnt = 0;

		while (n > 0) {
			cnt++;
			if (String.valueOf(cnt).contains("666")) {
				n--;
			}

		}
		System.out.println(cnt);
	}
}
