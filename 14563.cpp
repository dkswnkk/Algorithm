//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/14563
//  BOJ14563 완전수
#include <iostream>

using namespace std;

/*
N의 약수는 N을 반으로 나눈것보다 초과된 값은 약수가 될 수 없다.(N은 포함) ex)10-> 1,2,5,10
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		bool check[10001] = { false };
		int sum = 0;
		int N; cin >> N;
		for (int i = 1; i<=N/2; i++) {	
			if (N % i == 0) check[i] = true;
			}
		
		for (int i = 1; i <= N/2; i++) {
			if (check[i])sum += i;
		}
		
		if (sum > N) cout << "Abundant" << "\n";
		else if (sum < N) cout << "Deficient" << '\n';
		else cout << "Perfect" << "\n";
		
	
	}
}