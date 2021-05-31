//  Copyright © 2021 안주형. All rights reserved.
//  플로이드-와샬 알고리즘
//  https://www.acmicpc.net/problem/11562
//  BOJ11562 백양로 브레이크

#include <iostream>
#define INF 1e9 //무한대를 의미하는 값으로 10억을 지정
using namespace std;
int graph[251][251];
int N, M, K;	//N=건물의 수, M=길의 수, 학생들의 질문
/*
문제 아이디어 
1.그래프를 생성할때, 양방향으로 만들어 줘야 하기 때문에 왕복이 되지 않는 방향을 1로 만든다.
  u v b를 입력받을때 b=1(양방향)인 경우 이미 양방향 이기때문에 graph[u][v]=graph[v][u]=0 이된다.
  b=0(단방향)인 경우 양방향으로 만들어줘야 하기때문에 graph[u][v]=0,graph[v][u]=1이 된다.
2.자기 자신으로 오는 경우는 무조건 갈 수 있는 경우기 때문에 0으로 설정한다.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < 251; i++) {
		fill(graph[i], graph[i] + 251, INF);
	}
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;	//자신끼리 자신과 비교할수 없으니 횟수를 0으로 처리
		}		
	}
	for (int i = 0; i < M; i++) {	//길에 대한 정보 입력
		int a, b, c; cin >> a >> b >> c;
		if (c == 0) {
			graph[a][b] = 0;	//c=0일때 일방통행이기때문에
			graph[b][a] = 1;	//양방으로 만들어야 하기때문에 +1
		}
		else if (c == 1) {				//c=1일때 양방통행이기때문에
			graph[a][b] = 0;
			graph[b][a] = 0;			//양방으로 만들어주지 않아도 된다.
		}
	}
	
	for (int k = 1; k <= N; k++) {	//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}


	cin >> K;	//학생들의 질문 입력
	
	
	

	for (int i = 0; i < K; i++) {
		int s, e; cin >> s >> e;
		cout << graph[s][e] << "\n";		
	}

}
