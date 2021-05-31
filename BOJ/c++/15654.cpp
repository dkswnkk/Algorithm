//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15654
//  BOJ15654 N과 M (5)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 9
using namespace std;

int N, M;
int arr[max];
bool visited[max];
vector<int>temp;

void dfs(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[start] = temp[i];
				dfs(start + 1);
				visited[i] = false;
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
		temp.push_back(num);
	}
	sort(temp.begin(), temp.end());
	dfs(0);

}