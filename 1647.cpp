//  Copyright © 2021 안주형. All rights reserved.
//  크루스칼 알고리즘(최소 스패닝 트리)
//  https://www.acmicpc.net/problem/1647
//  BOJ1647 도시 분할 계획

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;	//N=집의 개수(노드), M=길의 개수(간선)
int parent[100001];
int ans = 0;
vector<int>totalCost;
vector<pair<int, pair<int, int>>>edges;
/*
문제해결 아이디어
1.마을의 이장은 마을을 두개의 분리된 마을로 분할할 것이다.
2.각 마을에는 집이 하나 이상 있어야 한다.
따라서 최소 스패닝 트리가 두개 라는 소리이다.
모든 길들의 합이 최소가 되도록 스패닝 트리를 두개를 만들려면 최대 가중치로 연결되어있는 집(노드)를 하나 분리하면 된다.
이는 오름차순으로 정렬되어있는 비용의 테이블에서 마지막 원소를 더하지 않으면 된다.
*/
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
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {	//부모 테이블 상에서, 부모 자신을 부모 자기자신으로 초기화
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({c, { a,b }});	//비용을 기준으로 정렬하기 위해 튜플의 첫번째 원소를 비용으로 삽입
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			totalCost.push_back(cost);	//비용을 모두 테이블에 저장한다.
		}
	}
		for (int i = 0; i < totalCost.size() - 1; i++) {	//스패닝 트리를 두개 만들어야 하기 때문에 최대 가중치인 마지막 원소를 더하지 않는다.
		ans += totalCost[i];
		}
	cout << ans;

}