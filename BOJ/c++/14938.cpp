//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14938
//  BOJ14938 서강그라운드

#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n,m,r,ans;  //n=지역의 갯수, m=수색범위, r=길이의 갯수
int graph[101][101];
int item[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>r;
    
    for(int i=0; i<101; i++){
        fill(graph[i],graph[i]+101,INF);
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            if(i==k) graph[i][k]=1;
        }
    }
    
    for(int i=1; i<=n; i++){
        cin>>item[i];
    }
    
    for(int i=1; i<=r; i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    
    for(int i=1; i<=n; i++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                graph[a][b]=min(graph[a][b],graph[a][i]+graph[i][b]);
            }
        }
    }
    for(int a=1; a<=n; a++){
        int temp=0;
        for(int b=1; b<=n; b++){
            if(graph[a][b]!=INF&&graph[a][b]<=m) temp+=item[b];
        }
        ans=max(ans,temp);
    }
    cout<<ans;
}
