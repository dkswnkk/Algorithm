//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1789
//  BOJ1789 수들의 합

#include <iostream>
#define ll long long 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll N,sum=0,cnt=0,i=1; cin >> N;
	
	while (true) {
		sum += i;
		i++;
		cnt++;
		if (sum > N) {
			cnt--;
			break;
		}
	}
	cout << cnt;


}