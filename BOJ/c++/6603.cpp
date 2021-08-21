//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/6603
//  BOJ6603 로또

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int print[6],n;

void find(const vector<int>&lotto,int start,int depth){
    if(depth==6){
        for(int i:print){
            cout<<i<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start; i<n; i++){
        print[depth]=lotto[i];
        find(lotto,i+1,depth+1);
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        cin>>n;
        if(n==0) break;
        vector<int>lotto;
        for(int i=0; i<n; i++){
            int inp; cin>>inp;
            lotto.push_back(inp);
        }
        find(lotto,0,0);
        cout<<'\n';
    }
    
}
