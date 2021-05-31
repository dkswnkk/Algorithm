//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15663
//  BOJ15663 N과 M(9)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 9

using namespace std;

int N, M;
int arr[max];
bool visited[max];
vector<int>v;

void dfs(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		int check = -1;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]&&v[i-1]!=check) {
				visited[i] = true;
				check = v[i - 1];
				arr[start] = v[i - 1];
				dfs(start + 1);
				visited[i]=false;
			}
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
