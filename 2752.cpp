//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2752
//  BOJ2752 세 수 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v(3);
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	v[0] = a; v[1] = b; v[2] = c;
	sort(v.begin(), v.end());

	for (int i : v) {
		cout << i << " ";
	}

}