//  Copyright © 2021 안주형. All rights reserved.
//
//  https://www.acmicpc.net/problem/1015
//  BOJ1015 수열 정렬
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int A; //배열의 크기
	cin >> A;
	vector<int>arr_value;
	vector<int>arr_index;
	vector<int>ans;
	for (int i = 0; i < A; i++) {
		int number;
		cin >> number;
		arr_value .push_back(number);
		arr_index.push_back(number);

	}
	sort(arr_index.begin(), arr_index.end());

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (arr_value[i] == arr_index[j]) {
				ans.push_back(j);
				arr_index[j] = -1;	//먼저 나오는 똑같은 값을  인덱스로 판단할수 있기때문에 값 변경.
				break;		
			}
		}
	}
	for (int i = 0; i < A; i++) {
		cout << ans[i]<<" ";
	}


}