//  Copyright © 2021 안주형. All rights reserved.
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/12015
//  BOJ12015 가장 긴 증가하는 부분 수열2(Longest Increasing Subsequence,Lis)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	이분탐색을 이용하여 풀이.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int>dp;
	dp.push_back(0);
	for (int i = 0; i < n; i++) {
		int number; cin >> number;
		if (dp.back() < number) dp.push_back(number);	//벡터 마지막 값보다 입력받은 값이 더 크면 삽입한다.
		else {											//벡터 이전의 값보다 입력받은 값이 더 작으면
			auto it = lower_bound(dp.begin(), dp.end(), number);//이분 탐색을 통해 입력받은 값(number) 보다 같거나 큰 값의 인덱스를 받고
			*it = number;										//그 인덱스에 입력받은 값으로 갱신해준다.		
		}
	}
	cout << dp.size() - 1;
}