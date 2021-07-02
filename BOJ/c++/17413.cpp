//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/17413
//  BOJ17413 단어 뒤집기2

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s,ans="",temp="";
    bool flag=false;
    getline(cin,s);
    
    for(int i=0; i<s.length(); i++){
        if(s[i]=='<'){
            if(temp.length()!=0){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                temp.clear();
                ans+=s[i];
                flag=true;
                continue;
            }
            flag=true;
            ans+=s[i];
            continue;
        }
        else if(s[i]=='>'){
            flag=false;
            ans+=s[i];
            continue;
        }
        
        if(flag) ans+=s[i]; //태그가 열려 있을때는 뒤집지 않는다.
        else{   //현재 태그가 닫혀있는 상태일때
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                temp.clear();

            }
            else temp+=s[i];
        }
        
    }
    if(temp.length()!=0){
        reverse(temp.begin(),temp.end());
        ans+=temp;
    }
    cout<<ans;
}
