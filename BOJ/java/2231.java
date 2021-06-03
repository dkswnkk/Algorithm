package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2231 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int result = 0;
		for (int i = N; i > 0; i--) {
			int sum = 0;
			String s = String.valueOf(i);

			for (int j = 0; j < s.length(); j++) {
				sum += s.charAt(j) - '0';
			}
			if (i + sum == N)
				result = i;
		}

		if (result == 0)
			System.out.println(0);
		else
			System.out.println(result);
	}
}