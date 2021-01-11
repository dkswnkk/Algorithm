//  Copyright © 2021 안주형. All rights reserved.
//  DFS알고리즘
//  https://www.acmicpc.net/problem/1012
//  BOJ1012 유기농 배추
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;  //M:가로길이 N:세로길이 K: 배추 개수
int map[51][51];
int visited[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0<=nx&&nx<N&&0<=ny&&ny<M) {
			if (map[nx][ny] && !visited[nx][ny]) { //방문하지 않았고, 지렁이가 있을때
				visited[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}
void reset() {
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			map [i][k] = 0;
			visited[i][k] = 0;
		}
	}

}

int main() {
	int T, a, b;
	cin >> T;
	while (T--) {
		int cnt = 0;
		reset();
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			map[b][a] = 1; //배추 위치 입력
		}
		for (int i = 0; i < N; i++) { //지렁이 탐색
			for (int k = 0; k < M; k++) {
				if (map[i][k] && !visited[i][k]) { // 지렁이가 있고, 방문하지 않았을때
					dfs(i, k);
					cnt++;
				}
			}

		}
			cout << cnt << "\n";
	}
}