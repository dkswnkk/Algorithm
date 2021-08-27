//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9655
//  BOJ9655 돌 게임

#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;

    cout<<(N%2?"SK":"CY");    //N=홀수, 상근 승, 짝수, 창근 승
    
}
