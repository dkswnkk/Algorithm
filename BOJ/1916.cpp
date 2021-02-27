//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘
//  https://www.acmicpc.net/problem/1916
//  BOJ1916 최소비용 구하기
#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9
using namespace std;
vector<pair<int,int>>graph[1001];
int d[1001];		//비용을 저장하는 배열
int N, M, start,fin;	//N=도시의 개수(노드) M=버스의 개수(간선) start=시작점 fin=도착점 

void dijkstra(int start) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });	//출발점의 비용은 0
	d[start] = 0;			
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;	//이미 처리된 노드라면 무시한다.
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second; 
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost,graph[now][i].first });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N>> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;;	 cin >> a >> b >> c;
		graph[a].push_back({ b,c });	//a에서 b까지 가는 데 드는 비용 c
	}
	
	fill(d, d + 1001, INF);
	cin >> start >> fin;
	dijkstra(start);

	cout << d[fin];

}