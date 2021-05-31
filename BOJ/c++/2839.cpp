//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/2839
//  BOJ2839 설탕배달
#include <iostream>
#include <vector>

	
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int N; cin >> N;

	vector<int>dp(N+1,5001);	//만들지 못하는 메모이제이션들을 최대값으로 저장,
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {	//Bottom-up 동적계획법
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	if (dp[N] >= 5001) {
		cout << -1;
	}
	else {
		cout << dp[N];
	}
}