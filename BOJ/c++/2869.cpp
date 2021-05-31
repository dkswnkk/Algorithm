//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2869
//  BOJ2869 달팽이는 올라가고 싶다
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int A, B, V;cin >> A >> B >> V;
	if ((V - B) % (A - B) == 0) {
		cout << ((V-B)/(A-B));
		return 0;
	}
	else cout << ((V-B)/(A-B)+1);
	return 0;

}