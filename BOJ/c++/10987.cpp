//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/10987
//  BOJ10987 모음의 개수

#include <iostream>
using namespace std;

int cnt=0;

char alphabet[6]="aeiou";
int check(string s){
    for(int i=0; i<6; i++){
        for(int k=0; k<s.length(); k++){
            if(s[k]==alphabet[i]) cnt++;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    cout<<check(s);
}
