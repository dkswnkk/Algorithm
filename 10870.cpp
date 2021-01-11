//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/10870
//  BOJ10870 피보나치 수5
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long int> dp(100);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	
	

}