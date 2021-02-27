//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1978
//  BOJ1978 소수 찾기
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ans;
vector<int>v(1001, true);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v[1] = false;	//자연수 1은 소수가 아님.

	int N; cin >> N;

	for (int i = 2; i <= 1000; i++) {	//1~1000까지의 수 중 소수인경우 true 처리.
		if (v[i] == true) {
			int j = 2;
			while (i * j <= 1000) {
				v[i * j] = false;
				j += 1;
			}
		}
	}
	for (int k = 0; k < N; k++) {
		int n; cin >> n;
		if (v[n] == true) ans++;
	}
	cout << ans;



}

