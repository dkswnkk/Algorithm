//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2559
//  BOJ2559 수열

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M; cin >> N >> M;
	vector<int>v(N+1);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		sum += num;
		v[i + 1] = sum;		
	}
	int ans = -1e9;

	for (int i =M; i <= N; i++) {
		ans = max(ans, v[i] - v[i - M]);

	}
	cout << ans;
}