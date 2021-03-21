//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/10162
//  BOJ10162 전자레인지

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int>v(3), ans;
	v[0] = 300; v[1] = 60; v[2] = 10;

	int T; cin >> T;

	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		cnt = T / v[i];
		T -= cnt * v[i];
		ans.push_back(cnt);
	}

	if (T != 0) cout << -1;
	else {
		for (int i : ans) {
			cout << i << " ";
		}
	}
}
