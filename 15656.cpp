//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15656
//  BOJ15656 N과 M(7)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 8

using namespace std;

bool visited[max];
int arr[max];
int N, M;
vector<int>v;

void dfs(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			visited[i] = true;
			arr[start] = v[i];
			dfs(start + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	dfs(0);
}