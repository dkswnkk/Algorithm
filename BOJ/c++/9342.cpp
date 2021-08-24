//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9342
//  BOJ9342 염색체

#include <iostream>
#include <map>

using namespace std;

bool check_one(string s){   // 문자열은 {A, B, C, D, E, F} 중 0개 또는 1개로 시작해야 한다.
    if(s[0]=='A'||s[0]=='B'||s[0]=='C'||s[0]=='D'||s[0]=='E'||s[0]=='F'){
        return true;
    }
    return false;
}

bool check_two(string s){   //그 다음에는 A가 하나 또는 그 이상 있어야 한다.
    for(int i=1; i<s.length(); i++){
        if(s[i]=='A') return true;
    }
    return false;
}
bool check_three(string s){ //그 다음에는 F가 하나 또는 그 이상 있어야 한다.
    for(int i=2; i<s.length(); i++){    //
        if(s[i]=='F') return true;
    }
    return false;
}
bool check_four(string s){  //그 다음에는 C가 하나 또는 그 이상 있어야 한다.
    for(int i=3; i<s.length(); i++){
        if(s[i]=='C') return true;
    }
    return false;
}

bool check_five(string s){  //그 다음에는 {A, B, C, D, E, F} 중 0개 또는 1개가 있으며, 더 이상의 문자는 없어야 한다.
    int cnt=0;
    for(int i=4; i<s.length(); i++){
        if(s[i]!='A'||s[i]!='B'||s[i]!='C'||s[i]!='D'||s[i]!='E'||s[i]!='F') return false;
        else cnt++;
    }
    if(cnt<=1) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        bool flag=true;
        map<char,int>m;
        string temp,s; cin>>temp;
        
        if(temp.length()<4){
            if(temp=="A"||temp=="AF"||temp=="AFC"||temp=="B"||temp=="C"||temp=="D"||temp=="E"||temp=="F"){
                cout<<"Infected!"<<'\n';
                continue;
            }
            cout<<"Good"<<'\n';
            continue;
        }
        else{
            s+=temp[0];
            for(int i=1; i<temp.length(); i++){
                if(m[temp[i]]==0){
                    m[temp[i]]++;
                    s+=temp[i];
                }
            }
            if(!check_one(s))flag=false;
            if(!check_two(s))flag=false;
            if(!check_three(s))flag=false;
            if(!check_four(s))flag=false;
            if(!check_five(s))flag=false;
            
            if(flag) cout<<"Infected!"<<'\n';
            else cout<<"Good"<<'\n';
        }
    }
}
