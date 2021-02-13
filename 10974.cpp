//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/10974
//  BOJ10974 모든 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	bool flag = true;
	vector<int>v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	while (flag) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
		cout << "\n";
	 flag=next_permutation(v.begin(), v.end());	//다음 순열이 없으면 false 반환.
	}
}