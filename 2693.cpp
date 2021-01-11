//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2693
//  BOJ2693 N번째 큰 수
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--) {
		vector<int>map(11);
		for (int i = 0; i < 10; i++) {
			int number;
			cin >> number;
			if (!(find(map.begin(), map.end(), number) != map.end()));
			map[i] = number;
		}
		sort(map.begin(), map.end(), greater<int>());
		cout << map[2]<<"\n";
		
	}

}