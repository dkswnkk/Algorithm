//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍,피사노주기
//  https://www.acmicpc.net/problem/2749
//  BOJ2749 피보나치 수3
#include <iostream>
#include <vector>
const long long int mod = 1e6;
using namespace std;
vector<long long int>v(1500001); 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*	 피사노 주기.
		피사노 주기란 피보나치 수를 k로 나눴다고 했을 때, 그 나머지는 항상 주기를 가지게 되는데  이를 피사노 주기라고한다.
		피보나치에서 mod 값이 10^k 일때 k>2 이면, 주기는 항상 15*10^k-1 을 가진다.
	*/
	long long int n; cin >> n;
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;
	
	for (int i = 2; i <= 1500000; i++) {
		v[i] = (v[i - 1] + v[i - 2])%mod;
	}
	cout << v[n% 1500000];
}