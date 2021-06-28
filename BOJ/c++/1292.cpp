//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/1292
//  BOJ1292 쉽게 푸는 문제

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int start,end; cin>>start>>end;
    vector<int>v;
    
    for(int k=1; k<=end; k++){
        for(int i=0; i<k; i++){
            v.push_back(k);
        }
    }
    
    int ans=0;
    for(int i=start-1; i<end; i++){
        ans+=v[i];
    }
    cout<<ans;
}
