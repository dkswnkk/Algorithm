//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2902
//  BOJ2902 KMP는 왜 KMP일까?
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	vector<char>v(s.length());
	cout << s[0];
	for (int i = 1; i <= s.length()-1; i++) {
		if (s[i] == '-') cout<<s[i+1];
	}

}