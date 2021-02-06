//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10988
//  BOJ10988 팰린드롬인지 확인하기

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	bool flag = true;
	
	if (s.length() % 2 != 0) {	//길이가 홀수일떄
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - i-1]) flag = false;
		}
	}
	else {	//길이가 짝수일때
		if (s[s.length() / 2-1] == s[s.length() / 2]) {
			for (int i = 0; i < s.length() / 2; i++) {
				if (s[i] != s[s.length() - i-1]) flag = false;
			}
		}
		else flag = false;

	}
	if (flag) cout << "1";
	else cout << "0";
}