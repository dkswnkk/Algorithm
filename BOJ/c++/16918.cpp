//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16198
//  BOJ16198 에너지 모으기

#include <iostream>
#include <vector>

using namespace std;

vector<int>v;
int visited[11];
int ans,N,score=-1;

void find(vector<int>&v,int score){
    if(v.size()==2){
        ans=max(ans,score);
        return;
    }
    for(int i=1; i<v.size()-1; i++){
        int inp=v[i];
        score+=v[i-1]*v[i+1];
        v.erase(v.begin()+i);
        find(v,score);
        v.insert(v.begin()+i,inp);
        score-=v[i-1]*v[i+1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    find(v,0);
    cout<<ans;
}
