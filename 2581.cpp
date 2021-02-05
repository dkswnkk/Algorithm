//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2581
//  BOJ2581 소수

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N; cin >> M >> N;
	int min = 1e4, ans = 0;
	vector<int>v(N + 1, true);

	for (int i = 2; i <= N; i++) {
		if (v[i] == true) {
			if (i >= M) ans += i;
			if (i <= min&&i>=M) min = i;
			int j = 2;
			while (i * j<=N) {
				v[i * j] = false;
				j++;
			}
		}
	}
	if (ans == 0) cout << -1;
	else cout << ans << "\n" << min;
}
