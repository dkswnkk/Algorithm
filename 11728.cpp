//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11728
//  BOJ11728 배열합치기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a_size, b_size;
	cin >> a_size >> b_size;
	vector<int>a(a_size);
	vector<int>b(b_size);
	for (int i = 0; i < a_size; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < b_size; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < b.size(); i++) {
		a.push_back(b[i]);
	}
	sort(a.begin(), a.end());
	
	for (int i : a) {
		cout << i << " ";
	}

}