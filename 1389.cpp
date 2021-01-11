//  Copyright © 2021 안주형. All rights reserved.
//  
//  https://www.acmicpc.net/problem/1389
//  BOJ1389 케빈 베이컨의 6단계 법칙
/*
플로이드-와샬 알고리즘
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9	//무한대를 의미하는 값으로 10억을 지정
using namespace std;
int N, M; //N=유저의 수, M=친구 관계 수
int graph[101][101];
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < 101; i++) {	
		fill(graph[i], graph[i] + 101,INF);	//무한대로 초기화	
	}

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;	//자기 자신으로 통하는 것은 0
		}
	}

	for (int i = 1; i <= M; i++) {	//친구 관계 입력. 한다리씩 건널때 1씩 증가
		int a, b; cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;	//양방향처리.
	}

	for (int k = 1; k <= N; k++) {	//플로이드-와샬 알고리즘 수행
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}	
	vector<int>kevin(N+1);	//케빈베이컨 정보를 담는 테이블
	kevin[0] = INF;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if(graph[a][b]==INF)continue;
			kevin[a] += graph[a][b];	//각 사람마다 다른사람에게 갈수 있는 모든 최단경로를 더해준다.
		}
	}

	int min_index = min_element(kevin.begin(), kevin.end()) - kevin.begin();	//케빈베이컨 수가 가장 적은 사람을 출력한다.
	cout << min_index;
	
	
}
	
