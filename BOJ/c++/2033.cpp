//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2033
//  BOJ2033 반올림

#include <iostream>
#include <string>
#define ll long long 

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n; cin >> n;
	int t = 1;
	while (n > t * 10) {
		n += 5 * t;
		t *= 10;
		n -= n % t;
	}
	cout << n;
	
}