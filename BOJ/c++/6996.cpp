//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/6996
//  BOJ6996 애너그램
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;

	while (N--) {
		string a, b; cin >> a >> b;
		string ans1 = a; string ans2 = b;
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(b.begin(), b.end(), b.begin(), ::tolower);
		if (a.length() != b.length()) cout << ans1 << ' ' << '&' << ' ' << ans2 << ' ' << "are NOT anagrams." << "\n";
		else {
			int cnt = 0;
			for (int i = 0; i < a.length(); i++) {
				for (int k = 0; k < b.length(); k++) {
					if (a[i] == b[k]) {
						cnt++;
						b[k] = '*';	//한번 검사해서 나온 값은 의미없는 값으로 대체
						break;
					}
				}
			}
			if (cnt == a.length())cout << ans1 << ' ' << '&' << ' ' << ans2 << ' ' << "are anagrams." << "\n";	
			else cout << ans1 << ' ' << '&' << ' ' << ans2 << ' ' << "are NOT anagrams." << "\n";
		}
	}
	

}