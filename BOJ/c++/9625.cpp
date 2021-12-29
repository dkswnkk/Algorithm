//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9625
//  BOJ9625 BABBA

#include <iostream>
using namespace std;

int A[46],B[46];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n; cin>>n;
    
    A[0]=1; B[0]=0;
    A[1]=0; B[1]=1;
    A[2]=1; B[2]=1;
 
    
    for(int i=3; i<=n; i++){
        A[i] = B[i-1];
        B[i] = A[i-1] + B[i-1];
    }
    cout<<A[n]<< ' '<<B[n];
}
