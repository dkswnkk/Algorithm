//  Copyright © 2021 안주형. All rights reserved.
//  유니온 파인드 알고리즘
//  https://www.acmicpc.net/problem/15462
//  BOJ16562 친구비

#include <iostream>

using namespace std;
int parent[10001];
int cost[10001];
int N, M, k;	//N=학생의 수, M=친구 관계 수, k=가지고 있는 돈

int findParent(int x) {	//특정 원소가 속한 집합 찾기
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);	//루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
}

void unionParent(int a, int b) {	//두 원소가 속한 집합 합치기
	a = findParent(a);
	b = findParent(b);
	if (cost[a]<=cost[b]) parent[b] = a;	//비용이 작은 노드로 바꿔준다.
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {	// 친구비용 입력
		cin >> cost[i];
	}
	for (int i = 1; i <= N; i++) {	//부모 테이블 상에서, 부모를 자기 자신으로 초기화
		parent[i] = i;
	}
	for (int i = 1; i <= M; i++) {	//연결 요소 입력
		int a, b; cin >> a >> b;
		unionParent(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {	//출력
		int node = findParent(i);	//1번부터 순서대로 부모노드를 찾아서
		if (node != 0) {
			ans += cost[node];		//부모노드의 비용을 더해준다
			unionParent(0, node);	//한번 비용을 냈기때문에 친구의 친구들은 0원이 된다.
		}
	}
	if (ans > k) cout << "Oh no";	//만약 비용이 가지고 있는 돈을 초과할때
	else cout << ans;	//초과하지 않을때
}