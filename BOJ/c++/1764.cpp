//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1764
//  BOJ1764 듣보잡
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<string>peo;
	vector<string>peo_check;
	vector<string>ans;
	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		peo.push_back(input);
	}
	for (int i = 0; i < M; i++) {
		string input; cin >> input;
		peo_check.push_back(input);
	}
	sort(peo.begin(), peo.end());


	for (int i = 0; i < M; i++) {	//이진탐색 
		int start = 0;
		int end = N - 1;
		string target = peo_check[i];
		while (start <= end) {
			int mid = (start + end) / 2;
			if (target == peo[mid]) {
				ans.push_back(target);
				break;
			}
			else if (target > peo[mid]) {	//찾는 값이 중앙값보다 더 클때 오른쪽 탐색
				start = mid +1 ;
			}
			else {							//찾는 값이 중앙값보다 더 작을경우 왼쪽 탐색
				end = mid - 1;
			}

		}

	}

	
	sort(ans.begin(), ans.end());	//출력
	cout << ans.size() << "\n";
	for (string s : ans) {
		cout << s << "\n";
	}
}
		