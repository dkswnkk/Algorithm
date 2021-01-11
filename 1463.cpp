//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/1463
//  BOJ1463 1로 만들기
#include <iostream>
#include <vector>
using namespace std;

vector<int>dp(1e7);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;	//현재의 수에서 1을 빼는 경우
		if(i% 2 ==0 ) dp[i] = min(dp[i], dp[i / 2] + 1);	//현재의 수가 2로 나누어 떨어지는 경우
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);	//현재의 수가 3으로 나누어 떨어지는 경우
	}
	cout << dp[N];
}