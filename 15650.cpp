//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15650
//  BOJ15650 N과 M (2) 

#include <iostream>
#include <vector>
#define max 9
using namespace std;

int N, M;
int arr[max];
bool visited[max];

void dfs(int num,int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = num; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[start] = i;
				dfs(i,start + 1);
				visited[i] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	dfs(1,0);
}