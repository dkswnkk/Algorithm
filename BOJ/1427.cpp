//  Copyright © 2021 안주형. All rights reserved.
//  정렬 알고리즘
//  https://www.acmicpc.net/problem/1427
//  BOJ1427 소트인사이드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int n1, int n2) {
	return n1 > n2;
}
int main() {
	string s;
	vector<int> v;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]-'0');
	}
	sort(v.begin(), v.end(), desc);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	
}