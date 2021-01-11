//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1330
//  BOJ1330 두 수 비교하기
#include <iostream>
using namespace std;

string compare(int n1, int n2) {
	if (n1 > n2)  return ">";
	else if (n1 < n2)  return "<";
	else  return "==";
}
int main() {
	int A, B;
	cin >> A >> B;

	cout<<compare(A, B);
	

}