//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1100
//  BOJ1100 하얀 칸
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	char c[8][8];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (c[i][j] == 'F') cnt++;
			}
		}
	}
	cout << cnt;
}