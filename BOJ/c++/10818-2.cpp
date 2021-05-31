//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10818
//  BOJ10818 최소,최대
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	int max = v[0];
	int min = v[0];
	for (int i = 0; i < N; i++) {
		if (max <= v[i]) max = v[i];
		if (min >= v[i]) min = v[i];
	}
	cout << min << " " << max;

}