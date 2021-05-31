//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10824
//  BOJ10824 네 수

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string temp1, temp2;
	string a, b, c, d; cin >> a >> b >> c >> d;
	temp1 = a + b;
	temp2 = c + d;
	cout << stoll(temp1) + stoll(temp2);

}

