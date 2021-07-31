//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1676
//  BOJ1676 팩토리얼 0의 개수

#include <iostream>
using namespace std;

/*
인수로 5가 들어가는 갯수만 세어주면 된다.
EX) 10!= 10*9*8*7*6*5*4*3*2*1 = 2
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,ans=0; cin >> n;

	while (n >= 5) {
		ans += n / 5;
		n /= 5;
	}

	cout << ans;
}
