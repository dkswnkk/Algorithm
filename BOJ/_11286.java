package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class _11286 {
	public static void main(String[] args) throws IOException {
		PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (Math.abs(o1) > Math.abs(o2) || Math.abs(o1) == Math.abs(o2) && o1 > o2) {
					return 1;
				} else {
					return -1;
				}
			}

		});

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			int x = Integer.parseInt(br.readLine());

			if (x == 0) {
				if (pq.isEmpty()) {
					System.out.println(0);
				} else
					System.out.println(pq.poll());

			} else {
				pq.offer(x);
			}
		}
	}
}
