//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10988
//  BOJ10988 팰린드롬인지 확인하기

#include <iostream>
using namespace std;

int main() {
	string s; cin >> s;
	int N = s.length();
	int start = 0;
	int end = s.length()-1;
	bool flag = true;
	while (start <= end) {
		if (s[start] != s[end]) flag = false;
		start++;
		end--;
	}
	if (flag) cout << "1";
	else cout << "0";
}