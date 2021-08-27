//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/13239
//  BOJ13239 Combinations

#include <iostream>
#define MOD 1000000007
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        long long int arr[1001][1001];
        int N,K; cin>>N>>K;
        
        for(int i=0; i<=N; i++){
            for(int k=0; k<=K; k++){
                if(i==k||k==0)arr[i][k]=1;
                else arr[i][k]=(arr[i-1][k-1]+arr[i-1][k])%MOD;
            }
        }
        cout<<arr[N][K]<<'\n';
    }
}
