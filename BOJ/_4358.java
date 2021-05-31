package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class _4358 {
	static int allcount;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<String, Integer> hs = new HashMap<>();

		while (true) {
			String s = br.readLine();
			if (s == null || s.length() == 0) {
				break;
			}
			allcount++;
			if (hs.containsKey(s))
				hs.replace(s, hs.get(s) + 1);
			else
				hs.put(s, 1);
		}
		Object arr[] = hs.keySet().toArray();
		Arrays.sort(arr);

		for (Object a : arr) {
			String ss = (String) a;
			int cnt = hs.get(ss);
			double per = (double) (cnt * 100.0) / allcount;
			System.out.println(ss + " " + String.format("%.4f", per));
		}

	}
}