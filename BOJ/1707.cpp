//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1707
//  BOJ1707 이분 그래프

#include <iostream>
#include <vector>
#include <memory.h>
#define max 20001

using namespace std;

vector<int> graph[max];
int visited[max];	//0=방문x, 1=빨강, 2=파랑
int V, E;	//V=정점의 개수, E=간선의 개수


void dfs(int start) {
	if (!visited[start]) visited[start] = 1;	//방문하지 않았다면 빨강색으로 처리

	for (int i = 0; i < graph[start].size(); i++) {	//현재 노드랑 연결되어있는 노드만큼 탐색
		int neighbor = graph[start][i];
		if (!visited[neighbor]) {
			if (visited[start] == 1) visited[neighbor] = 2;
			else if (visited[start] == 2) visited[neighbor] = 1;
			dfs(neighbor);
		}
	}
}

bool check() {
	for (int i = 1; i <= V; i++) {
		for (int k = 0; k < graph[i].size(); k++) {
			if (visited[i] == visited[graph[i][k]]) {
				return 0;	//현재 노드랑 연결된 노드의 색깔이 같다면 이분그래프X
			}
		}
	}
	return 1;
}

void reset() {	//초기화 함수
	for (int i = 0; i < max; i++) {
		graph[i].clear();
	}
	memset(visited, 0, sizeof(visited));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {	//간선 정보 입력
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {	//dfs탐색
			if (!visited[i]) dfs(i);	
		}


		if (check()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		reset();
	}

}