//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/5576
//  BOJ5576 콘테스트
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int>a(10);
	vector<int>b(10);

	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end(),greater<int>());
	sort(b.begin(), b.end(),greater<int>());

	int ans1 = 0;
	int ans2 = 0;
	
	for (int i = 0; i < 3; i++) {
		ans1 += a[i];
		ans2 += b[i];
	}
	cout << ans1 << " " << ans2;
}