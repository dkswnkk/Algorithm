//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1673
//  BOJ1673 치킨 쿠폰
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k; 
	while (cin >> n >> k) {
		int ans = 0;
		ans = n;
		while (n / k != 0) {
			int extraCupon = n % k;
			n = n / k;
			ans += n;
			n += extraCupon;
		}	
		n = 0, k = 0;
		cout << ans << "\n";
	}
}