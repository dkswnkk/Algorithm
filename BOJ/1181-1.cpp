//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1181
//  BOJ1181	단어정렬
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string>v;
bool desc(string a, string b) {
	if (a.length() == b.length()) return a < b;	//길이가 같으면 사전순으로 정렬
	else return a.length() < b.length();		//길이가 다르면 짧은 것 부터 정렬
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		string s; cin >> s;
		v.push_back(s);	//배열에 같은 문자가 없을때 삽입.
	}

	sort(v.begin(), v.end(), desc);	//정해준 기준으로 정렬

	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			if (v[i] != v[v.size() - 2]) {
				cout << v[i];
				return 0;
			}
		}
		if (v[i] == v[i+1]) continue;
		else cout << v[i] << "\n";
	}

}