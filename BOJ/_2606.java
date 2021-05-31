package baekjoon;

import java.util.Scanner;

public class _2606 {
	static int N; 
	static int M; 
	static int check[][]; 
	static boolean checked[]; 
	static int cnt;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		check = new int[N+1][N+1];
		checked = new boolean[N+1];
		for (int i = 0; i < M; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			check[A][B] = check[B][A] = 1;
		}

		DFS(1);
		System.out.print(cnt);

	}

	public static void DFS(int n) {
		checked[n] = true;

		for (int i = 1; i <= N; i++) { 
			if (check[n][i] == 1 && checked[i] == false) {
				cnt++;
				DFS(i);
			}
		}
	}
}
