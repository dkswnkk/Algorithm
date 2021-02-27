//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/1316
//  BOJ1316 그룹 단어 체커
#include <iostream>
#include <memory.h>

using namespace std;


int cnt = 0;
bool flag = true;
void check(string s) {
	for (int i = 0; i < s.length() - 2; i++) {	
		if (s[i] != s[i + 1]) {	//1과 2의 단어가 다를때
			for (int k = i + 2; k < s.length(); k++) {	//3부터 끝까지 체크해 1과 같은 단어가 있는지 체크
				if (s[i] == s[k]) {
					flag = false;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int ans = 0;
	while (N--) {
		string s; cin >> s;
		if (s.length() == 1) ans++;	//단어가 한글자라면 그룹단어이다.
		else {	//단어가 한글자가 아니라면	
			check(s);	//탐색한다
			if (flag) ans++;
			flag = true;
		}
	}
	cout << ans;
}