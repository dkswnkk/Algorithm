//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1715
//  BOJ1715 카드 정렬하기
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>>pq;	//최소힙으로 변경
	int N; cin >> N;
	while (N--) {
		int num; cin >> num;
		pq.push(num);
	}

	int sum = 0;
	while (pq.size()!=1) {
		int temp1 = pq.top(); pq.pop();
		int temp2 = pq.top(); pq.pop();
		sum += temp1 + temp2;
		pq.push(temp1+temp2);
	}
	cout << sum;


}