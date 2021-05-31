package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class _2957R {

	static long ans;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		TreeMap<Integer, Integer> map = new TreeMap<>();

		for (int i = 0; i < N; i++) {
			int m = Integer.parseInt(br.readLine());

			if (i == 0) {
				map.put(m, 0);
				ans = 0;
			} else {
				Integer upperKey = map.higherKey(m);
				Integer lowerKey = map.lowerKey(m);

				int depth = 0;
				if (upperKey == null) {
					depth = map.get(lowerKey) + 1;
					map.put(m, depth);
				} else if (lowerKey == null) {
					depth = map.get(upperKey) + 1;
					map.put(m, depth);
				} else {
					int upper = map.get(upperKey);
					int lower = map.get(lowerKey);

					depth = upper > lower ? upper + 1 : lower + 1;
					map.put(m, depth);
				}
				ans += depth;
			}
			sb.append(ans).append("\n");
		}
		System.out.print(sb);
	}
}
