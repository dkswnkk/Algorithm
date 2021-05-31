//  Copyright © 2021 안주형. All rights reserved.
//
//  https://www.acmicpc.net/problem/1003
//  BOJ1003 피보나치 함수
#include <iostream>
#include <vector>

using namespace std;
int dp[41][2] = { {1,0},{0,1} };	// dp[0][0]=1; dp[0][0]=0; dp[1][0]=0; dp[1][1]=1;
									//num:0 일때 0이 출력되는경우 1개 1이 출력되는 경우0개
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 2; i <=N; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];	//0이 사용되는 갯수 저장
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];	//1이 사용되는  갯수 저장
		}
		cout << dp[N][0] << " " << dp[N][1] << "\n";
	}
}