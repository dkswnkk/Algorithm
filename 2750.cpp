//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2750
//  BOJ2750 수 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N,number;
	vector<int> v;
	cin >> N;
	while (N--) {
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}