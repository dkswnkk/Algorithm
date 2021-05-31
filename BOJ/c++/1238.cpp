//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘
//  https://www.acmicpc.net/problem/1238
//  BOJ1238 파티

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9 //무한을 뜻하는 값으로 10억 지정.

using namespace std;
int N, M, X; //N=마을(노드) M=도로(간선) X=도착지
int d[1001];	//최소 시간을 기록해두는 테이블
int result[1001]; //i->x->i의 시간을 기록하는 테이블
int ans = 0;
vector<pair<int, int>>graph[1001];

//일반적인 다익스트라 알고리즘
void dijkstra(int start) {	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });	//출발지는 시간이 0;
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now]<dist) continue; //이미 방문된 노드라면 무시
		for (int i = 0; i < graph[now].size(); i++) {
			int neighborDist = dist+graph[now][i].second;
			int neighbor = graph[now][i].first;

			if (neighborDist < d[neighbor]) {
				d[neighbor] = neighborDist;
				pq.push({ neighborDist,neighbor });
			}
		}
	}
}

void reset() {
	fill(d, d + 1001, INF);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b,c });	//a에서 b까지 가는데 c만큼의 시간이 든다.
	}
	
	for (int i = 1; i <= N; i++) {	//i->X 까지 시간 기록
		reset();				//매 탐색마다 초기화 시켜준다.
		dijkstra(i);
		result[i] = d[X];
	}
		reset();
		dijkstra(X);	//왕복을 해야 하니까 X에서 각 마을(노드)=i 까지 걸리는 d[] 테이블에 기록
	for (int i = 1; i <= N; i++) {	//X->i까지의 시간을 i->X 까지 걸리는 시간에 더함. 
		result[i] += d[i];
	}
	for (int i = 1; i <= N; i++) {	//i->X->i 까지 걸리는 시간의 최댓값을 구한다.
		ans = max(ans, result[i]);
	}
	cout << ans;
	
}