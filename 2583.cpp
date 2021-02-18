//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2583
//  BOJ2583 영역 구하기

#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int M, N, K, cnt,temp;	//M=세로, N=가로, K=그리는 직사각형 갯수, cnt=영역의 갯수, temp=넓이
int map[101][101];
int visited[101][101];
int dx[] = { 0,0,-1,1 };	//상 하 좌 우
int dy[] = { -1,1,0,0 };

queue<pair<int, int>>q;
vector<int>ans;
void bfs(int a, int b) {
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		temp++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (!map[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
		ans.push_back(temp);
		temp = 0;


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {		//직사각형 부분을 1로 채운다.	
			for (int k = y1; k < y2; k++) {
				map[k][i] = 1;
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			if (map[i][k] == 0 && !visited[i][k]) {	
				bfs(i, k);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << ' ';		
	}
	
}