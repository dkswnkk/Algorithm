//  Copyright © 2021 안주형. All rights reserved.
//  위상 정렬(topologySort)알고리즘
//  https://www.acmicpc.net/problem/1766
//  BOJ1766 문제집

#include <iostream>
#include <queue>

using namespace std;
int N, M;	//N=문제의 수, M=문제 정보의 수
vector<int>graph[32001];
int indegree[32001];

void topologySort() {
	priority_queue<int, vector<int>, greater<int>>pq;	//최소힙으로 변경
	vector<int>ans;	//알고리즘 수행 결과를 담을 테이블

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	while (!pq.empty()) {
		int now = pq.top();
		ans.push_back(now);
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]] -= 1;	//진입 차수 하나 제거
			if (indegree[graph[now][i]] == 0) pq.push(graph[now][i]);	//진입 차수가 0일때 큐에 넣음
		}
	}
	for (int i : ans) {
		cout << i << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {	//간선 정보 입력
		int a, b; cin >> a >> b;
		graph[a].push_back(b);	//정점A에서 B로 이동 가능
		indegree[b] += 1;	// 진입 차수를 1 증가
	}
	topologySort();	//위상정렬 알고리즘 수행
}