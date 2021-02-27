//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/4673
//  BOJ4673 셀프넘버
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool selfNumber[30000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(selfNumber, true, sizeof(selfNumber));

	for (int i = 1; i <= 10000; i++) {
		if (i < 10) selfNumber[i + i] = false;
		else if (i < 100&&i>=10) selfNumber[i / 10 + i % 10 + i] = false;
		else if (i < 1000&&i>=100) selfNumber[i / 100 + (i%100)/10 + i % 10+ i] = false;
		else if (i < 10000&&i>=1000)selfNumber[i / 1000 + (i %1000)/100 + i%100/10+i%10+i] = false;
	}
	
	for (int i = 1; i <= 10000; i++) {
		if (selfNumber[i]) cout << i << "\n";
	}
}