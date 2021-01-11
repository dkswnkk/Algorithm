//  Copyright © 2021 안주형. All rights reserved.
//  그리디알고리즘
//  https://www.acmicpc.net/problem/11047
//  BOJ11047 동전2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	
int main() {
	ios_base::sync_with_stdio(false);
	int T, K; //T=테스트 케이스 K=가격 
	int cnt = 0; //cnt=동전 갯수 최소값
	vector<int> v;
	cin >> T >> K;

	while (T--) {
		int N; // 동전 종류
		cin >> N;
		v.push_back(N);
	}
	sort(v.begin(), v.end(),greater<int>());
	
	for (int i = 0; i < v.size(); i++) {
		 if (K == 0) break;
		else if (K >= v[i]) {
			cnt += K / v[i];
			K %= v[i];
		}
	}
	cout << cnt;
	
}