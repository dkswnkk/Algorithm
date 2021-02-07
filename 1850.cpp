//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1850
//  BOJ1850 최대공약수

#include <iostream>
#define ll unsigned long long
using namespace std;

ll gcd(ll A, ll B) {
	if (B == 0) return A;
	else return gcd(B, A % B);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll A, B; cin >> A >> B;
	string s;
	ll C = gcd(A, B);

	
	for (ll i = 0; i < C; i++) {
		s += "1";
	}
	
	cout << s;
	
}