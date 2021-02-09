//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2018
//  BOJ2018 수들의 합5

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;

	int end = 1,sum=0, cnt = 0;
	for (int i = 1; i <= N; i++) {

		while (end < N && sum < N) {	//end를 가능한 만큼 이동시킨다.
			sum += end;
			end++;
		}
		if (sum == N) cnt++;	//부분 합이 정수N일때 카운터 증가
		sum -= i;
	}
	cout << cnt+1;
}