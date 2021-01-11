//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2164
//  BOJ2164 카드2

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N,temp;
	queue<int> que;
	cin >> N;

	for(int i=1; i<=N; i++){
		que.push(i);
	}

	while (que.size() != 1) {
		que.pop();
		if (que.size() == 1) break;
		temp = que.front();
		que.pop();
		que.push(temp);
	}
	cout << que.front();
	
	
	 

}