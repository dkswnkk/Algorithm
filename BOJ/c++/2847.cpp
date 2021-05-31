//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2847
//  BOJ2847 게임을 만든 동준이

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);

	for (int i = 0; i < N; i++) {
		cin>>v[i];
	}
	int cnt = 0;

	for (int i = N-1; i > 0; i--) {
		while (v[i]<=v[i-1]) {
			cnt++;
			v[i - 1]--;

		}
	}
	cout << cnt;
}

