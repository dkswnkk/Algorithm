//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/11441
//  BOJ11441 합 구하기

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;

	int sum = 0;
	vector<int>v(N+1);
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		sum += num;
		v[i+1] = sum;
	}
	int M; cin >> M;
	while (M--) {
		int a, b; cin >> a >> b;
		cout << v[b] - v[a-1] << "\n";
	}
}