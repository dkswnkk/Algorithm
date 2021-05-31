//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/6588
//  BOJ6588 골드바흐의 추측

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		vector<int>check(1000001, true);
		vector<int>v;
		int N;

		for (int i = 2; i <=sqrt(1000001); i++) {	//에라토스테네스 알고리즘 수행
			if (check[i] == true) {
				if (i > 2) v.push_back(i);
				int j = 2;
				while (i * j <= 1000000) {
					check[i * j] = false;
					j++;
				}
			}
		}
	while (true) {
		int a, b; cin >> N;
		int ans = 0;
		if (N == 0) return 0;
		for (int i = 0; i < v.size(); i++) {
			if(check[N-v[i]]==true){
				 a = v[i];
				 b = N - v[i];
				 break;
			}
		}
		if (a != 0 && b != 0) cout << N << " = " << a << " + " << b << "\n";
		else cout << "Goldbach's conjecture is wrong."<<"\n";
	}
}