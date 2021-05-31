//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10811
//  BOJ10811 바구니 뒤집기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>v(N+1);
	for (int i = 1; i <= N; i++) {
		v[i] = i;
	}
	
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		reverse(v.begin()+a,v.end()-N+b);
		}

	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}