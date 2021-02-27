//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1431
//  BOJ1431 시리얼 번호
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();	//길이가 다른경우 짧은 것 부터 나열
	
	else  { //길이가 같은경우 
		int sumA=0,sumB= 0;
		for (int i = 0; i <a.length(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) sumA += a[i] - '0';
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) sumB += b[i] - '0';
		}
		if (sumA != sumB) return  sumA < sumB;	// 합이 작은게 앞으로
		else return a < b;	//합이 같을경우 사전순으로
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<string>v;
	while (N--) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);

	for (string s : v) {
		cout << s << "\n";
	}
}