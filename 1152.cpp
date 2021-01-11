//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1152
//  BOJ1152 단어의 개수
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == ' ') cnt++;
	}
		if (s.at(0) == ' ') cnt--;
	    if (s.at(s.length() - 1) == ' ') cnt--;
	cout << cnt + 1;
}