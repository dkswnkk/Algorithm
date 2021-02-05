//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1929
//  BOJ1929 소수 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N; cin >> M >> N;
	vector<bool>v(N + 1, true);
	v[0] = v[1] = false;
	for(int i=2; i<=N; i++){
		if (v[i] == true) {
			int j = 2;
			while (i * j <= N) {
				v[i * j] = false;
				j++;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (v[i] == true) cout << i << "\n";
	}

}