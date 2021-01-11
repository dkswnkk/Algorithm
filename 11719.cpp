//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11719
//  BOJ11719 그대로 출력하기2
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	for (int i = 0; i < 100; i++) {
		getline(cin, s); //엔터가 나오기 전까지 한 줄 입력
		cout << s << endl;
	}
}