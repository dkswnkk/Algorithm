//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘
//  https://www.acmicpc.net/problem/14284
//  BOJ14284 간선 이어가기2
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 //무한대를 의미하는 값으로 10억을 지정.
using namespace std;

vector<pair<int, int>>graph[5002];
int n, m, start, fin; //n=정점의 개수 m=간선의 개수	start=시작 노드 fin=끝 노드
int d[5002]; //가중치를 저장하는 테이블


void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });	//시작 노드는 가중치가 0
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (d[now] < dist)	continue; //이미 방문한 노드는 무시.
		for (int i = 0; i < graph[now].size(); i++) {
			int neighbor = graph[now][i].first;
			int neighborDist = dist+graph[now][i].second;
			if (neighborDist < d[neighbor]) {
				d[neighbor] = neighborDist;
				pq.push({ neighborDist,neighbor });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;		
		graph[a].push_back({ b,c });	//a에서 b까지가는데 c만큼의 가중치가 든다.
		graph[b].push_back({ a,c });		//무방향(양방향) 처리
	}
	fill(d, d + 5001, INF);
	
	cin >> start >> fin;
	dijkstra(start);
	cout << d[fin];
}