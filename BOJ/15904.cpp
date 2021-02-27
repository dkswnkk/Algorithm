//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/15904
//  BOJ15904 UCPC는 무엇의 약자일까?

#include <iostream>
#include <string>

using namespace std;

string s, ans;
bool U, C1, P, C2;

void check(char c) {
	if (ans != "UCPC") {
		if (c == 'U' && U == false&&U==false) {
			ans += c;
			U = true;
		}
		if (c == 'C' && U == true&&C1==false) {
			ans += c;
			C1 = true;
		}	if (c == 'P' && C1 == true&&P==false) {
			ans += c;
			P = true;
		}
		if (c == 'C' && P == true&&C2==false) {
			ans += c;
			C2 == true;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		check(s[i]);
	}

	
	if (ans == "UCPC") cout << "I love UCPC";
	else cout << "I hate UCPC";
	
	



}