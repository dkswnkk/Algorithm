//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1010
//  BOJ1010 다리 놓기

#include <iostream>
using namespace std;

int arr[31][31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int N,M; cin>>N>>M;
        
        for(int i=0; i<=M; i++){
            for(int k=0; k<=N; k++){
                if(i==k||k==0) arr[i][k]=1;
                else{
                    arr[i][k]=arr[i-1][k-1]+arr[i-1][k];
                }
            }
        }
        cout<<arr[M][N]<<'\n';
        
    }
}
