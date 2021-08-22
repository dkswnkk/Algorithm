//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/10819
//  BOJ10819 차이를 최대로

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,ans,temp;
int visited[201];
vector<int>v;

void find(){
    do{
        for(int i=2; i<=n; i++){
            temp+=abs(v[i-2]-v[i-1]);
        }
        ans=max(ans,temp);
        temp=0;
    }
    while(next_permutation(v.begin(),v.end()));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    find();
    cout<<ans;
}


