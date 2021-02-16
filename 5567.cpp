//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/5567
//  BOJ5567 결혼식

#include <iostream>
#include <queue>

using namespace std;

int n, m;	//n=동기의 수 , m=리스트의 길이
int map[501][501];
int visited[501];
int ans;
queue<int>q;

void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && map[x][i]) {
				visited[i] = 1;
				ans++;
			}
		}
	}

}
int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {	//간선 연결
		int a, b; cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
		if (a == 1) {
			q.push(b);
			visited[b] = 1;
			ans++;
		}
		if (b == 1) {
			q.push(a);
			visited[a] = 1;
			ans++;
		}
	}
	
	bfs();
	cout << ans - 1;
}