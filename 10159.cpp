//  Copyright © 2021 안주형. All rights reserved.
//  플로이드-와샬 알고리즘
//  https://www.acmicpc.net/problem/10159
//  BOJ10159 저울

#include <iostream>
#define INF 1e9	//무한대를 의미하는 값으로 10억을 지정
using namespace std;
int N, M; //N=물건의 개수, M=물건 쌍의 개수
int graph[101][101];
int ans[101] = { 0, };	//비교결과를 알수없는 물건 갯수를 저장하는 테이블

int main() {
	cin >> N >> M;

	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}
	
	for (int a = 1; a<= N; a++) {		//자기 자신과 비교하는 경우는 0으로 설정
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}
	for (int i = 1; i <= M; i++) {	//비교 결과 입력
		int a, b; cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k <= N; k++) {	//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	for (int a = 1; a <= N; a++) {	//출력
		for (int b = 1; b <= N; b++) {
			if (graph[a][b] == INF&&graph[b][a]==INF) ans[a]++;	//N번째 물건이 다른번호와 서로 비교가 불가능할때 카운터를 세준다.
		}
		cout << ans[a] << "\n";
	}

}