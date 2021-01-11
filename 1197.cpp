//  Copyright © 2021 안주형. All rights reserved.
//  크루스칼 알고리즘(최소스패닝 트리)
//  https://www.acmicpc.net/problem/1197
//  BOJ1197 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int V, E;	// V=정점의 개수, E=간선의 개수
int parent[10001];	//부모 테이블 초기화
vector<pair<int, pair<int, int>>>edges;	//모든 간선을 담을 리스트와, 최종 비용을 담을 변수
int ans = 0;

int findParent(int x) {
	if (x == parent[x]) return x;
	else return x = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {	//부모 테이블상에서, 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {	//모든 간선에 대한 정보 입력
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost, { a,b } });	//비용 순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
	}
	sort(edges.begin(), edges.end());	//간선을 비용순으로 정렬(오름차순)

	for (int i = 0; i < edges.size(); i++) {	//간선을 하나씩 확인
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		 
		if (findParent(a) != findParent(b)) {	//사이클이 발생하지 않는 경우에만 집합에 포함
			unionParent(a, b);
			ans += cost;
		}
	}
	cout << ans;
}