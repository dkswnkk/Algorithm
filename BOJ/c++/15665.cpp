//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15665
//  BOJ15665 N과 M(11)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 8

using namespace std;

int N, M;
int arr[max];
bool visited[max];
vector<int>v;

void dfs(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= v.size()-1; i++) {		
				arr[start] = v[i - 1];
				dfs(start + 1);	
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
	v.erase(unique(v.begin(), v.end()), v.end()-1);
	dfs(0);

}