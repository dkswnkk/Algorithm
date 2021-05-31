//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1026
//  BOJ1026 보물
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	int ans = 0;
	cin >> T;
	vector<int>less(T);
	vector<int>greate(T);

	for (int i = 0; i < T; i++) {
		cin >> less[i];
	}
	for (int i = 0; i < T; i++) {
		cin >> greate[i];
	}
	sort(less.begin(), less.end());	//오름차순 정렬
	sort(greate.begin(), greate.end(), greater<int>()); //내림차순 정렬

	for (int i = 0; i < T; i++) {
		ans += less[i] * greate[i];
	}
	cout << ans<<"\n";
}