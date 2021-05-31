//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1931
//  BOJ1931 회의실 배정

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first< b.first;
	else return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>>v;
	int N; cin >> N;

	while (N--) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);


	int start = v[0].second;
	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (start <= v[i].first) {
			cnt++;
			start = v[i].second;
		}
	}
	cout << cnt;
}