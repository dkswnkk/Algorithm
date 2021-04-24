//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/13414
//  BOJ13414 수강신청

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//시간 초과 코드
	/*
	int k, L; cin >> k >> L;
	vector<int>ans;
	for (int i = 0; i < L; i++) {
		int sno; cin >> sno;
		if (find(ans.begin(), ans.end(), sno) != ans.end()) {	//중복되는 값이 있을경우
			auto it = find(ans.begin(), ans.end(), sno) - ans.begin();
			ans.erase(ans.begin() + it);	//삭제하고
			ans.push_back(sno);	//맨뒤에 삽입
		}
		else ans.push_back(sno);	//중복되는 값이 없을 경우 그냥 삽입
	}
	for (int i = 0; i < k; i++) {
		cout << ans[i] << "\n";
	}
	*/

	map<string, int>m;
	vector<pair<int, string>>v;

	int k, L; cin >> k >> L;
	for (int i = 0; i < L; i++) {
		string number; cin >> number;
		m[number] = i + 1;
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		string a = i->first;
		int b = i->second;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++) {	//출력
		cout << v[i].second << "\n";
	}
}