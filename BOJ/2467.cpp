//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2467
//  BOJ2467 용액

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2147483647
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int>v,ans;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int start = 0, end = N - 1,check=0;
	int minValue = INF;
	int check1, check2;
	while (start < end) {
		int temp = abs(v[start] + v[end]);
		if (temp < minValue) {
			minValue = temp;
			check1 = v[start];
			check2 = v[end];
		}
		if (v[start] + v[end] < 0) start++;
		else end--;
	}
	
	cout << min(check1,check2) << " " << max(check1,check2);
}