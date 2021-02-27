//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2204
//  BOJ2204 도비의 난독증 테스트
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		int n; cin >> n;
		if (n == 0) return 0;
		vector<string>v;
		map<string, string>m;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			string original = s;
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			m.insert({ original, s });
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (auto k = m.begin(); k != m.end(); k++) {
			if (v[0] == k->second) {
				cout << k->first << "\n";
				break;
			}
		}

	}
}