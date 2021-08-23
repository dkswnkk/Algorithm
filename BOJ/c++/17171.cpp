//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16171
//  BOJ17171 나는 친구가 적다(Small)

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1,s2,temp; cin>>s1>>s2;
    
    for(int i=0; i<s1.length(); i++){
        if(!(s1[i]>='0'&&s1[i]<='9')) temp+=s1[i];  //숫자만 뺴준다.
    }
    
    
    if(temp.find(s2)==string::npos) cout<<0;  //포함되어 있지 않을때
    else cout<<1;               //포함되어 있을 때
}
