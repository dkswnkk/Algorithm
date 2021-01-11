//  Copyright © 2021 안주형. All rights reserved.
//  이분탐색
//  https://www.acmicpc.net/problem/1920
//  BOJ1920 수 찾기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	vector<int>A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number; cin >> number;
		A.push_back(number);
	}
	cin >> M;
	sort(A.begin(), A.end());
	
	int check;
	for (int i = 0; i < M; i++) {
		cin >> check;
		cout << binary_search(A.begin(), A.end(), check) << "\n";
	}

}