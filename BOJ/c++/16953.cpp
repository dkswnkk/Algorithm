//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16953
//  BOJ16953 A → B

#include <iostream>
#define max 1e9
using namespace std;

int ans=max;
void dfs(long long start,long long end,int cnt){
    if(start==end){
        ans=min(cnt,ans);
        return;
    }
    else if(start<end){
        dfs(start*2,end,cnt+1);
        dfs(start*10+1,end,cnt+1);
    }
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long A,B; cin>>A>>B;
    
    dfs(A,B,1);
    if(ans==max) cout<<-1;
    else cout<<ans;
}
