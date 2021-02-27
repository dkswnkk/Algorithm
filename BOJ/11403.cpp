//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/11403
//  BOJ11403 경로 찾기

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int graph[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			int value; cin >> value;
			graph[i][k] = value;
		}
	}
		for (int k = 1; k <= N; k++) {
			for (int a = 1; a <= N; a++) {
				for (int b = 1; b <= N; b++) {
					if (graph[a][k] && graph[k][b]) graph[a][b] = 1;
				}
			}
		}


	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cout << graph[a][b]<<' ';
		}
		cout << "\n";
	}
}

