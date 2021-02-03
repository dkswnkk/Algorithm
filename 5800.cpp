//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/5800
//  BOJ5800 성적 통계
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K; cin >> K;
	int max = 0;

	for(int i=1; i<=K; i++) {
		int n; cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int score; cin >> score;
			v.push_back(score);
		}
		sort(v.begin(), v.end(), greater<>());
		cout << "Class " << i << "\n"<<"Max "<< v[0] << ", Min " << v[n-1] << ", Largest gap ";
		for (int i = 1; i < v.size(); i++) {
			if (abs(v[i] - v[i - 1]) >= max) max = abs(v[i] - v[i - 1]);
		}
		cout << max << "\n";
		max = 0;

	}
}