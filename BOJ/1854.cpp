//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘
//  https://www.acmicpc.net/problem/1854
//  BOJ1854 K번째 최단경로 찾기

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9	//무한대를 의미하는 값으로 10억을 지정

using namespace std;
priority_queue<int>d[1001];	//i번째 도시까지의 거리를 최대 힙으로 저장.
vector<pair<int, int>>graph[1001];
int n, m, k;	//n=도시 갯수(정점), m=도로의 갯수(간선), k=k번째 최단경로


void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,start });	//시작점의 비용은 0
	d[1].push(0);

	while (!pq.empty()) {
		int dist = pq.top().first; 
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int neighbor = graph[now][i].first;
			int neighborDist = dist+graph[now][i].second;
			if (d[neighbor].size() < k) {
				d[neighbor].push(neighborDist);
				pq.push({ neighborDist, neighbor });
			}
			else if (d[neighbor].top() > neighborDist) {
				d[neighbor].pop();
				d[neighbor].push(neighborDist);
				pq.push({ neighborDist,neighbor });
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {	//간선 정보 입력
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });	//a에서 b까지 가는데 c만큼의 비용이 듦.
	}
	dijkstra(1);

	for (int i = 1; i <= n; i++) {
		if (d[i].size() < k) cout << -1 << "\n";
		else cout << d[i].top() << "\n";
	}
}