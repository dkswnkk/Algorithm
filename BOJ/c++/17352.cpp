//  Copyright © 2021 안주형. All rights reserved.
//  유니온 파인드 알고리즘 
//  https://www.acmicpc.net/problem/17352
//  BOJ17352 여러분의 다리가 되어 드리겠습니다!

#include <iostream>

using namespace std;
int N;	//섬의 개수
int parent[300001];

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
/*
서로 부모노드가 다른 집합을 출력하면 된다.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {	//부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < N - 2; i++) {
		int a, b; cin >> a >> b;
		unionParent(a, b);		//unionParent 수행
	}
	int check = findParent(1);	//체크할 부모노드를 첫번째 섬으로 해놓고 
	for (int i = 1; i <= N; i++) {
		if (check!=findParent(i)) {	//만약 어떤 섬의 부모노드가 다를경우
			cout << check << ' ' << findParent(i);	//각각 부모노드들을 출력한다.
			break;
		}
	}
}