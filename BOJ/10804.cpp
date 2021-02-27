//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10804
//  BOJ10804 카드 역배치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v(21);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 20; i++) {
		v[i] = i;
	}

	for (int i = 1; i <= 10; i++) {
		int a, b; cin >> a >> b;
		reverse(v.begin() + a, v.end() - 21 + b+1);
	}

	for (int i = 1; i <= 20; i++) {
		cout << v[i] << ' ';
	}
}