//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/14920
//  BOJ14920 3n+1 수열
#include <iostream>

using namespace std;

int cnt = 0;
int check(int N) {
	cnt++;
	if (N == 1) return 0;
	if (N % 2 == 0) return check(N / 2);	//짝수일때
	else return check(3 * N + 1);			//홀수일때
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	check(N);
	cout << cnt;
}