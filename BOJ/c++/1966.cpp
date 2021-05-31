//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1966
//  BOJ1966 프린터 큐

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		queue<pair<int, int>>q;
		priority_queue<int>pq;	//최대힙
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			q.push({ i,num });	//{인덱스번호,순위};
			pq.push(num);
		}

		while (!q.empty()) {

			if (pq.top() == q.front().second) {
				cnt++;
				if (q.front().first == M) {
					cout << cnt << "\n";
					break;
				}
				q.pop();
				pq.pop();
			}
			else {
				int A = q.front().first;
				int B = q.front().second;
				q.pop();
				q.push({ A,B });
			}
		}


	}
}