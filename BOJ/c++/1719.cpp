//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1719
//  BOJ1719 택배

#include <iostream>
#define INF 9e8
using namespace std;

int graph[201][201];
int dp[201][201];
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        fill(graph[i],graph[i]+201,INF);
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            if(i==k) graph[i][k]=0;
        }
    }
    
    for(int i=1; i<=m; i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
        dp[a][b]=b;
        dp[b][a]=a;
    }
    
    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                if(graph[a][k]+graph[k][b]<graph[a][b]){
                    graph[a][b]=graph[a][k]+graph[k][b];
                    if(k!=a) dp[a][b]=dp[a][k];
                }
            }
        }
    }
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            if(dp[a][b]==0) cout<<'-'<<' ';
            else cout<<dp[a][b]<<' ';
        }
        cout<<'\n';
    }
    
    
}
