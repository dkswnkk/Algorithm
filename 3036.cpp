//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/3036
//  BOJ3036 링
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N-1; i++) {
		int a = v[0];
		int b = v[i + 1];
		int div = gcd(a, b);
		cout << a / div << '/' << b / div << "\n";
	}
}