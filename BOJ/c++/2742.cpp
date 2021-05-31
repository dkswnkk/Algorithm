//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2742
//  BOJ2742 기찍N
#include <stdio.h>

int main() {
	int N;
	scanf_s("%d", &N);
	while (N--) {
		printf("%d\n", N+1);
		if (N==0) return 0;
	}
}