//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/9012
//  BOJ9012 괄호
#include <iostream>
#include <stack>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		stack<char>st;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '('){ 
				if (st.empty()) st.push(s[i]);
				else st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty()) st.push(s[i]);
				else if (st.top() == '(') st.pop();
				else st.push(s[i]);
			}
		}

		if (st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
}
