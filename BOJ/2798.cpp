//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2798
//  BOJ2798 블랙잭
#include <iostream>
#include <vector>
using namespace std;

vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	int max = 0;
	for (int i = 0; i < v.size()-2; i++) {
		for (int j = i + 1; j < v.size() - 1; j++) {
			for (int k = j + 1; k < v.size(); k++) {
				if (v[i] + v[j] + v[k] > M)continue;
				else {
					if (v[i] + v[j] + v[k] > max) max = v[i] + v[j] + v[k];
				}
			}
		}
	}
	cout << max;
}