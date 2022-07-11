#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


bool visited[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int>graph(N + 1);

		for (int i = 1; i <= N - 1; i++) {
			int a, b; cin >> a >> b;
			graph[b] = a;
		}
		int a, b; cin >> a >> b;
		visited[a] = true;
		while (a != graph[a]) {
			visited[a] = true;
			a = graph[a];
		}

		while (true) {

			if (visited[b] == true) {
				cout << b << '\n';
				break;
			}
			b = graph[b];

		}
		memset(visited, 0, sizeof(visited));
	}
}
