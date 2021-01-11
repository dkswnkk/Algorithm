//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘  
//  https://www.acmicpc.net/problem/1753
//  BOJ1753 최단 경로

#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9	//무한을 의미하는 값으로 10억을 설정
using namespace std;

int N, M, start;	//N= 정점(노드)의 개수, M=간선의 개수, start=시작노드
vector<pair<int, int>>map[20001]; //각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[300001];	//최단 거리 테이블



void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	//시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0,start });	//({거리,노드})
	d[start] = 0;
	while (!pq.empty()){	//큐가 비어있지 않다면
		int dist = -pq.top().first;	//현재 노드까지의 비용
		int now = pq.top().second;	// 현재 노드
		pq.pop();
		if (d[now] < dist) continue;	//현재 노드가 이미 처리된 적이 있는 노드라면 무시
		
		for (int i = 0; i < map[now].size(); i++) {	//현재 노드와 연결된 다른 인접한 노드들을 확인
			int cost = dist + map[now][i].second;
			if (cost < d[map[now][i].first]) {//현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
				d[map[now][i].first] = cost;
				pq.push(make_pair(-cost, map[now][i].first));
			}
				
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M>>start;
	for (int i = 0; i < M; i++) {	//모든 간선 정보를 입력받기
		int a, b, c; cin >> a >> b >> c;
		map[a].push_back({ b,c });	//a번 노드에서 b번 노드로 가는 비용이 c라는 의미
	}
	fill(d, d + 100001, INF);	//최단 거리 테이블을 모두 무한으로 초기화
	
	dijkstra(start);	//다익스트라 알고리즘 수행


	for (int i = 1; i <= N; i++) {	//모든 노드로 가기 위한 최단 거리를 출력
		if (d[i] == INF) {
			cout << "INF"<<"\n";
		}
		else {
			cout << d[i]<<"\n";
		}

	}
}