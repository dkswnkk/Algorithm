//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2003
//  BOJ2003 수들의 합2

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int>v;
	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	
	int checkSum = 0, start = 0, end = 0,cnt=0;

	for (start = 0; start < v.size(); start++) {	//start를 차례대로 증가시키며 반복
		while (end<N && checkSum < M) {		//end를 가능한 만큼 이동 시키기
			checkSum += v[end];
			end++;
		}
		if (checkSum == M) cnt++;	//부분합이 M일때 카운트 증가
		checkSum -= v[start];
	}
	cout << cnt;
}