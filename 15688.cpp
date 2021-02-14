//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/15688
//  BOJ15688 수 정렬하기5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v;
	while (N--) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << '\n';
	}
}