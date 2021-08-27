//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1759
//  BOJ1759 암호 만들기

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int L,C;
int visited[1001];
map<char,int>m;
string s;

bool valid_check(string temp){
    bool flag=false;
    int cnt=0;  //두개의 자음인지 체크
    for(int i=0; i<temp.length(); i++){
        if(temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u') flag=true;
        else cnt++;
    }
    if(flag&&cnt>=2) return true;
    else return false;
}

void find(int start_index,string pass){
    if(pass.back()<s[start_index]) pass+=s[start_index];
    if(pass.length()==L){
        if(valid_check(pass)) cout<<pass<<'\n';
    }
    else{
        for(int i=start_index; i<s.length(); i++){
            if(!visited[s[i]-97]){
                visited[s[i]-97]=1;
                find(i,pass);
                visited[s[i]-97]=0;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>L>>C;
    
    for(int i=0; i<C; i++){
        char temp; cin>>temp;
        s+=temp;
    }
    sort(s.begin(),s.end());
    
    for(int i=0; i<s.length(); i++){
        visited[s[i]-97]=1;
        find(i,"");
    }
    
}
