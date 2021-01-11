//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10815
//  BOJ10815 숫자 카드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	vector<int>v;
	for (int i = 0; i < N; i++) {
		int number; cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	cin >> M;

	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = N - 1;
		int check;
		cin >> check;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (v[mid] == check) {		//찾는값이 있으면 출력
				cout << 1 << " ";
				break;
			}
			else if (v[mid] < check) {		//찾는값이 더 크면 오른쪽탐색
				start = mid + 1;
			}
			else {						//찾는 값이 작으면 왼쪽 탐색
				end = mid - 1;
			}
			if (start > end) cout << 0 << " ";
		}
	}
}
