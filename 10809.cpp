//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10809
//  BOJ10809 알파벳 찾기
#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	string check = "abcdefghijklmnopqrstuvwxyz";
	cin >> S;
	for (int i = 0; i < check.length(); i++) {
		if (S.find(check[i]) == string::npos)
			cout << -1 << " ";
		else
			cout << S.find(check[i]) << " ";
		}

}