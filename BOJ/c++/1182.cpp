//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1182
//  BOJ1182 부분 수열의 합

#include <iostream>
using namespace std;

int arr[20];
int ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,S; cin>>N>>S;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=1; i<(1<<N); i++){ //공집합은 제외
        int sum=0;
        for(int k=0; k<N; k++){
            if(i&(1<<k)) sum+=arr[k];
        }
        if(sum==S) ans++;
    }
    cout<<ans;
}
