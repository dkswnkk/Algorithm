//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2217
//  BOJ2217 로프

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<int>v;
	

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int ans = 3;
	int cnt = N;
	for (int i = 0; i < N; i++) {
		ans = max(ans, v[i]*cnt);
		cnt--;
	 	}
		cout << ans;
	}


	
