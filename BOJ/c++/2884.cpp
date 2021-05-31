//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2884
//  BOJ2884 알람시계
#include <iostream>
using namespace std;

int main() {
	int H, M; cin >> H>> M;
	int temp = H * 60 + M-45;
	if (temp > 1439) temp -= 1440 - 45;
	if (temp < 0) temp += 1440;

	cout << temp / 60 << ' ' << temp % 60;
	
}