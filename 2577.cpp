//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2577
//  BOJ2577 숫자의 개수
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int	 mul = A * B * C;
	string s = to_string(mul);
	int ans;

	 vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	
	for (int i = 0; i < v.size(); i++) {
		ans = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j]==v[i]+'0') ans++;
		}
		cout << ans << "\n";
	}
}
