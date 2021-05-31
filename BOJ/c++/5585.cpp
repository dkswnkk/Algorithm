//  Copyright © 2021 안주형. All rights reserved.
//  그리디 알고리즘
//  https://www.acmicpc.net/problem/5585
//  BOJ5585 거스름돈
#include <iostream>
#include <vector>

using namespace std;
vector<int>v = { 500,100,50,10,5,1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int change = 1000 - N;
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += change / v[i];
		change = change % v[i];
		if (change == 0) break;
	}

	cout << ans;
	
}