//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1253
//  BOJ1253 좋다
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());	//이분탐색을 위한 정렬
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int start = 0;
		int end = N - 1;
		while (start < end) {
			if (v[start] + v[end] == v[i]) {
				if (start != i && end != i) {
					cnt++;
					break;
				}
				else if (start == i) start++;
				else if (end== i) end--;

			}
			else if (v[start] + v[end] < v[i]) start++;
			else end--;
		}
	}

	cout << cnt;

}