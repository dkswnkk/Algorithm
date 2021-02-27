//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/12738
//  BOJ12738 가장 긴 증가하는 부분 수열3(Longest Increasing Subsequence,Lis)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<long long>v;
	v.push_back(-1e9);	//입력 받을 수 있는 최솟값
	for (int i = 0; i < N; i++) {
		long long  number; cin >> number;
		if (v.back() < number) v.push_back(number);
		else {
			auto it = lower_bound(v.begin(), v.end(), number);
			*it = number;
		}
	}
	cout << v.size() - 1;
}