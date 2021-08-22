//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14425
//  BOJ14425 문자열 집합

#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M,cnt=0; cin>>N>>M;
    map<string,int>m;
    for(int i=0; i<N; i++){
        string inp; cin>>inp;
        m[inp]++;
    }
    for(int i=0; i<M; i++){
        string inp; cin>>inp;
        if(m[inp]==1) cnt++;
    }
    cout<<cnt;
}
