//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/2579
//  BOJ2579 계단 오르기
#include <iostream>
#include <vector>

using namespace std;
vector<int>dp(301);
vector<int>arr(301);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;

	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}
	dp[0] = 0; dp[1] = arr[1];
	dp[2] = dp[1] + arr[2]; //첫 계단 밟았을 경우 dp[2]가 사용됨. 

	for (int i = 3; i <= N; i++) {
//		arr[i] + arr[i - 1] + dp[i - 3] => 마지막 전의 계단을 밟은 경우.
//		arr[i] + dp[i - 2] ==> 마지막 전전 계단을 밟은 경우.
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
	}
	cout << dp[N];


		
}