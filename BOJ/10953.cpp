//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10953
//  BOJ10953 A+B-6
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string s;
	
	cin >> T;
	while (T-- > 0) {
		cin >> s;
		cout << (s[0]-'0')+ (s[2]-'0')<<"\n";
	}
}