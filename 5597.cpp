//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/5597
//  BOJ5597 과제 안 내신 분..?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>arr(31);
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 28; i++) {
		int num; cin >> num;
		arr[num] = 1e9;
	}
	
	for (int i = 1; i <= 30; i++) {
		if (arr[i]!=1e9) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << "\n";
	}
	}
