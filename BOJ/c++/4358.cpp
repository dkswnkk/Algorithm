//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/4358
//  BOJ4358 생태학

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	int cnt = 0;
	map<string, int>m;

	while (getline(cin, input)) {
		m[input]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto i = m.begin(); i != m.end(); i++) {
		double percent;
		percent = (i->second / double(cnt)) * 100;
		cout << i->first << ' ' << percent << "\n";
	}
}