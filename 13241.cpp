//  Copyright © 2021 안주형. All rights reserved.
//  유클리드 호제법
//  https://www.acmicpc.net/problem/13241
//  BOJ13241 최소공배수
#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	long long int A, B;

	cin >> A>>B;

	cout << A*B/gcd(A, B);
}