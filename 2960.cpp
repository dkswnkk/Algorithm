//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2960
//  BOJ2960 에라토스테네스의 체

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, K; cin >> N >> K;
	vector<int>ans;
	vector<bool>v(N + 1, true);
	for (int i = 2; i <= N; i++) {
		if (v[i] == true) {
			int j = 1;
			while (i * j <= N) {
				if (v[i * j] == false) {
					j++;
				}
				else {
					v[i * j] = false;
					ans.push_back(i * j);
					j++;
				}
			}

		}
	}
	cout << ans[K-1];
}