//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10773
//  BOJ10773 제로
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T, ans = 0;
	stack<int> st;
	cin >> T;
	while (T--) {
		int number;
		cin >> number;
		if (number == 0) {
			if (!st.empty()) st.pop();
		}
		else st.push(number);
		}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
}