//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2010
//  BOJ2010 플러그

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//(각 멀티탭 구멍의 총합) - (멀티탭의 개수 - 1)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		ans += num;
	}
	ans = ans - (N - 1);
	cout << ans;

}