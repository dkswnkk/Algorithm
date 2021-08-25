//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/20053
//  BOJ20053 최소,최대 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        vector<int>v;
        int N; cin>>N;
        for(int i=0; i<N; i++){
            int inp; cin>>inp;
            v.push_back(inp);
        }
        sort(v.begin(),v.end());
        cout<<v.front()<<' '<<v.back()<<'\n';
    }
}
