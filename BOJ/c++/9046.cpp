//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9046
//  BOJ9046 복호화

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    cin.ignore();
    
    while(T--){
        map<char,int>m;
        bool flag=false;
        string s; getline(cin,s);
        int max_cnt=-1;
        char max_char;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ') m[s[i]]++;
        }
        for(auto i=m.begin(); i!=m.end(); i++){ //가장 빈번하게 나타나는 문자체크
            if(i->second>=max_cnt){
                max_char=i->first;  //가장 빈번하게 나타나는 문자
                max_cnt=i->second;  //가장 빈번하게 나타나는 문자의 빈번횟수
            }
        }
        for(auto i=m.begin(); i!=m.end(); i++){ //가장 빈번하게 나타나는 문자가 여러개 인지 체크
            if(i->second==max_cnt&&i->first!=max_char){
                cout<<'?'<<'\n';
                flag=true;
                break;
            }
        }
        if(!flag) cout<<max_char<<'\n';
    }
}
