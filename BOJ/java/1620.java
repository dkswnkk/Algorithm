package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;	
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class _1620 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int poketmonCnt = Integer.parseInt(st.nextToken());
		int cnt = Integer.parseInt(st.nextToken());

		Map<String, Integer> map1 = new HashMap<>();
		Map<Integer, String> map2 = new HashMap<>();
		for (int i = 1; i <= poketmonCnt; i++) {
			String poketmonNum = br.readLine();

			map1.put(poketmonNum, i); // 문자열일때
			map2.put(i, poketmonNum); // 정수일때
		}
		StringBuilder sb = new StringBuilder();
		while (cnt-- > 0) {
			var s = br.readLine();
			// Character.isDigit 는 정수형일때 true 반환
			if (Character.isDigit(s.charAt(0))) { // 정수형일때
				int a = Integer.parseInt(s);
				sb.append(map2.get(a)).append("\n");
			} else {
				sb.append(map1.get(s)).append("\n");
			}
		}
		System.out.print(sb);
	}
}