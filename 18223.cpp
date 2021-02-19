//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/18223
//  BOJ18223 민준이와 마산 그리고 건우

#include <iostream>
#include <queue>
#define INF 1e9 //무한을 의미하는 값으로 10억을 지정.

using namespace std;

int V, E, P;	//V=정점의 개수, E=간선의 개수, P=건우의 위치
vector<pair<int, int>>graph[5001];	//노드에 대한 정보를 담는 테이블
int d[10001];	//최단거리 테이블

int check[10001];	//건우를 포함한 최단거리와 그냥 최단거리를 비교하기 위해 저장하는 테이블 

void reset() {
	fill(d, d + 10001, INF);
}
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;	//최소힙
	pq.push({ 0,start });	//시작 노드의 최단경로는 0
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;	//현재 노드까지의 비용
		int now = pq.top().second;	//현재 노드
		pq.pop();
		if (d[now] < dist) continue; //현재 노드가 이미 처리된 적이 있는 노드라면 무시

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

	cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b,c });	//a에서 b까지 가는데 c거리
		graph[b].push_back({ a,c });	//양방향 처리
	}
	reset();

	/*
	1->V까지의 최단거리와 1->건우 까지 최단거리 + 건우->V 까지의 최단 거리가 같으면 최단경로위에 건우가 있다.
	// start->end==start->P(건우)->end;
	*/
	dijkstra(1);
	check[0] = d[V];
	check[1] = d[P];
	
	reset();
	dijkstra(P);
	check[2] = d[V];
	if (check[0] == check[1] + check[2]) cout << "SAVE HIM";
	else cout << "GOOD BYE";


}