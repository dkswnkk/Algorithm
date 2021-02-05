//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/4948
//  BOJ4948 베트르랑 공준

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		int N; cin >> N;
		if (N == 0) return 0;
		vector<int>v(246913, true);
		int cnt = 0;	
		for (int i = 2; i <= 2*N; i++) {
			if (v[i] == true) {
				if (i >N) cnt++;
				int j = 2;
				while (i * j <= 2 * N) {
					v[i * j] = false;
					j++;
				}
			}
		}
		cout << cnt<<"\n";
	}
}