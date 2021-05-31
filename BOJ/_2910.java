package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

/*
 * 숙지할 것.
 * LinkedHashMap 이 무엇인지.
 * return Integer.compare(tree.get(b), tree.get(a)); 이 무엇인지 
 * 
 */

public class _2910 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		HashMap<Integer, Integer> tree = new LinkedHashMap<>();
		for (int i = 0; i < N; i++) {
			int temp = Integer.parseInt(st.nextToken());
			if (tree.containsKey(temp))
				tree.replace(temp, tree.get(temp) + 1);
			else
				tree.put(temp, 1);
		}

		ArrayList<Integer> arr = new ArrayList<Integer>(tree.keySet());
		Collections.sort(arr, new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				//arr.get(b) 와 arr.get(a)의 위치가 바뀌면 오름차순이 된다.
				return Integer.compare(tree.get(b), tree.get(a));
				// b<a 이면 -1 출력
			}
		});

		Iterator<Integer> it = arr.iterator();
		while (it.hasNext()) {
			Integer element = it.next();
			for (int i = 0; i < tree.get(element); i++) {
				System.out.print(element + " ");
			}
		}
	}
}
