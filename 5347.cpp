//  Copyright © 2021 안주형. All rights reserved.
//  유클리드 호제법
//  https://www.acmicpc.net/problem/5347
//  BOJ5347 LCM
#include <iostream>

using namespace std;

long long int gcd(long long int n1, long long int n2) {
	if (n2 == 0) return n1;
	else return gcd(n2, n1 % n2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int N; cin >> N;
	while (N--) {
		long long int  A, B; cin >> A >> B;
		cout << A * B / gcd(A, B)<<"\n";
	}
}