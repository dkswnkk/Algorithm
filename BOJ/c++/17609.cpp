//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/17609
//  BOJ17609 회문

#include <iostream>
#include <algorithm>
using namespace std;

bool check_palindrome(string s){
    int start=0,end=(int)s.length()-1;
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}

bool make_palindrome(string s){
    int start=0,end=(int)s.length()-1;
    int cnt=0,cant_make=0;
    while(start<end){   //앞 글자를 무시.
        if(s[start]!=s[end]){
            start++;
            cnt++;
            if(cnt==2){
                cant_make++;
                break;
            }
        }
        else{
            start++;
            end--;
        }
    }
    start=0,end=(int)s.length()-1,cnt=0;
    while(start<end){   //뒷 글자를 무시.
        if(s[start]!=s[end]){
            end--;
            cnt++;
            if(cnt==2){
                cant_make++;
                break;
            }
        }
        else{
            start++;
            end--;
        }
    }
    
    if(cant_make==2) return false;
    else return true;
}

int main(){
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        if(check_palindrome(s)){
            cout<<0<<'\n';
            continue;
        }
        if(make_palindrome(s)){
            cout<<1<<'\n';
            continue;
        }
        cout<<2<<'\n';
    }
}
