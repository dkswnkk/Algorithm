//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/5543
//  BOJ5543 상근날드

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;

	vector<int>ham(3), drink(2);
	int ans = 1e9;
	
	ham[0] = a, ham[1] = b, ham[2] = c;
	drink[0] = d, drink[1] = e;

	for (int i = 0; i < 3; i++) {
		ans = min(ans, min(ham[i] + drink[0], ham[i] + drink[1]));
	}
	cout << ans-50;
}