//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/3986
//  BOJ3986 좋은 단어

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	int N; cin >> N;

	while (N--) {	//테스트 케이스 만큼 반복
		stack<char>st;
		string s; cin >> s;
		for (int i = 0; i < s.length(); i++) {	
			if(st.empty()) st.push(s[i]);
			else {
				if (st.top() == s[i]) st.pop();
				else st.push(s[i]);
			}
		}
		if (st.empty()) cnt++; 
	}
	cout << cnt;
	
}