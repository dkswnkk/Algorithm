//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/8958
//  BOJ8958 OX퀴즈
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T-- > 0) {
		string str;
		int score = 0, cnt = 0;
		cin >> str;
		vector<char>charArray(str.begin(), str.end());

		for (int i = 0; i < str.length(); i++) {
			if (charArray[i] == 'O') cnt++;
			else cnt = 0;
			score += cnt;
			}		
			cout << score << "\n";
	}
}

