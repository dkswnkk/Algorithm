//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10872
//  BOJ10872 팩토리얼
#include <iostream>

using namespace std;
int sum = 1;
int factorial(int N) {
	if (N == 0) {
		cout << sum;
		return 1;
	}
	else { 
		sum *= N;
		return factorial(N - 1);
	}
	}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	factorial(N);
}