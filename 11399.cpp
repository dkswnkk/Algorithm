//  Copyright © 2021 안주형. All rights reserved.
//  그리디 알고리즘
//  https://www.acmicpc.net/problem/11399
//  BOJ11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v;
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int cnt = N;
	for (int i = 0; i < N; i++) {
		int number; cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++ ) {	
		ans+=v[i] * cnt;	// ex) N=5일때 1x5, 2x4, 3x3, 4x2, 5x1
		cnt--;
	}
	cout << ans;
}