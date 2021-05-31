//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/2755
//  BOJ2755 이번학기 평점은 몇점?
#include <iostream>
#include <vector>

using namespace std;
float check(float num, string grade) {
	if (grade == "A+") return num *= 4.3; if (grade == "A0") return num *= 4.0; if (grade == "A-") return num *= 3.7;
	if (grade == "B+") return num *= 3.3; if (grade == "B0") return num *= 3.0; if (grade == "B-") return num *= 2.7;
	if (grade == "C+") return num *= 2.3; if (grade == "C0") return num *= 2.0; if (grade == "C-") return num *= 1.7;
	if (grade == "D+") return num *= 1.3; if (grade == "D0") return num *= 1.0; if (grade == "D-") return num *= 0.7;
	if (grade == "F+") return num *= 0.0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	float totalGrade = 0;
	float totalNum = 0;
	while (N--) {
		string name; float num; string grade;
		cin >> name >> num >> grade;
		totalNum += num;	//총 학점
		totalGrade+=check(num, grade);	//학점*성적
	}
	cout << fixed;
	cout.precision(2);
	cout << totalGrade / totalNum+0.000000000001;


}