//  Copyright © 2021 안주형. All rights reserved.
//  이분탐색
//  https://www.acmicpc.net/problem/1920
//  BOJ1920 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>A;
vector<int>B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(), A.end());

	
	for (int i = 0; i < M; i++) {	///이진 탐색
		int start = 0;
		int end = N - 1;
		int target = B[i];
		while (start <= end) {
			int mid = (start + end) / 2;
			if (A[mid] == target) {
				cout << 1 << "\n";
				break;
			}
			else if (A[mid]<target) {	//찾는 값이 중앙 값 보다 더 큰 경우(오른쪽 탐색)
				start = mid + 1;
			}
			else {						//찾는 값이 중앙값보다 더 작은 경우
				end = mid - 1;
			}
		}
		if (start > end) {
			cout << 0 << "\n";
		}
	}

}