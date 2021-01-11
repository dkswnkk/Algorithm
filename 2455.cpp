//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2455
//  BOJ2455 지능형 기차

#include <iostream>

using namespace std;

int main() {
	int a, b;
	int c = 0;
	int max = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		c = c - a + b;
		if (c > max) max = c;

	}
	cout << max;
}