//  Copyright © 2021 안주형. All rights reserved.
//	위상정렬 알고리즘
//  https://www.acmicpc.net/problem/1005
//  BOJ1005 ACM Craft
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int N, K,W; //N=건물의 개수 , K=건설순서 규칙 개수, W=승리하기 위해 건설해야 할 건물
int indegree[1001];
int time[1001];
int totalTime[1001];
vector<int>graph[1001];

void itit() {
	memset(time, 0, sizeof(time));
	memset(totalTime, 0, sizeof(totalTime));
	memset(indegree, 0, sizeof(indegree));
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}
}
void topologySort() {	//위상정렬 알고리즘 수행
	queue<int>q;
	for (int i = 1; i <= N; i++) {	//처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
		totalTime[i] = time[i];
		if (indegree[i] == 0) q.push(i);		
	}
	while (!q.empty()) {
		if (indegree[W] == 0) break;
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {	
			indegree[graph[now][i]]--;	// 해당 원소와 연결된 노드들의 진입차수에서 1빼기
			totalTime[graph[now][i]] = max(totalTime[graph[now][i]], time[graph[now][i]] +totalTime[now]);
			if (indegree[graph[now][i]] == 0) q.push(graph[now][i]); //새롭게 진입차수가 0이 되는 노드를 큐에 삽입
	
		}
	}
	cout << totalTime[W]<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tk; cin >> tk;
	while (tk--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {	//건설에 걸리는 시간 입력
			int t; cin >> t;
			time[i] = t;
		}
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);	//	정점 A에서 B로 이동가능
			indegree[b] += 1;	//진입차수 1 증가
		}
		cin >> W;
		
		topologySort();
		itit();	//테스트 케이스 여러개일 수 있으니 초기화
	}
	
	
}