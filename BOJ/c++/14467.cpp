//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14467
//  BOJ14467 소가 길을 건너간 이유1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,cnt=0; cin>>N;
    for(int i=0; i<N; i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
    }
    
    
    for(int i=1; i<=10; i++){
        if(v[i].size()<=1) continue;
        int first=v[i][0];
        for(int k=1; k<v[i].size(); k++){
            if(v[i][k]!=first){
                cnt++;
                first=v[i][k];
            }
        }
        
    }
    cout<<cnt;
}
