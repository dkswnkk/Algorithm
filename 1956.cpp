//  Copyright © 2021 안주형. All rights reserved.
//  플로이드-와샬 알고리즘
//  https://www.acmicpc.net/problem/1956
//  BOJ1956 운동

#include <iostream>
#define INF 1e9 //무한을 뜻하는 값으로 10억을 지정
using namespace std;

int N, M; //N=마을의 개수, M=도로의 개수
int graph[401][401];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i <401; i++) {
		fill(graph[i], graph[i] + 401, INF);	//최단거리 테이블 초기화
	}
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a == b) graph[a][b] =0;	//자기 자신에서 자기자신으로 가는 비용은 0으로 처리
		}
	}
	for (int i = 1; i <= M; i++) {		//간선 정보 입력
		int a, b, c; cin >> a >> b >> c;
		graph[a][b] = c;	//a에서 b로가는데 c만큼의 비용이 듦

	}
	for (int k = 1; k <= N; k++) {		//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	int ans = INF;
	for (int a = 1; a <= N; a++) {			//출력
		for (int b = 1; b <= N; b++) {
			if (a==b) continue;
			ans = min(ans, graph[a][b] + graph[b][a]);	//사이클이기때문에 최소가되는 왕복값을찾는다.		
		}	
	}
	if (ans == INF) cout << -1;
	else cout << ans;

}