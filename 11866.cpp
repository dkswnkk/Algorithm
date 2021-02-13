//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/11866
//  BOJ11866 요세푸스 문제0
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K; cin >> N>>K;
	queue<int>q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		int cnt = 1;
		while (true) {
			if (cnt == K) {
				cout << q.front();
				q.pop();
				if (!q.empty()) cout << ", ";
				break;
			}
			int temp = q.front();
			q.pop();
			q.push(temp);
			cnt++;
		}
		
	}
	cout << ">";
}