//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2953
//  BOJ2953 나는 요리사다
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max_point = 0;
	int max_index = 0;

	for (int i = 1; i <= 5; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		max_point = max(max_point, a + b + c + d);
		if (max_point == a + b + c + d) max_index = i;
	}
	cout << max_index << ' ' << max_point;
}