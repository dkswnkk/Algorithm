//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16943
//  BOJ16943 숫자 재배치

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string A,B; cin>>A>>B;
    sort(A.begin(),A.end());
    int ans=-1;
    do{
        if(stoi(A)<stoi(B)&&A[0]!='0') ans=max(ans,stoi(A));
    }
    while(next_permutation(A.begin(), A.end()));
    cout<<ans;
}
