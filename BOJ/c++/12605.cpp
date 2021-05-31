//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/12605
//  BOJ12605 단어 순서 뒤집기

#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++) {
		string s, temp, ans;
		stack<string> st;
		getline(cin, s);

		for (int k = 0; k < s.length(); k++) {
			if (s[k] == ' ') {
				st.push(temp);
				st.push(" ");
				temp.clear();
			}
			else temp += s[k];
		}
		st.push(temp);
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		cout << "Case #" << i << ": " << ans << "\n";


	}


}