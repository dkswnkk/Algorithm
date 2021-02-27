//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10816
//  BOJ10816 숫자카드 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	vector<int>v;
	for (int i = 0; i < N; i++) {
		int number; cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	int ans;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int target; cin >> target;
		auto upper = upper_bound(v.begin(), v.end(), target);
		auto lower = lower_bound(v.begin(), v.end(), target);
		ans = upper - lower;
		cout << ans << " ";
		}
	}
