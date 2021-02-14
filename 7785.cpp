//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/7785
//  BOJ7785 회사에 있는 사람

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	map<string, string,greater<string>>m; //역순으로 출력하기위해 내림차순 정렬
	for (int i = 0; i < N; i++) {
		string a, b; cin >> a >> b;
		if (b == "enter") {
			m.insert({ a,b });	//(이름,출입정보)
		}
		else m.erase(a);	
	}
		for (auto i = m.begin(); i!= m.end(); i++) {	
			cout << i->first << "\n";
		}

}