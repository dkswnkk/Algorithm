//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15651
//  BOJ15650 N과 M (3) 
#include <iostream>
#include <vector>
#define max 8
using namespace std;

int N, M;
int arr[max];
bool visited[max];
void dfs(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			visited[i] = true;
			arr[start] = i;
			visited[i] = false;
			dfs(start + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	dfs(0);

}