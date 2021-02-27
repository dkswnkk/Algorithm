//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1406
//  BOJ1406 에디터

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	int t; cin >> t;

	stack<char>left, right;

	for (int i = 0; i < s.length(); i++) {
		left.push(s[i]);
	}

	while (t--) {

		char com; cin >> com;

		if (com == 'L') {
			if (left.empty()) continue;
			right.push(left.top());
			left.pop();
		}
		else if (com == 'D') {
			if (right.empty()) continue;
			left.push(right.top());
			right.pop();
		}
		else if (com == 'B') {
			if (!left.empty()) left.pop();
		}
		else if (com == 'P') {
			char c; cin >> c;
			left.push(c);
		}

	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

}