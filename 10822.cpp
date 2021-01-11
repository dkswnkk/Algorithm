//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10822
//  BOJ10822 더하기
#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;
vector<string>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string>v;
	string s; cin >> s;
	string stringBuffer;
	stringstream ss(s);

	while (getline(ss, stringBuffer, ',')) {
		v.push_back(stringBuffer);
	}
	
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += stoi(v[i]);
	}
	cout << ans;
	
	

	
}