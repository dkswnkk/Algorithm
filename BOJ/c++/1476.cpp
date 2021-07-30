//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1476
//  BOJ1476 날짜 계산

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int E,S,M; cin>>E>>S>>M;
    
    for(int i=0; ; i++){
        if(i%15==E-1&&i%28==S-1&&i%19==M-1){
            cout<<i+1;
            break;
        }
    }
}
