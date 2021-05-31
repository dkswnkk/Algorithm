package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class _1302 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		HashMap<String, Integer> hash = new HashMap<>();

		for (int i = 0; i < N; i++) {

			String temp = br.readLine();
			if (hash.containsKey(temp))
				hash.replace(temp, hash.get(temp) + 1);
			else
				hash.put(temp, 1);
		}
		int max = 0;
		for (String key: hash.keySet()) {
			max = Math.max(max, hash.get(key));
		}

		ArrayList<String> arr = new ArrayList<String>(hash.keySet());
		Collections.sort(arr);

		for (String key : arr) {
			if (hash.get(key) == max) {
				System.out.println(key);
				break;
			}
		}
	}
}