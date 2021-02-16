//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/14588
//  BOJ14588 Line Friends (Small)

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N,Q;
int graph[301][301];
vector<pair<int, int>>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> N;
	for (int i = 0; i < 301; i++) {	//최단 거리 테이블을 모두 무한으로 초기화
		fill(graph[i], graph[i] + 301, INF);
	}
	for (int a = 1; a <= N; a++) {	//자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}	
	for (int i = 0; i < N; i++) {	//간선정보 입력
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			if (v[i-1].second >= v[k-1].first && v[k-1].second >= v[i-1].first) {	//그래프가 겹치는 부분이 있을때 친구관계이다.
				graph[i][k] = 1;
				graph[k][i] = 1;
			}
		}
	}
	for (int k = 1; k <= N; k++) {	//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {	//선분이 가까운 정도를 출력.
		int a, b; cin >> a >> b;
		if (graph[a][b] == INF) cout << -1 << "\n";
		else cout << graph[a][b] << "\n";
	}
}