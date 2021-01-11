//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/4470
//  BOJ4470 줄번호
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	cin.ignore();
	for(int i=1; i<=N; i++) {
		string s; getline(cin, s);
		cout << i << "." << " " << s << "\n";
	}
}