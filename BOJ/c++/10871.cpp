//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10871
//  BOJ10871 X보다 작은 수 

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, X; cin >> N >> X;
	
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num < X) cout << num << ' ';
	}
}