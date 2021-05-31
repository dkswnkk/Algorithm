//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/18883
//  BOJ18883 N M 찍기

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int check = 1;
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= M; k++) {
			cout << check;
			if (M!=k) cout << ' ';
			check++;
		}
		cout << "\n";
	}
}