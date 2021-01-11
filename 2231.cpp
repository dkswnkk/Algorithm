//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2231
//  BOJ2231 분해합

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int check = N;
	vector<int>v;
	while (N--) {
		if (N > 0 && N < 10) {	//1~9일때
			if (N + N == check) {
				v.push_back(N);
			}
		}
		else if (N >= 10 && N < 100) {	//10~99 일때
			if (N / 10 + N % 10 + N == check) {
				v.push_back(N);
			}
		}
		else if (N >= 100 && N < 1000) {	//100~999 일때
			if (N / 100 + N % 10 + N % 100 / 10 + N == check) {
				v.push_back(N);
			}
		}
		else if (N >= 1000 && N < 10000) {	//1000~9999 일때
			if (N / 1000 + N % 1000 / 100 + N % 1000 % 100 / 10 + N % 1000 % 100 % 10 + N == check) {
				v.push_back(N);
			}
		}
		else if (N >= 10000 && N < 100000) {	//10000~99999 일때
			if (N / 10000 + N % 10000 / 1000 + N % 10000 % 1000 / 100 + N % 10000 % 1000 % 100 / 10 + N % 10000 % 1000 % 100 % 10 + N == check) {
				v.push_back(N);
			}
		}
		else if (N >= 100000 && N < 1000000) {	//100000~99999 일때
			if (N / 100000 + N % 100000 / 10000 + N % 100000 % 10000 / 1000 + N % 100000 % 10000 % 1000 / 100 + N % 100000 % 10000 % 1000 % 100 / 10 + N % 100000 % 10000 % 1000 % 100 % 10 + N == check) {
				v.push_back(N);
			}
		}
	}
		sort(v.begin(), v.end());
		if (v.empty()) cout << 0;
		else cout << v[0];
}