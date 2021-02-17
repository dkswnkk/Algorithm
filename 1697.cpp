//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1697
//  BOJ1697 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int N, K; //N=수빈이가 있는 위치 K=동생이 있는 위치
int visited[200001];
queue<int>q;
void bfs(int n) {

	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K) break;
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <=100000 && visited[x + 1] == 0) {
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
		if (2 * x <=100000 && visited[2 * x] == 0) {
			visited[2 * x] = visited[x] + 1;
			q.push(2 * x);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	bfs(N);
	cout << visited[K]-1;
}