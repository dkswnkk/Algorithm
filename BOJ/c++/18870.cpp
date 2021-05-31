//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/18870
//  BOJ18870 좌표 압축 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	
	vector<int>v1, v2;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
			v1.push_back(num);
			v2.push_back(num);
	}
	sort(v1.begin(), v1.end());	//이분탐색을 위한 정렬
	
	v1.erase(unique(v1.begin(), v1.end()), v1.end());	//중복되는 값을 쓰레기 값으로 변경 후 제거.

	for (int i = 0; i < N; i++) {	//이분탐색
		int start = 0;
		int end = v1.size()-1;
		int target = v2[i];
		while (start <= end) {
			int mid = (start + end) / 2;
			if (target == v1[mid]) {
				cout << mid<< ' ';
				break;
			}
			else if (target > v1[mid]) start = mid + 1;	//오른쪽 탐색
			else end = mid - 1; //왼쪽탐색
		}
	}
}