//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10825
//  BOJ10825 국영수
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<string, int, int, int>a, tuple<string, int, int, int>b) {
	if (get<1>(a) == get<1>(b)) {	//국어 점수가 같을때
		if (get<2>(a) == get<2>(b)) {	//국어점수와 영어점수가 같을때
			if (get<3>(a) == get<3>(b)) { //국어,영어,수학 점수가 같을때
				return get<0>(a) < get<0>(b); //사전 순으로 출력
			}
			return get<3>(a) > get<3>(b);	//수학점수가 감소하는 순으로 출력
		}
		return get<2>(a) < get<2>(b); //영어 점수가 증가하는 순으로 출력
	}
	else return get<1>(a) > get<1>(b);	//국어 점수가 다를때 감소하는 순으로 출력
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<tuple<string, int, int, int>>v;
	while (N--) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(make_tuple(name, kor, eng, math));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << get<0>(v[i]) << "\n";
	}
}