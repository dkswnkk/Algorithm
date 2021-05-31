package baekjoon;

import java.util.Scanner;

public class _1316 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cnt = n;

		for (int i = 0; i < n; i++) {
			String s = sc.next();
			boolean[] check = new boolean[26];

			for (int j = 1; j < s.length(); j++) {
				if (s.charAt(j - 1) != s.charAt(j)) {
					if (check[s.charAt(j) - 'a'] == true) {
						cnt--;
						break;
					}
					check[s.charAt(j - 1) - 'a'] = true;
				}
			}
		}
		System.out.println(cnt);
	}
}
