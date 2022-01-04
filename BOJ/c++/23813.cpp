//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/23813
//  BOJ23813 회전


#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    
    long long ans = stoll(s);
    int cnt = s.length()-1;
    
    for(int i=0; i<cnt; i++){
        char first = s.front();
        string second = s.substr(1,cnt);
        s = second + first;
        ans += stoll(s);
    }
    cout<<ans;
}
