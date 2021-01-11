//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11652
//  BOJ11652 카드
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; 
	cin >> N;
	vector<long long> number;
	int cnt = 1, max = 1;
	long long ans;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		number.push_back(num);
	}
	sort(number.begin(),number.end());
	ans = number[0];
	for (int i = 1; i < N; i++) {
		if (number[i] == number[i-1]) {
			cnt++;
			if (max < cnt) {
				max = cnt;
				ans = number[i];
			}
		}
		else cnt = 1;
	}
	cout << ans;
	
}