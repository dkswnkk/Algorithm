package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class _2075 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		LinkedList arr = new LinkedList();
		for (int i = 0; i < N; i++) {

			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr.add(Integer.parseInt(st.nextToken()));
			}
		}
		Collections.sort(arr, Collections.reverseOrder());

		System.out.println(arr.get(N - 1));
	}
}
