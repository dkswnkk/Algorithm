//  Copyright © 2021 안주형. All rights reserved.
//  이분탐색
//  https://www.acmicpc.net/problem/2805
//  BOJ2805 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;	//N=나무의 수 , M=가져가려는 나무의 길이
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		v.push_back(height);
	}
	
	int start = 0; //이진 탐색을 위한 시작점 끝점 설정.
	int end = 2e9;
	int result = 0;

	while (start <= end) {	//이진 탐색 수행
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (v[i] > mid) total += v[i] - mid;	//잘렸을 때의 나무길이 계산.
		}
		if (total < M) {	//나무 길이가 부족할 경우 더 많이 자른다. (mid를 왼쪽으로 옮겨 탐색)
			end = mid - 1;
		}
		else {		//나무길이가 충분 할 경우 덜 잘라서 최대한 덜 자른 값을 찾는다. (start를 mid오른쪽으로 옮긴다.)
			result = mid;	//최대한 덜 잘랐을때가 정답이므로 기록한다.
			start = mid + 1;
		}
	}
	cout << result;

}
