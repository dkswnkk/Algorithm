//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/20437
//  BOJ20437 문자열 게임2


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
시간초과 풀이
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        string s;
        int cnt;
        cin>>s>>cnt;
        vector<int>v;
        for(int i=0; i<s.length(); i++){
            map<char,int>m;
            m[s[i]]=1;
            for(int k=i+1; k<s.length(); k++){
                if(s[i]==s[k])m[s[i]]++;
                if(m[s[i]]==cnt){
                    v.push_back(k-i+1);
                    m[s[i]]-=cnt;
                }
            }
        }
        if(v.empty()) cout<<-1<<'\n';
        else cout<<*min_element(v.begin(), v.end())<<' '<<*max_element(v.begin(), v.end())<<'\n';
        
        
    }
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        string s;
        int cnt;
        cin>>s>>cnt;
        vector<int>v,index[26];
        
        for(int i=0; i<s.length(); i++){
            index[s[i]-97].push_back(i);
        }
        int short_word=9999,long_word=-1;
        
        for(int i=0; i<26; i++){
            if(index[i].size()>=cnt){
                for(int k=0; k<=index[i].size()-cnt; k++){   // 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
                    short_word=min(short_word,index[i][k+cnt-1]-index[i][k]+1);
                    long_word=max(long_word,index[i][k+cnt-1]-index[i][k]+1);
                }
            }
        }
        
        
        if(short_word==9999||long_word==-1) cout<<-1<<'\n';
        else cout<<short_word<<' '<<long_word<<'\n';
        
    }
}
