//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11718
//  BOJ11718 그대로 출력하기
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (getline(cin, s)) {
		cout << s << "\n";
	}
}