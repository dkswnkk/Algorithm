//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11721
//  BOJ11721 열 개씩 끊어 출력하기
#include <iostream>
#include <string>

using namespace std;

int main() {
	string N;
	getline(cin, N);

	for (int i = 0; i < N.size(); i++) {
		cout << N.at(i);
		if ((i + 1) % 10 == 0) {
			cout << "\n";
		}
	}
	cout << "\n";

}