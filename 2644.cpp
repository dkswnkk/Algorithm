//  Copyright © 2021 안주형. All rights reserved.
//  bfs알고리즘
//  https://www.acmicpc.net/problem/2644
//  BOJ2644 촌수계산
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int start,finish;	//찾는 촌수
int N;	//전체 사람의 수
int map[101][101];
int dp[101];



void bfs(int n) {	//시작 노드(촌수)부터 탐색한다.
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {	//사람 수 만큼 bfs탐색을 통해 촌수를 살펴본다.
			if (map[x][i]&&!dp[i]) {	//촌수가 연결되어있고, 방문하지 않았다면
				dp[i] = dp[x] + 1;		//그 촌수에 전의 촌수 를 더해준다.
				q.push(i);	
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;	
	cin >> start>>finish;
	int count; cin >> count;

	for (int i = 0; i < count; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = map[b][a] = 1;	//연결되어 있는 촌수들을 양방향으로 만들어준다.
	}
	bfs(start);
	if (dp[finish] == 0) cout << -1;	//촌수가 연결되어있지 않을때
	else cout << dp[finish];			//촌수가 연결되어 있을때 몇촌인지 출력.
	
}

