//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1493
//  BOJ1493 뒤집기

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	int zero = 0, one = 0;
	bool flag = true;

	for (int i = 0; i < s.length() - 1; i++) {	 //연속된 수 갯수 체크
		if (s[i] == '0') {
			if (flag) zero++;
			flag = false;
		}
		if (s[i] == '1') {
			if (!flag) one++;
			flag = true;
		}
	}
	cout << min(zero, one);

}