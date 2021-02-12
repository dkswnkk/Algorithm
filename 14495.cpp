//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/14495
//  BOJ14495 피보나치 비스무리한 수열
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll dp[200];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 0; dp[1] = 1; dp[2] = 1;

	int n; cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[n];
}