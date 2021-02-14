//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/10972
//  BOJ10972 다음 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	bool flag = next_permutation(v.begin(), v.end());

	if (flag) {
		for (int i : v) {
			cout << i << ' ';
		}
	}
	else cout << -1;
}