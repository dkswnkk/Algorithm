//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/4458
//  BOJ4458 첫 글자를 대문자로
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	  int N; cin >> N;
	  cin.ignore();
	  for (int i = 0; i < N; i++) {
		string s; getline(cin, s);
		transform(s.begin(), s.begin()+1, s.begin(), ::toupper);
		cout << s << "\n";
	}
}