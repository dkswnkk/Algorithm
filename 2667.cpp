//  Copyright © 2021 안주형. All rights reserved.
//  dfs알고리즘
//  https://www.acmicpc.net/problem/2667
//  BOJ2667 단지번호붙이기
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N; //지도의 크기 (정사각형)
int map[26][26];
int visited[26][26];
int dy[] = { -1,1,0,0 }; //상 하 좌 우
int dx[] = { 0,0,-1,1 }; 
int cnt = 0; // 단지 수
int house_cnt;
vector<int> house; //단지 내 집의 수

void dfs(int x, int y) {
	house_cnt++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] && !visited[nx][ny]) { //번지수 1이고, 방문안했으면
				visited[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}

int main() {


	cin >> N;

		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				scanf_s("%1d", &map[i][k]); //단지 번호 입력
			}
		}
		for(int i=0; i<N; i++){
			for (int k = 0; k < N; k++) { //단지 탐색
				if (map[i][k] && !visited[i][k]) {
					house_cnt = 0;
					dfs(i, k);
					house.push_back(house_cnt);
				}
			}
	}
		sort(house.begin(), house.end());
		cout << house.size() << "\n";
		for (int i : house) {
			cout << i << "\n";
		}

}