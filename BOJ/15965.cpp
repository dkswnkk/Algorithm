//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/15965
//  BOJ15965 K번째 소수

#include <iostream>
#include <vector>
#include <cmath>
#define max 10000001
using namespace std;

vector<bool>v(max, true);
int ans, check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v[0] = false;	//자연수 1은 소수가 아님.
	int K; cin >> K;
	for (int i = 2; i <= (int)sqrt(max); i++) {	//에라토스테네스 알고리즘수행 하여 소수만 true 처리
		if (v[i] == true) {
			int j = 2;
			while (i * j <max) {
				v[i * j] = false;
				j += 1;
			}
		}
	}


	for (int i = 2; i <max; i++) {
		if (v[i] == true) {
			check++;
			ans = i;
			if (check == K) break;
		}
	}
	cout << ans;
}
