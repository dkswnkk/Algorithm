//  Copyright © 2021 안주형. All rights reserved.
//  유니온 파인드 알고리즘
//  https://www.acmicpc.net/problem/1717
//  BOJ1717 집합의 표현

#include <iostream>

using namespace std;

int n, m;	//n=노드의 개수. m=연산(간선)의 개수
int parent[1000001]; //부모테이블 초기화

int findParent(int x) {	//특정 원소가 속한 집합을 찾기
	if (x == parent[x]) return x;	
	return parent[x] = findParent(parent[x]);//루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
}
void unionParent(int a, int b) {	//두 원소가 속한 집합을 합치기
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {	//부모 테이블 상에서, 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (!a) unionParent(b, c);	//a가 합친다는 의미이면
		else {
			if (findParent(b) == findParent(c)) {
				cout << "YES" <<"\n";
			}
			else cout << "NO" << "\n";
		}
	}
}