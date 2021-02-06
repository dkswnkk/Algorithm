//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1259
//  BOJ1259 팰린드롬수

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string N; cin >> N;
		if (N == "0") return 0;
		int start = 0;
		int end = N.length() - 1;
		bool flag = true;
		while (start <= end) {
			if (N[start] != N[end]) flag = false;
			start++;
			end--;
		}
		if (flag) cout << "yes" << "\n";
		else cout<< "no"<<"\n";
	}
}