#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;


vector<int>indegree[MAX + 1];
unordered_map<int, int> outdegree; // node, cnt
unordered_set<int> node;
int edge_cnt = 0;

int remove_leaf() {
	queue<int> q;
	int remove_cnt = 0;

	for (auto cur : node) {
		if (outdegree[cur] == 0 && indegree[cur].size() == 1) {
			q.push(cur);
		}
	}

	while (!q.empty()) {
		remove_cnt++;
		int nod = q.front();
		q.pop();

		if (indegree[nod].size() == 1) {
			vector<int> nexts;
			for (auto next : indegree[nod]) {
				nexts.push_back(next);
			}
			for (auto next : nexts) {
				outdegree[next]--;
				if (outdegree[next] == 0 && indegree[next].size() == 1) {
					q.push(next);
				}
			}
		}
	}
	return remove_cnt;
}


void init() {
	outdegree.clear();
	node.clear();
	for (int i = 0; i < MAX; i++) indegree[i].clear();
	edge_cnt = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	int num = 1;
	while (cin >> a >> b) {
		if (a == -1 && b == -1) break;
		else if (a == 0 && b == 0) {
			int leaf_cnt = remove_leaf();
			if (node.size() == 0 || node.size() == leaf_cnt + 1)  cout << "Case " << num << " is a tree."<<'\n';
			else cout << "Case " << num << " is not a tree." << '\n';
			num++;
			init();
		}
		else {
			edge_cnt++;
			if (a != b) outdegree[a]++;
			indegree[b].push_back(a);
			node.insert(a);
			node.insert(b);
		}

	}
}
