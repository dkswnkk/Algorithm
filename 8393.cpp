//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/8393
//  BOJ8393 합

#include <iostream>
#define ll long long 
using namespace std;
ll dp[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + i;
	}
	cout << dp[N];
	
}