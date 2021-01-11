//  Copyright © 2021 안주형. All rights reserved.
//  크루스칼 알고리즘(최소 스패닝 트리)
//  https://www.acmicpc.net/problem/1922
//  BOJ1922 네트워크 연결

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int parent[1001];
int N, M; //N=컴퓨터의 수, M=연결 할 수 있는 선의 수
int a, b, c;
int ans = 0;
vector < pair<int, pair<int, int>>>edges;	//모든 간선을 담을 리스트와, 최종 비용으 담을 테이블

int findParent(int x) {
	if (x == parent[x]) return x;
	else return x = findParent(parent[x]);
}
void unionParent(int a,int b){
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {		//부모테이블 상에서, 부모자신을 자기 자신으로 초기화
		parent[i] = i;				
	}

	for (int i = 0; i < M; i++) {	//모든 간선에 대한 정보 입력
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });	//비용순으로 정렬하기 위해서 튜플의 첫번째 원소를 비용으로 설정
	}
	sort(edges.begin(), edges.end());	//간선을 비용 순으로 정렬(오름차순)

	for (int i = 0; i <edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {	//사이클이 발생하지 않는경우(같은 집합이 아닐때) 집합에 포함
			unionParent(a, b);
			ans += cost;	
		}
	}
		cout << ans;
}