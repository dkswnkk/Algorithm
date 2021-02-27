//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1032
//  BOJ1032 명령 프롬프트
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	string check; cin >> check;
	string temp = check;
	for (int i = 0; i < N-1; i++) {
		string s; cin >> s;
		for (int k = 0; k < check.length(); k++) {
			if (check[k] != s[k]) {
				temp[k] = '?';
			}
		}
	}
	cout << temp;
}