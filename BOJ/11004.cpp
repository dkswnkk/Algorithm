//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11004
//  BOJ11004 K번째 수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N, A;
	cin >> N>>A;
	vector<long long int>v(N);

	for(int i=0; i<N; i++){
		long long int number;
		cin >> number;
		v[i] = number;
		
	}
	sort(v.begin(), v.end());

	cout << v[A-1];

}