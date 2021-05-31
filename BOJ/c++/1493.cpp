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
	int flag = -1;

	for (int i = 0; i < s.length(); i++) {	 //연속된 수 갯수 체크
		if (s[i] == '0') {
			if (flag != 1) zero++;
			flag = 1;
		}
		else if (s[i] == '1') {
			if (flag != 0) one++;
			flag = 0;
		}
	}
	cout << min(zero, one);

}