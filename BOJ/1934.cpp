//  Copyright © 2021 안주형. All rights reserved.
//  유클리드 호제법
//  https://www.acmicpc.net/problem/1934
//  BOJ1934 최소공배수
#include <iostream>
using namespace std;

int GCD(int n1, int n2) {
	if (n2 == 0) return n1;
	else return GCD(n2, n1 % n2);
}
int main() {

	int T, A, B;
	cin >> T;
	while (T-- > 0) {
		cin >> A >> B;
		cout << A * B / GCD(A, B) << "\n";
	}
}