#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int visited[1001];
int cnt = 0;
int N, M;

void dfs(int x) {
	visited[x] = 1;

	for (int i = 1; i <=N; i++) {
		if (!visited[i] && map[x][i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N>>M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;	//연결요소 입력
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
}