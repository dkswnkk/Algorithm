//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/1110
//  BOJ1110 더하기 사이클

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string check; cin >> check;
	string cycle;
	int cnt = 0;

	if (check.length() == 1) {
		check = "0" + check;
	}
	cycle = check;
	while (true) {
		int temp = stoi(cycle) / 10 + stoi(cycle) % 10;
		int temp3 = stoi(cycle) % 10;
		cycle = to_string(temp3) + to_string(temp % 10);
		if (check == cycle) break;
		else cnt++;
	}
	cout << cnt + 1;
}