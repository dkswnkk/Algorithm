package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1789 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long S = Long.parseLong(br.readLine());

		long cnt = 1;
		long sum = 0;
		while (true) {
			sum += cnt;
			if (sum > S) {
				break;
			}
			cnt++;
		}
		System.out.println(cnt - 1);
	}
}
