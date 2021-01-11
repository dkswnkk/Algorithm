//  Copyright © 2021 안주형. All rights reserved.
//
//  https://www.acmicpc.net/problem/1009
//  BOJ1009 분산처리
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	while (N--) {
		int a, b; cin >> a >> b;
		if (b % 4 == 0)b = 4;	//모든 제곱들이 4의 주기를 가짐.
		else b %= 4;
		long long final = pow(a, b);
		if (final % 10 == 0) cout << 10<<"\n";
		else  cout << final % 10 << "\n";
	}
}