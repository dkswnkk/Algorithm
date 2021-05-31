package baekjoon;

import java.util.Scanner;

public class _1012 {
	static boolean visited[][];
	static int node[][];
	static int[] dy = { -1, 1, 0, 0 }; //상하
	static int[] dx = { 0, 0, -1, 1 }; //좌우
	static int T; // 테스트 케이스
	static int M; // 가로길이
	static int N; // 세로길이
	static int K; // 배추 위치
	static int cnt;

	public static void dfs(int row, int col) {
		visited[row][col] = true;
		for (int i = 0; i < 4; i++) {
			int next_row = row + dy[i];
			int next_col = col + dx[i];
			if (isValid(next_row, next_col) && node[next_row][next_col] == 1 && visited[next_row][next_col] == false) {
				dfs(next_row, next_col);
			}
		}
	}

	static boolean isValid(int i, int k) {
		if (i < 0 || k < 0 || i >= N || k >= M)
			return false;

		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();

		for (int A = 1; A <= T; A++) {
			M = sc.nextInt();
			N = sc.nextInt();
			K = sc.nextInt();
			cnt = 0;
			node = new int[N][M];
			visited = new boolean[N][M];
			int row, col;
			for (int i = 0; i < K; i++) {
				col = sc.nextInt();
				row = sc.nextInt();
				node[row][col] = 1;
			}

			for (int i = 0; i < N; i++) {
				for (int k = 0; k < M; k++) {
					if (node[i][k] == 1 && visited[i][k] == false) {
						dfs(i, k);
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}

	}
}
