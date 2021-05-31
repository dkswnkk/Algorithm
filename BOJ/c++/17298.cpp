//  Copyright © 2021 안주형. All rights reserved.
// 
//  https://www.acmicpc.net/problem/17298
//  BOJ17298 오큰수

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	stack<pair<int,int>>st;
	vector<int>v(N, -1);	//오큰수를 담는 테이블, 오큰수가 없는 경우인 -1로 초기화

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (st.empty()) st.push({ num,i });	//처음에 스택이 비었다면 삽입 (수열값,인덱스)
		else {								//스택이 비지 않았을때
			while(st.top().first<num){	//스택의 상단 값이 입력 값보다 작을때
				v[st.top().second] = num;	//그 스택의 상단값은 오큰수 이기에 오큰수 테이블에 저장
				st.pop();					//오큰수를 구한 스택은 pop
				if (st.empty()) break;				
			}
			 st.push({ num,i });		//스택의 상단 값이 입력값보다 크면 입력값 push
		}
	}
	for (int i : v) {	//오큰수 출력
		cout << i << ' ';
	}

}