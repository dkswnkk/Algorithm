//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2857
//  BOJ2857 FBI
#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int main() {
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length()-2; j++) {
			if (s[j] == 'F') {
				if (s[j + 1] == 'B') {
					if (s[j + 2] == 'I')
						v.push_back(i);
					break;
				}
			}
		}
	}
	if (v.empty()) {
		cout<<"HE GOT AWAY!";
	}
	else {
		for (int i : v) {
			cout << i+1 << ' ';
		}
	}
}