package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _1920 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());

		int cnt = st.countTokens();

		for (int i = 0; i < cnt; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		cnt = st.countTokens();

		for (int i = 0; i < cnt; i++) {
			int index = Arrays.binarySearch(arr, Integer.parseInt(st.nextToken()));
			if (index < 0)
				System.out.println("0");
			else
				System.out.println("1");
		}

	}
}
