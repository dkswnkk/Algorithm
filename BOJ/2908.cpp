//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2908
//  BOJ2908 상수
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	
	string A, B;
	char temp1,temp2;
	int n1, n2;

	cin >> A>> B;


		temp1 = A[0]; 
		A[0] = A[2];
		A[2] = temp1;
		temp2 = B[0];
		B[0] = B[2];
		B[2] = temp2;


		n1 = stoi(A);
		n2 = stoi(B);
		if (n1 > n2) cout << n1;
		else cout << n2;
		
	
}