//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2665
//  BOJ2665 미로만들기

#include <iostream>
#include <queue>
#include <memory.h>
#define INF 1e9	//무한을 의미하는 값으로 10억을 지정

using namespace std;

int n; //n=바둑판 크기
int visited[51][51];
int map[51][51];
int dx[] = { 1,-1,0,0 };	//동 서 남 북
int dy[] = { 0,0,1,-1 };

void reset() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			visited[i][k] = INF;
		}
	}
}

void bfs() {
	reset();
	queue<pair<int, int>>q;
	visited[0][0] = 0;	//시작점은 0으로 초기화
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {	//동 서 남 북 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {	//바둑판의 범위를 넘어가지 않을때
				if (map[nx][ny] == 1) {//다음 방이 흰 방일때
					if (visited[nx][ny] > visited[x][y]) {	//검은 방을 흰 방으로 교체하여 온 값이 저장되어 있는경우 지금 보다 값이 크기 때문에 지금 의 값으로 교체 
						visited[nx][ny] = visited[x][y];
						q.push({ nx,ny });
					}
				}
				else {	//다음 방이 검은 방인 경우
					if (visited[nx][ny] > visited[x][y] + 1) {	
						visited[nx][ny] = visited[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {	//바둑판 정보 입력 0=검은 방, 1=흰 방
		string s; cin >> s;
		for (int k = 0; k < n; k++) {
			map[i][k] = s[k] - '0';
		}
	}

	bfs();
	cout << visited[n - 1][n - 1];
}