//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘
//  https://www.acmicpc.net/problem/5972
//  BOJ5972 택배배송
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9 //무한을 뜻하는 의미로 10억을 지정.
using namespace std;

int N, M; //N=개의 헛간 M=소들의길(양방향)
int d[50001];
vector<pair<int, int>>graph[50001];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });	//첫 시작점의 비용은 0
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue; //이미 방문했던 노드는 무시
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

	cin >> N >> M;
	for (int i = 0;  i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });	//a에서 b까지 가는데 c의 비용이 든다.
		graph[b].push_back({ a,c });	//양방향 이기때문에 처리해준다.
	}
	fill(d, d + 50001, INF);
	dijkstra(1);
	cout << d[N];

}