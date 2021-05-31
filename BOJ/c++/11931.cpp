//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11931
//  BOJ11931 수 정렬하기4
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<int>map;
	while (T--) {
		int number;
		cin >> number;
		map.push_back(number);
	}
	sort(map.begin(), map.end(), greater<int>());
	
	for (int i : map) {
		cout << i << "\n";
	}
}