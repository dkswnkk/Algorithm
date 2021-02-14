//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/7795
//  BOJ7795 먹을 것인가 먹힐 것인가
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		vector<int>A, B;
		int a, b; cin >> a >> b;
		for (int i = 0; i < a; i++) {	//A벡터 원소 삽입
			int num; cin >> num;
			A.push_back(num);
		}
		for (int i = 0; i < b; i++) {	//B벡터 원소 삽입
			int num; cin >> num;
			B.push_back(num);
		};
		sort(B.begin(), B.end()); //이분탐색을 위한 정렬
		int cnt = 0;
		for (int i = 0; i < a; i++) {
			cnt += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
		}
		cout << cnt << "\n";
	}
}