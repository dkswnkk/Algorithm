//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2739
//  BOJ2739 구구단
#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		cout << N << " * "<< i << " = " << N * i<<"\n";
	}
}