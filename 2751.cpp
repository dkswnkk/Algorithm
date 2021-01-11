//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2751
//  BOJ2751 수 정렬하기2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, number;
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