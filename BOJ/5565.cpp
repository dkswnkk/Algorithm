//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/5565
//  BOJ5565 영수증
#include <stdio.h>

int main() {
	int sum=0;
	scanf_s("%d", &sum);
	for (int i = 0; i < 9; i++) {
		int n;
		scanf_s("%d", &n);
		sum -= n;
	}
	printf("%d",sum);
}