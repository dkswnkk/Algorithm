//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/14681
//  BOJ14681 사분면 고르기
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b; cin >> a >> b;

	if (a > 0 && b > 0) cout << 1;
	else if (a > 0 && b < 0) cout << 4;
	else if (a < 0 && b>0) cout << 2;
	else if (a < 0 && b < 0) cout << 3;
}