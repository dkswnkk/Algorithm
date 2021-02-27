//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11659
//  BOJ11659 구간 합 구하기4
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M,temp=0; cin >> N >> M;
	vector<int>v(N + 1), sum(N+1);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		temp += v[i];	
		sum[i + 1] = temp;
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << sum[b] - sum[a - 1] <<"\n";
	}
	
	
}