package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class _1715 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Long> pq = new PriorityQueue<Long>();
		int N = Integer.parseInt(br.readLine());
		long sum = 0;
		long temp = 0;
		long score = 0;
		for (int i = 0; i < N; i++) {
			pq.add(Long.parseLong(br.readLine()));
		}
		while (pq.size() > 1) {
			temp = pq.poll() + pq.poll();
			sum = temp;
			pq.add(sum);
			score += sum;
			temp = 0;
			sum = 0;
		}
		System.out.println(score);
	}
}