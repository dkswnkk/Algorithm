//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/9663
//  BOJ9663 N-Queen


#include <iostream>
#include <vector>
#define max 16

using namespace std;

int N,cnt;	//N=체스판 위의 퀸의 개수, cnt=경우의 수
bool visited1[30];	//y축에 있는 퀸 정보 'I'
bool visited2[30];	//좌측하단과 우측 상단을 연결하는 대각선에 있는 퀸 정보	 ex) '／'
bool visited3[30];	//좌측 상단과 우측 하단을 연결하는 대각선에 있는 퀸 정보 ex) '＼'

void dfs(int cur) {
	if (cur == N) {
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited1[i] || visited2[i + cur] || visited3[cur - i + N - 1]) continue;
			visited1[i] = 1, visited2[i + cur] = 1, visited3[cur - i + N - 1] = 1;
			dfs(cur + 1);
			visited1[i] = 0, visited2[i + cur] = 0, visited3[cur - i + N - 1] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dfs(0);
	cout << cnt;
}