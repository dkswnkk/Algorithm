//  Copyright © 2021 안주형. All rights reserved.
//  DFS,BFS 알고리즘
//  https://www.acmicpc.net/problem/1260
//  BOJ1260 DFS와 BFS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int visited[1001];
int map[1001][1001];
queue<int>q;
int N, M, V;

void dfs(int n) {
	visited[n] = 1; //현재 노드를 방문처리
	cout << n << ' ';
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && map[n][i]) {
			dfs(i);
		}
	}
}

void bfs(int n) {
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int x = q.front(); //큐에서 하나의 원소를 뽑아 출력
		q.pop();
		cout << x << ' ';
		for (int i = 1; i <=N; i++) {
			if (!visited[i] && map[x][i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}


int main() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) { // 간선 연결
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	bfs(V);
}