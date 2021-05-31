//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1541
//  BOJ1541 잃어버린 괄호

/*
뺄셈 이후마다 괄호를 치면 최소가 된다.
*/

#include <iostream>
#include <string>

using namespace std;

string s, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	bool minus = false;
	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-' || s[i] == '+') {	//연산자일때
			if (minus)	ans -= stoi(temp);	//마이너스 연산자가 나온상태이면 값을 빼준다.
			else ans += stoi(temp);
			temp.clear();
			if (s[i] == '-') minus = true;
		}
		else temp += s[i];	//피연산자일때
	}

	if (minus) ans -= stoi(temp);	//마지막 연산자 이후의 수를 마무리해준다.
	else ans += stoi(temp);

	cout << ans;
}