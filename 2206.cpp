//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2206
//  BOJ2206 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M; //N개의 줄, M개의 숫자 
int ans[1001][1001][2];	//벽을 뚫었을때와 뚫지않았을때의 최단거리를 담는 테이블
int map[1001][1001];
int dx[] = { 0,0,-1,1 };	//상 하 좌 우
int dy[] = { -1,1,0,0 };


void bfs() {
	queue<tuple<int, int, int>>q;	//(x,y,벽뚫기여부)
	q.push({ 0,0,1 });	//벽을 뚫을 수 있으면 1				
	ans[0][0][1] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int block = get<2>(q.front());
		q.pop();

		if (x == N - 1 && y == M - 1) break;	//도착했을때 종료.

		for (int i = 0; i < 4; i++) {	//상 하 좌 우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {	//맵의 범위를 벗어나지 않을때
				if (map[nx][ny] == 1 && block) {	//벽이 있고, 뚫을 수 있을때
					ans[nx][ny][block - 1] = ans[x][y][block] + 1;	//벽을 뚫고 이전 최단거리에 1 더해준다
					q.push({ nx,ny,block - 1 });
				}
				else if (map[nx][ny] == 0 && !ans[nx][ny][block]) {	//벽이 없고, 방문하지 않았던 곳이라면
					ans[nx][ny][block] = ans[x][y][block] + 1;	//한칸 이동한다.
					q.push({ nx,ny,block });
				}
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {	//맵의 정보 입력
		string s; cin >> s;
		for (int k = 0; k < M; k++) {
			map[i][k] = s[k] - '0';
		}
	}
	bfs();
	
	int check1 = ans[N - 1][M - 1][0];
	int check2 = ans[N - 1][M - 1][1];
	
	if (!check1 && !check2) cout << -1;
	else cout << max(check1, check2);
}
