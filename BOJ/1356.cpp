//  Copyright © 2021 안주형. All rights reserved.
//	
//  https://www.acmicpc.net/problem/1356
//  BOJ1356 유진 수
#include <iostream>
#include <string>
using namespace std;
bool check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string N; cin >> N;
	
	int tempLeft = 1;
	for (int i = 0; i < N.length()-1; i++) {
		int tempRight = 1;
		tempLeft *= (N[i]-'0');
		for (int k = i + 1; k < N.length(); k++) {
			tempRight *= (N[k] - '0');
		}
		if (tempLeft == tempRight) {
			check = true;
			break;
		}
	}
		if (check) cout << "YES";
		else cout << "NO";
}