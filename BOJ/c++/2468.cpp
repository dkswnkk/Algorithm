//  Copyright © 2021 안주형. All rights reserved.
//  dfs알고리즘
//  https://www.acmicpc.net/problem/2468
//  BOJ2468 안전 영역
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
int visited[101][101];
int cnt = 0;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y,int z) {
	visited[x][y] = 1;
	int height = z; 
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >=0 && nx < N && ny >=0 && ny < N) {
			if (!visited[nx][ny] && map[nx][ny] > height)
				dfs(nx, ny, height);
		}
	}
}
void reset() {
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			visited[i][k] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	int ans = 1;
	int max_value=0, min_value=101;
	for (int i = 0; i < N; i++) { //높이 정보 입력
		for (int k = 0; k < N; k++){ 
			cin >> map[i][k];
			max_value = max(max_value, map[i][k]);
			min_value = min(min_value, map[i][k]);
		}
	}
	for (int i = min_value; i < max_value; i++) { //최소 봉우리부터 탐색 시작.
		reset();
		cnt = 0;
		for (int j = 0; j < N; j++) { 
			for (int k = 0; k < N; k++) {
				if (map[j][k] > i && !visited[j][k]) {
					cnt++;
					dfs(j, k, i);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;

}