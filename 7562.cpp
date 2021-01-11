//  Copyright © 2021 안주형. All rights reserved.
//  bfs알고리즘
//  https://www.acmicpc.net/problem/7562
//  BOJ7562 나이트의 이동
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>


using namespace std;
int map[301][301];
int dx[] = { -1,-1,-2,-2,1,1,2,2 };	//나이트가 갈수 있는 범위들
int dy[] = { -2,2,-1,1,-2,2,-1,1 };
int N;	//체스판 크기
int cnt = 0;
int end1, end2;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == end1 && y == end2) {		//도착점에 나이트가 있다면 종료,	
			cout << map[x][y]<<"\n";
			break;
		}
		for (int i = 0; i < 8; i++) {		//나이트 말 이동	
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {	//체스판의 범위를 넘어가지 않고
				if (map[nx][ny]==0) {						//아직 밟은 발판이 아닐때
					map[nx][ny] = map[x][y] + 1;			//나이트를 이동하고 이동한 횟수를 더해준다
					q.push({ nx,ny });						
				}

			}
		}
	}
}
void reset() {
	memset(map, 0, sizeof(map));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> N;
		int start1,start2 ; cin >> start1 >> start2;	//나이트 시작지점 삽입
		cin >> end1 >> end2;							//나이트 도착지점 삼입
		bfs(start1, start2);							//시작지점 부터 BFS 탐색
		reset();										//map 리셋
		}
	}
