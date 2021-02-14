//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1629
//  BOJ1629 곱셈
#include <iostream>
#define ll long long
using namespace std;

/*
10^4를 구할때 10*10*10*10  보다는 10^2 * 10^2 가 더 빠른 경우임을 생각하여 풀이한다.
a^b일때 b가 홀수인 경우는 a를 한번 더 곱해줘야 한다.
*/
ll pow(ll a, ll b, ll c) {
	if (b == 0) return 1;
	else {
		ll temp = pow(a, b / 2, c);	
		temp = temp * temp % c;

		if (b % 2 == 0) return temp;	//b가 짝수일때
		else return (temp * a) % c;		//b가 홀수일때

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C; cin >> A >> B >> C;

	cout << pow(A, B, C);

}
