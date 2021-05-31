//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2675
//  BOJ2675 문자열 반복
#include <iostream>
using namespace std;

int main() {
	int T, N;
	string S;
	cin >> T;

	while (T-- > 0) {
	cin >> N >> S;

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < N; j++) {
			cout << S[i];
		}
	}
		cout << "\n";


	}
}