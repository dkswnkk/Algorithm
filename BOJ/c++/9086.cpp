//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/9086
//  BOJ9086 문자열

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin>>T;

    while(T--){
        string s; cin>>s;
        cout<<s[0]<<s[s.length()-1]<<'\n';
    }
}

