//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/14720
//  BOJ14720 우유 축제
#include <iostream>
using namespace std;
int N, checkMilk,cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	while (1) {
		cin >> checkMilk;
		if (checkMilk == 0)	break;
		else N--;
	}
	cnt++;
	for (int i = 0; i < N; i++) {
		int milk; cin >> milk;
		if (checkMilk == 0 && milk == 1) {
			cnt++;
			checkMilk = milk;
		}
		else if (checkMilk == 1 && milk == 2) {
			cnt++;
			checkMilk = milk;
		}
		else if (checkMilk == 2 && milk == 0) {
			cnt++;
			checkMilk = milk;
		}
	}
	cout << cnt;
}