//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1822
//  BOJ1822 차집합
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b; cin >> a >> b;
	
	set<int>A;	//바이너리 서치 및 오름차순 정렬 역할
	for (int i = 0; i < a; i++) {	//집합 A원소 삽입
		int n; cin >> n;
		A.insert(n);
	}
	
	for(int i=0; i<b; i++){
		int num; cin >> num;	
		auto it = A.find(num);
		if (it == A.end()) continue;	//A집합에 B원소가 없다면 무시
		else A.erase(it);			//A집합에 B원소가 있다면 삭제.
	}
	cout << A.size() << "\n";
	for (int i : A) {
		cout << i << " ";
	}
}