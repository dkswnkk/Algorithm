//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/4949
//  BOJ4949 균형잡힌 세상

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		string s;
		stack<char>st;
	
		getline(cin, s);
		if (s[0] == '.') break;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				if (st.empty()) cout << "yes"<<"\n";
				else cout << "no"<<"\n";
			}
			else if(s[i]=='['|| s[i] == ']'|| s[i] == '('|| s[i] == ')') {
				if (st.empty()) st.push(s[i]);
				else {
					if (s[i] == ')' && st.top() == '(') st.pop();
					else if (s[i] == ']' && st.top() == '[') st.pop();
					else st.push(s[i]);
				}
			}
		}
	}
}
