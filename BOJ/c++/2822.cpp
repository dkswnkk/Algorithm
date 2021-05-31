//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2822
//  BOJ2822 점수계산
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T = 8;
	int sum = 0;
	int index;
	vector<int>num;
	vector<int>num_index;
	vector<int>ans;
	for (int i = 0; i < 8; i++) {
		int number;
		cin >> number;
		num.push_back(number);
		num_index.push_back(number);
	}
	sort(num.begin(), num.end(), greater<int>());

	for (int i = 0; i < 5; i++) {
		sum += num[i];
		for (int k = 0; k < num_index.size(); k++) {
			if (num[i] == num_index[k]) ans.push_back(k+1);
		}
	}
	cout << sum << "\n";
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << " ";
	}


}