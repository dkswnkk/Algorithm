//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2920
//  BOJ2920 음계

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;  getline(cin, s);
	vector<string>v;
	v.push_back(s);

	if (find(v.begin(), v.end(), "1 2 3 4 5 6 7 8") != v.end()) cout << "ascending";
	else if (find(v.begin(), v.end(), "8 7 6 5 4 3 2 1") != v.end())cout << "descending";
	else cout << "mixed";

	}
