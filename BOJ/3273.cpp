//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/3273
//  BOJ3273 두 수의 합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, X, cnt = 0;	cin >> N;

	for (int i = 0; i < N; i++) {	//전체 수열 입력
		int num; cin >> num;
		v.push_back(num);
	}

	cin >> X;	//찾고자 하는 부분 합 입력

	sort(v.begin(), v.end());	//이분탐색을 하기위해 정렬

	for (int i = 0; i < N; i++) {	//이분탐색
		int start = 0; int end = N - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (v[mid] == X - v[i]) {
				cnt++;
				break;
			}
			else if (v[mid] < X - v[i]) 	//오른쪽 탐색
				start = mid + 1;
			else end = mid - 1;		//왼쪽탐색
		}
	}
	cout << cnt / 2;	//ex) (11,2) (2,11) 처럼 하나의 쌍을 두번 찾게 되므로 나눠준다.
}