//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/16401
//  BOJ16401 과자 나눠주기

#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int>v;
    
    int M,N; cin>>M>>N;
    
    for(int i=0; i<N; i++){ //과자 길이정보 삽입
        int len; cin>>len;
        v.push_back(len);
    }
    
    int start=1,end=1e9+1,ans=0;
    
    while(start<=end){
        int cnt=0;
        int mid=(start+end)/2;
        for(int i=0; i<N; i++){
            cnt+=v[i]/mid;
        }
        if(cnt>=M){
            start=mid+1;
            ans=max(ans,mid);
        }
        else if(cnt<M){
            end=mid-1;
        }
    }
    cout<<ans;
    
}
