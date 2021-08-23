//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/4659
//  BOJ4659 비밀번호 발음하기

#include <iostream>
using namespace std;

bool check_one(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') return true;
    }
    return false;
}

bool check_two(string s){
    int cnt_a=0,cnt_b=0;    //cnt_a=모음 카운터, cnt_b=자음 카운터
    for(int i=0; i<s.length(); i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            cnt_b=0;
            cnt_a++;
        }
        else{
            cnt_b++;
            cnt_a=0;
        }
        if(cnt_b==3||cnt_a==3) return false;
    }
    return true;
}

bool check_third(string s){
    char before=' ';
    for(int i=0; i<s.length(); i++){
        if(s[i]!='o'&&s[i]!='e'){
            if(before==s[i]) return false;
            else before=s[i];
        }

    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        string s; cin>>s;
        if(s=="end") break;
        
        if(!check_one(s)){
            cout<<"<"<<s<<"> is not acceptable."<<'\n';
            continue;
        }
        if(!check_two(s)){
            cout<<"<"<<s<<"> is not acceptable."<<'\n';
            continue;
        }
        if(!check_third(s)){
            cout<<"<"<<s<<"> is not acceptable."<<'\n';
            continue;
        }
        cout<<"<"<<s<<"> is acceptable."<<'\n';
    }
}
