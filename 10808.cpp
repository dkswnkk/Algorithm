//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10808
//  BOJ10808 알파벳 개수
#include <iostream>
#include <vector>

using namespace std;
vector<char>alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
vector<int>ans(alphabet.size());
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < alphabet.size(); j++) {
			if (s[i] == alphabet[j]) ans[j]++;
		}
	}
	for (int i : ans) {
		cout << i << " ";
	}
}
