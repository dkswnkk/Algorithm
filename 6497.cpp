//  Copyright © 2021 안주형. All rights reserved.
//  크루스칼 알고리즘(최소스패닝 트리)
//  https://www.acmicpc.net/problem/6497
//  BOJ6497 전력난

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int m, n, maxCost, minCost;	//m=집(노드)의 수, n=길(간선)의 수
int parent[200001];
vector<pair<int, pair<int, int>>>edges;

void init() {	//초기화 함수
	edges.clear();
	m = 0, n = 0, maxCost = 0, minCost = 0;
	memset(parent, 0, sizeof(parent));
}

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

	while (cin >> m >> n) {
		
		if (!m && !n) break;	//입력이 0 0 이면 종료

		for (int i = 1; i <= m; i++) {	//부모 테이블 상에서, 부모자신을 자기자신으로 초기화
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int a, b, c; cin >> a >> b >> c;
			edges.push_back({ c,{a,b} });	//비용으로 정렬을 하기 위해 튜플의 첫번쨰 원소에 비용 입력
			edges.push_back({ c,{b,a} });	//양방향 이기때문에 양방향처리
			maxCost += c;

		}
		sort(edges.begin(), edges.end());

		for (int i = 0; i < edges.size(); i++) {
			int cost = edges[i].first;
			int a = edges[i].second.first;
			int b = edges[i].second.second;

			if (findParent(a) != findParent(b)) {
				unionParent(a, b);
				minCost += cost;
			}
		}
		cout << maxCost - minCost<<"\n";	//최대비용 -최소비용 = 절약할수 있는 최대 비용
		init();	//테스트 케이스가 바뀔 수 있으니 초기화
	}
}



