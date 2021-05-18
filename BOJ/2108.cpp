//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2108
//  BOJ2108 통계학

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, sum = 0; cin >> n;
	vector<int> v, secondCheck;
	map<int, int>m;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		m[input]++;
		sum += input;
		v.push_back(input);
	}
	int maxCnt = 1, maxValue = -1,value=v[0];
	bool flag = false, cntCheck = false;;
	if (m.size() == 1) flag = true;

	if (!flag) {
		for (auto i = m.begin(); i != m.end(); i++) {	//최빈값 을 찾는다.
			if (i->second > maxValue) {
				maxValue = i->second;
				value = i->first;

			}
		}
		for (auto i = m.begin(); i != m.end(); i++) {	//그 최빈값이 여러개일경우 두번째로 작은 값을 찾기위해 다른 배열에 넣어둔다.
			if (i->second == maxValue) {
				secondCheck.push_back(i->first);
			}
		}
	}
	else maxValue = v[0];
	
	sort(secondCheck.begin(), secondCheck.end());	//정렬
	sort(v.begin(), v.end());

	
	if (sum == 0) cout << 0 << "\n";
	else cout << round(sum / (double)n) << "\n";	//소수점 첫째자리에서 반올림

	if (n == 1) cout << v[0] << '\n';
	else cout << v[n / 2] << "\n";	

	if (secondCheck.size() >= 2) {	//최빈값이 여러개 일때 최빈값 중 두번째로 작은 값 출력
		cout << secondCheck[1] << '\n';
	}
	else cout << value<<'\n';	//최빈값이 하나일때 그대로 출력

	cout << v.back()-v.front();	//범위 출력
	
}