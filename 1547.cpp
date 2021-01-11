//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1547
//  BOJ1547 공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v(4);
int main() {
	int M; cin >> M;
	v[1] = 1; v[2] = 0; v[3] = 0;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		swap(v[a], v[b]);
	}
	cout << max_element(v.begin(), v.end())-v.begin();
}