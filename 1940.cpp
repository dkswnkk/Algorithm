//  Copyright © 2021 안주형. All rights reserved.
//  투포인터 알고리즘
//  https://www.acmicpc.net/problem/1940
//  BOJ1940 주몽

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; cin >> N >> M;
	int cnt = 0;
	vector<int>v;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

		int start = 0;
		int end = N - 1;
		while (start < end) {
			if (v[start] + v[end] == M) {
				start++; end--;
				cnt++;
			}
			else if (v[start] + v[end] < M) start++;
			else end--;	//v[start]+v[end]>M;
		}
	
	cout << cnt;

}
