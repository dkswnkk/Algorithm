//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/9095
//  BOJ9095 1,2,3 더하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> dp(12);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int T, num;
	cin >> T;
	while (T--) {
		cin >> num;
		for (int i = 4; i <= num; i++) {
			dp[i] = dp[i - 1] + dp[i - 2]+dp[i-3];
		}
	cout << dp[num]<<"\n";

	}
}