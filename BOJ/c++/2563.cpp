//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2563
//  BOJ2563 색종이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];	//색종이 범위

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int ans = 0;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {	//색종이의 부분만 1로 채워준다.
		int x, y; cin >> x >> y;
		for (int k = x; k < 10 + x; k++) {
			for (int z = y; z < 10 + y; z++) {
				arr[k][z] = 1;
			}
		}
	}
	for (int i = 0; i < 101; i++) {		//1로 채워진 부분만 세면 색종이의 넓이이다.
		for (int k = 0; k < 101; k++) {
			if (arr[i][k] == 1) ans++;
		}
	}
	cout << ans;
}