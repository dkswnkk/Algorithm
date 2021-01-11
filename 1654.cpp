//  Copyright © 2021 안주형. All rights reserved.
//  이분 탐색
//  https://www.acmicpc.net/problem/1654
//  BOJ1654 랜선 자르기
#include <iostream>
#include <vector>

using namespace std;

int K, N;  //K=랜선의 개수,  N=필요한 랜선의 개수
vector<long long int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K >> N;

	int  start = 1;
	long long int end = (1<<31)-1;	//랜선의 최대 길이
	long long int ans = 1;

	for (int i = 0; i < K; i++) {	//랜선의 길이 입력
		long long int length;
		cin >> length;
		v.push_back(length);
	}
	while (start <= end) {	//이진 탐색 수행
		long long int total = 0;
		long long int mid = (start + end) / 2;
		for (int i = 0; mid>0&&i < K; i++) {
			if (v[i] >= mid) total += v[i] / mid;		//잘랐을때의 랜선 갯수 저장
		}
		if (total <N) {					//랜선의 갯수가 부족할 경우 더 자른다(왼쪽탐색)
			end = mid - 1;
		}
		else {								//랜선의 갯수가 충분할 경우 최대한 덜 자른 값을 찾는다(오른쪽 탐색)
			ans = mid;						//mid값으로 자른경우가 결과이므로 저장한다.
			start = mid + 1;
		}
		
	}
	cout << ans;
}