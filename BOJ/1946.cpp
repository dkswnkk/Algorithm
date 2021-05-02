//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/1946
//  BOJ1946 신입사원

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int cnt = 0;
		vector<pair<int, int>>v;
		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end(), cmp);
		
		int ans = 1; //젤 첫사람은 무조건 합격;
		int temp = v[0].second;
		for (int i = 1; i < N; i++) {
			if (v[i].second < temp) {
				ans++;
				temp = v[i].second;
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
}