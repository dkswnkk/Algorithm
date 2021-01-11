//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/10610
//  BOJ10610 30
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string N;
	cin >> N;
	
	long long sum = 0;
	bool check = true;
	for (int i = 0; i < N.length(); i++) {	//30의 배수가 될려면 , 각 자리의 수의 합이 3의 배수이고, 끝자리가 0 이어야한다
		sum += (N[i] - '0');
		if (!(N[i]-'0')) check = false;	//숫자중에 0이 없으면 false, 0이 있으면 true
	}
	if (sum%3||check) cout << -1<< "\n";	//각자리 수의 합이 3의배수가 아니거나 , 끝자리가 0이 아니면 -1
	else {
		sort(N.begin(), N.end(), greater<char>());	//30의 배수라면 가장 큰 수 출력.
		cout << N<<"\n";
	}

} 