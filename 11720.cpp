//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11720
//  BOJ11720 숫자의 합
#include <iostream>
using namespace std;

int main() {

	int cnt;
	char N;
	int sum = 0;
	cin >> cnt;

	while (cnt-- > 0) {
		cin >> N;
		sum += (N - '0');
	}
	cout << sum;
}