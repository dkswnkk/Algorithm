//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/15903
//  BOJ15903 카드 합체 놀이

#include <iostream>
#include <queue>
#define ll long long int

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m; //n=카드의 개수, m=카드 합체 수 
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>>pq;	//최소힙
	for (ll i = 0; i < n; i++) {
		int num; cin >> num;
		pq.push(num);
	}
	while (m--) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		ll sum = a + b;
		pq.push(sum);
		pq.push(sum);
	}
	
	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;

}