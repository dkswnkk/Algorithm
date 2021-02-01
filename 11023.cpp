//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11023
//  BOJ11023 더하기 3

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int ans = 0;
	while (cin >> n) {
		ans += n;
	}
	cout << ans;
}