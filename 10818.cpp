//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10818
//  BOJ10818 최소,최대
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>>pq1; //작은 순서대로
	priority_queue<int, vector<int>,less<int>>pq2; //큰 순서대로

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		pq1.push(number);
		pq2.push(number);
	}
	cout << pq1.top() <<"\n"<< pq2.top();

	
}