//  Copyright © 2021 안주형. All rights reserved.
//  bfs알고리즘
//  https://www.acmicpc.net/problem/2178
//  BOJ2178 미로탐색

#include <iostream>
#include <queue>

using namespace std;
int N, M;
int map[101][101];
// 이동할 네가지 방향(상.하,좌,우)
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {  //현재 위치에서 상 하 좌 우 위치 확인
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > N || ny < 0 || ny > M) continue; // 미로 공간 벗어난 경우 무시
				if (map[nx][ny] == 0) continue; // 못가는 경우 무시
				if (map[nx][ny] == 1) { //갈수있는 곳일때 처음방문하는 경우 거리 기록
					map[nx][ny] = map[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		
	}
	return map[N-1][M-1]; //최단거리 반환
}
	int main() {
	cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				scanf_s("%1d", &map[i][k]); //하나씩 입력받아 넣음.
			}
		}
		cout<<bfs(0,0);
	}



