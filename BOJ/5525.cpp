//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/5525
//  BOJ5525 IOIOI

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	string s; cin >> s;

	int cnt = 0, ans = 0;

	for (int i = 0; i < s.length();) {
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {	//연속적으로 IO가 나올때
			cnt++;
			i += 2;
		}
		else {
			if (cnt != n) cnt = 0;
			i++;
		}
		if (cnt == n) {
			ans++;
			cnt--;
		}
	}
	cout << ans;
}