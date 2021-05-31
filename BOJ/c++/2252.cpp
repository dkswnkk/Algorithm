//  Copyright © 2021 안주형. All rights reserved.
//  위상 정렬(topologySort)알고리즘
//  https://www.acmicpc.net/problem/2252
//  BOJ2252 줄 세우기

#include <iostream>
#include <queue>

using namespace std;
int N, M;	//N=학생의 수,	M=키 비교 횟수
int indegree[32001];	//모든 노드에 대한 집입차수는 0으로 초기화
vector<int>graph[32001];

void topologySort() {
	vector<int>result; //위상정렬 수행 결과를 담을 리스트
	queue<int>q;	
	
	for (int i = 1; i <= N; i++) {	//처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
		if (indegree[i] == 0) q.push(i);
	}
	
	while (!q.empty()) {	//큐가 빌 때까지 반복
		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int i = 0; i < graph[now].size(); i++) {	//해당 원소와 연결된 노드들의 진입차수에서 1빼기
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0) q.push(graph[now][i]);	//새롭게 진입차수가 0이 되는 노드를 큐에 삽입
		}
	}
	for (int i = 0; i < result.size(); i++) {	//위상 정렬을 수행한 결과 출력
		cout << result[i] << ' ';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);	//정점 A에서 B로 이동가능
		indegree[b] += 1;		//진입 차수를 1증가
	}
	topologySort();

}