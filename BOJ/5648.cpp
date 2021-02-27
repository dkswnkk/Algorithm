//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/5648
//  BOJ5648 역원소 정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll unsigned long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector <ll>v;
	while (N--) {
		string s; cin >> s;		//수를 뒤집기 위해 문자열로 입력받음.
		reverse(s.begin(), s.end());	//수 뒤집기
		ll num=stoull(s);	//수를 정수형으로 바꿔준다
		v.push_back(num);
	}
	sort(v.begin(), v.end());	//오름차순 대입
	for (ll i : v) {
		cout << i << "\n";
	}
	
}