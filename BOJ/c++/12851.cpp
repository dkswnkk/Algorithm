//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/12851
//  BOJ12851 숨바꼭질2

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;


int N,K;    //N= 수빈이가 있는 위치, K= 동생이 있는 위치
int short_time=MAX,cnt;
int visited[MAX];

void bfs(int start,int time){
    queue<pair<int,int>>q;
    q.push({start,0});
    visited[start]=1;
    
    while(!q.empty()){
        int start=q.front().first;
        int time=q.front().second;
        q.pop();
        visited[start]=1;
        
        if(cnt&&short_time==time&&start==K){
            cnt++;   //최소 시간으로 수빈이가 동생이 있는 위치에 또 도착했을때 카운트 추가
        }
        
        if(!cnt&&start==K&&short_time){   //최초로 수빈이가 동생이 있는 위치에 도착했을 때
            short_time=time;
            cnt++;
        }
        
        if(start+1<MAX&&!visited[start+1]) q.push({start+1,time+1}); //수빈이가 걸을떄
        if(start-1<MAX&&!visited[start-1]) q.push({start-1,time+1}); //수빈이가 걸을떄
        if(start*2<MAX&&!visited[start*2]) q.push({start*2,time+1}); //수빈이가 순간이동 할 때
        
    }
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>K;
    
    bfs(N,0);
    cout<<short_time<<'\n'<<cnt;
}
