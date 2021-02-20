//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15649
//  BOJ15649 N과 M(1)

#include <iostream>
#include <vector>
#define max 9
using namespace std;


int arr[max];
bool visited[max];
int N, M;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[cnt] = i;
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	dfs(0);
}