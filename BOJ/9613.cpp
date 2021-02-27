//  Copyright © 2021 안주형. All rights reserved.
//  유클리드 호제법
//  https://www.acmicpc.net/problem/9613
//  BOJ9613 GCD합
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int n1, int n2) {
	if (n2 == 0) return n1;
	else return gcd(n2, n1 % n2);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int cnt;
		vector<int>v;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}

		long sum = 0;
		for (int i = 0; i < v.size() ; i++) {
			for (int j = 0; j < i; j++) {
				sum += gcd(v[i], v[j]);
			}
		}
		cout << sum << "\n";
	}
}

