//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/5635
//  BOJ5635 생일
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<tuple<int,int,int,string>>v;	//연도 순으로 정렬하기 때문에 투플의 원소를 순서대로 연 월 일 이름으로 지정
	while (n--) {
		string name;
		int y, m, d;
		cin >> name >> d >> m >> y;
		v.push_back(make_tuple( y, m, d, name) );
	}
		sort(v.begin(), v.end());	//오름차순으로 정렬

		cout << get<3>(v[v.size()-1]) << "\n" << get<3>(v[0]);	
}