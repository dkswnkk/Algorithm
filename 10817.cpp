//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10817
//  BOJ10817 세 수

#include<iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int,vector<int>,greater<int>>pq;
	int A, B, C; cin >> A >> B >> C;
	pq.push(A); pq.push(B); pq.push(C);
	pq.pop();
	cout << pq.top();
	
}