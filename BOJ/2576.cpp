//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2576
//  BOJ2576 홀수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	vector<int>v;
	for (int i = 0; i < 7; i++) {
		int N; cin >> N;
		if (N % 2 != 0) {
			v.push_back(N);
			sum += N;
		}
	}
	sort(v.begin(), v.end());
	if (v.empty()) cout << -1;
	else cout << sum << "\n" << v[0];
	

}