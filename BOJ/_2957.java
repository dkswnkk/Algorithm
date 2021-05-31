package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2957 {
	static int binaryTree[] = new int[300001];
	static int c = 0;

	public static void insert(int num, int idx) {
		c++;
		if (num < binaryTree[idx]) { // 새로 들어온 숫자가 노드보다 작으면
			if (binaryTree[idx * 2] == 0) { // 왼쪽 자식이 없으면
				binaryTree[idx * 2] = num;
			} else {
				insert(num, idx * 2);
			}
		} else if (num > binaryTree[idx]) { // 새로 들어온 숫자가 노드보다 크면
			if (binaryTree[idx * 2 + 1] == 0) {// 오른쪽 자식이 없다면
				binaryTree[idx * 2 + 1] = num;
			} else {
				insert(num, idx * 2 + 1);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());

		for (int i = 1; i <= N; i++) {
			int num = Integer.parseInt(br.readLine());

			if (i == 1) {
				binaryTree[1] = num;
			} else {
				insert(num, 1);
			}
			sb.append(c).append("\n");
		}
		System.out.print(sb);

	}
}
