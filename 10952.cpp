//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10952
//  BOJ10952 A+B-5
#include <iostream>
using namespace std;


int main(){
int A, B;

while (true) {
	cin >> A >> B;
	if (A == 0 && B == 0) break;
	cout << A + B<<"\n";
}
}
