//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1157
//  BOJ1157 단어 공부
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	vector<char>alphabet = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	vector<int>check(26);
	vector<int> cnt_check(26);
	transform(s.begin(), s.end(), s.begin(), ::toupper);

	for (int i = 0; i < s.length(); i++) {
		for (int k = 0; k < alphabet.size(); k++) {
			if (s[i] == alphabet[k]) {			
				check[k]++;
				cnt_check[k]++;
				break;
			}
		}

	}
	sort(cnt_check.begin(), cnt_check.end(), greater<int>());
	if (cnt_check[0] == cnt_check[1]) cout << '?';	//가장 많이 사용된 알파벳이 여러 개 존재하는 경우
	else {
		int max_index = max_element(check.begin(), check.end()) - check.begin();
		cout << alphabet[max_index];
	}
}
