//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/13549
//  BOJ13549 숨바꼭질3

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;


int N,K;    //N=수빈이가 있는 위치, K=동생이 있는 위치
int visited[MAX];
int ans=MAX;

void bfs(int start,int time){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //{시간,현재 거리}
    pq.push({0,start});
    visited[start]=1;
    
    while(!pq.empty()){
        int time=pq.top().first;
        int start=pq.top().second;
        pq.pop();
        visited[start]=1;
        if(start==K){
            ans=time;
            return;
        }
        else{
            if(start>=0&&start-1<MAX&&!visited[start-1]) pq.push({time+1,start-1});    //걸을떄 시간 +1
            if(start+1<MAX&&!visited[start+1]) pq.push({time+1,start+1});  //걸을때 시간 +1
            if(start*2<MAX&&!visited[start*2]) pq.push({time,start*2});  //순간이동 할때 시간 +0
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>K;
    bfs(N,0);
    cout<<ans;
}
