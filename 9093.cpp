//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/9093
//  BOJ9093 단어뒤집기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string s; getline(cin, s);
		string temp;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				reverse(temp.begin(), temp.end());
				cout << temp << ' ';
				temp.clear();
			}
			else temp += s[i];
		}
		reverse(temp.begin(), temp.end());
		cout << temp << "\n";
	}
}