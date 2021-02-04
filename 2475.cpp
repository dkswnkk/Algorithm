//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2475
//  BOJ2475 검증수
#include <iostream>
#include <algorithm>

#define lli long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	lli a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	lli ans = (lli)(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2)) % 10;
	cout << ans;


}