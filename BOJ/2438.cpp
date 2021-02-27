//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2438
//  BOJ2438 별찍기-1
#include <iostream>
using namespace std;

int main() {
	int N;
	int i = 1;
	cin >> N;
	while (N-- > 0) {
		for (int j = 0;  j < i; j++) {
			cout << "*";
		}
			i++;
		cout << "\n"; 
	}
}
