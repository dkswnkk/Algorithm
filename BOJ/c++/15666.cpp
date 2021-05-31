//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15666
//  BOJ15666 N과 M(12)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 8

using namespace std;

int N, M;
int arr[max];
bool visited[max];
vector<int>v;

void dfs(int num, int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = num; i <= v.size() - 1; i++) {
			arr[start] = v[i - 1];
			dfs(i,start + 1);
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
	v.erase(unique(v.begin(), v.end()), v.end() - 1);
	dfs(1,0);

}