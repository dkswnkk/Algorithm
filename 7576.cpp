//  Copyright © 2021 안주형. All rights reserved.
//  bfs알고리즘
//  https://www.acmicpc.net/problem/7576
//  BOJ7576 토마토
#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
bool check = true;
int dy[] = { -1,1,0,0 }; //상 하 좌 우 
int dx[] = { 0,0,-1,1 };
int M, N; //M=가로 칸  , N=세로 칸
int ans = 0;
queue<pair<int, int>>q;

void bfs(){
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) { //상 하 좌 우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // 상자 범위를 넘어가지 않고
				if (map[nx][ny] == 0) {					// 토마토가 익지 않았을때.
					map[nx][ny] = map[x][y] + 1;		// 익게만든다 .
					q.push({ nx,ny });					//익은 토마토 다시 큐에 넣고 탐색
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> M >> N;

	for (int i = 0; i < N; i++) { //토마토 상태 삽입
		for (int k = 0; k < M; k++) {
			cin >> map[i][k];
			if (map[i][k]==1) {		// 토마토가 익었을떄에만 bfs 실행하기 위해 push.
				q.push({ i,k });
			}
		}
	}
	bfs();
		 
		
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (map[i][k] == 0) {	//익지 않은 토마토가 존재할때 -1 출력
					check = false;		//고립된 토마토가 있을수 있으니 . 예외처리
					cout << "-1" << "\n"; 
					exit(0);	//-1이 여러번 출력되는 경우 방지
					
				}
				if (ans < map[i][k]) ans = map[i][k];
			}
			
		}
		if(check) cout << ans-1;
}