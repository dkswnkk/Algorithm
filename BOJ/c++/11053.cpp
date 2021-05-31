//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/11053
//  BOJ11053 가장 긴 증가하는 부분 수열(Longest Increasing Subsequence,Lis) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr(1001);
vector<int>dp(1001,1);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];				//수열 입력.
	}

	for (int i = 1; i < N; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k]) dp[i] = max(dp[i], dp[k] + 1);	//수열 탐색
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}
