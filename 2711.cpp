//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2711
//  BOJ2711 오타맨 고창영
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int num; string s; cin >> num >> s;
		for (int i = 0; i < s.length(); i++) {
			if (i == num-1) continue;
			cout << s[i];
		}
		cout << "\n";
	}
}