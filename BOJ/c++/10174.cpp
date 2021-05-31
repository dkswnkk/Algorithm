//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10174
//  BOJ10174 팰린드롬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	cin.ignore();
	while (N--) {
		string s; 
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int start = 0;
		int end = s.length() - 1;
		bool flag = true;
		while (start <= end) {
			if (s[start] != s[end]) flag = false;
			start++;
			end--;
		}
		if (flag) cout << "Yes"<<"\n";
		else cout << "No"<<"\n";
	}
}
