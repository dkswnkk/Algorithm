//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11051
//  BOJ11051 이항 계수2

#include <iostream>
#define MOD 10007
using namespace std;

long long int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K; cin>>N>>K;
    
    for(int i=0; i<=N; i++){
        for(int k=0; k<=K; k++){
            if(i==k||k==0)arr[i][k]=1;
            else arr[i][k]=(arr[i-1][k-1]+arr[i-1][k])%MOD;
        }
    }
    cout<<arr[N][K];
}
