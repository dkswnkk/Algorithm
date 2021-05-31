//  Copyright © 2021 안주형. All rights reserved.
//  그리디 알고리즘
//  https://www.acmicpc.net/problem/14916
//  BOJ14916 거스름돈
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n; //가격
	int cnt = 0; //횟수
	cin >> n;
	int temp = n % 5;

	if (n == 1 || n == 3) cnt = -1;
	else if (temp % 2 == 0) cnt = n / 5 + temp / 2;
	else cnt = ((n / 5) - 1) + ((temp + 5) / 2);
	cout<<cnt;

	
}