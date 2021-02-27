//  Copyright © 2021 안주형. All rights reserved.
//  그리디 알고리즘
//  https://www.acmicpc.net/problem/1138
//  BOJ1138 한 줄로 서기
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v(N);
	for (int i = 1; i <= N; i++) {			// 키가1인 사람부터 시작해 N명까지
		int key; cin >> key;
		for (int j = 0; j < N; j++) {		//줄을 탐색한디.
			if (v[j] == 0 && key == 0) {	//자기 자리가 비었고, 키 큰 사람들을 다 지나쳤을 때 
				v[j] = i;				
				break;
			}
			else if (v[j] == 0) key--;		//키가 큰 사람이 있는만큼 지나친다.	//v[j]!=0 경우는 자기보다 키가 작은 사람이 이미 삽입되어있음.
		}
	}
	for (int i : v) {
		cout << i << " ";
	}
}