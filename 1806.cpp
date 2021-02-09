//  Copyright © 2021 안주형. All rights reserved.
//  투포인터 알고리즘
//  https://www.acmicpc.net/problem/1806
//  BOJ1806 부분합 
#include <iostream>
#include <vector>
#include <cmath>
#define INF 1e9
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, S; cin >> N >> S;
	vector<int>v(N+1);

	for (int i = 0; i < N; i++) {	//수열 삽입
		cin >> v[i];		
	}

	int left = 0, right = 0;
	int sum = v[0];
	int ans = INF;

	while (left<=right&&right<N) {
		if (sum < S) sum += v[++right];
		else if (sum == S) {
			ans = min(ans, (right - left + 1));
			sum += v[++right];
		}
		else if (sum > S) {
			ans = min(ans, (right - left + 1));
			sum -= v[left++];
		}
	}
	if (ans == INF) cout << 0;
	else cout << ans;
	
}