//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/101328
//  BOJ11328 strfry

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	
	while (N--) {
		string a, b; cin >> a >> b;
	
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a==b) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
}