//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2490
//  BOJ2490 윷놀이
#include <iostream>
using namespace std;

void check(int x) {
	if (x == 1)  cout << "C" << "\n";
	else if (x == 2)  cout << "B" << "\n";
	else if (x == 3) cout << "A" << "\n";
	else if (x == 4) cout << "E" << "\n";
	else if (x == 0) cout << "D" << "\n";

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int sum = 0;
		sum = a + b + c + d;
		check(sum);
	}
}