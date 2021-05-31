//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/11722
//  BOJ11722 가장 긴 감소하는 부분 수열(Longest decreasing Subsequence,Lds

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
수열을 역순으로 생각하여 가장 긴 증가하는 부분 수열을 구하게 되면 된다.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>arr(N);
	vector<int>dp(1001,1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	reverse(arr.begin(), arr.end());	//수열을 역순으로 바꾼다.
	
	for (int i = 1; i < N; i++) {		//가장 긴 증가하는 부분수열을 구한다.
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k]) dp[i] = max(dp[i], dp[k] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end());	
	
}