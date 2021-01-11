//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10814
//  BOJ10814 나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(pair<int,string>x ,pair<int,string>y) {
	return (x.first < y.first);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, string>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

}