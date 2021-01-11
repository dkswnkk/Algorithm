//  Copyright © 2021 안주형. All rights reserved.
//  유니온 파인드 알고리즘
//  https://www.acmicpc.net/problem/1976
//  BOJ1976 여행가자

#include <iostream>
#include <set>
using namespace std;
int N, M; //N=노드(도시)의 수
int parent[201];	//부모테이블 초기화

int findParent(int x) {	//특정 원소가 속한 집합 찾기
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);	//루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
}
void unionParent(int a, int b) {	//두 원소가 속한 집합 합치기
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {	//부모테이블 상에서 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {	//연결 요소 입력.
		for (int j = 1; j <= N; j++) {
			int input; cin >> input;
			if (input) unionParent(i, j);
		}
	}

	set<int>s;
	for (int i = 1; i <= M; i++) {
		int n; cin >> n;
		s.insert(findParent(n));	//부모값을 중복없이 넣는다.
	}

	if(s.size()==1) cout << "YES";		//부모가 다르다면 set에 사이즈가 2이상일것이다.
	else cout << "NO";
}
