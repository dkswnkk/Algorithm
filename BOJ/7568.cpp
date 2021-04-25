//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/7568
//  BOJ7568 덩치

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>>v;


	int rank = 1;

	for (int i = 0; i < n; i++) {	//덩치삽입
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < v.size(); k++) {
			if (v[i].first < v[k].first && v[i].second < v[k].second) rank++;	//자기 보다 덩치 큰 사람이 있으면 순위 +1
		}
		cout << rank << ' ';
		rank = 1;
	}
}