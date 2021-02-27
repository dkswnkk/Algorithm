//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1926
//  BOJ1926 그림

#include <iostream>
#include <queue>

using namespace std;

int n, m,drawNum,area,temp; //n=가로길이 m=세로길이 drawNum=그림의개수 area=그림의 넓이
int map[501][501];
int visited[501][501];
int dx[] = { 1,-1,0,0 };	//동 서 남 북 
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;


void bfs(int x,int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		temp++;
		int x = q.front().first;
		int y = q.front().second;
		cout<<x<<' '<<y<<"\n";
		q.pop();

		
		for (int i = 0; i < 4; i++) {	//동 서 남 북 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {	//도화지 범위를 넘어가지 않고
				if (map[nx][ny] == 1 && visited[nx][ny] == 0) {	//주변 그림정보가 1이고 방문하지 않았을때
					visited[nx][ny] = 1;	//방문처리하고 
					q.push({ nx,ny });	//그 주변에 그림정보1이 더 있는지 탐색
				}

			}
		}
		
	}
	area = max(area, temp);
	temp = 0;


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {	//도화지 정보 입력
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (!visited[i][k] && map[i][k]) {	//방문하지 않았거나 도화지 정보가 1이면
				bfs(i, k);
				drawNum++;
			}
		}
	}
	cout << drawNum<<"\n"<<area;
}
