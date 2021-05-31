//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11557
//  BOJ11557 Yangjojang of The Year

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	
	while (T--) {
		int N; cin >> N;
		vector<pair<int, string>> v;
		for (int i = 0; i < N; i++) {
			string S; int L; cin >> S >> L;
			v.push_back({ L,S });
		}
		sort(v.begin(), v.end(), greater<>());
		cout << v.front().second<<"\n";
	}
}