//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11286
//  BOJ11286 절댓값 힙

#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int x, int y) {
		if (abs(x) == abs(y)) return x > y;
		else return abs(x) > abs(y);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, compare>pq;
	int N; cin >> N; 
	while (N--) {
		int x; cin >> x;
		if (x != 0) pq.push(x);	//입력이 0이 아닐때
		else {	//입력이 0일때
			if (pq.empty()) cout << "0" << "\n";	//큐가 비어있다면 0 출력
			else {	//비어있지 않다면 
				cout << pq.top()<<'\n';	//최솟값 출력하고 
				pq.pop();	//삭제
			}
		}
	}
}