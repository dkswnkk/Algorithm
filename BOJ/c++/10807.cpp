//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/10807
//  BOJ10807 개수 세기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N,check; cin >> N;
	vector<int>v;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	cin >> check;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] == check) cnt++;
	}
	cout << cnt;
}