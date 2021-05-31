//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2562
//  BOJ2562 최댓값
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int max = 0, index = 0;
	vector<int>v;
	
	for (int i = 0; i < 9; i++) {
	cin >> N;
	v.push_back(N);
	if (max <= v[i]) {
		max = v[i];
		index = i;
	}
	}
	cout << max << "\n"<<index+1;

}
