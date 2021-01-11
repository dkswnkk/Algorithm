//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/15552
//  BOJ15552 빠른A+B
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T-- > 0) {
		int A, B;
		cin >> A >> B;
		cout << A + B << "\n";
	}

}