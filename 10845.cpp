//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10845
//  BOJ10845 큐

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	queue<int>q;
	while (N--) {
		string s; cin >> s;
		if (s == "push") {
			int num; cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") cout << q.size() << "\n";
		else if (s == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (s == "back") {
			if (q.empty())cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}
}