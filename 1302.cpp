//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1302
//  BOJ1302 베스트셀러

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map<string, int>m;
	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		m[s]++;		
	}
	int ans = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		ans = max(ans, i->second);	//가장 큰 값 찾기
	}
	for (auto k = m.begin(); k != m.end(); k++) {
		if (ans == k->second) {	//가장 큰 값이 있는 위치 찾기
			cout << k->first;
			return 0;
		}
	}
}