//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/20154
//  BOJ20154 이 구역의 승자는 누구야?!

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


char change(char c){
    if(c=='A') return '3';
    if(c=='B') return '2';
    if(c=='C') return '1';
    if(c=='D') return '2';
    if(c=='E') return '3';
    if(c=='F') return '3';
    if(c=='G') return '3';
    if(c=='H') return '3';
    if(c=='I') return '1';
    if(c=='J') return '1';
    if(c=='K') return '3';
    if(c=='L') return '1';
    if(c=='M') return '3';
    if(c=='N') return '3';
    if(c=='O') return '1';
    if(c=='P') return '2';
    if(c=='Q') return '2';
    if(c=='R') return '2';
    if(c=='S') return '1';
    if(c=='T') return '2';
    if(c=='U') return '1';
    if(c=='V') return '1';
    if(c=='W') return '2';
    if(c=='X') return '2';
    if(c=='Y') return '2';
    if(c=='Z') return '1';
    return '0';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s,num; cin>>s;
    int ans=0;
    for(int i=0; i<s.length(); i++){
        num+=change(s[i]);
    }
    int cnt=0;
    while(true){
        if(cnt+1<num.length()){
            if(num[cnt]-'0'+num[cnt+1]-'0'>10) ans+=(num[cnt]-'0'+num[cnt+1]-'0')%10;
            else ans+=num[cnt]-'0'+num[cnt+1]-'0';
            cnt+=2;
        }
        else{
            ans+=num[cnt]-'0';
            break;
        }
    }
    if(ans%2!=0&&ans!=0) cout<<"I'm a winner!";
    else  cout<<"You're the winner?";
}
