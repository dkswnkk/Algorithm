//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1652
//  BOJ1652 누울 자리를 찾아라
#include <iostream>

using namespace std;

char c[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int cnt = 0, row = 0, col = 0;	//row=가로 col=세로
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < N; i++) {		//가로 검사
		for (int j = 0; j < N; j++) {
			if (c[i][j] == '.') cnt++;
			else if (c[i][j] == 'X') {
				if (cnt >= 2) {
					row++;
					cnt = 0;
				}
				else cnt = 0;
			}
		}
		if (cnt >= 2) {
			row++;
			cnt = 0;
		}
		else cnt = 0;
	}
	cnt = 0;
	for (int j = 0; j < N; j++) {		//세로 검사
		for (int i = 0; i < N; i++) {
			if (c[i][j] == '.')cnt++;
			else if (c[i][j] == 'X') {
				if (cnt >= 2) {
					col++;
					cnt = 0;
				}
				else cnt = 0;
		   }
		}
		if (cnt >= 2) {
			col++;
			cnt = 0;
		}
		else cnt = 0;
	}
	cout << row<<' '<<col;
	
}