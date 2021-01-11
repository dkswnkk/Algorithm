//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11656
//  BOJ11656 접미사 배열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s,temp; cin >> s;
	vector<string>v;
	for (int i = 0; i < s.length(); i++) {
		for (int k = i; k < s.length(); k++) {
			temp += s[k];
		}
			v.push_back(temp);
			temp.clear();
	}
	sort(v.begin(), v.end());
	for (string s : v) {
		cout<<s<<"\n";
	}
}