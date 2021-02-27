//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/8892
//  BOJ8892 팰린드롬

#include <iostream>
#include <vector>
using namespace std;

bool flag1 = true,flag2=true;
string tmp1,tmp2;
vector<string>ans1,ans2;



void check1(string s) {
	int start = 0;
	int end = s.length() - 1;
	while (start <= end) {
		if (s[start] != s[end]) flag1 = false;
		start++;
		end--;
	}
}
void check2(string s) {
	int start = 0;
	int end = s.length() - 1;
	while (start <= end) {
		if (s[start] != s[end]) flag2 = false;
		start++;
		end--;
	}
}
void reset() {
	flag1 = true,flag2=true;
	string tmp1,tmp2;
	ans1.clear();
	ans2.clear();
}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);

		int T; cin >> T;
		while (T--) {	//테스트 케이스 만큼 반복
			reset();
			int N; cin >> N;
			vector<string>v;

			for (int i = 0; i < N; i++) {	//단어입력
				string s; cin >> s;
				v.push_back(s);
			}

			
			for (int i = 0; i < v.size()-1; i++) {
				for (int k = i + 1; k < v.size(); k++) {
					flag1 = true; flag2 = true;
					tmp1 = v[i] + v[k];
					tmp2 = v[k] + v[i];
					check1(tmp1);
					check2(tmp2);
					if (flag1) ans1.push_back(tmp1);	//단어를 합쳤을때 팰린드롭일 경우에 삽입.
					if (flag2) ans2.push_back(tmp2);
				}
			}
			if (!ans1.empty() || !ans2.empty()) {
				if (!ans1.empty()) cout << ans1[0] << "\n";
				else if(!ans2.empty()) cout << ans2[0] << "\n";
			}
			else  cout << 0 << "\n";		
		}
	}