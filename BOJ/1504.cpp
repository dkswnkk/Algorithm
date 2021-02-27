//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1504
//  BOJ1504 특정한 최단 경로

#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9 //무한대를 의미하는 값으로 10억을 설정


using namespace std;

int N, E, v1, v2;	//N=정점의 개수, E=간선의 개수,	v1,v2=거쳐야 하는 정점 번호
vector<pair<int, int>>graph[801];	//각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[801];	//최단 거리 테이블
int check[801];	//v1,v2를 거쳐 가는 최단 거리를 저장하는 테이블

void reset() {
	fill(d, d + 801, INF);
}

void dijkstra(int start) {
	reset();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; //최소힙 
	pq.push({ 0,start });	//시작 노드로 가기 위한 비용은 0으로 설정하여 큐에 삽입.
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;	//이미 처리된 적이 있는 노드라면 무시
		for (int i = 0; i < graph[now].size(); i++) {
			int neighbor = graph[now][i].first;
			int neighborDist = dist + graph[now][i].second;
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

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b,c });	//a에서b로 가는데 c만큼의 비용이 든다.
		graph[b].push_back({ a,c });	//양방향 처리
	}
	cin >> v1 >> v2;

	/* 고려 해야 할 경우의 수
	1. a->v1->v2->b
	2. a->v2->v1->b
	*/

	dijkstra(1);
	check[0] = d[v1];	//1->v1까지의 거리
	check[1] = d[v2];	//1->v2까지의 거리
	dijkstra(v1);
	check[2] = d[v2];	//v1->v2까지의 거리
	check[3] = d[N];	//v1->N까지의 거리
	dijkstra(v2);
	check[4] = d[N];	//v2->N까지의 거리
	check[5] = d[v1];	//v2->v1까지의 거리

	int ans = INF;
	ans = min(ans, check[0] + check[2] + check[4]);	//v1->v2
	ans = min(ans, check[1] + check[5] + check[3]);	//v2->v1

	if (ans == INF || check[2] == INF || check[5] == INF) cout << -1;
	else cout << ans;
}