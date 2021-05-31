//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1620
//  BOJ1620 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;  cin >> N >> M;
	map<string, int>poketName;
	map<int, string>poketNumber;
	for(int i=1; i<=N; i++) {	//1번부터 N번까지의 포켓몬 입력
		string s; cin >> s;
		poketName.insert({ s,i });
		poketNumber.insert({ i,s });
	}
	for (int i = 0; i < M; i++) {
		string ans; cin >> ans;
		if (ans[0] >= '0' && ans[0] <= '9') {	//입력이 숫자일때
			cout << poketNumber[stoi(ans)]<<"\n";
		}
		else {	//입력이 문자열일때
			cout << poketName[ans]<<"\n";
		}
		
	}

}