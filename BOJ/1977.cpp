//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1977
//  BOJ1977 완전제곱수

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, N; cin >> M >> N;
	int sum = 0;
	vector<int>v;

	for (int i = 1; i <= 10000; i++) {
		if (i * i >= M && i * i <= N) {
			v.push_back(i*i);
			sum += i * i;
		}
	}
	
	sort(v.begin(), v.end());
	if (v.empty()) cout << -1;
	else cout << sum<<"\n"<<v[0];
}