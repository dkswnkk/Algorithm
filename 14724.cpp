//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/14724
//  BOJ14724 관리자는 누구?
#include <iostream>
#include <vector>

using namespace std;

void check(int x) {
	if (x == 1)cout << "PROBRAIN";
	if (x == 2)cout << "GROW";
	if (x == 3)cout << "ARGOS";
	if (x == 4)cout << "ADMIN";
	if (x == 5)cout << "ANT";
	if (x == 6)cout << "MOTION";
	if (x == 7)cout << "SPG";
	if (x == 8)cout << "COMON";
	if (x == 9)cout << "ALMIGHTY";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	int maxNum=0,result=0,maxIndex;
	for (int i = 1; i <= 9; i++) {
		for (int k = 0; k < N; k++) {
			int num; cin >> num;
			if (num > maxNum) maxNum = num;
		}
		if (maxNum>result) {
			result=maxNum;
			maxIndex = i;
		}
	}
	check(maxIndex);

}