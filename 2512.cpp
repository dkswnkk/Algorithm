//  Copyright © 2021 안주형. All rights reserved.
//  이분탐색
//  https://www.acmicpc.net/problem/2512
//  BOJ2512 예산

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, check;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
		if (num > max) max = num;
	}
	cin >> check;

	int start = 0;
	int end = max;
	int result = 0;
	
	while (start <= end) {			//이진 탐색 시작
		 int mid = (start + end) / 2;
		 int total = 0;

		for (int i = 0; i < N; i++) {
			if (v[i] > mid) {		//지방 요청 예산이 더 클 경우 
				total += mid;		//상한액을 더한다
			}
			else {					// 지방 요청 예산이 더 작을 경우
				total += v[i];		//	 지방 요청 예산을 더한다
			}
		}
		if (total > check) {	//요청예상 총합이 총예산보다 많을때 왼쪽탐색을한다
			end = mid - 1;
		}
		else {					//요청예상 총합이 총예산보다 적을때 오른쪽탐색을 한다. (이때 mid값이 상한액이된다.)
			start = mid + 1;
			result = mid;
		}
		
	}
	
	cout << result;

}