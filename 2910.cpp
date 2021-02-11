//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2910
//  BOJ2910 빈도 정렬
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int>m;
vector<pair<int,int>>v;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return m[a.second]<m[b.second];
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, C; cin >> N >> C;


	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		m[num]++;
	}
	int ans = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		v.push_back({ i->second,i->first });
		}
	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < v[i].first; k++) {
			cout << v[i].second << ' ';
		}
	}
}
