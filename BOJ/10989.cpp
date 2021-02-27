//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10989
//  BOJ10989 수 정렬하기3
#include <iostream>
using namespace std;

int main() {

	int arr[10001] = { 0, };
	int N,number;
	cin >> N;
	
	while (N--) {
		scanf("%d", &number);
		arr[number]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int k = 0; k <arr[i]; k++) {
			printf("%d\n",i);
		}
	}
}
