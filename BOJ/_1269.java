package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class _1269 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int Anum = Integer.parseInt(st.nextToken());
		int Bnum = Integer.parseInt(st.nextToken());

		Set<Integer> hsA = new HashSet();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < Anum; i++) {
			hsA.add(Integer.parseInt(st.nextToken()));
		}
		Set<Integer> hsB = new HashSet();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < Bnum; i++) {
			hsB.add(Integer.parseInt(st.nextToken()));
		}

		TreeSet<Integer> tmp = new TreeSet<Integer>();
		tmp.addAll(hsA);
		hsA.removeAll(hsB);
		hsB.removeAll(tmp);

		System.out.println(hsA.size() + hsB.size());

	}
}