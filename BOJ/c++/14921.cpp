//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/14921
//  BOJ14921 용액합성하기

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9+1

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int start = 0; 
	int end = N - 1;
	int minValue = INF;
	int check,ans;
	while (start < end) {
		check = abs(v[start] + v[end]);
		if (check < minValue) {
			minValue = check;
			ans = v[start] + v[end];
		}
		if (v[start] + v[end] < 0) start++;
		else end--;
	}
	cout << ans;

}