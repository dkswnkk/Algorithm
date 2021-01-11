//  Copyright © 2021 안주형. All rights reserved.
//  다익스트라 알고리즘  
//  https://www.acmicpc.net/problem/11799
//  BOJ11779 최소비용 구하기2

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 //무한을 뜻하는 값으로 10억을 지정.

using namespace std;

vector<pair<int, int>>graph[1001];
int d[1001];//비용을 저장해두는 테이블
int N, M, start, fin; //N=도시(노드)의 개수, M=버스(간선)의 개수 ,start=시작점, fin=도착점
int	route[1001]; //최소비용을 갖는 경로를 방문하는 도시를 저장하는 테이블




void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });	//시작점의 비용은 0
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;	//이미 처리된 노드라면 무시한다.
		for (int i = 0; i < graph[now].size(); i++) {
			int neighbor = graph[now][i].first;
			int neighborDist = dist + graph[now][i].second;
			if (neighborDist < d[neighbor]) {
				d[neighbor] = neighborDist;
				route[neighbor] = now;	//방문하는 도시 저장.route[i]=경로에서 i노드로 가기 바로 직전 노드
				pq.push({ neighborDist,neighbor });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;	//간선 정보 입력
		graph[a].push_back({ b,c });		// a에서 b까지 가는데 c만큼의 비용 필요
	}
	cin >> start >> fin;
	fill(d, d + 1001, INF);

	dijkstra(start);

	cout << d[fin] << "\n";	//최소비용 출력
	vector<int>ans;
	int node = fin;

	while (node) {
		ans.push_back(node);
		node = route[node];	//경로를 역으로 저장하고 1일 경우 0이기 때문에 while 문 탈출
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {	//역순으로 저장되므로.
		cout << ans[i] << " ";
	}
}