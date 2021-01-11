//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10867
//  BOJ10867 중복 빼고 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int N;
	vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		if (!(find(v.begin(), v.end(), number) != v.end()))
			v.push_back(number);
	}
	sort(v.begin(), v.end());

	for (int i : v) {
		cout << i << " ";
	}
}
