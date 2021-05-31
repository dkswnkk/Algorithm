//  Copyright © 2021 안주형. All rights reserved.
//  dfs알고리즘
//  https://www.acmicpc.net/problem/4963
//  BOJ4963 섬의 개수
#include <iostream>

using namespace std;

int w, h;
int cnt = 0;
int map[51][51];
int visited[51][51];
// 상하좌우 뿐만아니라 대각선까지 탐색해야함.
int dx[] = { -1,1,0,0,1,-1,-1,1 };
int dy[] = { 0,0,-1,1,1,1,-1,-1};


void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (!visited[nx][ny] && map[nx][ny]) { //방문하지 않고, 땅일때
				visited[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}

void reset() {
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			map[i][k] = 0;
			visited[i][k] = 0;
		}
	}
		cnt = 0;
}
int main() {

	while (true) {
		reset();
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				scanf_s("%1d", &map[i][k]); //지도 입력
			}
		}

		for (int i = 0; i < h; i++) { //지도 탐색
			for (int k = 0; k < w; k++) {
				if (!visited[i][k] && map[i][k]) {
					dfs(i, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
		