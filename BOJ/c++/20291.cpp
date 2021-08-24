//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/20291
//  BOJ20291 파일 정리

#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    map<string,int>m;
    while(N--){
        string s,extention; cin>>s;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='.'){
                for(int k=i+1; k<s.length(); k++){
                    extention+=s[k];
                }
                break;
            }
        }
        m[extention]++;
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<' '<<i->second<<'\n';
    }
}
