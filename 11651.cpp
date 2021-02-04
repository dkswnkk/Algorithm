//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11651
//  BOJ11651 좌표 정렬하기2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	vector<pair<int, int>>v;
	while (N--) {
		int x, y; cin >> x >> y;
		v.push_back({ x,y });		
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << "\n";
	}
	
}