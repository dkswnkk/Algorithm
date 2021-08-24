//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16916
//  BOJ16916 부분 문자열


#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    char S[1000001],P[1000001]; cin>>S>>P;
    
    char *temp=strstr(S,P);
    if(temp!=NULL) cout<<1;
    else cout<<0;

    
}
