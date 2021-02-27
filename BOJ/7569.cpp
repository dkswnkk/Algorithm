//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/7569
//  BOJ7569 토마토

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H, cnt; //M=상자의 가로 칸의 수, N=상자의 세로 칸의 수, H=쌓아 올려지는 상자의 수, cnt=토마토 익는 날짜
int visited[101][101][101];
int map[101][101][101];
bool flag = true;
queue<tuple<int, int, int>>q;

int dx[] = { 1,-1,0,0,0,0 };	//동 서 남 북 상 하
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

bool check(int z, int y, int x) {
	if (x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H) return true;
	else return false;
}

void bfs() {
	while (!q.empty()) {
		int z = get<0>(q.front());	//높이
		int y = get<1>(q.front());	//세로
		int x = get<2>(q.front());	//가로
		visited[z][y][x] = 1;
		q.pop();

		for (int i = 0; i < 6; i++) {	//동 서 남 북 상 하 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (check(nz, ny, nx) && !visited[nz][ny][nx]) {	//박스의 범위를 넘어서지 않고 방문하지 않았을때	
				if (map[nz][ny][nx] == 0) {
					map[nz][ny][nx] = map[z][y][x] + 1; //토마토가 익지 않았으면 익게 만들고 이전 토마토의 익은 날짜수에 1을 더해준다.
					visited[nz][ny][nx] = 1;	//방문처리
					q.push({ nz,ny,nx });	//익은 토마토를 다시 q에 넣고 탐색	
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> H;	//가로 세로 높이

	for (int h = 0; h < H; h++) {	//상자안의 토마토 정보 삽입
		for (int i = 0; i < N; i++) {	//세로
			for (int k = 0; k < M; k++) {	//가로
				cin >> map[h][i][k];
				if (map[h][i][k] == 1) q.push({ h,i,k });	//토마토가 익었을때만 큐에 삽입
				if (map[h][i][k] == -1) visited[h][i][k] = 1;	//토마토가 들어있지 않는 칸이면 방문처리
			}
		}
	}

	bfs();

	int ans = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (map[h][i][k] == 0) {
					cout << -1;	//안익은 토마토가 하나라도 있으면 -1 출력하고 종료
					return 0;
				}
				else ans = max(ans, map[h][i][k]);
			}
		}
	}

	cout << ans - 1;
}
