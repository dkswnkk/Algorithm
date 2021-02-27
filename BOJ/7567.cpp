//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/7567
//  BOJ7567 그릇
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;

	int cnt = 10;
	char check = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == check) {
			cnt += 5;
			check = s[i];
		}
		else {
			cnt += 10;
			check = s[i];
		}
 	}
	cout << cnt;
	
}