package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class _15930 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int sum = Integer.parseInt(st.nextToken());

		PriorityQueue<Long> pq = new PriorityQueue<>();

		StringTokenizer st2 = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			pq.add(Long.parseLong(st2.nextToken()));
		}

		while (sum > 0) {
			long temp = pq.poll();
			temp += pq.poll();

			pq.add(temp);
			pq.add(temp);
			sum--;
		}

		long h = 0;
		while (!pq.isEmpty()) {
			h += pq.poll();
		}
		System.out.println(h);
	}
}
