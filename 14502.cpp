//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/14502
//  BOJ14502 연구소
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M, ans; //N=세로크기, M=가로크기, ans=안전 영역의 크기
int map[9][9];
int cpy[9][9];
int virus[9][9];
int dx[] = { -1,1,0,0 };	//동 서 남 북
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;

void bfs() {
	memcpy(virus, cpy, sizeof(cpy));	//cpy로 바이러스를 퍼트리면 다음 벽조합을 세울때 초기화가 안되니 다른 배열에 복사.

	for (int i = 0; i < N; i++) {	//현재 연구실에 있는 바이러스의 위치를 탐색한다
		for (int k = 0; k < M; k++) {
			if (virus[i][k] == 2) q.push({ i,k });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {	//동서남북 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { //연구실의 범위를 벗어나지 않을때	
				if (virus[nx][ny] == 0) {	//빈칸이면
					virus[nx][ny] = 2;	//그 부분은 바이러스로 퍼진다
					q.push({ nx,ny });

				}
			}
		}
	}
	int ans_check = 0;
	for (int i = 0; i < N; i++) {	//안전 영역의 크기를 구한다.
		for (int k = 0; k < M; k++) {
			if (virus[i][k] == 0) ans_check++;
		}
	}
	ans = max(ans, ans_check);	//안전 영역 크기의 최댓값 저장.
}


void wall(int cnt) {
	if (cnt == 3) {	//벽을 다 세웠으면 bfs 탐색을 통해 안전구역의 크기를 찾는다.
		bfs();
	}
	else {
		for (int i = 0; i < N; i++) {	//두번째 벽부터 세운다.
			for (int k = 0; k < M; k++) {
				if (cpy[i][k] == 0) {	//빈칸을 발견하면
					cpy[i][k] = 1;	//벽을 세우고
					wall(cnt + 1);	//세번째 벽을 세우기 위해 재귀를 호출.
					cpy[i][k] = 0;	//두번째 벽을 다음 조합으로 세운다.
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {	//연구실 정보 입력
		for (int k = 0; k < M; k++) {
			cin >> map[i][k];
		}
	}



	for (int i = 0; i < N; i++) {	//벽을 세우는 부분
		for (int k = 0; k < M; k++) {
			if (map[i][k] == 0) {	//빈칸을 발견하면
				memcpy(cpy, map, sizeof(map));	//연구실 정보를 복사하고
				cpy[i][k] = 1;	//첫번째 벽을세우고
				wall(1);	//나머지 두개의 벽을 재귀로 세운다.
				cpy[i][k] = 0;	//첫번째 벽을 다음 조합으로 시작한다.
			}
		}
	}
	cout << ans;
}