//  Copyright © 2021 안주형. All rights reserved.
//  플로이드-와샬 알고리즘
//  https://www.acmicpc.net/problem/11404
//  BOJ11404 플로이드

#include <iostream>
#include <vector>
#define INF 1e9		//무한을 뜻하는 값으로 10억을 정의
using namespace std;

int n, m;	//n=도시의 개수, m=버스의 개수
int graph[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < 101; i++) {			//최단 거리 테이블을 모두 무한을 초기화
		fill(graph[i], graph[i]+101, INF);
	}

	for (int a = 1; a <= n; a++) {		//자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화.
		for (int b = 1; b <= n; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}

	for (int i = 0; i < m; i++) {	//간선 정보 입력.
		int a, b, c; cin >> a >> b >> c;
											//a에서 b로 가는 비용은 c
		graph[a][b] = min(graph[a][b], c); // 시작노선과 도착노선이 여러개일수 있으니, 가장 작은 값으로 갱신

	}
	
	for (int k = 1; k <= n; k++) {		//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF) cout << 0 << ' ';
			else cout << graph[a][b] << ' ';
		}
		cout << "\n";
	}


}