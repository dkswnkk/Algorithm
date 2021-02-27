//  Copyright © 2021 안주형. All rights reserved.
//  DFS알고리즘
//  https://www.acmicpc.net/problem/2606
//  BOJ2606 바이러스
#include <iostream>
using namespace std;

int map[5001][5001];
int visited[101];
int cnt = 0;
int com_cnt, com;

void dfs(int n) {
	visited[n] = 1;

	for (int i = 1; i <=com_cnt; i++) {
		if (!visited[i] && map[n][i]) {
			visited[i] = 1;
			dfs(i);
			cnt++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> com_cnt;
	cin >> com;

	for (int i = 0; i < com; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;

	}
	dfs(1);
	cout << cnt;


}