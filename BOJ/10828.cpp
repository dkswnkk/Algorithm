//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10828
//  BOJ10828 스택

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<int>st;

	int N; cin >> N;
	while (N--) {
		string cmd; cin >> cmd;
		if (cmd == "push") {
			int num; cin >> num;
			st.push(num);
		}
		else if (cmd == "top") {
			if (st.empty()) cout << -1<<"\n";
			else cout << st.top()<<"\n";
		}
		else if (cmd == "size") cout << st.size()<<"\n";
		else if (cmd == "pop") {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top()<<"\n";
				st.pop();
			}
		}
		else if (cmd == "empty") {
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	
}