//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2075
//  BOJ2075 N번째 큰 수

#include <iostream>
#include <queue>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<int,vector<int>,greater<int>>pq;
	int n;
	cin >> n;
	/*
		c++ priority_queue는 최대 힙이기 때문에 최소힙으로 정렬(greater<int>)
		pq의 크기를 n만큼 유지하기위해
		n의 사이즈를 넘어갈때 입력값이 마지막의 값보다 작으면 무시.
		n만큼의 사이즈기 때문에 top의 값이 n번째로 큰 수가 된다.
	*/
	for (int i = 0; i < n * n; i++) {
		int num; cin >> num;
		if (pq.size() < n) pq.push(num);	//pq크기를 n만큼 유지
		else {
			if (pq.top() < num) {			
				pq.pop();
				pq.push(num);
			}
		}
	}
	cout << pq.top();
	
}

