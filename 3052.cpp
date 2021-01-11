//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/3052
//  BOJ3052 나머지
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int T = 10;
	int N;
	vector<int> v;

		for(int i=0; i<10; i++){
		cin >> N;
		int check = N % 42;
		if(v.empty()) v.push_back(check);
		if (!(find(v.begin(), v.end(), check) != v.end())) v.push_back(check);
	}
		cout << v.size();
}