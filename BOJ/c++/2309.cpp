//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/2309
//  BOJ2309 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v,ans;
	int sum = 100;
	for (int i = 0; i < 9; i++) {
		int num; cin >> num;
		if(num<100)	v.push_back(num);
	}
	sort(v.begin(), v.end());

	for(int a=0; a<v.size()-6; a++){
		for (int b = a + 1; b < v.size() -5; b++) {
			for (int c = b + 1; c < v.size() - 4; c++) {
				for (int d = c + 1; d < v.size()-3; d++) {
					for (int e = d + 1; e < v.size()-2; e++) {
						for (int f = e + 1; f < v.size()-1; f++) {
							for (int h = f + 1; h < v.size(); h++) {
								if (v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + v[h] == 100) {
									cout << v[a] << "\n" << v[b] << "\n" << v[c] << "\n" << v[d] << "\n" << v[e] << "\n" << v[f] << "\n" << v[h];
									break;
								}
							}
						}
					}
				}
			}
		}
	
	}


}