//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2007
//  BOJ1924 2007년

#include <iostream>

using namespace std;

void check(int n) {
	if (n == 1) cout << "MON";
	else if (n == 2) cout << "TUE";
	else if (n == 3) cout << "WED";
	else if (n == 4)cout << "THU";
	else if (n == 5)cout << "FRI";
	else if (n == 6)cout << "SAT";
	else cout << "SUN";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y; cin >> x >> y;

	if (x == 1) check(y % 7);
	else if (x == 2) check((y + 3) % 7);
	else if (x == 3) check((y + 3) % 7);
	else if (x == 4) check((y + 6) % 7);
	else if (x == 5) check((y + 1) % 7);
	else if (x == 6) check((y + 4) % 7);
	else if (x == 7) check((y + 6) % 7);
	else if (x == 8) check((y + 2) % 7);
	else if (x == 9) check((y + 5) % 7);
	else if (x == 10) check(y % 7);
	else if (x == 11) check((y + 3) % 7);
	else if (x == 12) check((y + 5) % 7);

}