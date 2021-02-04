//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/16212
//  BOJ16212 정열적인 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v;
	int N; cin >> N;
	while (N--) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << ' ';
	}
}