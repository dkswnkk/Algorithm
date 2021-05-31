package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class _14698 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		final long mod = 1000000007;
		for (int t = 0; t < T; t++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer	st = new StringTokenizer(br.readLine());
			PriorityQueue<Long> pq = new PriorityQueue<Long>();
			for (int i = 0; i <n; i++) {
				pq.add(Long.parseLong(st.nextToken()));
			}
			long score = 1;
			while (pq.size() >=2) {
				long one = pq.poll();
				long two = pq.poll();
				score*=(((one%mod)*(two%mod))%mod);
			pq.add(one*two);
			score%=mod;
			}
			sb.append(score).append("\n");

		}
		System.out.print(sb);
	}
}
