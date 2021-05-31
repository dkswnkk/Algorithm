//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2525
//  BOJ2525 오븐 시계
#include <stdio.h>

int main() {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	
	int temp = a * 60 + b + c;
	if (temp > 1439) temp=temp - 1440;
	a = temp / 60;
	b = temp % 60;
	printf("%d %d", a, b);
}