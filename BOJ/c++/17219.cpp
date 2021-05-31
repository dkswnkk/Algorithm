//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/17219
//  BOJ17219 비밀번호 찾기
#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;

	map<string, string>m;
	for (int i = 0; i < N; i++) {
		string a, b; cin >> a >> b;
		m.insert({ a,b });
	}
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		cout << m[s] << '\n';
	}
}