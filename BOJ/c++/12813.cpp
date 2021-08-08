//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/12813
//  BOJ12813 이진수 연산

#include <iostream>
#include <bitset>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    bitset<100000>A,B;
    cin>>A>>B;
    
    cout<<(A&B)<<'\n';
    cout<<(A|B)<<'\n';
    cout<<(A^B)<<'\n';
    cout<<(~A)<<'\n';
    cout<<(~B)<<'\n';
}
