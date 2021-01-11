//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/9498
//  BOJ9498 시험 성적
#include <iostream>
using namespace std;

string check(int score) {
	if (score >= 90) return "A";
	else if (score >= 80 && 89 >= score) return "B";
	else if (score >= 70 && 79 >= score) return "C";
	else if (score >= 60 && 69 >= score) return "D";
	else return "F";
}
int main() {
	int score;
	cin >> score;
	cout << check(score);

	

}