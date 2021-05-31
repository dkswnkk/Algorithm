package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class _14241 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int score = 0;

		PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			pq.add(Integer.parseInt(st.nextToken()));
		}
		int sum = 0;
		int triple = 0;

		while (pq.size() > 1) {
			int temp1 = pq.poll();
			int temp2 = pq.poll();

			sum = temp1 + temp2;
			triple = temp1 * temp2;
			score += triple;
			pq.add(sum);

		}
		System.out.println(score);
	}
}
