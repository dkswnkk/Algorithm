//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/10026
//  BOJ10026 적록색약
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int N,ans1,ans2;	//NxN, ans1=적록색약 아닌사람이 봤을때, ans=적록색약인 사람이 봤을때
char map[101][101];
int visited[101][101];
queue<pair<int, int>>q;
int dx[] = { 0,0,-1,1 };	//상 하 좌 우
int dy[] = { -1,1,0,0 };

void reset() {
	memset(visited,0,sizeof(visited));
}
void bfs(int a, int b) {
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {	//상 하 좌 우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {	//구역의 범위를 넘어서지 않을때
				if (!visited[nx][ny] && (map[nx][ny] == map[x][y])) {
					visited[nx][ny] = 1;
					q.push({ nx,ny });

				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {	//그림 정보 입력.
		for (int k = 0; k < N; k++) {
			cin >> map[i][k];
		}
	}


	for (int i = 0; i < N; i++) {	//적록색약 아닌사람이 볼때 탐색
		for (int k = 0; k < N; k++) {
			if (!visited[i][k]) {
				bfs(i, k);
				ans1++;
			}
		}
	}
	reset(); //방문 기록 초기화

	for (int i = 0; i < N; i++) {	//적록색약인 사람이 볼때를 탐색하기위해
		for (int k = 0; k < N; k++) {
			if (map[i][k] == 'G') map[i][k] = 'R';	//초록을 빨강으로 변경

		}
	}
	for (int i = 0; i < N; i++) {	//적록색약인 사람이 볼때 탐색
		for (int k = 0; k < N; k++) {
			if (!visited[i][k]) {
				bfs(i, k);
				ans2++;
			}
		}
	}

	cout << ans1<<' '<<ans2;
}