//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/11021
//  BOJ11021 A+B-7
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T,a,b;
	

	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> a >> b;
		cout << "Case #" << i << ": " << a+ b<< "\n";
	}

}