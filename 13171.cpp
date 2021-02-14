//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/13171
//  BOJ13171 A

/*
10^4를 구할때 10*10*10*10  보다는 10^2 * 10^2 가 더 빠른 경우임을 생각하여 풀이한다.
a^b일때 b가 홀수인 경우는 a를 한번 더 곱해줘야 한다.
*/
#include <iostream>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	else {
		ll n = pow(a, b / 2);
		ll temp = (n * n) % mod;
		if (b % 2 == 0) return temp;
		else return (temp * a) % mod;
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll A, B; cin >> A >> B;
	cout << pow(A%mod, B); //mod로 먼저 나눠주는게 핵심.

}